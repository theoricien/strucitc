%{
	/*
	 * Author: Maxime JEROME (maxime.jerome[at]protonmail[dot]com)
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
	 * Declaration stack representation
	 * [type_specifier, identifier, declaration_type]
	 * Ex:
	 * ["int", "a", "declaration"]
	 * (not yet implemented)
	 * ["int", "main", "function_declaration"]
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

	/* Declaration stack */
	struct stack_t *decl;
	/* Statement stack */
	struct stack_t *stmt;
	/* Correspondence table */
	struct crpdct_t *ct;
	/* Declaration buffer */
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
%token WHILE
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
%type <string> WHILE
%type <string> AND_OP
%type <string> OR_OP
%type <string> VOID
%type <string> INT
%type <string> MUL_ASSIGN
%type <string> DIV_ASSIGN
%type <string> ADD_ASSIGN
%type <string> SUB_ASSIGN
%type <string> STRUCT
%type <string> unary_operator
%type <string> assignment_operator
%type <string> pointer
%type <string> type_specifier

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
		{ $$ = $2;}
    ;

postfix_expression
    : primary_expression
		{$$ = $1;}

/* To implement
    | postfix_expression '(' ')'
		{ struct buf_t *buf = init_buf();
			struct stack_t *tmp = init_stack();
			buf->add(buf, "%s()", $1->get($1, 0));
			tmp->push(tmp, buf->string);
			$$ = tmp;}

    | postfix_expression '(' argument_expression_list ')'
		{struct buf_t *tmp = init_buf();
			tmp->add(tmp, "%s(args)", $1->get($1, 0));
			$$ = tmp;}

    | postfix_expression PTR_OP IDENTIFIER
		{struct buf_t *tmp = init_buf();
			tmp->add(tmp, "%s->%s", $1, $3);
			$$ = tmp;}*/
    ;

argument_expression_list
    : assignment_expression

    | argument_expression_list ',' assignment_expression
    ;

unary_expression
    : postfix_expression
		{$$ = $1;}

    | unary_operator cast_expression
		{ struct stack_t *tmp = init_stack();
			tmp->push(tmp, $1);
			tmp->push_stack(tmp, $2);
			$$ = tmp;}

/* To implement */
    | SIZEOF '(' unary_expression ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "4");
			$$ = stk;}

    | SIZEOF '(' type_name ')'
		{ struct stack_t *stk = init_stack();
			stk->push(stk, "4");
			$$ = stk;}
    ;

unary_operator
    : '&'
    {$$ = "&";}

    | pointer
    {$$ = $1;}

    | '+'
    {$$ = "+";}

    | '-'
    {$$ = "-";}
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
    | MUL_ASSIGN	{$$ = $1;}
    | DIV_ASSIGN	{$$ = $1;}
    | ADD_ASSIGN	{$$ = $1;}
    | SUB_ASSIGN	{$$ = $1;}
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

declaration
    : declaration_specifiers init_declarator_list ';'
		{decl->push(decl, "declaration");}

    | declaration_specifiers ';'
		{decl->push(decl, "declaration");}
    ;

declaration_specifiers
    : EXTERN type_specifier

    | type_specifier
    ;

// int a, b, c = 4, d = 6, e;
init_declarator_list
    : init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator
    : declarator
    // Autorise la declaration durant la definition
    | {stmt->push(stmt, "=");} declarator '=' initializer
    ;

type_specifier
    : VOID
    {decl->push(decl, "void");
		$$ = "void";}

    | INT
    {decl->push(decl, "int");
		$$ = "int";}

    | struct_or_union_specifier
		{$$ = "struct";}
    ;

struct_or_union_specifier
    : STRUCT IDENTIFIER '{' struct_declaration_list '}'
    | STRUCT '{' struct_declaration_list '}'
    | STRUCT IDENTIFIER
    ;

struct_declaration_list
    : struct_declaration
    | struct_declaration_list struct_declaration
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';'
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list
    | type_specifier
    ;

struct_declarator_list
    : struct_declarator
    | struct_declarator_list ',' struct_declarator
    ;

struct_declarator
    : declarator
    ;

declarator
    : pointer_direct_declarator

    | direct_declarator
    ;

// Pour ne pas permettre plusieur pointeurs
pointer_direct_declarator
    // int *aaaaaa
		: pointer direct_declarator_pointer

    // int *
    | pointer
    ;

direct_declarator
    : IDENTIFIER
		{decl->push(decl, $1);}

    | '(' declarator ')'
    | function_declarator
    ;

function_declarator
    : direct_declarator '(' parameter_list ')'
    | direct_declarator '(' identifier_list ')'
    | direct_declarator '(' ')'
    ;

