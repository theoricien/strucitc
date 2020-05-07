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

"extern"                {log("extern");return EXTERN;}
"struct"                {log("struct");return STRUCT;}
"if"                    {log("if");return IF;}
"else"                  {log("else");return ELSE;}
"while"                 {log("while");return WHILE;}
"for"                   {log("for");return FOR;}
"int"                   {log("int");return INT;}
"void"                  {log("void");return VOID;}
"return"                {log("return");return RETURN;}
"sizeof"                {log("sizeof");return SIZEOF;}

{L}({L}|{D})*           {log(yytext);return IDENTIFIER;}

0{D}+{IS}?              {log(yytext);return CONSTANT; /* DEC */}
{D}+{IS}?               {log(yytext);return CONSTANT; /* DEC */}
L?'(\\.|[^\\'])+'       {log(yytext);return CONSTANT; /* chelou */ }

L?\"(\\.|[^\\"])*\"	    {log(yytext);return(STRING_LITERAL);}

"+="                    {log(yytext); return(ADD_ASSIGN); }
"-="                    {log(yytext); return(SUB_ASSIGN); }
"*="                    {log(yytext); return(MUL_ASSIGN); }
"/="                    {log(yytext); return(DIV_ASSIGN); }

"<="                    {log(yytext);return LE_OP;}
">="                    {log(yytext);return GE_OP;}
">"                     {log(yytext);return G_OP;}
"<"                     {log(yytext);return L_OP;}
"=="                    {log(yytext);return EQ_OP;}
"!="                    {log(yytext);return NE_OP;}

"->"                    {log(yytext);return PTR_OP;}

"&&"                    {log(yytext);return AND_OP;}
"||"                    {log(yytext);return OR_OP;}

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
