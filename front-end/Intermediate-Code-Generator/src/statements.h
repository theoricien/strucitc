#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "declarations.h"
#include "crpdct.h"
#include "ifstmt.h"
#include "fundef.h"
#include "whilestmt.h"
#include "forstmt.h"

void statements (struct stack_t *,
                 struct stack_t *,
                 struct crpdct_t *,
                 struct buf_t *,
                 struct buf_t *,
                 unsigned int *,
                 unsigned int *,
                 unsigned int,
                 unsigned int,
                 unsigned int);

unsigned int search_end_if (struct stack_t *, unsigned int);
unsigned int search_next_else (struct stack_t *, unsigned int);
unsigned int search_end_while (struct stack_t *, unsigned int);
unsigned int search_end_for (struct stack_t *, unsigned int);
unsigned int search_next_semicolon (struct stack_t *, unsigned int);

void arithmetic_gen (struct stack_t *,
                     struct stack_t *,
                     struct crpdct_t *,
                     unsigned int,
                     unsigned int,
                     struct buf_t *,
                     struct buf_t *,
                     unsigned int *,
                     unsigned int *,
                     arithmetic_t,
                     unsigned int);

char *to_one_addr (struct stack_t *,
                   struct stack_t *,
                   struct crpdct_t *,
                   unsigned int,
                   unsigned int *,
                   struct buf_t *,
                   struct buf_t *,
                   char *,
                   unsigned int);

bool_t isidentifier (char *);
bool_t isdigit (char *);
bool_t isuop (char *);
void add_tab (struct buf_t *, unsigned int);

char * sizeof_int (void);
char * sizeof_voidp (void);
#endif // STATEMENTS_H
