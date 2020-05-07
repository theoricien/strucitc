%{
#include <stdio.h>
#include "y.tab.h"
int verbose = 1;

void log (char *msg)
{
    if (verbose)
        printf("%s", msg);
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
COMMENTAIRE_POLY        [\/][*][^*]*[*]+([^*\/][^*]*[*]+)*[\/]

%%

{COMMENTAIRE_POLY}      ;

"extern"                {log(yytext);yylval.string = strdup(yytext);return EXTERN;}
"struct"                {log(yytext);yylval.string = strdup(yytext);return STRUCT;}
"if"                    {log(yytext);yylval.string = strdup(yytext);return IF;}
"else"                  {log(yytext);yylval.string = strdup(yytext);return ELSE;}
"while"                 {log(yytext);yylval.string = strdup(yytext);return WHILE;}
"for"                   {log(yytext);yylval.string = strdup(yytext);return FOR;}
"int"                   {log(yytext);yylval.string = strdup(yytext);return INT;}
"void"                  {log(yytext);yylval.string = strdup(yytext);return VOID;}
"return"                {log(yytext);yylval.string = strdup(yytext);return RETURN;}
"sizeof"                {log(yytext);yylval.string = strdup(yytext);return SIZEOF;}

{L}({L}|{D})*           {log(yytext);yylval.string = strdup(yytext);return IDENTIFIER;}

0{D}+{IS}?              {log(yytext);yylval.string = strdup(yytext);return CONSTANT;}
{D}+{IS}?               {log(yytext);yylval.string = strdup(yytext);return CONSTANT;}
L?'(\\.|[^\\'])+'       {log(yytext);yylval.string = strdup(yytext);return CONSTANT;}

L?\"(\\.|[^\\"])*\"	    {log(yytext);yylval.string = strdup(yytext);return(STRING_LITERAL);}

"+="                    {log(yytext);yylval.string = strdup(yytext);return(ADD_ASSIGN); }
"-="                    {log(yytext);yylval.string = strdup(yytext);return(SUB_ASSIGN); }
"*="                    {log(yytext);yylval.string = strdup(yytext);return(MUL_ASSIGN); }
"/="                    {log(yytext);yylval.string = strdup(yytext);return(DIV_ASSIGN); }

"<="                    {log(yytext);yylval.string = strdup(yytext);return LE_OP;}
">="                    {log(yytext);yylval.string = strdup(yytext);return GE_OP;}
">"                     {log(yytext);yylval.string = strdup(yytext);return G_OP;}
"<"                     {log(yytext);yylval.string = strdup(yytext);return L_OP;}
"=="                    {log(yytext);yylval.string = strdup(yytext);return EQ_OP;}
"!="                    {log(yytext);yylval.string = strdup(yytext);return NE_OP;}

"->"                    {log(yytext);yylval.string = strdup(yytext);return PTR_OP;}

"&&"                    {log(yytext);yylval.string = strdup(yytext);return AND_OP;}
"||"                    {log(yytext);yylval.string = strdup(yytext);return OR_OP;}

";"                     {log(&yytext[0]); return(';'); }
"{"                     {log(&yytext[0]); return('{'); }
"}"                     {log(&yytext[0]); return('}'); }
","                     {log(&yytext[0]); return(','); }
":"                     {log(&yytext[0]); return(':'); }
"="                     {log(&yytext[0]); return('='); }
"("                     {log(&yytext[0]); return('('); }
")"                     {log(&yytext[0]); return(')'); }
"&"                     {log(&yytext[0]); return('&'); }
"~"                     {log(&yytext[0]); return('~'); }
"-"                     {log(&yytext[0]); return('-'); }
"+"                     {log(&yytext[0]); return('+'); }
"*"                     {log(&yytext[0]); return('*'); }
"/"                     {log(&yytext[0]); return('/'); }

" "                     {log(" ");}
"\t"                    {log("\t");}
"\v"                    {log("\v");}
"\n"                    {log("\n");}
"\f"                    {log("\f");}
"\r"                    {log("\r");}
.                       {return yytext[0];}
%%
