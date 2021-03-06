%{
#include <stdio.h>
#include "y.tab.h"
#include <errno.h>
int verbose = 0;

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
"if"                    {log(yytext);yylval.string = strdup(yytext);return IF;}
"else"                  {log(yytext);yylval.string = strdup(yytext);return ELSE;}
"while"                 {log(yytext);yylval.string = strdup(yytext);return WHILET;}
"for"                   {log(yytext);yylval.string = strdup(yytext);return FOR;}
"int"                   {log(yytext);yylval.string = strdup(yytext);return INT;}
"void"                  {log(yytext);yylval.string = strdup(yytext);return VOID;}
"return"                {log(yytext);yylval.string = strdup(yytext);return RETURN;}

{L}({L}|{D})*           {log(yytext);yylval.string = strdup(yytext);return IDENTIFIER;}

{D}+{IS}?               {log(yytext);yylval.string = strdup(yytext);return CONSTANT;}

L?\"(\\.|[^\\"])*\"	    {log(yytext);yylval.string = strdup(yytext);return(STRING_LITERAL);}

"<="                    {log(yytext);yylval.string = strdup(yytext);return LE_OP;}
">="                    {log(yytext);yylval.string = strdup(yytext);return GE_OP;}
">"                     {log(yytext);yylval.string = strdup(yytext);return G_OP;}
"<"                     {log(yytext);yylval.string = strdup(yytext);return L_OP;}
"=="                    {log(yytext);yylval.string = strdup(yytext);return EQ_OP;}
"!="                    {log(yytext);yylval.string = strdup(yytext);return NE_OP;}

";"                     {log(&yytext[0]); return(';'); }
"{"                     {log(&yytext[0]); return('{'); }
"}"                     {log(&yytext[0]); return('}'); }
","                     {log(&yytext[0]); return(','); }
":"                     {log(&yytext[0]); return(':'); }
"="                     {log(&yytext[0]); return('='); }
"("                     {log(&yytext[0]); return('('); }
")"                     {log(&yytext[0]); return(')'); }
"&"                     {log(&yytext[0]); return('&'); }
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
