#include "whilestmt.h"

void
while_gen (struct stack_t  * far_stk_decl,
           struct stack_t  * old_stk_stmt,
           struct crpdct_t * far_ct,
           unsigned int    from,    /* while */
           unsigned int    middle,  /* do */
           unsigned int    to,      /* endwhile */
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

    /*
     * from + 0: last v_t of condition expression
     * from + 1: do
     * from + 2: statements begins here
     */
    start_statements = from + 1;
    stk_decl = init_stack();
    new_stk_stmt = old_stk_stmt->clone(old_stk_stmt, middle + 1, to);

    /* Clean & deep clone */
    ct = far_ct->clone(far_ct);
    /* Temporary vX for inside-statement declarations */
    vx = *v;
    *l = *l + 1;

    //if_declaration(stk_decl);

    add_tab(decl_buf, curr_indent);
    decl_buf->add(decl_buf, "goto L%d; L%d: {\n", *l, *l + 1);
    //declaration(stk_decl, ct, decl_buf, &vx, curr_indent + 1);

    /* COMPOUND STATEMENT */
    //old_stk_stmt->print_stack(old_stk_stmt);
    //printf("FROM %x TO %x\n", from, to);
    //new_stk_stmt->print_stack(new_stk_stmt);
    statements(stk_decl, new_stk_stmt, ct, decl_buf, stmt_buf, &vx, l, 0, new_stk_stmt->size, curr_indent + 1);
    add_tab(stmt_buf, curr_indent);
    stmt_buf->add(stmt_buf, "} L%d:\n", *l);
    *l = *l + 1;
}
