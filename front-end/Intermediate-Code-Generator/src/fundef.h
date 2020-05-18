#ifndef FUNDEF_H
#define FUNDEF_H

#include <string.h>
#include "stack.h"
#include "declarations.h"
#include "crpdct.h"
#include "ifstmt.h"

/*
 * fun_t contains two attributes.
 * It defines a function definition
 * ot_ret: output type returned
 * it_args: input type arguments
 */
struct fun_t
{
    char         * ot_ret;
    struct buf_t ** it_args;
};

void
fundef_gen (struct stack_t *,
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

struct fun_t * init_fun (char *, struct buf_t **);

#endif // FUNDEF_H
