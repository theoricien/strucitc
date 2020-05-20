%{
	/*
	 * How the ICG works:
	 * For expressions, each expression's production
	 * returns an stack_t structure, then we just push each
	 * stack_t structure to the more general one.
	 * Then when our expression is finalized, we call the
	 * statements() function which will generate the code
	 * by the stack passed as argument
	 *
	 * Statement stack representation:
	 * [statement_type, data*, end_statement_type]
	 * Ex:
	 * ["expr", "=", "a", "3", ";"]
	 * ["ifelse", "==", "a", "3", "then", "expr", "=", "a", "4", ";" "else", "expr", "=", "a", "3", ";", "endif"]
	 *
	 * declarations stack representation
	 * [type_specifier, identifier, declarations_type]
	 * Ex:
	 * ["int", "a", "declarations"]
	 * (not yet implemented)
	 * ["int", "main", "function_declarations"]
	 *
	 * Correspondence table representation:
	 * It's just a linked list with 2 values: front-end repr & back-end repr
	 * [front-end-value, back-end-value, next]
	 * Ex:
	 * 0xCAFECAFE : ["a", "v0", 0xDEADBABE]
	 * 0xDEADBABE : [NULL, NULL, NULL]
	 */

	#include <stdio.h>
	#include <stdlib.h>

	#include "stack.h"
	#include "declarations.h"
	#include "statements.h"

	void log2 (char *msg)
	{
	    if (0)
	        printf("[***] %s\n", msg);
	}

	/* declarations stack */
	struct stack_t *decl;
	/* Statement stack */
	struct stack_t *stmt;
	/* Correspondence table */
	struct crpdct_t *ct;
	/* declarations buffer */
	struct buf_t *buf_decl;
	/* Statement buffer */
	struct buf_t *buf_stmt;
	/* Variable count */
	unsigned int vx;
	/* Label count */
	unsigned int lx;

	extern char yytext[];
	int printed = 0;
	void yyerror(char const *s);
	int yylex();

	void fix_ifelse (struct stack_t *, unsigned int);
	unsigned int rfix_ifelse (struct stack_t *, unsigned int);
	void create_primitive_functions (struct stack_t *);
%}

%union
{
	  char						* string;
		struct stack_t 	* stk;
}

%define parse.error verbose

%token IDENTIFIER
%token CONSTANT
%token STRING_LITERAL
%token SIZEOF
%token PTR_OP
%token LE_OP
%token GE_OP
%token EQ_OP
%token NE_OP
%token L_OP
%token G_OP
%token AND_OP
%token OR_OP
%token MUL_ASSIGN
%token DIV_ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token TYPE_NAME
%token EXTERN
%token INT VOID
%token STRUCT
%token IF
%token ELSE
%token WHILET
%token FOR
%token RETURN

%type <string> IDENTIFIER
%type <string> CONSTANT
%type <string> STRING_LITERAL
%type <string> SIZEOF
%type <string> PTR_OP
%type <string> LE_OP
%type <string> GE_OP
%type <string> L_OP
%type <string> G_OP
%type <string> EQ_OP
%type <string> NE_OP
%type <string> RETURN
%type <string> WHILET
%type <string> AND_OP
%type <string> OR_OP
%type <string> VOID
%type <string> INT
%type <string> STRUCT
%type <string> unary_operator
%type <string> assignment_operator

%type <stk> primary_expression
%type <stk> postfix_expression
%type <stk> unary_expression
%type <stk> cast_expression
%type <stk> multiplicative_expression
%type <stk> additive_expression
%type <stk> relational_expression
%type <stk> equality_expression
%type <stk> logical_and_expression
%type <stk> logical_or_expression
%type <stk> assignment_expression
%type <stk> if_expression
%type <stk> expression
%type <stk> expression_statement

