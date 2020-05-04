%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int verbose2 = 0;

void log2 (char *msg)
{
    if (verbose2)
        printf("[***] %s\n", msg);
}
%}

%union{
  node_t *node;
  char *string;
  char uop;
}


%token IDENTIFIER CONSTANT SIZEOF
%token PTR_OP LE_OP GE_OP L_OP G_OP EQ_OP NE_OP
%token INC_OP DEC_OP
%token RB_OP LB_OP
%token AND_OP OR_OP
%token EXTERN
%token INT VOID
%token STRUCT
%token IF ELSE WHILE FOR RETURN


%type <string> IDENTIFIER CONSTANT SIZEOF PTR_OP LE_OP GE_OP L_OP G_OP EQ_OP NE_OP RB_OP LB_OP

%type <string> AND_OP OR_OP

%type <node> primary_expression postfix_expression argument_expression_list

%type <node> unary_expression

%type <uop> unary_operator

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
        : IDENTIFIER  {log2("primary_expression -> IDENTIFIER");
                      $$ = build_leaf(TID, $1);}
        | CONSTANT    {log2("primary_expression -> IDENTIFIER");
                      $$ = build_leaf(TCONS, $1);}
        | '(' expression ')' {log2("primary_expression -> ( expression )");
                      $$ = $2;}
        ;

