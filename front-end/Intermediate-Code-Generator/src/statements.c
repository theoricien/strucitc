#include "statements.h"

/*
 * stk_stmt example (grow up to down):
 * ["expr"]
 * ["="]
 * [...]
 * [";"]
 * ["if"]
 * [...]
 * [";"]
 */
void
statements (struct stack_t  * stk_decl,
            struct stack_t  * stk_stmt,
            struct crpdct_t * ct,
            struct buf_t    * fdecl,
            struct buf_t    * fstmt,
            unsigned int    * v,
            unsigned int    * l,
            unsigned int    from,
            unsigned int    to,
            unsigned int    indent)
{
    char *type;
    unsigned int idx;

    for (size_t i = from; i < to; i++)
    {
        type = stk_stmt->get(stk_stmt, i)->value;
        //printf("TYPE: %s -- FROM: %x -- I: %x -- TO: %x\n", type, from, i, to);
        //stk_stmt->print_stack(stk_stmt);
        /* expr -> .... -> ;*/
        /* The semicolon is the end of an expr */
        if (!strcmp(type, "expr"))
        {
            idx = search_next_semicolon(stk_stmt, i);
            arithmetic_gen(stk_decl, stk_stmt, ct, i, idx, fdecl, fstmt, v, l, EXPRESSION, indent);
        }
        /* if -> ... -> then -> ... -> endif */
        else if (!strcmp(type, "if"))
        {
            unsigned int end_cond;
            struct buf_t *decl_buf;
            struct buf_t *stmt_buf;

            decl_buf = init_buf();
            stmt_buf = init_buf();

            /* if (cond) { ... } */
            idx = search_end_if(stk_stmt, i + 1);
            assert(idx != (unsigned int) -1, "if: idx = search_end_if(stk_stmt, i + 1) returns -1\n");
            //printf("endif found at %x\n", idx);

            /* end_cond = "then" */
            end_cond = search_end_cond(stk_stmt, i);
            assert(end_cond != (unsigned int) -1, "if: end_cond = search_end_cond(stk_stmt, i) returns -1");
            //printf("then found at %x\n", end_cond);

            /* CONDITION */
            /* if (condition)*/
            arithmetic_gen(stk_decl, stk_stmt, ct, i, end_cond, fdecl, fstmt, v, l, IFEXPR, indent);
            /* STATEMENT : DECLARATION + STATEMENT */
            /* { code inside if } */
            if_gen(stk_decl, stk_stmt, ct, end_cond, idx, v, l, decl_buf, stmt_buf, indent);

            //printf(decl_buf->string);
            //printf(stmt_buf->string);

            fstmt->add(fstmt, "%s\n", decl_buf->string);
            fstmt->add(fstmt, "%s\n", stmt_buf->string);
        }
        /* if -> ... -> then -> ... -> else -> ... -> endif */
        else if (!strcmp(type, "ifelse"))
        {
            /* if (cond) goto Lx { ... } Lx: { ... } */
            unsigned int end_cond;
            unsigned int else_idx;
            struct buf_t *ifdecl_buf;
            struct buf_t *ifstmt_buf;
            struct buf_t *elsedecl_buf;
            struct buf_t *elsestmt_buf;

            ifdecl_buf = init_buf();
            ifstmt_buf = init_buf();
            elsedecl_buf = init_buf();
            elsestmt_buf = init_buf();

            /* if (cond) { ... } */
            idx = search_end_if(stk_stmt, i + 1);
            assert(idx != (unsigned int) -1, "ifelse: idx = search_end_if(stk_stmt, i + 1) returns -1");
            /* = "then" */
            end_cond = search_next(stk_stmt, i, "then");
            assert(end_cond != (unsigned int) -1, "ifelse: end_cond = search_end_cond(stk_stmt, i) returns -1");
            /* = "else" */
            else_idx = search_next_else(stk_stmt, i + 1);
            assert(else_idx != (unsigned int) -1, "ifelse: else_idx = search_end_cond(stk_stmt, i) returns -1");

            /* CONDITION */
            /* if (condition) goto LX;*/
            arithmetic_gen(stk_decl, stk_stmt, ct, i, end_cond, fdecl, fstmt, v, l, IFELSE, indent);

            /* STATEMENT : DECLARATION + STATEMENT */
            /* { code inside else } LX: { code inside if }*/
            ifelse_gen(stk_decl, stk_stmt, ct, end_cond, else_idx, idx, v, l, ifdecl_buf, ifstmt_buf, elsedecl_buf, elsestmt_buf, indent);

            //printf(ifdecl_buf->string);
            //printf(ifstmt_buf->string);

            fstmt->add(fstmt, "%s\n", elsedecl_buf->string);
            fstmt->add(fstmt, "%s\n", elsestmt_buf->string);
            fstmt->add(fstmt, "%s\n", ifdecl_buf->string);
            fstmt->add(fstmt, "%s\n", ifstmt_buf->string);

            elsedecl_buf->free(elsedecl_buf);
            elsestmt_buf->free(elsestmt_buf);
            ifdecl_buf->free(ifdecl_buf);
            ifstmt_buf->free(ifstmt_buf);
        }
        else if (!strcmp(type, "func"))
        {
            struct buf_t *decl_buf;
            struct buf_t *stmt_buf;
            unsigned int middle;

            decl_buf = init_buf();
            stmt_buf = init_buf();

            middle = search_next(stk_stmt, i, "endarg");
            idx = search_next(stk_stmt, i, "endfun");
            fundef_gen(stk_decl, stk_stmt, ct, i, middle, idx, v, l, decl_buf, stmt_buf, indent);
            fstmt->add(fstmt, "%s\n", decl_buf->string);
            fstmt->add(fstmt, "%s\n", stmt_buf->string);
            print_ct(ct);
        }
        else if (!strcmp(type, "return"))
        {
            idx = search_next_semicolon(stk_stmt, i);
            add_tab(fstmt, indent);
            fstmt->add(fstmt, "return ");
            statements(stk_decl, stk_stmt, ct, fdecl, fstmt, v, l, i + 1, idx, indent);
            fstmt->add(fstmt, "\n");
        }
        else if (!strcmp(type, "while"))
        {
            unsigned int end_cond;
            struct buf_t *decl_buf;
            struct buf_t *stmt_buf;

            decl_buf = init_buf();
            stmt_buf = init_buf();

            /* if (cond) { ... } */
            idx = search_end_while(stk_stmt, i + 1);
            assert(idx != (unsigned int) -1, "idx = search_end_while(stk_stmt, i + 1) returns -1");
            //printf("endif found at %x\n", idx);

            /* end_cond = "then" */
            end_cond = search_next(stk_stmt, i, "do");
            assert(end_cond != (unsigned int) -1, "end_cond = search_end_cond(stk_stmt, i) returns -1");
            //printf("then found at %x\n", end_cond);

            /* goto LX; L(X+1): { While Code } */
            while_gen(stk_decl, stk_stmt, ct, i, end_cond, idx, v, l, decl_buf, stmt_buf, indent);
            /* LX: if (condition) goto L(X+1);*/
            arithmetic_gen(stk_decl, stk_stmt, ct, i, end_cond, decl_buf, stmt_buf, v, l, WHILE, indent);
            //printf(decl_buf->string);
            //printf(stmt_buf->string);

            fstmt->add(fstmt, "%s\n", decl_buf->string);
            fstmt->add(fstmt, "%s\n", stmt_buf->string);
        }
        else if (!strcmp(type, "for"))
        {
            unsigned int second_part;
            unsigned int third_part;
            unsigned int dofor;
            struct buf_t *decl_buf;
            struct buf_t *stmt_buf;

            decl_buf = init_buf();
            stmt_buf = init_buf();

            second_part = search_next(stk_stmt, i, "enddecl");
            assert(second_part != (unsigned int) -1, "second_part = search_next(stk_stmt, i, \"enddecl\") returns -1");

            third_part = search_next(stk_stmt, i, "endcond");
            assert(third_part != (unsigned int) -1, "third_part = search_next(stk_stmt, i, \"endcond\") returns -1");

            dofor = search_next(stk_stmt, i, "endstep");
            assert(dofor != (unsigned int) -1, "dofor = search_next(stk_stmt, i, \"endstep\") returns -1");

            idx = search_end_for(stk_stmt, i + 1);
            assert(idx != (unsigned int) -1, "idx = search_end_if(stk_stmt, i + 1) returns -1");

            /* goto LX; L(X+1): { While Code } */
            for_gen(stk_decl, stk_stmt, ct, i, second_part, third_part, dofor, idx, v, l, decl_buf, stmt_buf, fdecl, fstmt, indent);
            /* LX: if (condition) goto L(X+1);*/
            arithmetic_gen(stk_decl, stk_stmt, ct, second_part + 1, third_part, decl_buf, stmt_buf, v, l, WHILE, indent);
            //printf(decl_buf->string);
            //printf(stmt_buf->string);

            fstmt->add(fstmt, "%s\n", decl_buf->string);
            fstmt->add(fstmt, "%s\n", stmt_buf->string);
        }
        else
        {
            fprintf(stderr, "[TypeError] Type not found: %s at from 0x%08x with i = 0x%08x\n", type, from, i);
            stk_stmt->print_stack(stk_stmt);
            exit(2);
        }
        i = idx;
    }
        /*
        else if (!strcmp(type, "while"))
        {
        }
        else if (!strcmp(type, "for"))
        {

        }*/

}