%type <stk> function_declarator
%type <stk> function_type
%type <stk> function_oret
%type <stk> argument_type
%type <stk> declarations
%type <stk> declarations_specifiers
%type <stk> init_declarator
%type <stk> type_specifier
%type <stk> struct_oret
%type <stk> struct_declarations_list
%type <stk> struct_declarations
%type <stk> specifier_qualifier_list
%type <stk> struct_declarator
%type <stk> declarator
%type <stk> function_definer
%type <stk> function_declarator_pointer
%type <stk> parameter_list
%type <stk> parameter_declarations
%type <stk> identifier_list
%type <stk> init_declarator_list
%type <stk> initializer
%type <stk> struct_declarator_list
%type <stk> pointer_direct_declarator
%type <stk> direct_declarator
%type <stk> direct_declarator_pointer
%type <stk> function_parameter_list
%type <stk> type_name
%type <stk> abstract_declarator
%type <stk> abstract_declarator_with_pointer
%type <stk> direct_abstract_declarator
%type <stk> direct_abstract_declarator_pointer_free
%type <stk> argument_expression_list

%start _start
%%

primary_expression
    : IDENTIFIER
		{ struct stack_t *tmp = init_stack();
			tmp->push(tmp, $1);
			$$ = tmp;}

    | CONSTANT
		{ struct stack_t *tmp = init_stack();
			tmp->push(tmp, $1);
			$$ = tmp;}

    | '(' expression ')'
		{ struct stack_t *tmp = init_stack();
			tmp->push_stack(tmp, $2);
			tmp->push(tmp, ";");
			$$ = tmp;}
    ;

postfix_expression
    : primary_expression
		{$$ = $1;}

    | postfix_expression '(' ')'
		{ struct stack_t *tmp = init_stack();
			tmp->push(tmp, "funcall");
			tmp->push_stack(tmp, $1);
			tmp->push(tmp, "noarg");
			tmp->push(tmp, "endfuncall");
			$$ = tmp;}

    | postfix_expression '(' argument_expression_list ')'
		{ struct stack_t *tmp = init_stack();
			tmp->push(tmp, "funcall");
			tmp->push_stack(tmp, $1);
			tmp->push(tmp, "args");
			tmp->push_stack(tmp, $3);
			tmp->push(tmp, "endfuncall");
			$$ = tmp;}
/*
    | postfix_expression PTR_OP IDENTIFIER
		{struct buf_t *tmp = init_buf();
			tmp->add(tmp, "%s->%s", $1, $3);
			$$ = tmp;}*/
    ;

argument_expression_list
    : assignment_expression
		{ $$ = $1; }

    | argument_expression_list ',' assignment_expression
		{ struct stack_t *tmp = init_stack();
			tmp->push_stack(tmp, $1);
			tmp->push(tmp, ",");
			tmp->push_stack(tmp, $3);
			$$ = tmp;}
    ;

unary_expression
    : postfix_expression
		{$$ = $1;}

    | unary_operator cast_expression
		{ struct stack_t *tmp = init_stack();
			tmp->push(tmp, $1);
			tmp->push_stack(tmp, $2);
			$$ = tmp;}

    | SIZEOF '(' unary_expression ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "4");
			$$ = stk;}

    | SIZEOF '(' argument_type ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "sizeof");
			stk->push_stack(stk, $3);
			$$ = stk;}
    ;

unary_operator
    : '&'
    {$$ = "u&";}

    | pointer
    {$$ = "u*";}

    | '-'
    {$$ = "u-";}
  	;

cast_expression
    : unary_expression
		{$$ = $1;}

/* To implement
    | '(' type_name ')' cast_expression
		{char *tmp = (char *) calloc (3, 1);
			sprintf(tmp, "(%s) %s", $2, $4);
			$$ = tmp;}*/
  	;

multiplicative_expression
    : cast_expression
		{$$ = $1;}

    | multiplicative_expression '*' cast_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "*");
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

    | multiplicative_expression '/' cast_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "/");
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
  	;

additive_expression
    : multiplicative_expression
		{$$ = $1;}

    | additive_expression '+' multiplicative_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "+");
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

    | additive_expression '-' multiplicative_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "-");
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
  	;

relational_expression
    : additive_expression
		{$$ = $1;}

    | relational_expression L_OP additive_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

    | relational_expression G_OP additive_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

    | relational_expression LE_OP additive_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

    | relational_expression GE_OP additive_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
  	;

equality_expression
    : relational_expression
		{$$ = $1;}

    | equality_expression EQ_OP relational_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

    | equality_expression NE_OP relational_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
  	;

logical_and_expression
    : equality_expression
		{$$ = $1;}

    | logical_and_expression AND_OP equality_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
  	;

logical_or_expression
    : logical_and_expression
		{$$ = $1;}

    | logical_or_expression OR_OP logical_and_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
  	;

