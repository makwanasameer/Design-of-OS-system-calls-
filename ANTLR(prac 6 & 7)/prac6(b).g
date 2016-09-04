grammar sample;

options 
{
    backtrack	= true;
    memoize	= true;
    k		= 2;
    language	= C;
}

rollno 	: YEAR BRANCH NO
{
	printf("Wrong value entered"); 
}
;

fragment
BRANCH  : 'BCE' | 'BEE' |'BCL' | 'BEC' | 'BIC' | 'BME' | 'BCH' 
    ;

YEAR :	'0'..'1' '0'..'9'
    ;

NO :	'0'..'9' '0'..'9' '0'..'9'
    ;

