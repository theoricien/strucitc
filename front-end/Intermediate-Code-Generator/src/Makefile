CC=gcc
CFLAGS=-ll
EXEC=strucitfe

all: $(EXEC)

strucitfe: lex.yy.c y.tab
	$(CC) -o $(EXEC) lex.yy.c crpdct.c ifstmt.c stack.c declarations.c statements.c y.tab.c -include crpdct.h declarations.h ifstmt.h stack.h statements.h $(CFLAGS)

lex.yy.c:
	flex ANSI-C.l

y.tab:
	bison -v -g -d structfe.y
	mv structfe.tab.h y.tab.h
	mv structfe.tab.c y.tab.c

clean:
	rm y.tab.c lex.yy.c y.tab.h strucitfe*

tests:
	chmod +x ./mktests.sh
	./mktests.sh
