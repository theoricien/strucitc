#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "declarations.h"
#include "statements.h"

/*
 * Types front-end -> back-end:
 * int 			-> 	int
 * int * 		->	int, void *	: int *a; ...; foo(a);	->	int a; void *addr_a = &a; ...; foo(addr_a);
 * int (*)()	->  int, void * : int res; void *res_addr = &res; void *f = &func(res_addr);
 * void 		-> 	void
 * void *		-> 	void *
 * void (*)()	->	void *		: void *f = &func; (void) f();
 *
 * struct {int a; int b;} -> int, int
 *
 * Types back-end:
 * int 		: passage par valeur
 * void *	: passage par addr
 *
 * Variable names:
 * v0, v1, v2, ...
 * Argument names:
 * a0, a1, ...
 * Function names:
 * direct le nom de la fonction
 *
 * Stack representation of front-end types
 * int 			-> 	int
 * int * 		->	int *
 * int (*)()	->  int p
 * void 		-> 	void
 * void *		-> 	void *
 * void (*)()	->	void p
 */

void stack_statement (struct stack_t *);
void stack_declaration (struct stack_t *);
void print_file (const char *);

int
main (int 			argc,
	  const char	* argv [])
{
	struct stack_t *stk_decl;
	struct stack_t *stk_stmt;
	struct crpdct_t *correspondence_table;
	struct buf_t *fdecl;
	struct buf_t *fstmt;
	/* Variable count */
	unsigned int vx;
	/* Label count */
	unsigned int lx;

    lx = 0;
	vx = 0;
	fdecl = init_buf();
	fstmt = init_buf();
	correspondence_table = init_crpcdt();
	stk_stmt = init_stack();
    stk_decl = init_stack();
    stack_declaration(stk_decl);
    stack_statement(stk_stmt);

    declaration(stk_decl, correspondence_table, fdecl, &vx, 0);
    statements(stk_decl, stk_stmt, correspondence_table, fdecl, fstmt, &vx, 0, stk_stmt->size, 0);
    //print_ct(correspondence_table);
    fdecl->add(fdecl, "\n");

    printf("%s%s", fdecl->string, fstmt->string);

	return EXIT_SUCCESS;
}

void
stack_declaration (struct stack_t *stk_decl)
{
    stk_decl->push(stk_decl, "a");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "b");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "c");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "d");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "e");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "f");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");
}

void
stack_statement (struct stack_t *stk_stmt)
{/*
    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "5");
    stk_stmt->push(stk_stmt, ";");

    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "b");
    stk_stmt->push(stk_stmt, "/");
    stk_stmt->push(stk_stmt, "1");
    stk_stmt->push(stk_stmt, "0");
    stk_stmt->push(stk_stmt, ";");

    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "c");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "3");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "1");
    stk_stmt->push(stk_stmt, "2");
    stk_stmt->push(stk_stmt, ";");

    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "d");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "1");
    stk_stmt->push(stk_stmt, "2");
    stk_stmt->push(stk_stmt, "3");
    stk_stmt->push(stk_stmt, ";");

    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "e");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "1");
    stk_stmt->push(stk_stmt, "2");
    stk_stmt->push(stk_stmt, "3");
    stk_stmt->push(stk_stmt, "+");
    stk_stmt->push(stk_stmt, "d");
    stk_stmt->push(stk_stmt, "c");
    stk_stmt->push(stk_stmt, ";");

    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "b");
    stk_stmt->push(stk_stmt, "==");
    stk_stmt->push(stk_stmt, "<");
    stk_stmt->push(stk_stmt, "d");
    stk_stmt->push(stk_stmt, "2");
    stk_stmt->push(stk_stmt, ">");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "3");
    stk_stmt->push(stk_stmt, ";");

    stk_stmt->push(stk_stmt, "if");
    stk_stmt->push(stk_stmt, "==");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "4");
    stk_stmt->push(stk_stmt, "then");
    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "3");
    stk_stmt->push(stk_stmt, ";");
    stk_stmt->push(stk_stmt, "endif");*/

    stk_stmt->push(stk_stmt, "if");
    stk_stmt->push(stk_stmt, "==");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "4");
    stk_stmt->push(stk_stmt, "then");
    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "3");
    stk_stmt->push(stk_stmt, ";");
    stk_stmt->push(stk_stmt, "endif");

    stk_stmt->push(stk_stmt, "if");
    stk_stmt->push(stk_stmt, "1");
    stk_stmt->push(stk_stmt, "then");
    stk_stmt->push(stk_stmt, "if");
    stk_stmt->push(stk_stmt, "==");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "1337");
    stk_stmt->push(stk_stmt, "then");
    stk_stmt->push(stk_stmt, "expr");
    stk_stmt->push(stk_stmt, "=");
    stk_stmt->push(stk_stmt, "a");
    stk_stmt->push(stk_stmt, "42");
    stk_stmt->push(stk_stmt, ";");
    stk_stmt->push(stk_stmt, "endif");
    //stk_stmt->push(stk_stmt, ";");
    stk_stmt->push(stk_stmt, "endif");
}

void
print_file (const char *fname)
{
    FILE *f;
    char line[1024];

	f = fopen(fname, "rb");
    while (fgets(line, sizeof(line), f))
    {
    	fprintf(stdout, "%s", line);
    }
    fclose(f);
}
