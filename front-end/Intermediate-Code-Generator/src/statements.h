#ifndef STATEMENTS_H
#define STATEMENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "declarations.h"
#include "crpdct.h"

void statements (struct stack_t *, struct stack_t *, struct crpdct_t *, FILE *, FILE *, unsigned int *);
unsigned int search_next_semicolon (struct stack_t *, unsigned int);
void arithmetic_gen (struct stack_t *, struct stack_t *, struct crpdct_t *, unsigned int, unsigned int, FILE *, FILE *, unsigned int *);
char *to_one_addr (struct stack_t *, struct stack_t *, struct crpdct_t *, unsigned int, unsigned int *, FILE *, FILE *, char *);
bool_t isidentifier (char *);
bool_t isdigit (char *);

#endif // STATEMENTS_H