unsigned int
search_end_if (struct stack_t   * stk,
               unsigned int     current_index)
{
    //stk->print_stack(stk);
    //printf("for (size_t i = %d; i < %d; i++)\n", current_index, stk->size);
    for (size_t i = current_index; i < stk->size; i++)
    {
        //printf("i = %x with %s\n", i, stk->get(stk, i)->value);
        if (!strcmp(stk->get(stk, i)->value, "if") ||
            !strcmp(stk->get(stk, i)->value, "ifelse"))
        {
            //printf("if/ifelse found\n");
            i = search_end_if(stk, i + 1);
            continue;
        }

        if (!strcmp(stk->get(stk, i)->value, "endif"))
        {
            //printf("End at: %d\n", i);
            return i;
        }
    }
    //printf("Returns -1 !!\n");
    return (unsigned int)-1;
}

unsigned int
search_next_else (struct stack_t   * stk,
                  unsigned int     current_index)
{
    //stk->print_stack(stk);
    //printf("for (size_t i = %x; i < %x; i++)\n", current_index, stk->size);
    for (size_t i = current_index; i < stk->size; i++)
    {
        //printf("i = %x with %s\n", i, stk->get(stk, i)->value);
        if (!strcmp(stk->get(stk, i)->value, "ifelse"))
        {
            //printf("if/ifelse found\n");
            i = search_next_else(stk, i + 1);
            continue;
        }

        if (!strcmp(stk->get(stk, i)->value, "else"))
        {
            //printf("End at: %x\n", i);
            return i;
        }
    }
    //printf("Returns -1 !!\n");
    return (unsigned int)-1;
}

