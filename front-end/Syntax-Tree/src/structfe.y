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

%type <string> IDENTIFIER CONSTANT SIZEOF PTR_OP LE_OP GE_OP L_OP G_OP EQ_OP NE_OP RB_OP LB_OP RETURN WHILE
%type <string> AND_OP OR_OP unary_operator VOID INT

%type <node> primary_expression postfix_expression argument_expression_list
%type <node> unary_expression
%type <node> additive_expression multiplicative_expression relational_expression
%type <node> equality_expression logical_and_expression logical_or_expression
%type <node> binary_expression expression declaration declaration_specifiers
%type <node> type_specifier struct_specifier struct_declaration_list struct_declaration declarator direct_declarator
%type <node> parameter_list parameter_declaration statement compound_statement declaration_list statement_list
%type <node> expression_statement selection_statement iteration_statement jump_statement
%type <node> program external_declaration function_definition

%start program
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
     $1->leaf->value = realloc($1->leaf->value, strlen($1->leaf->value) + 3);
     strcat($1->leaf->value, "()");
     $$ = $1;}

  	| postfix_expression '(' argument_expression_list ')'
    {log2("postfix_expression -> postfix_expression ( argument_expression_list )");
     //$1->leaf->value = realloc($1->leaf->value, strlen($1->leaf->value) + 3 + strlen($3->leaf->value));
     strcat($1->leaf->value, "(");
     //strcat($1->leaf->value, $3->leaf->value);
     strcat($1->leaf->value, ")");
     $$ = $1;}

  	| postfix_expression PTR_OP IDENTIFIER
    {log2("postfix_expression -> postfix_expression PTR_OP IDENTIFIER");
     $1->leaf->value = realloc($1->leaf->value, strlen($1->leaf->value) + strlen($2) + 1 + strlen($3));
     strcat($1->leaf->value, $2);
     strcat($1->leaf->value, $3);
     $$ = $1;}
  	;

argument_expression_list
  	: assignment_expression
    {log2("argument_expression_list -> expression");
     $$ = $1;}

  	| argument_expression_list ',' assignment_expression
    {log2("argument_expression_list -> argument_expression_list , expression");
     $1->leaf->value = realloc($1->leaf->value, strlen($1->leaf->value) + 3 + strlen($3->leaf->value));
     strcat($1->leaf->value, ", ");
     strcat($1->leaf->value, $3->leaf->value);
     $$ = $1;}
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
     char* s = malloc(strlen($1) + 3 + strlen($3->leaf->value));
     strcat(s, $1);
     strcat(s, "(");
     strcat(s, $3->leaf->value);
     strcat(s, ")");
     $$ = build_leaf(TID,s);
     }

  	| SIZEOF '(' type_name ')'
    {log2("unary_expression -> SIZEOF ( type_name )");
     char* s = malloc(strlen($1) + 3 + strlen($3->leaf->value));
     strcat(s, $1);
     strcat(s, "(");
     strcat(s, $3->leaf->value);
     strcat(s, ")");
     $$ = build_leaf(TID,s);
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
  	;

if_expression
  	: logical_or_expression
    {log2("if_expression -> logical_or_expression");
     $$ = $1;}
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
    {log2("expression -> assignment_expression");
     $$ = $1;}

  	| expression ',' assignment_expression
    {log2("expression -> assignment_expression = expression");
     $$ = build_opr(",",$1,$3);}
  	;

declaration
  	: declaration_specifiers init_declarator_list ';'
    {log2("declaration -> declaration_specifiers init_declarator_list ';'");
     $$ = build_opr(";",$1,$2);}

  	| declaration_specifiers ';'
    {log2("declaration -> declaration_specifiers ';'");
     $$ = build_opr(";",$1,$2);}
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
  	| init_declarator_list ',' init_declarator
  	;

init_declarator
  	: declarator

  	// Autorise la declaration durant la definition
  	| declarator '=' initializer
  	;

type_specifier
  	: VOID
    {$$ = build_leaf(TT,$1);}

  	| INT
    {$$ = build_leaf(TT,$1);}

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
     char* s = malloc(strlen($1) + strlen($2) + 1);
     strcat(s, $1);
     strcat(s, $2);
     $$ = s;}

  	// int *
  	| pointer
    {$$ = $1;}
  	;

direct_declarator
  	: IDENTIFIER
    {$$ = build_leaf(TID,$1);}

  	| '(' declarator ')'
  	| direct_declarator '(' parameter_list ')'
  	| direct_declarator '(' identifier_list ')'
  	| direct_declarator '(' ')'
  	;

direct_declarator_pointer
  	: IDENTIFIER
    {$$ = build_leaf(TID,$1);}

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
    {$$ = $1;}
  	;

parameter_list
    	: parameter_declaration
      {$$ = $1;}

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
  	: '{' '}'
  	| '{' block_item_list '}'
    {$$ = $2;}

  	| ';'
  	;

block_item_list
  	: block_item
    {$$ = $1;}

  	| block_item_list block_item
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
  	: ';'
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
  	;

// Une suite de declaration de definitions de fonctions
external_declaration
  	: function_definition external_declaration
    {log2("external_declaration -> function_definition");
    $$ = $1;}

  	| declaration external_declaration
    {log2("external_declaration -> declaration");
    $$ = $1;}

  	| %empty
  	;

function_definition
  	: declaration_specifiers declarator declaration_list compound_statement
    {stringify($4,0);}

  	| declaration_specifiers declarator compound_statement
    {stringify($3,0);}
  	;

declaration_list
  	: declaration
    {$$ = $1;}

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
