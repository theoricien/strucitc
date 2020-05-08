%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "tree.h"

	int verbose2 = 0;

	void log2 (char *msg)
	{
	    if (verbose2)
	        printf("[***] %s\n", msg);
	}

	extern char yytext[];
	int printed = 0;
	void yyerror(char const *s);
	int yylex();
%}

%union
{
	  node_t *	node;
	  char *		string;
}

%define parse.error verbose

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP LE_OP GE_OP EQ_OP NE_OP
%token L_OP G_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN
%token TYPE_NAME

%token EXTERN
%token INT VOID
%token STRUCT

%token IF ELSE WHILE FOR RETURN

%type <string> IDENTIFIER STRING_LITERAL CONSTANT SIZEOF PTR_OP LE_OP GE_OP L_OP G_OP EQ_OP NE_OP RETURN WHILE
%type <string> AND_OP OR_OP unary_operator VOID INT pointer assignment_operator
%type <string> MUL_ASSIGN DIV_ASSIGN ADD_ASSIGN SUB_ASSIGN type_name STRUCT

%type <node> primary_expression postfix_expression argument_expression_list
%type <node> unary_expression
%type <node> additive_expression multiplicative_expression relational_expression
%type <node> equality_expression logical_and_expression logical_or_expression
%type <node> expression declaration declaration_specifiers
%type <node> type_specifier struct_declaration_list struct_declaration declarator direct_declarator
%type <node> parameter_list parameter_declaration statement compound_statement declaration_list
%type <node> expression_statement selection_statement iteration_statement jump_statement
%type <node> program external_declaration function_definition _start
%type <node> cast_expression assignment_expression if_expression direct_declarator_pointer
%type <node> block_item_list block_item init_declarator_list init_declarator initializer pointer_direct_declarator
%type <node> struct_or_union_specifier specifier_qualifier_list struct_declarator_list struct_declarator
%type <node> direct_declarator_function_pointer identifier_list abstract_declarator abstract_declarator_with_pointer
%type <node> direct_abstract_declarator direct_abstract_declarator_pointer_free

%start _start
%%

primary_expression
    : IDENTIFIER
    {log2("primary_expression -> IDENTIFIER");
    $$ = build_leaf(TID, $1);}

    | CONSTANT
    {log2("primary_expression -> CONSTANT");
    $$ = build_leaf(TCONS, $1);}

    | STRING_LITERAL
    {log2("primary_expression -> STRING_LITERAL");
    $$ = build_leaf(TCONS, $1);}

    | '(' expression ')'
    {log2("primary_expression -> ( expression )");
    $$ = $2;}
    ;

postfix_expression
    : primary_expression
    {$$ = $1;}

    | postfix_expression '(' ')'
    {log2("postfix_expression -> postfix_expression ( )");
    $$ = build_func($1,NULL);}

    | postfix_expression '(' argument_expression_list ')'
    {log2("postfix_expression -> postfix_expression ( argument_expression_list )");
		$$ = build_func($1,$3);}

    | postfix_expression PTR_OP IDENTIFIER
    {log2("postfix_expression -> postfix_expression PTR_OP IDENTIFIER");
		node_t *leaf = build_leaf(TID,$3);
    $$ = build_opr($2,$1,leaf);}
    ;

argument_expression_list
    : assignment_expression
    {log2("argument_expression_list -> expression");
    $$ = $1;}

    | argument_expression_list ',' assignment_expression
    {log2("argument_expression_list -> argument_expression_list , expression");
    $$ = build_opr("argument_expression_list",$1,$3);}
    ;

unary_expression
    : postfix_expression
    {log2("unary_expression -> postfix_expression");
    $$ = $1;}

    | unary_operator cast_expression
    {log2("unary_expression -> unary_operator unary_expression");
    $$ = build_uopr($1,$2);}

    | SIZEOF '(' unary_expression ')'
    {log2("unary_expression -> SIZEOF ( unary_expression)");
    $$ = build_uopr($1,$3);
    }

    | SIZEOF '(' type_name ')'
    {log2("unary_expression -> SIZEOF ( type_name )");
    $$ = build_uopr($1,$3);
    }
    ;

