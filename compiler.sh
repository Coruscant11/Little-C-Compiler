bison -d miniC.y
mv miniC.tab.h miniC.h
mv miniC.tab.c miniC.y.c
flex ANSI-C.l
mv lex.yy.c miniC.lex.c
gcc -c miniC.lex.c -o miniC.lex.o
gcc -c miniC.y.c -o miniC.y.o
gcc -c ast.c -o ast.o
gcc -o miniC miniC.lex.o miniC.y.o ast.o -lfl

