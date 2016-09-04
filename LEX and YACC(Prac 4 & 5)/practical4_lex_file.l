
/*
Roll no:09bce026
Author: Sameer Makwana
Licence: GPLv3

 */

%{
#include <stdlib.h>
#include <stdio.h>
#include "prac6.h"
void yyerror(char*);

%}

%%

[ \t]+ ;
[0-9]+  {yylval.ival = atoi(yytext);
                return INTEGER;}
[0-9]+\.[0-9]+ {yylval.fval = atof(yytext);
                return FLOAT;}
[-+*/]  {return *yytext;}
"("     {return *yytext;}
")"     {return *yytext;}
\n      {return *yytext;}