direct_declarator_pointer
    : IDENTIFIER
		{char *tmp = (char *) calloc (strlen($1) + 2, 1);
			sprintf(tmp, "*%s", $1);
			decl->push(decl, tmp);}

    // int (b)
    | '(' declarator ')'

    // Function pointer
    // int ( *b ) ( arguments )
    | '(' pointer_direct_declarator ')' '(' parameter_list ')'
    | '(' pointer_direct_declarator ')' '(' ')'

    // fonction: int foo ( arguments );
    | function_declarator_pointer
    ;

function_declarator_pointer
    // fonction: int foo ( arguments );
    : direct_declarator_pointer '(' parameter_list ')'
    | direct_declarator_pointer '(' identifier_list ')'
    | direct_declarator_pointer '(' ')'
    ;


direct_declarator_function_pointer
    : pointer IDENTIFIER
    ;

pointer
    : '*'
    {$$ = "*";}
    ;

parameter_list
    : parameter_declaration

    | parameter_list ',' parameter_declaration
    ;

// Parameters of func ptr / func
parameter_declaration
    // int *a,
    : declaration_specifiers declarator

    // int *,
    | declaration_specifiers abstract_declarator

    // int
    | declaration_specifiers
    ;

identifier_list
    : IDENTIFIER
    | identifier_list ',' IDENTIFIER
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
    ;

statement
    : compound_statement

    | expression_statement

    | selection_statement

    | iteration_statement

    | jump_statement
    ;

// Body d'une declaration
compound_statement
    : '{' '}' 								//{stmt->push(stmt, ";");}
    | '{' block_item_list '}'	//{stmt->push(stmt, ";");}
    | ';'											//{stmt->push(stmt, ";");}
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

// block_item est juste une suite de declaration
// et de statement
block_item
    : declaration
    //{declaration(decl, ct, buf_decl, &vx, 0);}

    | statement
    //{statements(decl, stmt, ct, buf_decl, buf_stmt, &vx, &lx, 0, stk_stmt->size, 0);}
    ;

expression_statement
    : ';'
		{$$ = stmt;}
    | expression ';'
		{ stmt->push_stack(stmt, $1);
			stmt->push(stmt, ";");
	    $$ = stmt;}
    ;

selection_statement
    : IF										{stmt->push(stmt, "if");}
		'(' if_expression ')'		{stmt->push(stmt, "then");}
		statement    						{stmt->push(stmt, "endif");}

    | IF 										{stmt->push(stmt, "ifelse");}
		 '(' if_expression ')' 	{stmt->push(stmt, "then");}
		 statement
		 ELSE 									{stmt->push(stmt, "else");}
		 statement							{stmt->push(stmt, "endif");}
    ;

iteration_statement
    : WHILE '(' expression ')' statement

    // for (;;) | for (expression; expression; )
    // for (i = 0; i < 5; )
    | FOR '(' expression_statement expression_statement ')' statement

    // le for "classique"
    // for (;;) | for (expression; expression; expression)
    // for (i = 0; i < 5; i = i + 1)
    | FOR '(' expression_statement expression_statement expression ')' statement

    // for (;;)
    // for (int i = 0, j, k; expression; )
    | FOR '(' declaration expression_statement ')' statement

    // for (int i = 0, j, k; expression; expression)
    | FOR '(' declaration expression_statement expression ')' statement
    ;

jump_statement
    : RETURN expression ';'

    | RETURN ';'
    ;

program
    : external_declaration

    | program external_declaration
    ;

_start
		: program

// Une suite de declaration de definitions de fonctions
external_declaration
    : function_definition

    | declaration

		| block_item_list
    ;

function_definition
    : declaration_specifiers function_declarator compound_statement
		;

declaration_list
    : declaration

    | declaration_list declaration
    ;

//iterable et external
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
	decl = init_stack();
	stmt = init_stack();
	ct = init_crpcdt();
	buf_decl = init_buf();
	buf_stmt = init_buf();
	vx = 0;
	lx = 0;

	fname = strdup(argv[1]);
	if ((yyin = fopen(argv[1], "r")) == NULL)
	{
		yyerror("[E] File not found\n");
		exit(2);
	} else {
		yyparse();
		declaration(decl, ct, buf_decl, &vx, 0);
		statements(decl, stmt, ct, buf_decl, buf_stmt, &vx, &lx, 0, stmt->size, 0);

		if (strlen(buf_decl->string))
		{
			buf_decl->add(buf_decl, "\n");
		}

		printf("\n----------------------\n%s%s", buf_decl->string, buf_stmt->string);
		printf("Success.\n");
	}
	return 0;
}
