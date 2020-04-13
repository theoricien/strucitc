%{
#include <stdio.h>
int verbose = 0;

void log (char *msg)
{
    if (verbose)
        printf("[*] %s\n", msg);
}


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

"extern"                {log("extern");}
"struct"                {log("struct");}
"if"                    {log("if");}
"else"                  {log("else");}
"while"                 {log("while");}
"for"                   {log("for");}
"int"                   {log("int");}
"void"                  {log("void");}
"return"                {log("return");}
"sizeof"                {log("sizeof");}

{L}({L}|{D})*           {log("IDENTIFIER");}

0[xX]{H}+{IS}?          {log("HEX");}
0{D}+{IS}?              {log("0DEC");}
{D}+{IS}?               {log("DEC");}
L?'(\\.|[^\\'])+'       {log("chelou 1");}

{D}+{E}{FS}?            {log("BIG INT");}
{D}*"."{D}+({E})?{FS}?  {log("flottant chelou");}
{D}+"."{D}*({E})?{FS}?  {log("flottant chelou 2"); }

L?\"(\\.|[^\\"])*\"     {log("chelou 2"); /* A completer */ }

"++"                    {log("++");}
"--"                    {log("--");}

">>"                    {log("RB_OP");}
"<<"                    {log("LB_OP");}

"<="                    {log("LE_OP");}
">="                    {log("GE_OP");}
">"                     {log("G_OP");}
"<"                     {log("L_OP");}
"=="                    {log("EQ_OP");}
"!="                    {log("NE_OP");}

"->"                    {log("PTR_OP");}

"&&"                    {log("AND_OP");}
"||"                    {log("OR_OP");}

"("|")"|"+"|"-"|"*"|"/" {log(yytext);}
"{"|"}"|"["|"]"|"&"|"|" {log(yytext);}
"="|";"|","             {log(yytext);}

[ \t\v\n\f\r]           ;
.                       {printf("\nInvalid Lexic: %s\n", yytext); exit(2);}
%%

int yywrap (void) {return 1;}

void
yyerror (char *s)
{
    fprintf(stderr, "%s", s);
    exit(2);
}

extern FILE *yyin;

int
main (int argc, char *argv[])
{
    if ((yyin = fopen(argv[1], "r")) == NULL)
    {
        yyerror("[E] File not found\n");
    } else {
        yylex();
        printf("Success.\n");
    }
    return 0;
}
