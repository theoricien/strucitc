CC=gcc
CFLAGS=-ll -lfl
EXEC=strucitbe

all: $(EXEC)

strucitbe: lex.yy.c y.tab
	$(CC) -o $(EXEC) lex.yy.c y.tab.c $(CFLAGS)

lex.yy.c:
	flex ANSI-C.l

y.tab:
	bison -d structbe.y
	mv structbe.tab.h y.tab.h
	mv structbe.tab.c y.tab.c

clean:
	rm y.tab.c lex.yy.c y.tab.h strucitbe

tests:
	chmod +x ./mktests.sh
	./mktests.sh
