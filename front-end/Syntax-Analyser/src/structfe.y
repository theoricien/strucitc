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

%start program
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression PTR_OP IDENTIFIER
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| pointer
	| '+'
	| '-'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

relational_expression
	: additive_expression
	| relational_expression L_OP additive_expression
	| relational_expression G_OP additive_expression
	| relational_expression LE_OP additive_expression
	| relational_expression GE_OP additive_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

logical_and_expression
	: equality_expression
	| logical_and_expression AND_OP equality_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

assignment_expression
	: logical_or_expression

	// Ca sert a affecter un terme unaire
// *ptr = a || b;
	// ptr->name = "aa";
	| unary_expression assignment_operator assignment_expression
	;

if_expression
	: logical_or_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

declaration
	: declaration_specifiers init_declarator_list ';'
	| declaration_specifiers ';'
	;

declaration_specifiers
	: type_specifier
	| type_specifier declaration_specifiers
	;

// int a, b, c = 4, d = 6, e;
init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator

	// Autorise la declaration durant la definition
	| declarator '=' initializer
	;

type_specifier
	: VOID
	| INT
	| struct_or_union_specifier
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
	| '(' declarator ')'
	| direct_declarator '(' parameter_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

direct_declarator_pointer
	: IDENTIFIER

	// int (b)
	| '(' declarator ')'

	// Function pointer
	// int ( *b ) ( arguments )
	| '(' pointer_direct_declarator ')' '(' parameter_list ')'
	| '(' pointer_direct_declarator ')' '(' ')'

	// fonction: int foo ( arguments );
	| direct_declarator_pointer '(' parameter_list ')'
	| direct_declarator_pointer '(' identifier_list ')'
	| direct_declarator_pointer '(' ')'
	;

direct_declarator_function_pointer
	: pointer IDENTIFIER
	;

pointer
	: '*'
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
	: '{' '}'
	| '{' block_item_list '}'
	| ';'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

// block_item est juste une suite de declaration
// et de statement
block_item
	: declaration
	| statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' if_expression ')' statement
	| IF '(' if_expression ')' statement ELSE statement
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

// Une suite de declaration de definitions de fonctions
external_declaration
	: function_definition external_declaration
	| declaration external_declaration
	| %empty
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
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