unsigned int
search_end_while (struct stack_t   * stk,
                  unsigned int     current_index)
{
    //stk->print_stack(stk);
    //printf("for (size_t i = %d; i < %d; i++)\n", current_index, stk->size);
    for (size_t i = current_index; i < stk->size; i++)
    {
        //printf("i = %x with %s\n", i, stk->get(stk, i)->value);
        if (!strcmp(stk->get(stk, i)->value, "while"))
        {
            i = search_end_while(stk, i + 1);
            continue;
        }

        if (!strcmp(stk->get(stk, i)->value, "endwhile"))
        {
            //printf("End at: %d\n", i);
            return i;
        }
    }
    //printf("Returns -1 !!\n");
    return (unsigned int) -1;
}

unsigned int
search_end_for (struct stack_t   * stk,
                unsigned int     current_index)
{
    //stk->print_stack(stk);
    //printf("for (size_t i = %d; i < %d; i++)\n", current_index, stk->size);
    for (size_t i = current_index; i < stk->size; i++)
    {
        //printf("i = %x with %s\n", i, stk->get(stk, i)->value);
        if (!strcmp(stk->get(stk, i)->value, "for"))
        {
            i = search_end_for(stk, i + 1);
            continue;
        }

        if (!strcmp(stk->get(stk, i)->value, "endfor"))
        {
            //printf("End at: %d\n", i);
            return i;
        }
    }
    //printf("Returns -1 !!\n");
    return (unsigned int) -1;
}

unsigned int
search_next_semicolon (struct stack_t   * stk,
                       unsigned int     current_index)
{
    for (size_t i = current_index; i < stk->size; i++)
        if (!strcmp(stk->get(stk, i)->value, ";"))
            return i;

    return (unsigned int)-1;
}

/*
 * Modifie stk_stmt & stk_decl pour avoir uniquement un code à 3 adresses
 */
