CC=gcc
CFLAGS=-ll
EXEC=strucitfe

all: $(EXEC)

strucitfe: lex.yy.c y.tab
	@$(CC) -o $(EXEC) lex.yy.c tree.c symbol_table.c semantical_check.c y.tab.c -include tree.h symbol_table.h semantical_check.h $(CFLAGS)

lex.yy.c:
	@flex ANSI-C.l

y.tab: tree.o
	@bison -v -g -d structfe.y
	@mv structfe.tab.h y.tab.h
	@mv structfe.tab.c y.tab.c

tree.o:
	@$(CC) -c tree.c

clean:
	@rm y.tab.c lex.yy.c strucitfe tree.o

tests:
	@chmod +x ./mktests.sh
	@./mktests.sh
