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
COMMENTAIRE_MONO        (\/\/.*)|(\/\*.*\*\/)
COMMENTAIRE_POLY        [\/][*][^*]*[*]+([^*\/][^*]*[*]+)*[\/]

%%

{COMMENTAIRE_MONO}      ;
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

{L}({L}|{D})*           {log("IDENTIFIER");return IDENTIFIER;}

0[xX]{H}+{IS}?          {log("HEX");return CONSTANT; /* HEX */}
0{D}+{IS}?              {log("0DEC");return CONSTANT; /* DEC */}
{D}+{IS}?               {log("DEC");return CONSTANT; /* DEC */}
L?'(\\.|[^\\'])+'       {log("chelou 1");; /* chelou */ }

{D}+{E}{FS}?            {log("BIG INT");return CONSTANT; /* BIG INT */}
{D}*"."{D}+({E})?{FS}?  {log("flottant chelou");return CONSTANT; /* flottant chelou: .588E-8 */ }
{D}+"."{D}*({E})?{FS}?  {log("flottant chelou 2");return CONSTANT; /* flottant chelou 2: 184.L */ }

L?\"(\\.|[^\\"])*\"     {log("chelou 2"); /* A completer */ }

"++"                    {log("++");return INC_OP;}
"--"                    {log("--");return DEC_OP;}

">>"                    {log("RB_OP");return RB_OP;}
"<<"                    {log("LB_OP");return LB_OP;}

"<="                    {log("LE_OP");return LE_OP;}
">="                    {log("GE_OP");return GE_OP;}
">"                     {log("G_OP");return G_OP;}
"<"                     {log("L_OP");return L_OP;}
"=="                    {log("EQ_OP");return EQ_OP;}
"!="                    {log("NE_OP");return NE_OP;}

"->"                    {log("PTR_OP");return PTR_OP;}

"&&"                    {log("AND_OP");return AND_OP;}
"||"                    {log("OR_OP");return OR_OP;}

[ \t\v\n\f\r]           ;
.                       {log(&yytext[0]); return yytext[0];}
%%
