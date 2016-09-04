all: cal
lex.yy.c: cal1.l y.tab.h
      lex -ll cal1.l

lex.yy.o: lex.yy.c
      gcc -c lex.yy.c

y.tab.c: cal1.y
      yacc -d cal1.y

y.tab.o: y.tab.c
      gcc -c y.tab.c

cal: lex.yy.o y.tab.o
      gcc -o temp lex.yy.o y.tab.o -ll -ly

y.tab.h: cal1.y
      yacc -d cal1.y

