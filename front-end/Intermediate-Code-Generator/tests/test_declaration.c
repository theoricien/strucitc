#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

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



void declaration (struct stack_t *, FILE *, unsigned int *);

int
main (int 			argc,
	  const char	* argv)
{
	struct stack_t *stk;
	FILE *ofile;
	unsigned int vx;
	unsigned int ax;
	FILE *rdfile;
	char line[1024];

	vx = 0;
	ax = 0;
	ofile = fopen("icg_decl.out", "w+");
    stk = init_stack();
    stk->push(stk, "integer");
    stk->push(stk, "int");
    stk->push(stk, "declaration");

    stk->push(stk, "integer_ptr");
    stk->push(stk, "int *");
    stk->push(stk, "declaration");

    stk->push(stk, "integer_function_pointer");
    stk->push(stk, "int p");
    stk->push(stk, "declaration");

    stk->push(stk, "void_pointer");
    stk->push(stk, "void *");
    stk->push(stk, "declaration");

    stk->push(stk, "void_function_pointer");
    stk->push(stk, "void p");
    stk->push(stk, "declaration");

    for (int i = 0; i < 5; i++)
    {
    	declaration(stk, ofile, &vx);
    	fprintf(ofile, "/* -------------- */\n");
    }
	
    fclose(ofile);

    rdfile = fopen("icg_decl.out", "rb");
    while (fgets(line, sizeof(line), rdfile))
    {
    	fprintf(stdout, "%s", line);
    }
    fclose(rdfile);

	return EXIT_SUCCESS;
}

void
declaration (struct stack_t * stk,
			 FILE 			* of,
			 unsigned int 	* v)
{
	char *type;
	
	stk->pop(stk);
	type = stk->pop(stk)->value;

	if (!strcmp(type, "int"))
	{
		fprintf(of, "%s v%d;\n", type, *v);
	}
	else if (!strcmp(type, "void *"))
	{
		fprintf(of, "%s v%d;\n", type, *v);
	}
	else if (!strcmp(type, "void p"))
	{
		fprintf(of, "%s v%d;\n", "void *", *v);
	}
	else if (!strcmp(type, "int *"))
	{
		fprintf(of, "%s v%d;\n", "int", *v);
		*v = *v + 1;
		fprintf(of, "%s v%d = &v%d;\n", "void *", *v, *v - 1);
	}
	else if (!strcmp(type, "int p"))
	{
		fprintf(of, "%s v%d;\n", "int", *v);
		*v = *v + 1;
		fprintf(of, "%s v%d = &v%d;\n", "void *", *v, *v - 1);
		*v = *v + 1;
		fprintf(of, "%s v%d;\n", "void *", *v);
	}
	*v += 1;
	stk->pop(stk);
}