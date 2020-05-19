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

0{D}+{IS}?              {count();log(yytext);yylval.string = strdup(yytext);return CONSTANT;}
{D}+{IS}?               {count();log(yytext);yylval.string = strdup(yytext);return CONSTANT;}
L?'(\\.|[^\\'])+'       {count();log(yytext);yylval.string = strdup(yytext);return CONSTANT;}

L?\"(\\.|[^\\"])*\"	    {count();log(yytext);yylval.string = strdup(yytext);return(STRING_LITERAL);}

"+="                    {count();log(yytext);yylval.string = strdup(yytext);return(ADD_ASSIGN); }
"-="                    {count();log(yytext);yylval.string = strdup(yytext);return(SUB_ASSIGN); }
"*="                    {count();log(yytext);yylval.string = strdup(yytext);return(MUL_ASSIGN); }
"/="                    {count();log(yytext);yylval.string = strdup(yytext);return(DIV_ASSIGN); }

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
.                       {return yytext[0];}
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
