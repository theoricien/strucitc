%{
#include <stdio.h>
#include "y.tab.h"
int verbose = 1;

void log (char *msg)
{
    if (verbose)
        printf("[*] %s\n", msg);
}
/* Ne gere pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*
COMMENTAIRE_MONO        (\/\/.*)|(\/\*.*\*\/)
COMMENTAIRE_POLY        [\/][*][^*]*[*]+([^*\/][^*]*[*]+)*[\/]

%%

{COMMENTAIRE_MONO}      ;
{COMMENTAIRE_POLY}      ;

"extern"                {log("extern");yylval.string = strdup(yytext);return EXTERN;}
"struct"                {log("struct");yylval.string = strdup(yytext);return STRUCT;}
"if"                    {log("if");yylval.string = strdup(yytext);return IF;}
"else"                  {log("else");yylval.string = strdup(yytext);return ELSE;}
"while"                 {log("while");yylval.string = strdup(yytext);return WHILE;}
"for"                   {log("for");yylval.string = strdup(yytext);return FOR;}
"int"                   {log("int");yylval.string = strdup(yytext);return INT;}
"void"                  {log("void");yylval.string = strdup(yytext);return VOID;}
"return"                {log("return");yylval.string = strdup(yytext);return RETURN;}
"sizeof"                {log("sizeof");yylval.string = strdup(yytext);return SIZEOF;}

{L}({L}|{D})*           {log("IDENTIFIER");yylval.string = strdup(yytext);return IDENTIFIER;}

0{D}+{IS}?              {log("0DEC");yylval.string = strdup(yytext);return CONSTANT; /* DEC */}
{D}+{IS}?               {log("DEC");yylval.string = strdup(yytext);return CONSTANT; /* DEC */}
L?'(\\.|[^\\'])+'       {log("chelou 1");; /* chelou */ }

L?\"(\\.|[^\\"])*\"     {log("chelou 2"); /* A completer */ }

"<="                    {log("LE_OP");yylval.string = strdup(yytext);return LE_OP;}
">="                    {log("GE_OP");yylval.string = strdup(yytext);return GE_OP;}
">"                     {log("G_OP");yylval.string = strdup(yytext);return G_OP;}
"<"                     {log("L_OP");yylval.string = strdup(yytext);return L_OP;}
"=="                    {log("EQ_OP");yylval.string = strdup(yytext);return EQ_OP;}
"!="                    {log("NE_OP");yylval.string = strdup(yytext);return NE_OP;}

"->"                    {log("PTR_OP");yylval.string = strdup(yytext);return PTR_OP;}

"&&"                    {log("AND_OP");yylval.string = strdup(yytext);return AND_OP;}
"||"                    {log("OR_OP");yylval.string = strdup(yytext);return OR_OP;}

[ \t\v\n\f\r]           ;
.                       {log(&yytext[0]); return yytext[0];}
%%
