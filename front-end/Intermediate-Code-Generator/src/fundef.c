#include "fundef.h"

void
fundef_gen (struct stack_t  * stk_decl,
            struct stack_t  * stk_stmt,
            struct crpdct_t * ct,
            unsigned int    from,    /* = "func" */
            unsigned int    middle,  /* = "endarg" */
            unsigned int    to,      /* = "endfun" */
            unsigned int    * v,
            unsigned int    * l,
            struct buf_t    * decl_buf,
            struct buf_t    * stmt_buf,
            unsigned int    curr_indent)
{
    /*
     * Representation in statement stack:
     * "func" -> ot_ret -> fun_name -> [ it_argX, it_nameX ]* -> "endfun" -> statements
     * statements = declarations + statements
     */
    char *ot_ret;
    char *fun_name;
    struct buf_t **it_args;
    struct stack_t *new_stk_stmt;
    struct stack_t *arg_stk_decl;
    struct fun_t *fun_attr;
    unsigned int ax;
    unsigned int vx;

    vx = 0;
    ax = 0;
    arg_stk_decl = init_stack();
    /* Function body */
    new_stk_stmt = stk_stmt->clone(stk_stmt, middle + 1, to);
    ot_ret = stk_stmt->get(stk_stmt, from + 1)->value;
    fun_name = stk_stmt->get(stk_stmt, from + 2)->value;
    it_args = (struct buf_t **) malloc (sizeof(struct buf_t) * ((middle - from + 3) / 2));
    fun_attr = init_fun(ot_ret, it_args);

    /* Check ot_ret type */
    if (!strcmp(ot_ret, "int *"))
    {
        /* int foo (int *arg) -> int foo (void *a0) */
        ot_ret = (char *) calloc (strlen("void *") + 1, 1);
        strcpy(ot_ret, "void *");
    }
    else if (!strcmp(ot_ret, "int p"))
    {
        /* int foo (int (*arg)(list)) -> int foo (void *a0) */
        ot_ret = (char *) calloc (strlen("void *") + 1, 1);
        strcpy(ot_ret, "void *");
    }
    else if (!strcmp(ot_ret, "void p"))
    {
        /* int foo (void (*arg)(list)) -> int foo (void *a0) */
        ot_ret = (char *) calloc (strlen("void *") + 1, 1);
        strcpy(ot_ret, "void *");
    }
    /* Else it's void/int/(void *) */

    /* Writing to decl_buf */
    decl_buf->add(decl_buf, "\n%s\n%s (", ot_ret, fun_name);
    /* Adding arguments */
    for (size_t i = 0; i < middle - (from + 3); i += 2, ax++)
    {
        char *type_backend;
        char *arg_name;
        char *be_name; // back-end name

        arg_name = stk_stmt->get(stk_stmt, from + 3 + i + 1)->value;
        /* Argument back-end name is aX */
        be_name = (char *) calloc (10, 1);
        sprintf(be_name, "a%d", ax);
        /* backend = frontend */
        type_backend = stk_stmt->get(stk_stmt, from + 3 + i)->value;

        /* fix backend = backend */
        if (!strcmp(type_backend, "int"))
        {
            /* int foo (int arg) -> int foo (int a0) */
            ct->add(ct, arg_name, be_name);

            arg_stk_decl->push(arg_stk_decl, "int");
            arg_stk_decl->push(arg_stk_decl, be_name);
            arg_stk_decl->push(arg_stk_decl, "declaration");
        }
        else if (!strcmp(type_backend, "int *"))
        {
            /* int foo (int *arg) -> int foo (void *a0) */
            type_backend = (char *) calloc (strlen("void *") + 1, 1);
            strcpy(type_backend, "void *");
            ct->add(ct, arg_name, be_name);

            arg_stk_decl->push(arg_stk_decl, "void *");
            arg_stk_decl->push(arg_stk_decl, be_name);
            arg_stk_decl->push(arg_stk_decl, "declaration");
        }
        else if (!strcmp(type_backend, "int p"))
        {
            /* int foo (int (*arg)(list)) -> int foo (void *a0) */
            type_backend = (char *) calloc (strlen("void *") + 1, 1);
            strcpy(type_backend, "void *");
            ct->add(ct, arg_name, be_name);

            arg_stk_decl->push(arg_stk_decl, "void *");
            arg_stk_decl->push(arg_stk_decl, be_name);
            arg_stk_decl->push(arg_stk_decl, "declaration");
        }
        else if (!strcmp(type_backend, "void *"))
        {
            /* int foo (void *arg) -> int foo (void *a0) */
            ct->add(ct, arg_name, be_name);

            arg_stk_decl->push(arg_stk_decl, "void *");
            arg_stk_decl->push(arg_stk_decl, be_name);
            arg_stk_decl->push(arg_stk_decl, "declaration");
        }
        else if (!strcmp(type_backend, "void p"))
        {
            /* int foo (void (*arg)(list)) -> int foo (void *a0) */
            ct->add(ct, arg_name, be_name);

            arg_stk_decl->push(arg_stk_decl, "void *");
            arg_stk_decl->push(arg_stk_decl, be_name);
            arg_stk_decl->push(arg_stk_decl, "declaration");
        }
        else
        {
            fprintf(stderr, "[Error] type_backend = %s\n", type_backend);
            exit(2);
        }

        /* Change front-end type by back-end type */
        it_args[i] = init_buf();
        //printf("Add to it_args[%d]: %s\n", i, stk_stmt->get(stk_stmt, from + 3 + i)->value);
        it_args[i]->add(it_args[i], "%s", type_backend);

        /* Argument writing */
        decl_buf->add(decl_buf, "%s %s", it_args[i]->string, be_name);
        if (i + 2 < middle - (from + 3))
            decl_buf->add(decl_buf, ", ");
    }
    decl_buf->add(decl_buf, ")\n{\n");
    /* Here the function body begins */
    statements(stk_decl, new_stk_stmt, ct, decl_buf, stmt_buf, &vx, l, 0, new_stk_stmt->size, curr_indent + 1);
    stmt_buf->add(stmt_buf, "}\n");
    for (size_t i = 0; i < (middle - (from + 3)) / 2; i++)
    {
        ct->rm_last(&ct);
    }
}

struct fun_t *
init_fun (char          * otr,
          struct buf_t  ** ita)
{
    struct fun_t *tmp;

    tmp = (struct fun_t *) malloc (sizeof(struct fun_t));
    tmp->ot_ret = strdup(otr);
    tmp->it_args = ita;

    return tmp;
}