unary_operator
    : '&'
    {log2("unary_operator -> &");
    $$ = "&";}

    | pointer
    {log2("unary_operator -> pointer");
    $$ = $1;}

    | '+'
    {log2("unary_operator -> +");
    $$ = "+";}

    | '-'
    {log2("unary_operator -> -");
    $$ = "-";}
  	;

cast_expression
    : unary_expression
    {log2("cast_expression -> unary_expression");
    $$ = $1;}

    | '(' type_name ')' cast_expression
		{log2("cast_expression -> '(' type_name ')' cast_expression");
    $$ = build_opr("cast",$2,$4);}
  	;

multiplicative_expression
    : cast_expression
    {log2("multiplicative_expression -> cast_expression");
    $$ = $1;}

    | multiplicative_expression '*' cast_expression
    {log2("multiplicative_expression -> multiplicative_expression * cast_expression");
    $$ = build_opr("*",$1,$3);}

    | multiplicative_expression '/' cast_expression
    {log2("multiplicative_expression -> multiplicative_expression / cast_expression");
    $$ = build_opr("/",$1,$3);}
  	;

additive_expression
    : multiplicative_expression
    {log2("additive_expression -> multiplicative_expression");
    $$ = $1;}

    | additive_expression '+' multiplicative_expression
    {log2("additive_expression -> additive_expression + multiplicative_expression");
    $$ = build_opr("+",$1,$3);}

    | additive_expression '-' multiplicative_expression
    {log2("additive_expression -> additive_expression - multiplicative_expression");
    $$ = build_opr("-",$1,$3);}
  	;

relational_expression
    : additive_expression
    {log2("relational_expression -> additive_expression");
    $$ = $1;}

    | relational_expression L_OP additive_expression
    {log2("relational_expression -> relational_expression L_OP additive_expression");
    $$ = build_opr($2,$1,$3);}

    | relational_expression G_OP additive_expression
    {log2("relational_expression -> relational_expression G_OP additive_expression");
    $$ = build_opr($2,$1,$3);}

    | relational_expression LE_OP additive_expression
    {log2("relational_expression -> relational_expression LE_OP additive_expression");
    $$ = build_opr($2,$1,$3);}

    | relational_expression GE_OP additive_expression
    {log2("relational_expression -> relational_expression GE_OP additive_expression");
    $$ = build_opr($2,$1,$3);}
  	;

equality_expression
    : relational_expression
    {log2("equality_expression -> relational_expression");
    $$ = $1;}

    | equality_expression EQ_OP relational_expression
    {log2("equality_expression -> equality_expression EQ_OP relational_expression");
    $$ = build_opr($2,$1,$3);}

    | equality_expression NE_OP relational_expression
    {log2("equality_expression -> equality_expression NE_OP relational_expression");
    $$ = build_opr($2,$1,$3);}
  	;

logical_and_expression
    : equality_expression
    {log2("logical_and_expression -> equality_expression");
    $$ = $1;}

    | logical_and_expression AND_OP equality_expression
    {log2("logical_and_expression -> logical_and_expression AND_OP equality_expression");
    $$ = build_opr($2,$1,$3);}
  	;

logical_or_expression
    : logical_and_expression
    {log2("logical_or_expression -> logical_and_expression");
    $$ = $1;}

    | logical_or_expression OR_OP logical_and_expression
    {log2("logical_or_expression -> logical_or_expression OR_OP logical_and_expression");
    $$ = build_opr($2,$1,$3);}
  	;

assignment_expression
    : logical_or_expression
    {log2("assignment_expression -> logical_or_expression");
    $$ = $1;}

    // Ca sert a affecter un terme unaire
    // *ptr = a || b;
    // ptr->name = "aa";

    | unary_expression assignment_operator assignment_expression
		{log2("assignment_expression -> unary_expression assignment_operator assignment_expression");
    $$ = build_opr($2,$1,$3);}
    ;

