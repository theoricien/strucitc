%{
#include <stdio.h>
#include "y.tab.h"


/* Ne gère pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%%
"extern"                { /* A completer */ }
"if"                    { /* A completer */ }
"else"                  { /* A completer */ }
"goto"                  { /* A completer */ }
"while"                 { /* A completer */ }
"for"                   { /* A completer */ }
"int"                   { /* A completer */ }
"void"                  { /* A completer */ }
"return"                { /* A completer */ }
"struct"                { /* A completer */ }
"sizeof"                { /* A completer */ }

{L}({L}|{D})*           { /* IDENTIFICATEUR */ }

0[xX]{H}+{IS}?          { /* HEXA: 0xbabeb33f */ }
0{D}+{IS}?              { /* int */ }
{D}+{IS}?               { /* int: 546LLLLLuUuuULlL */ }
L?'(\\.|[^\\'])+'       { /* chelou */ }

{D}+{E}{FS}?            { /* big int: 5e+88 */ }
{D}*"."{D}+({E})?{FS}?  { /* flottant chelou: .588E-8 */ }
{D}+"."{D}*({E})?{FS}?  { /* flottant chelou 2: 184.L */ }

L?\"(\\.|[^\\"])*\"     { /* A completer */ }

"<="                    { /* A completer */ }
">="                    { /* A completer */ }
">"                     { /* A completer */ }
"<"                     { /* A completer */ }
"=="                    { /* A completer */ }
"!="                    { /* A completer */ }

[ \t\v\n\f]             { /* A completer */ }
.                       { /*le ; j'imagine */  return yytext[0]; }
%%