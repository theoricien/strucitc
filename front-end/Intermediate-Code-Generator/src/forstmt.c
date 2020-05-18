#include "forstmt.h"

void
for_gen (struct stack_t  * far_stk_decl,
         struct stack_t  * old_stk_stmt,
         struct crpdct_t * far_ct,
         unsigned int    first_part,    /* for */
         unsigned int    second_part,   /* enddecl */
         unsigned int    third_part,    /* endcond */
         unsigned int    dofor,         /* endstep */
         unsigned int    endfor,        /* endfor */
         unsigned int    * v,
         unsigned int    * l,
         struct buf_t    * decl_buf,
         struct buf_t    * stmt_buf,
         struct buf_t    * old_decl_buf,
         struct buf_t    * old_stmt_buf,
         unsigned int    curr_indent)
{
    struct stack_t *stk_decl; /* declarations inside for */
    struct stack_t *new_stk_stmt; /* for body */
    struct stack_t *iteration; /* i++ per example */

    struct crpdct_t *ct;
    unsigned int vx;
    unsigned int start_statements;

    /*
     * first_part + 0: "for"
     * first_part + 1: "expr"
     * first_part + 2: ";" or the expr body
     */

    stk_decl = init_stack();
    new_stk_stmt = old_stk_stmt->clone(old_stk_stmt, dofor + 1, endfor);
    iteration = old_stk_stmt->clone(old_stk_stmt, third_part + 1, dofor);
    new_stk_stmt->push_stack(new_stk_stmt, iteration);
    /* Clean & deep clone */
    ct = far_ct->clone(far_ct);
    /* Temporary vX for inside-statement declarations */
    vx = *v;
    *l = *l + 1;

    /* for (int i = 0; ...) -> int i; i = 0; for(...) */
    statements(far_stk_decl, old_stk_stmt, far_ct, old_decl_buf, old_stmt_buf, v, l, first_part + 1, second_part, curr_indent);
    add_tab(decl_buf, curr_indent);
    decl_buf->add(decl_buf, "goto L%d; L%d: {\n", *l, *l + 1);
    //declaration(stk_decl, ct, decl_buf, &vx, curr_indent + 1);

    /* COMPOUND STATEMENT */
    //old_stk_stmt->print_stack(old_stk_stmt);
    //printf("FROM %x TO %x\n", from, to);
    //new_stk_stmt->print_stack(new_stk_stmt);

    /* = for body + iteration */
    statements(stk_decl, new_stk_stmt, ct, decl_buf, stmt_buf, &vx, l, 0, new_stk_stmt->size, curr_indent + 1);
    add_tab(stmt_buf, curr_indent);
    stmt_buf->add(stmt_buf, "} L%d:\n", *l);
    *l = *l + 1;
}