assignment_expression
    : logical_or_expression
		{$$ = $1;}

    // *ptr = a || b;
    // ptr->name = "aa";

    | unary_expression assignment_operator assignment_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
    ;

if_expression
    : logical_or_expression
		{$$ = $1;}
    ;

assignment_operator
    : '='					{$$ = "=";}
    ;

expression
    : assignment_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "expr");
			stk->push_stack(stk, $1);
			$$ = stk;}
    | expression ',' assignment_expression
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "expr");
			stk->push_stack(stk, $1);
			stk->push(stk, ";");
			stk->push(stk, "expr");
			stk->push_stack(stk, $3);
			$$ = stk;}
    ;

declarations
		/* int a, b, c; -> int a; int b; int c; */
    : argument_type init_declarator_list ';'
		{ struct stack_t *stk = init_stack();
			struct stack_t *ids = $2;
			for (size_t i = 0; i < ids->size; i++)
			{
				 stk->push_stack(stk, $1);
				 /* is juste an IDENTIFIER */
				 stk->push(stk, ids->get(ids, i)->value);
				 stk->push(stk, "declaration");
			}
			//decl->push_stack(decl, stk);
			$$ = stk;}
    ;

declarations_specifiers
    : EXTERN type_specifier
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "extern");
			stk->push_stack(stk, $2);
			$$ = stk;}

    | type_specifier
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			$$ = stk;}
    ;

function_type
		: EXTERN function_oret
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "extern");
			stk->push_stack(stk, $2);
			$$ = stk;}

		| function_oret
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			$$ = stk;}
		;

function_oret
		: INT
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			$$ = stk;}

		| INT pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int *");
			$$ = stk;}

		| VOID
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void");
			$$ = stk;}

		| VOID pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void *");
			$$ = stk;}

		| struct_oret pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "struct *");
			stk->push_stack(stk, $1);
			$$ = stk;}
		;

argument_type
		: INT
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			$$ = stk;}

		| INT pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int *");
			$$ = stk;}

		| INT argument_function_pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int p");
			$$ = stk;}

		| VOID argument_function_pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void p");
			$$ = stk;}

		| VOID pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void *");
			$$ = stk;}

		| struct_oret pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "struct *");
			stk->push_stack(stk, $1);
			$$ = stk;}

		| struct_oret pointer argument_function_pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void *");
			$$ = stk;}
		;

argument_function_pointer
		:	pointer '(' parameter_list ')'

		| pointer '(' ')'

		| '(' parameter_list ')'

		| '(' ')'
		;

// int a, b, c = 4, d = 6, e;
init_declarator_list
    : init_declarator
		{$$ = $1;}

    | init_declarator_list ',' init_declarator
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
    ;

init_declarator
    : IDENTIFIER
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			$$ = stk;}

    // Autorise la declarations durant la definition
    | IDENTIFIER '=' initializer
		{ struct stack_t *stk = init_stack();
			stmt->push(stmt, "expr");
			stmt->push(stmt, "=");
			stmt->push(stmt, $1);
			stmt->push_stack(stmt, $3);

			stk->push(stk, $1);
			$$ = stk;}
    ;

type_specifier
    : VOID
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void");
			$$ = stk;}

    | INT
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			$$ = stk;}

/* TO IMPLEM */
    | struct_or_union_specifier
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "struct");
			$$ = stk;}
    ;

struct_or_union_specifier
    : STRUCT IDENTIFIER '{' struct_declarations_list '}'
		{decl->push(decl, "struct");
		 decl->push(decl, $2);
		 decl->push_stack(decl, $4);
	 	 decl->push(decl, "struct_declarations");}

    | STRUCT '{' struct_declarations_list '}'
		/* TO IMPLEMENT FAST */

    | STRUCT IDENTIFIER
		{stmt->push(stmt, "struct");
		 stmt->push(stmt, $2);}
    ;

struct_oret
		: STRUCT IDENTIFIER
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $2);
			$$ = stk;}
		;

struct_declarations_list
    : struct_declarations
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			$$ = stk;}

    | struct_declarations_list struct_declarations
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $2);
			$$ = stk;}
    ;

struct_declarations
    : specifier_qualifier_list struct_declarator_list ';'
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $2);
			$$ = stk;}
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list
		{$$ = $2;}
    | type_specifier
		{$$ = $1;}
    ;

