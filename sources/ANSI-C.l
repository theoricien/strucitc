%{
#include <stdio.h>
#include "y.tab.h"

/* Ne gere pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%%
"extern"                {return EXTERN;}
"if"                    {return IF;}
"else"                  {return ELSE;}
"while"                 {return WHILE;}
"for"                   {return FOR;}
"int"                   {return INT;}
"void"                  {return VOID;}
"return"                {return RETURN;}
"sizeof"                {return SIZEOF;}

{L}({L}|{D})*           {return IDENTIFIER;}

0[xX]{H}+{IS}?          {return CONSTANT; /* HEX */}
0{D}+{IS}?              {return CONSTANT; /* DEC */}
{D}+{IS}?               {return CONSTANT; /* DEC */}
L?'(\\.|[^\\'])+'       {; /* chelou */ }

{D}+{E}{FS}?            {return CONSTANT; /* BIG INT */}
{D}*"."{D}+({E})?{FS}?  {return CONSTANT; /* flottant chelou: .588E-8 */ }
{D}+"."{D}*({E})?{FS}?  {return CONSTANT; /* flottant chelou 2: 184.L */ }

L?\"(\\.|[^\\"])*\"     {; /* A completer */ }

"<="                    {return LE_OP;}
">="                    {return GE_OP;}
">"                     {return GE_OP; /* A completer */ }
"<"                     {return LE_OP; /* A completer */ }
"=="                    {return EQ_OP;}
"!="                    {return NE_OP;}

"&&"                    {return AND_OP;}
"||"                    {return OR_OP;}

[ \t\v\n\f]             {; /* NE RIEN FAIRE */}
.                       {return yytext[0];}
%%