if_expression
    : logical_or_expression
    {log2("if_expression -> logical_or_expression");
    $$ = $1;}
    ;

assignment_operator
    : '='					{log2("assignment_operator -> ="); $$ = "=";}
    | MUL_ASSIGN 	{log2("assignment_operator -> MUL_ASSIGN"); $$ = $1;}
    | DIV_ASSIGN 	{log2("assignment_operator -> DIV_ASSIGN"); $$ = $1;}
    | ADD_ASSIGN 	{log2("assignment_operator -> ADD_ASSIGN"); $$ = $1;}
    | SUB_ASSIGN 	{log2("assignment_operator -> SUB_ASSIGN"); $$ = $1;}
    ;

expression
    : assignment_expression
    {log2("expression -> assignment_expression");
    $$ = $1;}

    | expression ',' assignment_expression
    {log2("expression -> assignment_expression = expression");
    $$ = build_opr("expr",$1,$3);}
    ;

declaration
    : declaration_specifiers init_declarator_list ';'
    {log2("declaration -> declaration_specifiers init_declarator_list ';'");
    $$ = build_opr("declaration",$1,$2);}

    | declaration_specifiers ';'
    {log2("declaration -> declaration_specifiers ';'");
    $$ = build_opr("declaration",$1,NULL);}
    ;

declaration_specifiers
    : EXTERN type_specifier
    {$$ = build_uopr("extern",$2);}

    | type_specifier
    {$$ = $1;}
    ;

// int a, b, c = 4, d = 6, e;
init_declarator_list
    : init_declarator
		{$$ = $1;}
    | init_declarator_list ',' init_declarator
		{$$ = build_opr("init_declarator_list",$1,$3);}
    ;

init_declarator
    : declarator
		{$$ = $1;}
    // Autorise la declaration durant la definition
    | declarator '=' initializer
		{$$ = build_opr("=",$1,$3);}
    ;

type_specifier
    : VOID
    {$$ = build_leaf(TT,$1);}

    | INT
    {$$ = build_leaf(TT,$1);}

    | struct_or_union_specifier
		{log2("type_specifier -> struct_or_union_specifier");
		$$ = $1;}
    ;

struct_or_union_specifier
    : STRUCT IDENTIFIER '{' struct_declaration_list '}'
		{node_t *leaf = build_leaf(TID,$2);
		$$ = build_struct(leaf,$4);}
    | STRUCT '{' struct_declaration_list '}'
		{$$ = build_struct(NULL,$3);}
    | STRUCT IDENTIFIER
		{node_t *leaf = build_leaf(TID,$2);
		$$ = build_struct(leaf,NULL);}
    ;

struct_declaration_list
    : struct_declaration
		{$$ = $1;}
    | struct_declaration_list struct_declaration
		{$$ = build_opr("struct_declaration_list",$1,$2);}
    ;

struct_declaration
    : specifier_qualifier_list struct_declarator_list ';'
		{$$ = build_opr("struct_declaration",$1,$2);}
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list
		{$$ = build_opr("specifier_qualifier_list",$1,$2);}
    | type_specifier
		{$$ = $1;}
    ;

struct_declarator_list
    : struct_declarator
		{$$ = $1;}
    | struct_declarator_list ',' struct_declarator
		{$$ = build_opr("struct_declarator_list",$1,$3);}
    ;

struct_declarator
    : declarator
		{$$ = $1;}
    ;

declarator
    : pointer_direct_declarator
    {log2("declarator -> pointer_direct_declarator direct_declarator");
    $$ = $1;}

    | direct_declarator
    {log2("declarator -> direct_declarator");
    $$ = $1;}
    ;

