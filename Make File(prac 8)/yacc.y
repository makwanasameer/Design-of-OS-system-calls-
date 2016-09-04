
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3

 */

%{
#include <stdlib.h>
#include <stdio.h>
int yylex(void);

%}
%union  {int ival; float fval;}

%token <ival> INTEGER
%token <fval> FLOAT
%type <fval> expr
%type <fval> mulex
%type <fval> term
%%

program:
       line program
       | line
line:
       expr '\n' { printf("%f\n",$1); }
       | '\n'
expr:
       expr '+' mulex { $$ = $1 + $3; }
       | expr '-' mulex { $$ = $1 - $3; }
       | mulex { $$ = $1; }
mulex:
       mulex '*' term { $$ = $1 * $3; }
       | mulex '/' term { $$ = $1 / $3; }
       | term { $$ = $1; }
term:
       '(' expr ')' { $$ = $2; }
       | INTEGER { $$ = $1; }
       | FLOAT {$$ = $1;}
%%
void yyerror(char *s)
{
fprintf(stderr,"%s\n",s);
return;
}

int main(void)
{
yyparse();
return 0;
}
