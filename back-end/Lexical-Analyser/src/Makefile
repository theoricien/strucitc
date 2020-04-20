CC=gcc
CFLAGS=-ll
EXEC=LA

all: $(EXEC)

LA: lex.yy.c
	$(CC) -o $(EXEC) lex.yy.c $(CFLAGS)

lex.yy.c:
	flex ANSI-C.l
clean:
	rm lex.yy.c LA

tests:
	chmod +x ./mktests.sh
	./mktests.sh
