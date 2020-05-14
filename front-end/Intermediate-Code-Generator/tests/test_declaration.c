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

void stack_declaration (struct stack_t *);
void declaration (struct stack_t *, FILE *, unsigned int *);
void print_file (FILE *);

int
main (int 			argc,
	  const char	* argv)
{
	struct stack_t *stk_decl;
	struct stack_t *stk_opr;
	FILE *ofile;
	unsigned int vx;
	unsigned int ax;
	FILE *rdfile;
	char line[1024];

	vx = 0;
	ax = 0;
	ofile = fopen("icg_decl.out", "w+");
	stk_opr = init_stack();
    stk_decl = init_stack();
    stack_declaration(stk_decl);

    for (int i = 0; i < 5; i++)
    {
    	declaration(stk_decl, ofile, &vx);
    	fprintf(ofile, "/* -- %s -- */\n", stk_decl->get(stk_decl, i));
    }
	
    fclose(ofile);
    print_file(rdfile);

	return EXIT_SUCCESS;
}

void
stack_declaration (struct stack_t *stk_decl)
{
    stk_decl->push(stk_decl, "integer");
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "integer_ptr");
    stk_decl->push(stk_decl, "int *");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "integer_function_pointer");
    stk_decl->push(stk_decl, "int p");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "void_pointer");
    stk_decl->push(stk_decl, "void *");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "void_function_pointer");
    stk_decl->push(stk_decl, "void p");
    stk_decl->push(stk_decl, "declaration");
}

void
print_file (FILE *f)
{
	f = fopen("icg_decl.out", "rb");
    while (fgets(line, sizeof(line), f))
    {
    	fprintf(stdout, "%s", line);
    }
    fclose(f);
}

void
declaration (struct stack_t * stk_decl,
			 FILE 			* of,
			 unsigned int 	* v)
{
	char *type;
	
	stk_decl->pop(stk_decl);
	type = stk_decl->pop(stk_decl)->value;

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
	stk_decl->pop(stk_decl);
}

void
operation (struct stack_t 	* stk_decl,
		   struct stack_t 	* stk_opr,
		   FILE 			* of,
		   unsigned int 	* v)
{
	
}