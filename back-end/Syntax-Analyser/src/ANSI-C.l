%{
#include <stdio.h>
#include "y.tab.h"
int verbose = 0;

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
COMMENTAIRE_POLY        [\/][*][^*]*[*]+([^*\/][^*]*[*]+)*[\/]

%%

{COMMENTAIRE_POLY}      ;

"extern"                {log("extern");return EXTERN;}
"if"                    {log("if");return IF;}
"int"                   {log("int");return INT;}
"void"                  {log("void");return VOID;}
"return"                {log("return");return RETURN;}
"goto"                  {log("goto");return GOTO;}

{L}({L}|{D})*           {log("IDENTIFIER");return IDENTIFIER;}

{D}+{IS}?               {log("DEC");return CONSTANT; /* DEC */}

"<="                    {log("LE_OP");return LE_OP;}
">="                    {log("GE_OP");return GE_OP;}
">"                     {log("G_OP");return G_OP;}
"<"                     {log("L_OP");return L_OP;}
"=="                    {log("EQ_OP");return EQ_OP;}
"!="                    {log("NE_OP");return NE_OP;}

";"                     {log(&yytext[0]); return(';'); }
"{"                     {log(&yytext[0]); return('{'); }
"}"                     {log(&yytext[0]); return('}'); }
","                     {log(&yytext[0]); return(','); }
"="                     {log(&yytext[0]); return('='); }
"("                     {log(&yytext[0]); return('('); }
":"                     {log(&yytext[0]); return(':'); }
")"                     {log(&yytext[0]); return(')'); }
"&"                     {log(&yytext[0]); return('&'); }
"-"                     {log(&yytext[0]); return('-'); }
"+"                     {log(&yytext[0]); return('+'); }
"*"                     {log(&yytext[0]); return('*'); }
"/"                     {log(&yytext[0]); return('/'); }

[ \t\v\n\f\r]           ;
.                       {log(&yytext[0]); return yytext[0];}
%%
