CC=gcc
CFLAGS=-ll -Wbuiltin-declaration-mismatch
EXEC=strucitfe

all: $(EXEC)

strucitfe: lex.yy.c y.tab
	@$(CC) -o $(EXEC) lex.yy.c crpdct.c ifstmt.c stack.c declarations.c statements.c forstmt.c fundef.c whilestmt.c y.tab.c -include crpdct.h declarations.h ifstmt.h stack.h statements.h forstmt.h fundef.h whilestmt.h $(CFLAGS)

lex.yy.c:
	@flex ANSI-C.l

y.tab:
	@bison -v -g -d structfe.y
	@mv structfe.tab.h y.tab.h
	@mv structfe.tab.c y.tab.c

clean:
	@rm y.tab.c lex.yy.c y.tab.h strucitfe structfe.dot structfe.output

tests:
	@chmod +x ./mktests.sh
	@./mktests.sh