void
arithmetic_gen (struct stack_t  * stk_decl,
                struct stack_t  * stk_stmt,
                struct crpdct_t * ct,
                unsigned int    from,
                unsigned int    to,
                struct buf_t    * fdecl,
                struct buf_t    * fstmt,
                unsigned int    * vx,
                unsigned int    * lx,
                arithmetic_t    output_type,
                unsigned int    indent)
{
    register char *expr_type;
    register char *variable_name;

    expr_type = stk_stmt->get(stk_stmt, from + 1)->value;
    variable_name = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2)->value);
    //print_ct(ct);

    if (!strcmp(expr_type, "="))
    {
        register char *assignement_type;

        assignement_type = stk_stmt->get(stk_stmt, from + 3)->value;

        if (!strcmp(assignement_type, "+") ||
            !strcmp(assignement_type, "-") ||
            !strcmp(assignement_type, "*") ||
            !strcmp(assignement_type, "/") ||
            !strcmp(assignement_type, "==") ||
            !strcmp(assignement_type, "!=") ||
            !strcmp(assignement_type, "<=") ||
            !strcmp(assignement_type, ">=") ||
            !strcmp(assignement_type, "<") ||
            !strcmp(assignement_type, ">"))
        {
            unsigned int end_left_operand = 0;
            unsigned int end_right_operand = 0;
            char *left_operand;
            char *right_operand;

            if (isdigit(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                //debug("Left side constant found: %s\n", stk_stmt->get(stk_stmt, from + 4)->value);
                end_left_operand = from + 5;
                left_operand = stk_stmt->get(stk_stmt, from + 4)->value;
            }
            else if (isuop(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                end_left_operand = from + 6;
                char *uop = stk_stmt->get(stk_stmt, from + 4)->value;
                struct buf_t *buf = init_buf();
                left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 5)->value);
                buf->add(buf, "%c%s", uop[1], left_operand);
                left_operand = buf->string;
            }
            else if (isidentifier(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                end_left_operand = from + 5;
                left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 4)->value);
            }
            else
            {
                struct mcell_t *left_cell_operand = init_mcell(0, variable_name);
                left_cell_operand->value = (char *) malloc (strlen(variable_name) + 2);
                strcpy(left_cell_operand->value, variable_name);
                strcat(left_cell_operand->value, "l");
                /* v0 -> v0l (=v0 left)*/
                if (find_fe_of(ct, left_cell_operand->value) == NULL)
                {
                    stk_decl->push(stk_decl, left_cell_operand->value);
                    stk_decl->push(stk_decl, "int");
                    stk_decl->push(stk_decl, "declaration");
                    ct->add(ct, left_cell_operand->value, left_cell_operand->value);
                    add_tab(fdecl, indent);
                    fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
                }
                /* left_operand = v0l */
                left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 4, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
            }

            if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
            }
            else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
                struct buf_t *buf = init_buf();
                right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                buf->add(buf, "%c%s", uop[1], right_operand);
                right_operand = buf->string;
            }
            else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand)->value);
            }
            else
            {
                struct mcell_t *right_cell_operand = init_mcell(0, variable_name);
                right_cell_operand->value = (v_t) malloc (strlen(variable_name) + 2);
                strcpy(right_cell_operand->value, variable_name);
                strcat(right_cell_operand->value, "r");
                /* v0 -> v0r (=v0 right)*/
                if (find_fe_of(ct, right_cell_operand->value) == NULL)
                {
                  stk_decl->push(stk_decl, right_cell_operand->value);
                  stk_decl->push(stk_decl, "int");
                  stk_decl->push(stk_decl, "declaration");
                  ct->add(ct, right_cell_operand->value, right_cell_operand->value);
                  add_tab(fdecl, indent);
                  fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);
                }

                /* right_operand = v0r */
                right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value, indent);
            }

            to = end_right_operand + 1;

            switch (output_type)
            {
                case EXPRESSION:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "%s = %s %s %s;\n", variable_name, left_operand, assignement_type, right_operand);
                    break;
                case CONDITION:
                    fstmt->add(fstmt, "%s = %s %s %s", variable_name, left_operand, assignement_type, right_operand);
                    break;
                case IFEXPR:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s %s %s) goto L%d; goto L%d; L%d:\n", variable_name, left_operand, assignement_type, right_operand, *lx, *lx + 1, *lx);
                    break;
                case IFELSE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s %s %s) goto L%d;\n", variable_name, left_operand, assignement_type, right_operand, *lx);
                    break;
                case WHILE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s %s %s) goto L%d;\n", variable_name, left_operand, assignement_type, right_operand, *lx);
                    break;
                default:
                    fstmt->add(fstmt, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                    break;
            }

        }
        else if (!strcmp(assignement_type, "&&"))
        {
            unsigned int end_left_operand = 0;
            unsigned int end_right_operand = 0;
            char *left_operand;
            char *right_operand;

            if (isdigit(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                //debug("Left side constant found: %s\n", stk_stmt->get(stk_stmt, from + 4)->value);
                end_left_operand = from + 5;
                left_operand = stk_stmt->get(stk_stmt, from + 4)->value;
            }
            else if (isuop(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                end_left_operand = from + 6;
                char *uop = stk_stmt->get(stk_stmt, from + 4)->value;
                struct buf_t *buf = init_buf();
                left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 5)->value);
                buf->add(buf, "%c%s", uop[1], left_operand);
                left_operand = buf->string;
            }
            else if (isidentifier(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                end_left_operand = from + 5;
                left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 4)->value);
            }
            else
            {
                struct mcell_t *left_cell_operand = init_mcell(0, variable_name);
                left_cell_operand->value = (char *) malloc (strlen(variable_name) + 2);
                strcpy(left_cell_operand->value, variable_name);
                strcat(left_cell_operand->value, "l");
                /* v0 -> v0l (=v0 left)*/
                if (find_fe_of(ct, left_cell_operand->value) == NULL)
                {
                    stk_decl->push(stk_decl, left_cell_operand->value);
                    stk_decl->push(stk_decl, "int");
                    stk_decl->push(stk_decl, "declaration");
                    ct->add(ct, left_cell_operand->value, left_cell_operand->value);
                    add_tab(fdecl, indent);
                    fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
                }
                /* left_operand = v0l */
                left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 4, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
            }

            if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
            }
            else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
                struct buf_t *buf = init_buf();
                right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                buf->add(buf, "%c%s", uop[1], right_operand);
                right_operand = buf->string;
            }
            else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand)->value);
            }
            else
            {
                struct mcell_t *right_cell_operand = init_mcell(0, variable_name);
                right_cell_operand->value = (v_t) malloc (strlen(variable_name) + 2);
                strcpy(right_cell_operand->value, variable_name);
                strcat(right_cell_operand->value, "r");
                /* v0 -> v0r (=v0 right)*/
                if (find_fe_of(ct, right_cell_operand->value) == NULL)
                {
                  stk_decl->push(stk_decl, right_cell_operand->value);
                  stk_decl->push(stk_decl, "int");
                  stk_decl->push(stk_decl, "declaration");
                  ct->add(ct, right_cell_operand->value, right_cell_operand->value);
                  add_tab(fdecl, indent);
                  fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);
                }

                /* right_operand = v0r */
                right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value, indent);
            }

            to = end_right_operand + 1;

            switch (output_type)
            {
                case EXPRESSION:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "%s = and(%s, %s);\n", variable_name, left_operand, right_operand);
                    break;
                case CONDITION:
                    fstmt->add(fstmt, "%s = and(%s, %s)", variable_name, left_operand, right_operand);
                    break;
                case IFEXPR:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = and(%s, %s)) goto L%d; goto L%d; L%d:\n", variable_name, left_operand, right_operand, *lx, *lx + 1, *lx);
                    break;
                case IFELSE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = and(%s, %s)) goto L%d;\n", variable_name, left_operand, right_operand, *lx);
                    break;
                case WHILE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = and(%s, %s)) goto L%d;\n", variable_name, left_operand, right_operand, *lx);
                    break;
                default:
                    fstmt->add(fstmt, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                    break;
            }
        }
        else if (!strcmp(assignement_type, "||"))
        {
            unsigned int end_left_operand = 0;
            unsigned int end_right_operand = 0;
            char *left_operand;
            char *right_operand;

            if (isdigit(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                //debug("Left side constant found: %s\n", stk_stmt->get(stk_stmt, from + 4)->value);
                end_left_operand = from + 5;
                left_operand = stk_stmt->get(stk_stmt, from + 4)->value;
            }
            else if (isuop(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                end_left_operand = from + 6;
                char *uop = stk_stmt->get(stk_stmt, from + 4)->value;
                struct buf_t *buf = init_buf();
                left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 5)->value);
                buf->add(buf, "%c%s", uop[1], left_operand);
                left_operand = buf->string;
            }
            else if (isidentifier(stk_stmt->get(stk_stmt, from + 4)->value))
            {
                end_left_operand = from + 5;
                left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 4)->value);
            }
            else
            {
                struct mcell_t *left_cell_operand = init_mcell(0, variable_name);
                left_cell_operand->value = (char *) malloc (strlen(variable_name) + 2);
                strcpy(left_cell_operand->value, variable_name);
                strcat(left_cell_operand->value, "l");
                /* v0 -> v0l (=v0 left)*/
                if (find_fe_of(ct, left_cell_operand->value) == NULL)
                {
                    stk_decl->push(stk_decl, left_cell_operand->value);
                    stk_decl->push(stk_decl, "int");
                    stk_decl->push(stk_decl, "declaration");
                    ct->add(ct, left_cell_operand->value, left_cell_operand->value);
                    add_tab(fdecl, indent);
                    fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
                }
                /* left_operand = v0l */
                left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 4, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
            }

            if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
            }
            else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
                struct buf_t *buf = init_buf();
                right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                buf->add(buf, "%c%s", uop[1], right_operand);
                right_operand = buf->string;
            }
            else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand)->value);
            }
            else
            {
                struct mcell_t *right_cell_operand = init_mcell(0, variable_name);
                right_cell_operand->value = (v_t) malloc (strlen(variable_name) + 2);
                strcpy(right_cell_operand->value, variable_name);
                strcat(right_cell_operand->value, "r");
                /* v0 -> v0r (=v0 right)*/
                if (find_fe_of(ct, right_cell_operand->value) == NULL)
                {
                  stk_decl->push(stk_decl, right_cell_operand->value);
                  stk_decl->push(stk_decl, "int");
                  stk_decl->push(stk_decl, "declaration");
                  ct->add(ct, right_cell_operand->value, right_cell_operand->value);
                  add_tab(fdecl, indent);
                  fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);
                }

                /* right_operand = v0r */
                right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value, indent);
            }

            to = end_right_operand + 1;

            switch (output_type)
            {
                case EXPRESSION:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "%s = or(%s, %s);\n", variable_name, left_operand, right_operand);
                    break;
                case CONDITION:
                    fstmt->add(fstmt, "%s = or(%s, %s)", variable_name, left_operand, right_operand);
                    break;
                case IFEXPR:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = or(%s, %s)) goto L%d; goto L%d; L%d:\n", variable_name, left_operand, right_operand, *lx, *lx + 1, *lx);
                    break;
                case IFELSE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = or(%s, %s)) goto L%d;\n", variable_name, left_operand, right_operand, *lx);
                    break;
                case WHILE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = or(%s, %s)) goto L%d;\n", variable_name, left_operand, right_operand, *lx);
                    break;
                default:
                    fstmt->add(fstmt, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                    break;
            }
        }
        else if (!strcmp(assignement_type, "sizeof"))
        {
            fstmt->add(fstmt, "%s = %s; /* sizeof */\n", variable_name, sizeof_int());
        }
        else if (!strcmp(assignement_type, "funcall"))
        {
            unsigned int end;
            /*
            * from + 4 = function name
            * from + 5 = expression
            * from + 5 + len(expression) = endfuncall
            */

            end = search_next(stk_stmt, from + 5, "endfuncall") - 1;
            add_tab(fstmt, indent);
            fstmt->add(fstmt, "%s = %s (", variable_name, stk_stmt->get(stk_stmt, from + 4)->value);
            arithmetic_gen(stk_decl, stk_stmt, ct, from + 5, end, fdecl, fstmt, vx, lx, CONDITION, indent);
            fstmt->add(fstmt, ");\n");
            to = end + 3;
        }
        /* *x = ??? */
        else if (isuop(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            char *uop = stk_stmt->get(stk_stmt, from + 2)->value;
            struct buf_t *buf = init_buf();
            char *vxt = (char *) calloc (10, 1);
            char *right;
            sprintf(vxt, "v%dt", *vx);
            *vx = *vx + 1;
            variable_name = find_be_of(ct, stk_stmt->get(stk_stmt, from + 3)->value);
            buf->add(buf, "%c%s", uop[1], variable_name);
            variable_name = buf->string;

            stk_decl->push(stk_decl, "int");
            stk_decl->push(stk_decl, "vxt");
            stk_decl->push(stk_decl, "declaration");
            add_tab(fdecl, indent);
            fdecl->add(fdecl, "int %s;\n", vxt);
            right = to_one_addr(stk_decl, stk_stmt, ct, from + 4, &to, fdecl, fstmt, vxt, indent);
            add_tab(fstmt, indent);
            fstmt->add(fstmt, "%s = %s;\n", variable_name, right);
        }
        else if (isdigit(assignement_type) ||
                 isidentifier(assignement_type))
        {
            switch (output_type)
            {
                case EXPRESSION:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "%s = %s;\n", variable_name, assignement_type);
                    break;
                case CONDITION:
                    fstmt->add(fstmt, "%s = %s", variable_name, assignement_type);
                    break;
                case IFEXPR:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s) goto L%d; goto L%d; L%d:\n", variable_name, assignement_type, *lx, *lx + 1, *lx);
                    break;
                case IFELSE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s) goto L%d;\n", variable_name, assignement_type, *lx);
                    break;
                case WHILE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s) goto L%d;\n", variable_name, assignement_type, *lx);
                    break;
                default:
                    fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                    break;
            }
        }
        else
        {
            fprintf(stderr, "[!] Operator not recognized in the assignment expression: %s\n", assignement_type);
        }
    }
    else if (!strcmp(expr_type, "==") ||
             !strcmp(expr_type, "!=") ||
             !strcmp(expr_type, "<=") ||
             !strcmp(expr_type, ">=") ||
             !strcmp(expr_type, "<") ||
             !strcmp(expr_type, ">"))
    {
        register char *variable_name;

        unsigned int end_left_operand = 0;
        unsigned int end_right_operand = 0;
        char *left_operand;
        char *right_operand;

        variable_name = (char *) malloc (256);
        sprintf(variable_name, "v%d", *vx);
        *vx = *vx + 1;

        /* 3 > X */
        if (isdigit(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            //debug("Left side constant found: %s\n", stk_stmt->get(stk_stmt, from + 4)->value);
            end_left_operand = from + 3;
            left_operand = stk_stmt->get(stk_stmt, from + 2)->value;
        }
        else if (isuop(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            end_left_operand = from + 1;
            char *uop = stk_stmt->get(stk_stmt, from + 2)->value;
            struct buf_t *buf = init_buf();
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2 + 1)->value);
            buf->add(buf, "%c%s", uop[1], left_operand);
            left_operand = buf->string;
        }
        /* var < X*/
        else if (isidentifier(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            end_left_operand = from + 3;
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2)->value);
        }
        /* 3 + var != X */
        else
        {
            struct mcell_t *left_cell_operand = init_mcell(0, variable_name);
            left_cell_operand->value = (char *) malloc (strlen(variable_name) + 2);
            strcpy(left_cell_operand->value, variable_name);
            strcat(left_cell_operand->value, "l");
            /* v0 -> v0l (=v0 left)*/
            if (find_fe_of(ct, left_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, left_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, left_cell_operand->value, left_cell_operand->value);
              add_tab(fdecl, indent);
              fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
            }
            /* left_operand = v0l */
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 2, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
        }

        if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
        }
        else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
            struct buf_t *buf = init_buf();
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            buf->add(buf, "%c%s", uop[1], right_operand);
            right_operand = buf->string;
        }
        else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
        }
        else
        {
            struct mcell_t *right_cell_operand = init_mcell(0, variable_name);
            right_cell_operand->value = (v_t) malloc (strlen(variable_name) + 2);
            strcpy(right_cell_operand->value, variable_name);
            strcat(right_cell_operand->value, "r");
            /* v0 -> v0r (=v0 right)*/
            if (find_fe_of(ct, right_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, right_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, right_cell_operand->value, right_cell_operand->value);
              add_tab(fdecl, indent);
              fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);
            }
            /* right_operand = v0r */
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value, indent);
        }

        to = end_right_operand + 1;

        switch (output_type)
        {
            case EXPRESSION:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "%s %s %s;\n", left_operand, expr_type, right_operand);
                break;
            case CONDITION:
                fstmt->add(fstmt, "%s %s %s", left_operand, expr_type, right_operand);
                break;
            case IFEXPR:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s %s %s) goto L%d; goto L%d; L%d:\n", left_operand, expr_type, right_operand, *lx, *lx + 1, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s %s %s) goto L%d;\n", left_operand, expr_type, right_operand, *lx);
                break;
            case WHILE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s %s %s) goto L%d;\n", left_operand, expr_type, right_operand, *lx);
                break;
            default:
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
        }
    }
    else if (!strcmp(expr_type, "&&"))
    {
        register char *variable_name;

        unsigned int end_left_operand = 0;
        unsigned int end_right_operand = 0;
        char *left_operand;
        char *right_operand;

        variable_name = (char *) malloc (256);
        sprintf(variable_name, "v%d", *vx);
        *vx = *vx + 1;

        /* 3 > X */
        if (isdigit(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            //debug("Left side constant found: %s\n", stk_stmt->get(stk_stmt, from + 4)->value);
            end_left_operand = from + 3;
            left_operand = stk_stmt->get(stk_stmt, from + 2)->value;
        }
        else if (isuop(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            end_left_operand = from + 1;
            char *uop = stk_stmt->get(stk_stmt, from + 2)->value;
            struct buf_t *buf = init_buf();
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2 + 1)->value);
            buf->add(buf, "%c%s", uop[1], left_operand);
            left_operand = buf->string;
        }
        /* var < X*/
        else if (isidentifier(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            end_left_operand = from + 3;
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2)->value);
        }
        /* 3 + var != X */
        else
        {
            struct mcell_t *left_cell_operand = init_mcell(0, variable_name);
            left_cell_operand->value = (char *) malloc (strlen(variable_name) + 2);
            strcpy(left_cell_operand->value, variable_name);
            strcat(left_cell_operand->value, "l");
            /* v0 -> v0l (=v0 left)*/
            if (find_fe_of(ct, left_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, left_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, left_cell_operand->value, left_cell_operand->value);
              add_tab(fdecl, indent);
              fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
            }
            /* left_operand = v0l */
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 2, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
        }

        if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
        }
        else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
            struct buf_t *buf = init_buf();
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            buf->add(buf, "%c%s", uop[1], right_operand);
            right_operand = buf->string;
        }
        else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
        }
        else
        {
            struct mcell_t *right_cell_operand = init_mcell(0, variable_name);
            right_cell_operand->value = (v_t) malloc (strlen(variable_name) + 2);
            strcpy(right_cell_operand->value, variable_name);
            strcat(right_cell_operand->value, "r");
            /* v0 -> v0r (=v0 right)*/
            if (find_fe_of(ct, right_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, right_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, right_cell_operand->value, right_cell_operand->value);
              add_tab(fdecl, indent);
              fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);
            }
            /* right_operand = v0r */
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value, indent);
        }

        to = end_right_operand + 1;

        switch (output_type)
        {
            case EXPRESSION:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "and(%s, %s);\n", left_operand, right_operand);
                break;
            case CONDITION:
                fstmt->add(fstmt, "and(%s, %s)", left_operand, right_operand);
                break;
            case IFEXPR:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (and(%s, %s)) goto L%d; goto L%d; L%d:\n", left_operand, right_operand, *lx, *lx + 1, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (and(%s, %s)) goto L%d;\n", left_operand, right_operand, *lx);
                break;
            case WHILE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (and(%s, %s)) goto L%d;\n", left_operand, right_operand, *lx);
                break;
            default:
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
        }
    }
    else if (!strcmp(expr_type, "||"))
    {
        register char *variable_name;

        unsigned int end_left_operand = 0;
        unsigned int end_right_operand = 0;
        char *left_operand;
        char *right_operand;

        variable_name = (char *) malloc (256);
        sprintf(variable_name, "v%d", *vx);
        *vx = *vx + 1;

        /* 3 > X */
        if (isdigit(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            //debug("Left side constant found: %s\n", stk_stmt->get(stk_stmt, from + 4)->value);
            end_left_operand = from + 3;
            left_operand = stk_stmt->get(stk_stmt, from + 2)->value;
        }
        else if (isuop(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            end_left_operand = from + 1;
            char *uop = stk_stmt->get(stk_stmt, from + 2)->value;
            struct buf_t *buf = init_buf();
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2 + 1)->value);
            buf->add(buf, "%c%s", uop[1], left_operand);
            left_operand = buf->string;
        }
        /* var < X*/
        else if (isidentifier(stk_stmt->get(stk_stmt, from + 2)->value))
        {
            end_left_operand = from + 3;
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 2)->value);
        }
        /* 3 + var != X */
        else
        {
            struct mcell_t *left_cell_operand = init_mcell(0, variable_name);
            left_cell_operand->value = (char *) malloc (strlen(variable_name) + 2);
            strcpy(left_cell_operand->value, variable_name);
            strcat(left_cell_operand->value, "l");
            /* v0 -> v0l (=v0 left)*/
            if (find_fe_of(ct, left_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, left_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, left_cell_operand->value, left_cell_operand->value);
              add_tab(fdecl, indent);
              fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
            }
            /* left_operand = v0l */
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 2, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
        }

        if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
        }
        else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
            struct buf_t *buf = init_buf();
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            buf->add(buf, "%c%s", uop[1], right_operand);
            right_operand = buf->string;
        }
        else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
        }
        else
        {
            struct mcell_t *right_cell_operand = init_mcell(0, variable_name);
            right_cell_operand->value = (v_t) malloc (strlen(variable_name) + 2);
            strcpy(right_cell_operand->value, variable_name);
            strcat(right_cell_operand->value, "r");
            /* v0 -> v0r (=v0 right)*/
            if (find_fe_of(ct, right_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, right_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, right_cell_operand->value, right_cell_operand->value);
              add_tab(fdecl, indent);
              fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);
            }
            /* right_operand = v0r */
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value, indent);
        }

        to = end_right_operand + 1;

        switch (output_type)
        {
            case EXPRESSION:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "or(%s, %s);\n", left_operand, right_operand);
                break;
            case CONDITION:
                fstmt->add(fstmt, "or(%s, %s)", left_operand, right_operand);
                break;
            case IFEXPR:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (or(%s, %s)) goto L%d; goto L%d; L%d:\n", left_operand, right_operand, *lx, *lx + 1, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (or(%s, %s)) goto L%d;\n", left_operand, right_operand, *lx);
                break;
            case WHILE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (or(%s, %s)) goto L%d;\n", left_operand, right_operand, *lx);
                break;
            default:
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
        }
    }
    else if (!strcmp(expr_type, "sizeof"))
    {
        fstmt->add(fstmt, "%s;\n", sizeof_int());
    }
    else if (!strcmp(expr_type, "funcall"))
    {
        unsigned int end;
        /*
            * from + 4 = function name
            * from + 5 = expression
            * from + 5 + len(expression) = endfuncall
            */
        end = search_next(stk_stmt, from + 2, "endfuncall") - 1;
        add_tab(fstmt, indent);
        fstmt->add(fstmt, "%s (", stk_stmt->get(stk_stmt, from + 2)->value);
        arithmetic_gen(stk_decl, stk_stmt, ct, from + 3, end, fdecl, fstmt, vx, lx, CONDITION, indent);
        fstmt->add(fstmt, ");\n");
    }
    else if (isuop(expr_type))
    {
        char *uop = expr_type;
        struct buf_t *buf = init_buf();
        variable_name = find_be_of(ct, stk_stmt->get(stk_stmt, from + 1 + 1)->value);
        buf->add(buf, "%c%s", uop[1], variable_name);
        variable_name = buf->string;
        switch (output_type)
        {
            case EXPRESSION:
                fstmt->add(fstmt, "%s;", variable_name);
                break;
            case CONDITION:
                fstmt->add(fstmt, "%s", variable_name);
                break;
            case IFEXPR:
                add_tab(fstmt, indent);
                //printf("indent for if (%s) = %d\n", op, indent);
                fstmt->add(fstmt, "if (%s) goto L%d; goto L%d; L%d:\n", variable_name, *lx, *lx + 1, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s) goto L%d;\n", variable_name, *lx);
                break;
            case WHILE:
                add_tab(fstmt, indent);
                //printf("indent for if (%s) = %d\n", expr_type, indent);
                fstmt->add(fstmt, "if (%s) goto L%d;\n", variable_name, *lx);
                break;
            default:
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
        }
    }
    else if (isdigit(expr_type) ||
             isidentifier(expr_type))
    {
        switch (output_type)
        {
            case EXPRESSION:
                fstmt->add(fstmt, "%s;", expr_type);
                break;
            case CONDITION:
                fstmt->add(fstmt, "%s", expr_type);
                break;
            case IFEXPR:
                add_tab(fstmt, indent);
                //printf("indent for if (%s) = %d\n", expr_type, indent);
                fstmt->add(fstmt, "if (%s) goto L%d; goto L%d; L%d:\n", expr_type, *lx, *lx + 1, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s) goto L%d;\n", expr_type, *lx);
                break;
            case WHILE:
                add_tab(fstmt, indent);
                //printf("indent for if (%s) = %d\n", expr_type, indent);
                fstmt->add(fstmt, "if (%s) goto L%d;\n", expr_type, *lx);
                break;
            default:
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
        }
    }
    else
    {
        fprintf(stderr, "[!] Operator not recognized in the expression: %s\n", expr_type);
    }
}