/* ALED */
struct_declarator_list
    : struct_declarator
    | struct_declarator_list ',' struct_declarator
    ;

struct_declarator
    : declarator
		{$$ = $1;}
    ;

declarator
    : pointer_direct_declarator
		{$$ = $1;}

    | direct_declarator
		{$$ = $1;}
    ;

// Pour ne pas permettre plusieur pointeurs
pointer_direct_declarator
    // int *aaaaaa
		: pointer direct_declarator_pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "u*");
			stk->push_stack(stk, $2);
			$$ = stk;}

    // int *
    | pointer
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "u*");
			$$ = stk;}
    ;

direct_declarator
    : IDENTIFIER
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			$$ = stk;}

    | '(' declarator ')'
		{$$ = $2;}

    | function_declarator
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			$$ = stk;}
    ;

function_declarator
    : IDENTIFIER '(' argument_type ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

		| IDENTIFIER '(' ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			stk->push(stk, "void");
			$$ = stk;}
    ;

function_definer
		/* foo (int a, int *b, int (*c)()) */
		: IDENTIFIER '(' function_parameter_list ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

		/* foo (a, b, c, ...) -> foo (int, int, int, ...) */
		| IDENTIFIER '(' identifier_list ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}

		/* foo () -> foo (void) */
		| IDENTIFIER '(' ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, $1);
			stk->push(stk, "void");
			$$ = stk;}
		;

function_parameter_list
		: argument_type declarator
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $2);
			$$ = stk;}

		| VOID
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "void");
			$$ = stk;}

		| function_parameter_list ',' argument_type declarator
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			stk->push_stack(stk, $4);
			$$ = stk;}
		;

direct_declarator_pointer
    : IDENTIFIER
		{ char *tmp = (char *) calloc (strlen($1) + 2, 1);
			sprintf(tmp, "*%s", $1);
			decl->push(decl, tmp);}

    // int (b)
    | '(' declarator ')'
		{$$ = $2;}

    // Function pointer
    // int ( *b ) ( arguments )
    | '(' pointer_direct_declarator ')' '(' parameter_list ')'
    | '(' pointer_direct_declarator ')' '(' ')'

    // fonction: int foo ( arguments );
    | function_declarator_pointer
		{$$ = $1;}
    ;

function_declarator_pointer
    // fonction: int foo ( arguments );
    : function_declarator
		{$$ = $1;}
    ;

direct_declarator_function_pointer
    : pointer IDENTIFIER
    ;

pointer
    : '*'
    ;

parameter_list
    : parameter_declarations
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			$$ = stk;}

    | parameter_list ',' parameter_declarations
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $3);
			$$ = stk;}
    ;

// Parameters of func ptr / func
parameter_declarations
    // int *a,
    : declarations_specifiers declarator
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $2);
			$$ = stk;}

    // int *,
    | declarations_specifiers abstract_declarator
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push_stack(stk, $2);
			$$ = stk;}

    // int
    | declarations_specifiers
		{ $$ = $1; }
    ;

identifier_list
    : IDENTIFIER
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "int");
			stk->push(stk, $1);
			$$ = stk;}

    | identifier_list ',' IDENTIFIER
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push(stk, "int");
			stk->push(stk, $3);
			$$ = stk;}
    ;

type_name
    : specifier_qualifier_list
    | specifier_qualifier_list abstract_declarator
    ;

abstract_declarator
    : abstract_declarator_with_pointer
    | direct_abstract_declarator
    ;

abstract_declarator_with_pointer
    : pointer
    | pointer direct_abstract_declarator_pointer_free

direct_abstract_declarator
    : '(' abstract_declarator ')'
    | '(' ')'
    | '(' parameter_list ')'
    | direct_abstract_declarator '(' ')'
    | direct_abstract_declarator '(' parameter_list ')'
    ;

direct_abstract_declarator_pointer_free
    : '(' direct_abstract_declarator_pointer_free ')'
    | '(' ')'
    | '(' parameter_list ')'
    | direct_abstract_declarator_pointer_free '(' ')'
    | direct_abstract_declarator_pointer_free '(' parameter_list ')'
    ;

initializer
    : assignment_expression
		{$$ = $1;}
    ;

