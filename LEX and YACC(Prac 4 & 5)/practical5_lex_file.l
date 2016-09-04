
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3

 */

%{
#include <stdlib.h>
#include <stdio.h>
#include "prac8.h"
void yyerror(char*);
int varindex(char *var);
%}

%%

[ \t]+ ;
"int"   {return INT;}
"float" {return *yytext;}
[0-9]+  {yylval.ival = atoi(yytext);
                return INTEGER;}
[0-9]+\.[0-9]+ {yylval.fval = atof(yytext);
                return FLOAT;}
[-+*/=] {return *yytext;}
"("     {return *yytext;}
")"     {return *yytext;}
[a-z][a-z0-9]*  {yylval.ival = varindex(yytext);
                return NAME;}
,       {return *yytext;}
;       {return *yytext;}
\n      {return *yytext;}