char *
to_one_addr (struct stack_t  * stk_decl,
             struct stack_t  * stk_stmt,
             struct crpdct_t * ct,
             unsigned int    from,
             unsigned int    * to,
             struct buf_t    * fd,
             struct buf_t    * fs,
             char            * vname,
             unsigned int    indent)
{
    /* Inside an expression */

    register char *operand;

    operand = stk_stmt->get(stk_stmt, from)->value;
    /*printf("T I got %s !\n", vname);
    stk_stmt->print_stack(stk_stmt);
    printf("From %x to %x\n", from, *to);*/
    if (!strcmp(operand, "+") ||
        !strcmp(operand, "-") ||
        !strcmp(operand, "*") ||
        !strcmp(operand, "/") ||
        !strcmp(operand, "==") ||
        !strcmp(operand, "!=") ||
        !strcmp(operand, "<=") ||
        !strcmp(operand, ">=") ||
        !strcmp(operand, "<") ||
        !strcmp(operand, ">"))
    {
        unsigned int end_left_operand = 0;
        unsigned int end_right_operand = 0;
        char *left_operand;
        char *right_operand;
        char *uexpr;


        //stk_stmt->print_stack(stk_stmt);
        uexpr = vname;
        if (isdigit(stk_stmt->get(stk_stmt, from + 1)->value))
        {
            end_left_operand = from + 2;
            left_operand = strdup(stk_stmt->get(stk_stmt, from + 1)->value);
        }
        else if (isuop(stk_stmt->get(stk_stmt, from + 1)->value))
        {
            char *uop = stk_stmt->get(stk_stmt, from + 1)->value;
            struct buf_t *buf = init_buf();
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 1 + 1)->value);
            buf->add(buf, "%c%s", uop[1], left_operand);
            left_operand = buf->string;
        }
        else if (isidentifier(stk_stmt->get(stk_stmt, from + 1)->value))
        {
            end_left_operand = from + 2;
            left_operand = find_be_of(ct, stk_stmt->get(stk_stmt, from + 1)->value);
        }
        else
        {
            struct mcell_t *left_cell_operand = init_mcell(0, vname);
            left_cell_operand->value = (char *) malloc (strlen(vname) + 2);
            strcpy(left_cell_operand->value, vname);
            strcat(left_cell_operand->value, "l");
            /* v0 -> v0l (=v0 left)*/
            if (find_fe_of(ct, left_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, left_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, left_cell_operand->value, left_cell_operand->value);
              add_tab(fd, indent);
              fd->add(fd, "int %s;\n", left_cell_operand->value);
            }
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 1, &end_left_operand, fd, fs, left_cell_operand->value, indent);
        }

        if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            end_right_operand = end_left_operand + 1;
            right_operand = strdup(stk_stmt->get(stk_stmt, end_left_operand)->value);
        }
        else if (isuop(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            char *uop = stk_stmt->get(stk_stmt, end_left_operand)->value;
            struct buf_t *buf = init_buf();
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            buf->add(buf, "%c%s", uop[1], right_operand);
            right_operand = buf->string;
        }
        else if (isidentifier(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            end_right_operand = end_left_operand + 1;
            right_operand = find_be_of(ct, stk_stmt->get(stk_stmt, end_left_operand)->value);
        }
        else
        {
            struct mcell_t *right_cell_operand = init_mcell(0, vname);
            right_cell_operand->value = (v_t) malloc (strlen(vname) + 2);
            strcpy(right_cell_operand->value, vname);
            strcat(right_cell_operand->value, "r");
            /* v0 -> v0r (=v0 right)*/
            if (find_fe_of(ct, right_cell_operand->value) == NULL)
            {
              stk_decl->push(stk_decl, right_cell_operand->value);
              stk_decl->push(stk_decl, "int");
              stk_decl->push(stk_decl, "declaration");
              ct->add(ct, right_cell_operand->value, right_cell_operand->value);
              add_tab(fd, indent);
              fd->add(fd, "int %s;\n", right_cell_operand->value);
            }
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fd, fs, right_cell_operand->value, indent);
        }

        add_tab(fs, indent);
        fs->add(fs, "%s = %s %s %s;\n", uexpr, left_operand, operand, right_operand);
        *to = end_right_operand;

        return uexpr;
    }
    else if (!strcmp(operand, "sizeof"))
    {
        return sizeof_int();
    }
    else if (isuop(operand))
    {
        char *uop = operand;
        struct buf_t *buf = init_buf();
        buf->add(buf, "%c%s", uop[1], find_be_of(ct, stk_stmt->get(stk_stmt, from + 1)->value));
        return buf->string;
    }
    else
    {
        /* IDENTIFIER || CONSTANT */
        *to = from + 2;
        return stk_stmt->get(stk_stmt, from + 1)->value;
    }
}

bool_t
isidentifier (char *s)
{
    size_t i = 0;

    if (!((s[i] >= 'A' && s[i] <= 'Z') ||
          (s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] == '_')))
        return false;

    for (i = 1; s[i] != '\0'; i++)
    {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              (s[i] == '_')))
            return false;
    }
    return true;
}

bool_t
isdigit (char *s)
{
    size_t i = 0;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
            return false;
    }
    return true;
}

bool_t
isuop (char *s)
{
    //printf("S: [%c, %c]\n", s[0], s[1]);
    if (s[0] != 'u')
        return false;
    if (s[1] != '*' &&
        s[1] != '&' &&
        s[1] != '-')
        return false;
    return true;
}

void
add_tab (struct buf_t   * b,
         unsigned int   indent)
{
    for (size_t i = 0; i < indent; i++)
        b->add(b, "    ");
}

char *
sizeof_int (void)
{
    char *tmp;

    tmp = (char *) calloc (3, 1);
    sprintf(tmp, "%d", sizeof(int));

    return tmp;
}

char *
sizeof_voidp (void)
{
    char *tmp;

    tmp = (char *) calloc (3, 1);
    sprintf(tmp, "%d", sizeof(void *));

    return tmp;
}