statement
    : compound_statement

    | expression_statement
		{stmt->push_stack(stmt, $1);}

    | selection_statement

    | iteration_statement

    | jump_statement
    ;

// Body d'une declarations
compound_statement
		:	compound_body_statement
		| compound_nop_statement
    ;

compound_body_statement
		: '{' '}' 								//{stmt->push(stmt, ";");}
		| '{' block_item_list '}'	//{stmt->push(stmt, ";");}

compound_nop_statement
    : ';'											//{stmt->push(stmt, ";");}
		;

block_item_list
    : block_item
    | block_item_list block_item
    ;

// block_item est juste une suite de declarations
// et de statement
block_item
    : declarations
    { decl->push_stack(decl, $1);}

    | statement
    ;

expression_statement
    : ';'
		{ struct stack_t *stk = init_stack();
			$$ = stk;}
    | expression ';'
		{ struct stack_t *stk = init_stack();
			stk->push_stack(stk, $1);
			stk->push(stk, ";");
			$$ = stk;}
    ;

selection_statement
    : if_statement {stmt->push(stmt, "endif");}

    | if_statement ELSE 		{fix_ifelse(stmt, stmt->size);
														 stmt->push(stmt, "else");}
		 statement							{stmt->push(stmt, "endif");}
    ;

if_statement
		: IF '(' if_expression ')'
		{ stmt->push(stmt, "if");
	  	stmt->push_stack(stmt, $3);
		  stmt->push(stmt, "then");}
		statement
		;

iteration_statement
    : WHILET '(' expression ')'
		{stmt->push(stmt, "while");
				stmt->push_stack(stmt, $3);
				stmt->push(stmt, "do");}

		statement
		{stmt->push(stmt, "endwhile");}

    // for (i = 0; i < 5; )
    | FOR '(' expression_statement expression_statement ')'
		{stmt->push(stmt, "for");
		stmt->push_stack(stmt, $3);
		stmt->push(stmt, "enddecl");
		stmt->push_stack(stmt, $4);
		stmt->push(stmt, "endcond");
		stmt->push(stmt, "endstep");}

		statement
		{stmt->push(stmt, "endfor");}

    // for (i = 0; i < 5; i = i + 1)
		| FOR '(' expression_statement expression_statement expression ')'
		{stmt->push(stmt, "for");
		stmt->push_stack(stmt, $3);
		stmt->push(stmt, "enddecl");
		stmt->push_stack(stmt, $4);
		stmt->push(stmt, "endcond");
		stmt->push_stack(stmt, $5);
		stmt->push(stmt, "endstep");}

		statement
		{stmt->push(stmt, "endfor");}

    // for (int i = 0, j, k; expression; )
    | FOR '(' declarations expression_statement ')'
		{stmt->push(stmt, "for");
		stmt->push(stmt, "enddecl");
		stmt->push_stack(stmt, $4);
		stmt->push(stmt, "endcond");
		stmt->push(stmt, "endstep");}

		statement
		{stmt->push(stmt, "endfor");}

    // for (int i = 0, j, k; expression; expression)
		| FOR '(' declarations expression_statement expression ')'
		{stmt->push(stmt, "for");
		stmt->push(stmt, "enddecl");
		stmt->push_stack(stmt, $4);
		stmt->push(stmt, "endcond");
		stmt->push_stack(stmt, $5);
		stmt->push(stmt, "endstep");}

		statement
		{stmt->push(stmt, "endfor");}
    ;

jump_statement
    : RETURN expression ';'
		{stmt->push(stmt, "return");
		 stmt->push_stack(stmt, $2);
	 	 stmt->push(stmt, ";");}

    | RETURN ';'
		{stmt->push(stmt, "return");
		 stmt->push(stmt, "expr");
	 	 stmt->push(stmt, ";");}
    ;

program
    : external_declarations

    | program external_declarations
    ;

_start
		: program
		{ declaration(decl, ct, buf_decl, &vx, 0);
      statements(decl, stmt, ct, buf_decl, buf_stmt, &vx, &lx, 0, stmt->size, 0);}

// Une suite de declarations de definitions de fonctions
external_declarations
    : declarations
		{ decl->push_stack(decl, $1);}

		| function_definition

		| function_declarations_
    ;