postfix_expression
        : primary_expression {$$ = $1;}
        | postfix_expression '(' ')'  {log2("postfix_expression -> postfix_expression ( )");
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
        | postfix_expression '.' IDENTIFIER
                                      {log2("postfix_expression -> postfix_expression . IDENTIFIER");
                                      $1->leaf->value = realloc($1->leaf->value, strlen($1->leaf->value) + 2 + strlen($3));
                                      strcat($1->leaf->value, ".");
                                      strcat($1->leaf->value, $3);
                                      $$ = $1;}
        | postfix_expression PTR_OP IDENTIFIER
                                      {log2("postfix_expression -> postfix_expression PTR_OP IDENTIFIER");
                                      $1->leaf->value = realloc($1->leaf->value, strlen($1->leaf->value) + strlen($2) + 1 + strlen($3));
                                      strcat($1->leaf->value, $2);
                                      strcat($1->leaf->value, $3);
                                      $$ = $1;}
        ;

argument_expression_list
        : expression
                                      {log2("argument_expression_list -> expression");
                                      $$ = $1;}
        | argument_expression_list ',' expression
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
        | unary_operator unary_expression
                                      {log2("unary_expression -> unary_operator unary_expression");
                                      $$ = build_uopr($1,$2);}
        | SIZEOF '(' type_specifier ')'
                                      {log2("unary_expression -> SIZEOF ( type_specifier )");
                                      char* s = malloc(strlen($1) + 3 + strlen($3->leaf->value));
                                      strcat(s, $1);
                                      strcat(s, "(");
                                      strcat(s, $3->leaf->value);
                                      strcat(s, ")");
                                      $$ = build_leaf(TID,s);
                                      }
        | SIZEOF '(' expression ')'
                                      {log2("unary_expression -> SIZEOF ( expression)");
                                      char* s = malloc(strlen($1) + 3 + strlen($3->leaf->value));
                                      strcat(s, $1);
                                      strcat(s, "(");
                                      strcat(s, $3->leaf->value);
                                      strcat(s, ")");
                                      $$ = build_leaf(TID,s);
                                      }
        ;

unary_operator
        : '&'                         {log2("unary_operator -> &");
                                      $$ = '&';}
        | '*'                         {log2("unary_operator -> *");
                                      $$ = '*';}
        | '-'                         {log2("unary_operator -> -");
                                      $$ = '-';}
        ;

multiplicative_expression
        : unary_expression            {log2("multiplicative_expression -> unary_expression");
                                      $$ = $1;}
        | multiplicative_expression '*' unary_expression
                                      {log2("multiplicative_expression -> multiplicative_expression * unary_expression");
                                      $$ = build_opr('*',$1,$3);}
        | multiplicative_expression '/' unary_expression
                                      {log2("multiplicative_expression -> multiplicative_expression / unary_expression");
                                      $$ = build_opr('/',$1,$3);}
        ;

additive_expression
        : multiplicative_expression   {log2("additive_expression -> multiplicative_expression");
                                      $$ = $1;}
        | additive_expression '+' multiplicative_expression
                                      {log2("additive_expression -> additive_expression + multiplicative_expression");
                                      $$ = build_opr('+',$1,$3);}
        | additive_expression '-' multiplicative_expression
                                      {log2("additive_expression -> additive_expression - multiplicative_expression");
                                      $$ = build_opr('-',$1,$3);}
        ;

relational_expression
        : additive_expression         {log2("relational_expression -> additive_expression");
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
        : relational_expression       {log2("equality_expression -> relational_expression");
                                      $$ = $1;}
        | equality_expression EQ_OP relational_expression
                                      {log2("equality_expression -> equality_expression EQ_OP relational_expression");
                                      $$ = build_opr($2,$1,$3);}
        | equality_expression NE_OP relational_expression
                                      {log2("equality_expression -> equality_expression NE_OP relational_expression");
                                      $$ = build_opr($2,$1,$3);}
        ;

logical_and_expression
        : equality_expression         {log2("logical_and_expression -> equality_expression");
                                      $$ = $1;}
        | logical_and_expression AND_OP equality_expression
                                      {log2("logical_and_expression -> logical_and_expression AND_OP equality_expression");
                                      $$ = build_opr($2,$1,$3);}
        ;

logical_or_expression
        : logical_and_expression      {log2("logical_or_expression -> logical_and_expression");
                                      $$ = $1;}
        | logical_or_expression OR_OP logical_and_expression
                                      {log2("logical_or_expression -> logical_or_expression OR_OP logical_and_expression");
                                      $$ = build_opr($2,$1,$3);}
        ;

binary_expression
        : logical_or_expression RB_OP logical_or_expression
                                      {log2("binary_expression -> logical_or_expression RB_OP logical_or_expression");
                                      $$ = build_opr($2,$1,$3);}
        | logical_or_expression LB_OP logical_or_expression
                                      {log2("binary_expression -> logical_or_expression LB_OP logical_or_expression");
                                      $$ = build_opr($2,$1,$3);}
        ;

expression
        : logical_or_expression       {log2("expression -> logical_or_expression");
                                      $$ = $1;}
        | unary_expression '=' expression
                                      {log2("expression -> unary_expression = expression");
                                      $$ = build_opr('=',$1,$3);}
        | binary_expression           {log2("expression -> binary_expression");
                                      $$ = $1;}
        ;

declaration
        : declaration_specifiers declarator ';'
                                      {log2("declaration -> declaration_specifiers declarator ';'");
                                      $$ = build_uopr(';',$2);}
        | struct_specifier ';'
        ;

declaration_specifiers
        : EXTERN type_specifier
        | type_specifier              //{$$ = $1;}
        ;

type_specifier
        : VOID
        | INT
        | struct_specifier
        ;

struct_specifier
        : STRUCT IDENTIFIER '{' struct_declaration_list '}'
        | STRUCT '{' struct_declaration_list '}'
        | STRUCT IDENTIFIER
        ;

struct_declaration_list
        : struct_declaration
        | struct_declaration_list struct_declaration
        ;

struct_declaration
        : type_specifier declarator ';'
        ;

declarator
        : '*' direct_declarator             {log2("declarator -> '*' direct_declarator");
                                            char* s = malloc(strlen("*") + strlen($2) + 1);
                                            strcat(s, "*");
                                            strcat(s, $2);
                                            $$ = s;}
        | direct_declarator                 {log2("declarator -> direct_declarator");
                                            $$ = $1;}
        ;

direct_declarator
        : IDENTIFIER
        | '(' declarator ')'
        | direct_declarator '(' parameter_list ')'
        | direct_declarator '(' ')'
        ;

parameter_list
        : parameter_declaration {$$ = $1;}
        | parameter_list ',' parameter_declaration
        ;

parameter_declaration
        : declaration_specifiers declarator
        ;

statement
        : compound_statement {log2("statement -> compound_statement");$$ = $1;}
        | expression_statement {log2("statement -> expression_statement");$$ = $1;}
        | selection_statement {log2("statement -> selection_statement");$$ = $1;}
        | iteration_statement {log2("statement -> iteration_statement");$$ = $1;}
        | jump_statement {log2("statement -> jump_statement");$$ = $1;}
        ;

compound_statement
        : '{' '}'
        | '{' statement_list '}'
        | '{' declaration_list '}'
        | '{' declaration_list statement_list '}'
        ;

declaration_list
        : declaration {log2("declaration_list -> declaration");$$ = $1;}
        | declaration_list declaration
        ;

statement_list
        : statement {log2("statement_list -> statement");$$ = $1;}
        | statement_list statement
        ;

expression_statement
        : ';'
        | expression ';' {log2("expression_statement -> expression");
                          $$ = $1;
                          stringify($$,0);}
        ;

selection_statement
        : IF '(' expression ')' statement
        | IF '(' expression ')' statement ELSE statement
        ;

iteration_statement
        : WHILE '(' expression ')' statement
        | FOR '(' expression_statement expression_statement expression ')' statement
        ;

jump_statement
        : RETURN ';'
        | RETURN expression ';'
        ;

program
        : external_declaration {log2("program -> external_declaration");
                                $$ = $1;}
        | program external_declaration
        ;

external_declaration
        : function_definition {log2("external_declaration -> function_definition");$$ = $1;}
        | declaration {log2("external_declaration -> declaration");$$ = $1;}
        ;

function_definition
        : declaration_specifiers declarator compound_statement
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
