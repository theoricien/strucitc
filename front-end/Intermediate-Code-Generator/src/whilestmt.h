#ifndef WHILESTMT_H
#define WHILESTMT_H

#include <stdarg.h>
#include "crpdct.h"
#include "statements.h"

void while_gen (struct stack_t *,
                struct stack_t *,
                struct crpdct_t *,
                unsigned int,
                unsigned int,
                unsigned int,
                unsigned int *,
                unsigned int *,
                struct buf_t *,
                struct buf_t *,
                unsigned int);

#endif // WHILESTMT_H
