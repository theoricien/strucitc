#ifndef IFSTMT_H
#define IFSTMT_H

#include <stdarg.h>
#include "crpdct.h"
#include "statements.h"

void if_gen (struct stack_t *,
             struct stack_t *,
             struct crpdct_t *,
             unsigned int,
             unsigned int,
             unsigned int *,
             unsigned int *,
             struct buf_t *,
             struct buf_t *,
             unsigned int);

void ifelse_gen (struct stack_t *,
                 struct stack_t *,
                 struct crpdct_t *,
                 unsigned int,
                 unsigned int,
                 unsigned int,
                 unsigned int *,
                 unsigned int *,
                 struct buf_t *,
                 struct buf_t *,
                 struct buf_t *,
                 struct buf_t *,
                 unsigned int);

unsigned int search_end_cond (struct stack_t *, unsigned int);
unsigned int search_next (struct stack_t *, unsigned int, char *);
void if_declaration (struct stack_t *);

#endif // IFSTMT_H
