#include "stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define DEBUG 1

void
assert (int 	expr,
	    const char *fmt,
	    ...)
{
	if (!expr)
	{
		fprintf(stderr, "[AssertionError]: ");
		va_list arg;
        va_start(arg, fmt);
        vfprintf(stdout, fmt, arg);
        va_end(arg);
        printf("[Errno]: %s\n", strerror(errno));
        perror("[Perror]: ");
		exit(2);
	}
}

void
debug (const char *fmt, ...)
{
    if (DEBUG)
    {
        va_list arg;
        va_start(arg, fmt);
        vfprintf(stdout, fmt, arg);
        va_end(arg);
    }
}

/* Init struct definitions */

struct mcell_t *
init_mcell (int 	addr,
			char  	* value)
{
	struct mcell_t *tmp;

	tmp = (struct mcell_t *) malloc (sizeof (struct mcell_t));
	assert(tmp != NULL, "Memory error, malloc returns NULL mcell_t\n");

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
	assert(tmp != NULL, "Memory error, malloc returns NULL dllist_t\n");

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
	assert(stk != NULL, "Memory error, malloc returns NULL stack_t\n");

	stk->size = 0;
	stk->bottom = init_dllist();
	stk->top = stk->bottom;

	stk->pop = pop;
	stk->push = push;
	stk->push_stack = push_stack;
	stk->get = get;
	stk->clone = _stack_clone;
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
	//stk->print_stack(stk);
	debug("!stk->is_empty(stk) = %d\n", !stk->is_empty(stk));
	assert(!stk->is_empty(stk), "Pop error, empty stack");

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
push (struct stack_t * stk,
	  char           * fmt,
	  ...)
{
  struct buf_t *buf = init_buf();
	assert(stk != NULL, "NULL stack_t passed as argument");

	va_list arg;
    va_start(arg, fmt);
    vsprintf(buf->string, fmt, arg);
    va_end(arg);

    assert(strlen(buf->string) < buf->size, "Line too long for ICG to push correctly: %s", buf->string);

	if (stk->is_empty(stk))
	{
		stk->bottom->curr = init_mcell(stk->size, buf->string);
		stk->top = stk->bottom;
	}
	else
	{
	    stk->top->next = init_dllist();
		stk->top->next->curr = init_mcell(stk->size, buf->string);
		stk->top->next->prev = stk->top;

		stk->top = stk->top->next;
	}
    stk->size++;

	//stk->print_stack(stk);

	return stk->top->curr;
}

void
push_stack (struct stack_t * stk,
            struct stack_t * to_push)
{
	  //printf("PUSHING\n");
		//to_push->print_stack(to_push);
		//printf("TO\n");
    for (size_t i = 0; i < to_push->size; i++)
    {
        stk->push(stk, to_push->get(to_push, i)->value);
    }
    //stk->print_stack(stk);
}


struct mcell_t *
get (struct stack_t * stk,
	 int 			index)
{
	struct dllist_t *tmp;
	int 			i;

	assert(stk != NULL, "NULL stack_t passed as argument");
	assert(stk->size >= index, "Index out of range: %d out of %d\n", index, stk->size);

	tmp = stk->bottom;
	i = 0;
	while (i++ < index)
        tmp = tmp->next;


	return tmp->curr;
}

struct stack_t *
_stack_clone (struct stack_t    * stk,
              size_t            from,
              size_t            to)
{
    struct stack_t *res;

    res = init_stack();
    for (size_t i = from; i < to; i++)
    {
        res->push(res, stk->get(stk, i)->value);
    }

    return res;
}

bool_t
is_empty (struct stack_t *stk)
{
	return stk->size == 0;
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

void
_buf_add_buf (struct buf_t   * b,
              const char     * fmt,
              ...)
{
    struct buf_t *to_add;
    va_list args;

    to_add = init_buf();

    va_start(args, fmt);
    vsprintf(to_add->string, fmt, args);
    va_end(args);

    while (strlen(to_add->string) + strlen(b->string) > b->size)
    {
        b->string = (char *) realloc(b->string, b->size * 2);
        b->size *= 2;
    }

    sprintf(b->string + strlen(b->string), "%s", to_add->string);
}

struct buf_t *
init_buf (void)
{
    struct buf_t *tmp;

    tmp = (struct buf_t *) malloc (sizeof(struct buf_t));

    tmp->size = 1024;
    tmp->string = (char *) calloc (1024, 1);
    tmp->add = _buf_add_buf;
    tmp->free = _buf_free;

    return tmp;
}

void
_buf_free (struct buf_t * buf)
{
    free(buf->string);
    free(buf);
}
