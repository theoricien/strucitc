CC=gcc
CFLAGS=-ll -lfl
EXEC=strucitfe

all: $(EXEC)

strucitfe: lex.yy.c y.tab
	$(CC) -o $(EXEC) lex.yy.c y.tab.c $(CFLAGS)

lex.yy.c:
	flex ANSI-C.l

y.tab:
	bison -d structfe.y
	mv structfe.tab.h y.tab.h
	mv structfe.tab.c y.tab.c

clean:
	rm y.tab.c lex.yy.c y.tab.h

tests:
	chmod +x ./mktests.sh
	./mktests.sh
