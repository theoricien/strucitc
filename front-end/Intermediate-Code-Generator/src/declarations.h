#ifndef DECLARATIONS_H
#define DECLARATIONS_H

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "crpdct.h"
#include "ifstmt.h"

void declaration (struct stack_t *, struct crpdct_t *, struct buf_t *, unsigned int *, unsigned int);
char * search_declaration_type (struct stack_t *, unsigned int, unsigned int *);
void variable_declaration (struct stack_t *, struct crpdct_t *, struct buf_t *, unsigned int *, unsigned int, unsigned int, char *);
void function_declaration (struct stack_t *, struct crpdct_t *, struct buf_t *, unsigned int *, unsigned int, unsigned int, char *);


#endif // DECLARATIONS_H
