#include "ifstmt.h"

/*
 * On copie la _stk_decl et la _stk_stmt
 * dans de nouvelles stacks.
 *
 * Les declarations seront faites en amont
 */
void
if_gen (struct stack_t  * far_stk_decl,
        struct stack_t  * old_stk_stmt,
        struct crpdct_t * far_ct,
        unsigned int    from,
        unsigned int    to,
        unsigned int    * v,
        unsigned int    * l,
        struct buf_t    * decl_buf,
        struct buf_t    * stmt_buf,
        unsigned int    curr_indent)
{
    struct stack_t *stk_decl;
    struct stack_t *new_stk_stmt;
    struct crpdct_t *ct;
    unsigned int vx;
    unsigned int start_statements;
    unsigned int bk_l;

    /*
     * from + 0: last v_t of condition expression
     * from + 1: then
     * from + 2: statements begins here
     */
    start_statements = from + 1;
    stk_decl = init_stack();
    new_stk_stmt = old_stk_stmt->clone(old_stk_stmt, start_statements, to);

    /* Clean & deep clone */
    ct = far_ct->clone(far_ct);
    /* Temporary vX for inside-statement declarations */
    vx = *v;
    bk_l = *l + 1;
    *l = *l + 2;


    //if_declaration(stk_decl);

    add_tab(decl_buf, curr_indent);
    decl_buf->add(decl_buf, "{\n");
    //declaration(stk_decl, ct, decl_buf, &vx, curr_indent + 1);

    /* COMPOUND STATEMENT */
    //old_stk_stmt->print_stack(old_stk_stmt);
    //printf("FROM %x TO %x\n", from, to);
    //new_stk_stmt->print_stack(new_stk_stmt);
    statements(stk_decl, new_stk_stmt, ct, decl_buf, stmt_buf, &vx, l, 0, new_stk_stmt->size, curr_indent + 1);
    add_tab(stmt_buf, curr_indent);
    stmt_buf->add(stmt_buf, "} L%d:\n", bk_l);
}

void
ifelse_gen (struct stack_t  * far_stk_decl,
            struct stack_t  * old_stk_stmt,
            struct crpdct_t * far_ct,
            unsigned int    from,       /* = then + ... + else + ... + endif */
            unsigned int    end_if,     /* = else */
            unsigned int    end_else,   /* = endif */
            unsigned int    * v,
            unsigned int    * l,
            struct buf_t    * ifdecl_buf,
            struct buf_t    * ifstmt_buf,
            struct buf_t    * elsedecl_buf,
            struct buf_t    * elsestmt_buf,
            unsigned int    curr_indent)
{
    struct stack_t *stk_decl;
    struct stack_t *else_stk_stmt;
    struct stack_t *if_stk_stmt;
    struct crpdct_t *ct;
    unsigned int vx;
    unsigned int start_statements;
    unsigned int bk_l;

    /*
     * from + 0: last v_t of condition expression
     * from + 1: then
     * from + 2: statements begins here
     */
    start_statements = from + 1;
    stk_decl = init_stack();
    if_stk_stmt = old_stk_stmt->clone(old_stk_stmt, start_statements, end_if);
    //if_stk_stmt->print_stack(if_stk_stmt);
    else_stk_stmt = old_stk_stmt->clone(old_stk_stmt, end_if + 1, end_else);

    /* Clean & deep clone */
    ct = far_ct->clone(far_ct);
    /* Temporary vX for inside-statement declarations */
    vx = *v;
    bk_l = *l + 1;
    *l = *l + 1;

    /*
     * if (cond) goto Lx;
     * {
     *     cond == false
     * } Lx: {
     *     cond == true
     * }
     */

    /* ELSE PART */
    add_tab(elsedecl_buf, curr_indent);
    elsedecl_buf->add(elsedecl_buf, "{\n");
    statements(stk_decl, else_stk_stmt, ct, elsedecl_buf, elsestmt_buf, &vx, l, 0, else_stk_stmt->size, curr_indent + 1);
    add_tab(elsestmt_buf, curr_indent + 1);
    elsestmt_buf->add(elsestmt_buf, "goto L%d;\n", *l);
    bk_l = *l;
    add_tab(elsestmt_buf, curr_indent);
    elsestmt_buf->add(elsestmt_buf, "} ");

    /* IF PART */
    add_tab(ifdecl_buf, curr_indent);
    ifdecl_buf->add(ifdecl_buf, "L%d: {\n", *l - 1);
    *l += 1;
    statements(stk_decl, if_stk_stmt, ct, ifdecl_buf, ifstmt_buf, &vx, l, 0, if_stk_stmt->size, curr_indent + 1);
    add_tab(ifstmt_buf, curr_indent);
    ifstmt_buf->add(ifstmt_buf, "} L%d:\n", bk_l);
    *l += 1;
}

unsigned int
search_end_cond (struct stack_t * stk,
                 unsigned int   from)
{
    for (size_t i = from; i < stk->size; i++)
        if (!strcmp(stk->get(stk, i)->value, "then"))
            return i;

    return (unsigned int) -1;
}

unsigned int
search_next (struct stack_t * stk,
             unsigned int   from,
             char           * search)
{
    for (size_t i = from; i < stk->size; i++)
        if (!strcmp(stk->get(stk, i)->value, search))
            return i;

    return (unsigned int) -1;
}

void
if_declaration (struct stack_t *stk_decl)
{
    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "a");
    stk_decl->push(stk_decl, "declaration");

    stk_decl->push(stk_decl, "int");
    stk_decl->push(stk_decl, "b");
    stk_decl->push(stk_decl, "declaration");
}
