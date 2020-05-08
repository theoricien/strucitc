#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void
assert (int 	expr,
	    char 	* msg)
{
	if (!expr)
	{
		fprintf(stderr, "%s", msg);
		exit(2);
	}
}

/* Init struct definitions */

struct mcell_t *
init_mcell (int 	addr,
			char  	* value)
{
	struct mcell_t *tmp;

	tmp = (struct mcell_t *) malloc (sizeof (struct mcell_t));
	assert(tmp != NULL, "Memory error, malloc returns NULL\n");

	tmp->addr = addr;
	tmp->value = strdup(value);
	tmp->print_cell = print_cell;

	return tmp;
}

struct dllist_t *
init_dllist (void)
{
	struct dllist_t *tmp;

	tmp = (struct dllist_t *) malloc (sizeof (struct dllist_t));
	assert(tmp != NULL, "Memory error, malloc returns NULL\n");

	tmp->curr = NULL;
	tmp->prev = NULL;
	tmp->next = NULL;

	return tmp;
}

struct stack_t *
init_stack (void)
{
	struct stack_t *stk;

	stk = (struct stack_t *) malloc (sizeof (struct stack_t));
	assert(stk != NULL, "Memory error, malloc returns NULL\n");

	stk->size = 0;
	stk->bottom = init_dllist();
	stk->top = stk->bottom;

	stk->pop = pop;
	stk->push = push;
	stk->get = get;
	stk->is_empty = is_empty;
	stk->print_stack = print_stack;

	return stk;
}

/* Structs functions definitions */

struct mcell_t 	*
pop (struct stack_t *stk)
{
	struct mcell_t *popped;

	assert(stk != NULL, "NULL stack_t passed as argument");

	if (stk->is_empty(stk))
	{
		fprintf(stderr, "Pop error, empty stack");
		stk->print_stack(stk);
		exit(2);
	}

	popped = stk->top->curr;
	if (stk->size == 1)
    {
        stk->size = 0;
        stk->bottom = init_dllist();
        stk->top = stk->bottom;
    }
    else
    {
        stk->top = stk->top->prev;
        stk->top->next = NULL;
        stk->size--;
    }

	return popped;
}

struct mcell_t 	*
push (struct stack_t *stk,
	  v_t            value)
{
	assert(stk != NULL, "NULL stack_t passed as argument");

	if (stk->is_empty(stk))
	{
		stk->bottom->curr = init_mcell(stk->size, value);
		stk->top = stk->bottom;
	}
	else
	{
	    stk->top->next = init_dllist();
		stk->top->next->curr = init_mcell(stk->size, value);
		stk->top->next->prev = stk->top;

		stk->top = stk->top->next;
	}
    stk->size++;

	return stk->top->curr;
}

struct mcell_t *
get (struct stack_t * stk,
	 int 			index)
{
	struct dllist_t *tmp;
	int 			i;

	assert(stk != NULL, "NULL stack_t passed as argument");
	assert(stk->size >= index, "Index out of range");

	tmp = stk->bottom;
	i = 0;
	while (i++ < index)
        tmp = tmp->next;


	return tmp->curr;
}

bool_t
is_empty (struct stack_t *stk)
{
	return !stk->size;
}

/* Struct debug information definition */

void
print_cell (struct mcell_t *cell)
{
	printf(" 0x%08x -- %s\n", cell->addr, cell->value);
}

void
print_stack (struct stack_t *stk)
{
	struct dllist_t *tmp;
	tmp = stk->top;

	printf("\n          --   ADDR   --  VALUES  --\n");
	while (tmp != NULL)
	{
		if (tmp == stk->bottom)
			printf("bottom => ");
		else if (tmp == stk->top)
			printf("top    => ");
		else
			printf("          ");

        if (tmp->curr)
            print_cell(tmp->curr);
        else
            printf("    NULL    --    NULL    \n");

		tmp = tmp->prev;
	}
	printf("          -------------------------\n");
}