// Pour ne pas permettre plusieur pointeurs
pointer_direct_declarator
    // int *aaaaaa
    : pointer direct_declarator_function_pointer
    {log2("pointer_direct_declarator -> pointer direct_declarator_function_pointer");
    $$ = build_opr("pointer_direct_declarator", $1,$2);}

		|pointer direct_declarator_pointer
		{log2("pointer_direct_declarator -> pointer direct_declarator_pointer");
    $$ = build_opr("pointer_direct_declarator", $1,$2);}

    // int *
    | pointer
    {$$ = $1;}
    ;

direct_declarator
    : IDENTIFIER
    {log2("direct_declarator -> IDENTIFIER");
		log2($1);
		$$ = build_leaf(TID,$1);}
    | '(' declarator ')'
		{$$ = $2;}
    | direct_declarator '(' parameter_list ')'
		{$$ = build_func($1,$3);}
    | direct_declarator '(' identifier_list ')'
		{$$ = build_func($1,$3);}
    | direct_declarator '(' ')'
		{$$ = build_func($1,NULL);}
    ;

direct_declarator_pointer
    : IDENTIFIER
    {$$ = build_leaf(TID, $1);}

    // int (b)
    | '(' declarator ')'
		{$$ = $2;}

    // Function pointer
    // int ( *b ) ( arguments )
    | '(' pointer_direct_declarator ')' '(' parameter_list ')'
		{$$ = build_func($2,$5);}
    | '(' pointer_direct_declarator ')' '(' ')'
		{$$ = build_func($2,NULL);}

    // fonction: int foo ( arguments );
    | direct_declarator_pointer '(' parameter_list ')'
		{$$ = build_func($1,$3);}
    | direct_declarator_pointer '(' identifier_list ')'
		{$$ = build_func($1,$3);}
    | direct_declarator_pointer '(' ')'
		{$$ = build_func($1,NULL);}
    ;

direct_declarator_function_pointer
    : pointer IDENTIFIER
		{node_t *leaf = build_leaf(TID,$2);
		$$ = build_opr("direct_declarator__function_pointer",$1,leaf);}
    ;

pointer
    : '*'
    {$$ = build_leaf(TID,"*");}
    ;

parameter_list
    : parameter_declaration
    {$$ = $1;}

    | parameter_list ',' parameter_declaration
		{$$ = build_opr("parameter_list",$1,$3);}
    ;

// Parameters of func ptr / func
parameter_declaration
    // int *a,
    : declaration_specifiers declarator
		{$$ = build_opr("parameter_declaration",$1,$2);}

    // int *,
    | declaration_specifiers abstract_declarator
		{$$ = build_opr("parameter_declaration",$1,$2);}

    // int
    | declaration_specifiers
		{$$ = $1;}
    ;

identifier_list
    : IDENTIFIER
		{$$ = build_leaf(TID,$1);}
    | identifier_list ',' IDENTIFIER
		{node_t *leaf = build_leaf(TID,$3);
		$$ = build_opr("identifier_list",$1,leaf);}
    ;

type_name
    : specifier_qualifier_list
		{$$ = $1;}
    | specifier_qualifier_list abstract_declarator
		{$$ = build_opr("type_name",$1,$2);}
    ;

abstract_declarator
    : abstract_declarator_with_pointer
		{$$ = $1;}
    | direct_abstract_declarator
		{$$ = $1;}
    ;

abstract_declarator_with_pointer
    : pointer
		{$$ = $1;}
    | pointer direct_abstract_declarator_pointer_free
		{$$ = build_opr("abstract_declarator_with_pointer",$1,$2);}

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
    : assignment_expression {$$ = $1;}
    ;

statement
    : compound_statement
    {log2("statement -> compound_statement");
    $$ = $1;}

    | expression_statement
    {log2("statement -> expression_statement");
    $$ = $1;}

    | selection_statement
    {log2("statement -> selection_statement");
    $$ = $1;}

    | iteration_statement
    {log2("statement -> iteration_statement");
    $$ = $1;}

    | jump_statement
    {log2("statement -> jump_statement");
    $$ = $1;}
    ;