/* int and (int a, int b) { ... } */
function_definition
    : function_type function_definer
		{ stmt->push(stmt, "func");
			stmt->push_stack(stmt, $1); /* (extern) + ??? */
			stmt->push_stack(stmt, $2); /* fun_name ((types +) args) */
			stmt->push(stmt, "endarg");}
		compound_body_statement
		{ stmt->push(stmt, "endfun");}
		;

/* extern void *malloc (int size); */
function_declarations_
		: function_type function_declarator compound_nop_statement
		{ decl->push_stack(decl, $1); /* (extern) + ??? */
			decl->push_stack(decl, $2); /* fun_name (types) */
			decl->push(decl, "fundecl");}
		;

declarations_list
    : declarations
		{ decl->push_stack(decl, $1);}

    | declarations_list declarations
		{ decl->push_stack(decl, $2);}
    ;

%%

extern FILE *yyin;

char *fname;

void
yyerror (char const *s)
{
	fprintf(stderr, "%s", s);
	exit(2);
}

int
main (int argc, char *argv[])
{
	FILE *fbe;

	decl = init_stack();
	stmt = init_stack();
	create_primitive_functions(stmt);
	ct = init_crpcdt();
	buf_decl = init_buf();
	buf_stmt = init_buf();
	vx = 0;
	lx = 0;

	fname = strdup(argv[1]);
	if ((yyin = fopen(fname, "r")) == NULL)
	{
		yyerror("[!] File not found\n");
		exit(2);
	} else {
		yyparse();
		//print_ct(ct);
		if (strlen(buf_decl->string))
		{
			buf_decl->add(buf_decl, "\n");
		}

		if (argc > 2)
		{
			stmt->print_stack(stmt);
			decl->print_stack(decl);
		}

		fbe = fopen("a.be", "w+");
		fprintf(fbe, "%s%s", buf_decl->string, buf_stmt->string);
		fclose(fbe);
		printf("Success.\n");
	}
	return 0;
}

unsigned int
rfix_ifelse (struct stack_t 	* stk,
						 unsigned int 		index)
{
	for (size_t i = index; i > 0 ; i--)
	{
			if (!strcmp(stk->get(stk, i)->value, "endif"))
			{
					i = rfix_ifelse(stk, i - 1);
					continue;
			}

			if (!strcmp(stk->get(stk, i)->value, "if"))
			{
					return i;
			}
	}
  return (unsigned int)-1;
}

void
fix_ifelse (struct stack_t 	* stk,
						unsigned int 		index)
{
	for (size_t i = index; i > 0 ; i--)
	{
			if (!strcmp(stk->get(stk, i)->value, "endif"))
			{
					i = rfix_ifelse(stk, i - 1);
					continue;
			}

			if (!strcmp(stk->get(stk, i)->value, "if"))
			{
					stk->get(stk, i)->value = strdup("ifelse");
					return;
			}
	}
  return (unsigned int)-1;
}

void
create_primitive_functions (struct stack_t *stmt)
{
		stmt->push(stmt, "func");
    stmt->push(stmt, "int");
    stmt->push(stmt, "and");
    stmt->push(stmt, "int");
    stmt->push(stmt, "a");
    stmt->push(stmt, "int");
    stmt->push(stmt, "b");
    stmt->push(stmt, "endarg");
    stmt->push(stmt, "if");
    stmt->push(stmt, "==");
    stmt->push(stmt, "a");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "0");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "if");
    stmt->push(stmt, "==");
    stmt->push(stmt, "b");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "0");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "1");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endfun");

    stmt->push(stmt, "func");
    stmt->push(stmt, "int");
    stmt->push(stmt, "or");
    stmt->push(stmt, "int");
    stmt->push(stmt, "a");
    stmt->push(stmt, "int");
    stmt->push(stmt, "b");
    stmt->push(stmt, "endarg");
    stmt->push(stmt, "if");
    stmt->push(stmt, "!=");
    stmt->push(stmt, "a");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "1");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "if");
    stmt->push(stmt, "!=");
    stmt->push(stmt, "b");
    stmt->push(stmt, "0");
    stmt->push(stmt, "then");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "1");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endif");
    stmt->push(stmt, "return");
    stmt->push(stmt, "expr");
    stmt->push(stmt, "0");
    stmt->push(stmt, ";");
    stmt->push(stmt, "endfun");
}
