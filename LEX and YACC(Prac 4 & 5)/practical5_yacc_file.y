
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3

 */

%{
#include <stdlib.h>
#include <stdio.h>
#include "prac8.h"
%{
#include <stdlib.h>
#include <stdio.h>
int yylex(void);
#define N 100
char *vars[N]; double vals[N]; int n=0;
//#include "prac6.h"
%}

%union { float fval; int ival; }
%token <ival> INTEGER
%token <fval> FLOAT
%token <ival> NAME
%type <fval> expr
%type <fval> mulex
%type <fval> term

%%

program:
        line program
        | line
line:
        expr '\n'       { printf("%g\n",$1); }
        | NAME '=' expr '\n'    {vals[$1]=$3;}
expr:
        expr '+' mulex          { $$ = $1 + $3; }
        | expr '-' mulex        { $$ = $1 - $3; }
        | mulex                 { $$ = $1; }
mulex:
        mulex '*' term          { $$ = $1 * $3; }
        | mulex '/' term        { $$ = $1 / $3; }
        | term                  { $$ = $1; }
term:
        '(' expr ')'            { $$ = $2; }
        | INTEGER               { $$ = $1; }
        | FLOAT                 { $$ = $1; }
        | NAME                  {$$ = vals[$1];}

%%

int varindex(char *var)
{
        int i;
        for (i=0; i<n; i++)
                if (strcmp(var,vars[i])==0)
                        return i;
        vars[n] = strdup(var);
        return n++;
}
void yyerror(char *s)
{
fprintf(stderr,"%s\n",s);
return;
}

int main(void)
{
/*yydebug=1;*/
yyparse();
return 0;
}