// Body d'une declaration
compound_statement
    : '{' '}' {$$ = build_leaf(TID,"{}");}
    | '{' block_item_list '}'
    {$$ = $2;}
    | ';'			{$$ = build_leaf(TID,";");}
    ;

block_item_list
    : block_item
    {$$ = $1;}

    | block_item_list block_item
		{$$ = build_opr("block_item_list",$1,$2);}
    ;

// block_item est juste une suite de declaration
// et de statement
block_item
    : declaration
    {$$ = $1;}

    | statement
    {$$ = $1;}
    ;

expression_statement
    : ';' {$$ = build_leaf(TID,";");}
    | expression ';'
    {$$ = $1;}
    ;

selection_statement
    : IF '(' if_expression ')' statement
    {log2("selection_statement -> IF ( expression ) statement");
    $$ = build_if($3,$5,NULL);}

    | IF '(' if_expression ')' statement ELSE statement
    {log2("selection_statement -> IF ( expression ) statement ELSE statement");
    $$ = build_if($3,$5,$7);}
    ;

iteration_statement
    : WHILE '(' expression ')' statement
    {log2("iteration_statement -> WHILE '(' expression ')' statement ");
    $$ = build_opr($1,$3,$5);}

    // for (;;) | for (expression; expression; )
    // for (i = 0; i < 5; )
    | FOR '(' expression_statement expression_statement ')' statement
    {log2("iteration_statement -> FOR '(' expression_statement expression_statement ')' statement ");
    $$ = build_for($3,$4, NULL,$6);}

    // le for "classique"
    // for (;;) | for (expression; expression; expression)
    // for (i = 0; i < 5; i = i + 1)
    | FOR '(' expression_statement expression_statement expression ')' statement
    {log2("iteration_statement -> FOR '(' expression_statement expression_statement expression ')' statement ");
    $$ = build_for($3,$4,$5,$7);}

    // for (;;)
    // for (int i = 0, j, k; expression; )
    | FOR '(' declaration expression_statement ')' statement
    {log2("iteration_statement -> FOR '(' declaration expression_statement ')' statement ");
    $$ = build_for($3,$4, NULL,$6);}

    // for (int i = 0, j, k; expression; expression)
    | FOR '(' declaration expression_statement expression ')' statement
    {log2("iteration_statement -> FOR '(' declaration expression_statement expression ')' statement ");
    $$ = build_for($3,$4,$5,$7);}
    ;

jump_statement
    : RETURN expression ';'
    {log2("jump_statement -> RETURN expression ;");
    $$ = build_uopr("return",$2);}

    | RETURN ';'
    {log2("jump_statement -> RETURN ;");
    $$ = build_leaf(TRET,$1);}
    ;

program
    : external_declaration
    {log2("program -> external_declaration");
		$$ = $1;}

    | program external_declaration
		{$$ = build_opr("program",$1,$2);}
    ;

_start
	:program
	{stringify($1,0);}


// Une suite de declaration de definitions de fonctions
external_declaration

    : function_definition
    {log2("external_declaration -> function_definition");
    $$ = $1;}

    | declaration
    {log2("external_declaration -> declaration");
    $$ = $1;}
    ;

function_definition

    : declaration_specifiers declarator compound_statement
		{$$ = build_opr("function_definition",build_opr("function",$1,$2),$3);}
    ;

declaration_list
    : declaration
    {$$ = $1;}

    | declaration_list declaration
		{build_opr("declaration_list",$1,$2);}
    ;


%%

extern FILE *yyin;

void
yyerror (char const *s)
{
	fprintf(stderr, "%s\n", s);
	exit(2);
}

int
main (int argc, char *argv[])
{
	if ((yyin = fopen(argv[1], "r")) == NULL)
	{
		yyerror("[E] File not found\n");
		exit(2);
	} else {
		yyparse();
		printf("Success.\n");
	}
	return 0;
}
