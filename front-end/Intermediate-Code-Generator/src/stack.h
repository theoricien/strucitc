#ifndef _STACK_H_
#define _STACK_H_

#include <errno.h>

/*
 * bool_t
 * Type that represents a boolean
 * Values: false: 0, true: 1
 */
typedef enum {false, true} bool_t;
//typedef unsigned int size_t;
typedef char * v_t;


typedef enum {EXPRESSION,
              CONDITION,
              IFEXPR,
              IFELSE,
              WHILE}
        arithmetic_t;

struct buf_t
{
    size_t  size;
    char    * string;

    /* Realloc itself if needed */
    void    (*add) (struct buf_t *, const char *, ...);
    void    (*free) (struct buf_t *);
};

/*
 * mcell_t
 * Type that represents a memory cell
 * addr: Address of the cell
 * value: Value of the cell
 */
struct mcell_t
{
	int		addr;
	v_t  	value;

	void	(*print_cell) (struct mcell_t *);
	void    (*free) (struct mcell_t *);
};

/*
 * dllist_t
 * Type that represents a double linked list
 * curr: Memory cell of the node
 * prev: Previous mcell_t
 * next: Next mcell_t
 */
struct dllist_t
{
	struct mcell_t	* curr;

	struct dllist_t * prev;
	struct dllist_t * next;
	void            (*free) (struct dllist_t *);
};

/*
 * stack_t
 * Type that represents a stack
 * top: Top of the stack
 * bottom: Bottom of the stack
 * pop: Pop the top of the stack and returns the memory cell
 * push: Push the memory cell on the top of the stack
 * get: Get the nth element of the stack memory
 * is_empty: Is the stack empty ?
 * print: Print all the stack for debugging
 */
struct stack_t
{
	struct dllist_t * top;
	struct dllist_t * bottom;
	size_t			size;

	struct mcell_t 	*(*pop) (struct stack_t *);
	struct mcell_t 	*(*push) (struct stack_t *, char *, ...);
	void         	(*push_stack) (struct stack_t *, struct stack_t *);
	struct mcell_t  *(*get) (struct stack_t *, int);
	struct stack_t  *(*clone) (struct stack_t *, size_t, size_t);
	bool_t 			(*is_empty) (struct stack_t *);
	void			(*print_stack) (struct stack_t *);
	void            (*free) (struct stack_t *);
};

void assert (int, const char *, ...);
struct mcell_t *init_mcell (int, char *);
struct dllist_t *init_dllist (void);
struct stack_t *init_stack (void);
struct mcell_t *pop (struct stack_t *);
struct mcell_t *push (struct stack_t *, char *, ...);
void push_stack (struct stack_t *, struct stack_t *);
struct mcell_t *get (struct stack_t *, int);
struct stack_t *_stack_clone (struct stack_t *, size_t, size_t);
bool_t is_empty (struct stack_t *);
void print_cell (struct mcell_t *);
void print_stack (struct stack_t *);
struct buf_t * init_buf (void);
void _buf_add_buf (struct buf_t *, const char *, ...);

void _buf_free (struct buf_t *);
void _mcell_free (struct mcell_t *);
void _dllist_free (struct dllist_t*);
void _stack_free (struct stack_t *);

#endif
