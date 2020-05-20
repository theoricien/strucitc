%{
#include <stdio.h>
#include "y.tab.h"
#include <errno.h>
int verbose = 0;

extern int line_count;
extern int column_count;
extern char line_buffer[1000];
extern int buffer_count;

void log (char *msg)
{
    if (verbose)
        printf("%s", msg);
}

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

"extern"                {count();log(yytext);yylval.string = strdup(yytext);return EXTERN;}
"struct"                {count();log(yytext);yylval.string = strdup(yytext);return STRUCT;}
"if"                    {count();log(yytext);yylval.string = strdup(yytext);return IF;}
"else"                  {count();log(yytext);yylval.string = strdup(yytext);return ELSE;}
"while"                 {count();log(yytext);yylval.string = strdup(yytext);return WHILE;}
"for"                   {count();log(yytext);yylval.string = strdup(yytext);return FOR;}
"int"                   {count();log(yytext);yylval.string = strdup(yytext);return INT;}
"void"                  {count();log(yytext);yylval.string = strdup(yytext);return VOID;}
"return"                {count();log(yytext);yylval.string = strdup(yytext);return RETURN;}
"sizeof"                {count();log(yytext);yylval.string = strdup(yytext);return SIZEOF;}

{L}({L}|{D})*           {count();log(yytext);yylval.string = strdup(yytext);return IDENTIFIER;}

{D}+{IS}?               {count();log(yytext);yylval.string = strdup(yytext);return CONSTANT;}

"<="                    {count();log(yytext);yylval.string = strdup(yytext);return LE_OP;}
">="                    {count();log(yytext);yylval.string = strdup(yytext);return GE_OP;}
">"                     {count();log(yytext);yylval.string = strdup(yytext);return G_OP;}
"<"                     {count();log(yytext);yylval.string = strdup(yytext);return L_OP;}
"=="                    {count();log(yytext);yylval.string = strdup(yytext);return EQ_OP;}
"!="                    {count();log(yytext);yylval.string = strdup(yytext);return NE_OP;}

"->"                    {count();log(yytext);yylval.string = strdup(yytext);return PTR_OP;}

"&&"                    {count();log(yytext);yylval.string = strdup(yytext);return AND_OP;}
"||"                    {count();log(yytext);yylval.string = strdup(yytext);return OR_OP;}

";"                     {count();log(&yytext[0]); return(';'); }
"{"                     {count();log(&yytext[0]); return('{'); }
"}"                     {count();log(&yytext[0]); return('}'); }
","                     {count();log(&yytext[0]); return(','); }
":"                     {count();log(&yytext[0]); return(':'); }
"="                     {count();log(&yytext[0]); return('='); }
"("                     {count();log(&yytext[0]); return('('); }
")"                     {count();log(&yytext[0]); return(')'); }
"&"                     {count();log(&yytext[0]); return('&'); }
"~"                     {count();log(&yytext[0]); return('~'); }
"-"                     {count();log(&yytext[0]); return('-'); }
"+"                     {count();log(&yytext[0]); return('+'); }
"*"                     {count();log(&yytext[0]); return('*'); }
"/"                     {count();log(&yytext[0]); return('/'); }

" "                     {count();log(" ");}
"\t"                    {count();log("\t");}
"\v"                    {count();log("\v");}
"\n"                    {count();log("\n");}
"\f"                    {count();log("\f");}
"\r"                    {count();log("\r");}

0[xX]{H}+{IS}?          { yyerror("Invalid Lexic: Hexadecimal numbers unauthorized."); exit(2); }
0{D}+{IS}?              { yyerror("Invalid Lexic: Octal numbers unauthorized."); exit(2); }
L?'(\\.|[^\\'])+'       { yyerror("Invalid Lexic: Chars unauthorized."); exit(2); }

{D}+{E}{FS}?            { yyerror("Invalid Lexic: Big integer unauthorized."); exit(2); }
{D}*"."{D}+({E})?{FS}?  { yyerror("Invalid Lexic: Float numbers unauthorized."); exit(2); }
{D}+"."{D}*({E})?{FS}?  { yyerror("Invalid Lexic: Float numbers unauthorized."); exit(2); }

L?\"(\\.|[^\\"])*\"     { yyerror("Invalid Lexic: String literals unauthorized."); exit(2); }

"..."                   { yyerror("Invalid Lexic: Ellipsis operator unauthorized."); exit(2); }
">>="                   { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"<<="                   { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"+="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"-="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"*="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"/="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"%="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"&="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"^="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"|="                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
">>"                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"<<"                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"++"                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }
"--"                    { yyerror("Invalid Lexic: Operator unauthorized."); exit(2); }

.                       { yyerror("Invalid Lexic."); exit(2); }
%%

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++){
		if (yytext[i] == '\n'){
			column_count = 1;
      line_count ++;
    }
		else if (yytext[i] == '\t'){
			column_count += 8 - (column_count % 8);
		}else{
			column_count++;
    }
 }
}

void get_nth_line (FILE *file, int n, char **s)
{
    char line[1024];
    int curr_line = 0;
    fseek(file,0L,SEEK_SET);
    while (fgets(line,1024,file) != NULL)
    {
        strtok(line,"\n");
        strtok(line,"\t");
        if (curr_line == n)
        {
            char *l = malloc(1024);
            int j = 0;
            printf("%d\n",l[j]);
            strcpy(l,line);
            while(l[j] == '\t'){
              j++;
            }
            *s = &l[j];
            return;
        }
        else
            curr_line++;
    }
}
