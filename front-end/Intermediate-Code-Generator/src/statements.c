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
            assert(idx != (unsigned int) -1, "idx = search_end_if(stk_stmt, i + 1) returns -1");
            //printf("endif found at %x\n", idx);

            /* end_cond = "then" */
            end_cond = search_end_cond(stk_stmt, i);
            assert(end_cond != (unsigned int) -1, "end_cond = search_end_cond(stk_stmt, i) returns -1");
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
            assert(idx != (unsigned int) -1, "idx = search_end_if(stk_stmt, i + 1) returns -1");
            /* = "then" */
            end_cond = search_next(stk_stmt, i, "then");
            assert(end_cond != (unsigned int) -1, "end_cond = search_end_cond(stk_stmt, i) returns -1");
            /* = "else" */
            else_idx = search_next(stk_stmt, i, "else");
            assert(else_idx != (unsigned int) -1, "else_idx = search_end_cond(stk_stmt, i) returns -1");

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
        }
        else
        {
            fprintf(stderr, "[TypeError] Type not found: %s\n", type);
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
                stk_decl->push(stk_decl, left_cell_operand->value);
                stk_decl->push(stk_decl, "int");
                stk_decl->push(stk_decl, "declaration");

                add_tab(fdecl, indent);
                fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
                /* left_operand = v0l */
                left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 4, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
            }

            if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
            {
                //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
                right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
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
                stk_decl->push(stk_decl, right_cell_operand->value);
                stk_decl->push(stk_decl, "int");
                stk_decl->push(stk_decl, "declaration");

                add_tab(fdecl, indent);
                fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);

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
                    fstmt->add(fstmt, "if (%s = %s %s %s) goto L%d; L%d:\n", variable_name, left_operand, assignement_type, right_operand, *lx, *lx);
                    break;
                case IFELSE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s %s %s) goto L%d;\n", variable_name, left_operand, assignement_type, right_operand, *lx);
                    break;
                default:
                    fstmt->add(fstmt, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                    break;
            }

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
                    fstmt->add(fstmt, "if (%s = %s) goto L%d; L%d:\n", variable_name, assignement_type, *lx, *lx);
                    break;
                case IFELSE:
                    add_tab(fstmt, indent);
                    fstmt->add(fstmt, "if (%s = %s) goto L%d;\n", variable_name, assignement_type, *lx);
                    break;
                default:
                    fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                    break;
            }
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
            stk_decl->push(stk_decl, left_cell_operand->value);
            stk_decl->push(stk_decl, "int");
            stk_decl->push(stk_decl, "declaration");

            add_tab(fdecl, indent);
            fdecl->add(fdecl, "int %s;\n", left_cell_operand->value);
            /* left_operand = v0l */
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 2, &end_left_operand, fdecl, fstmt, left_cell_operand->value, indent);
        }

        if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            //debug("Right side constant found: %s\n", stk_stmt->get(stk_stmt, end_left_operand + 1)->value);
            right_operand = stk_stmt->get(stk_stmt, end_left_operand)->value;
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
            stk_decl->push(stk_decl, right_cell_operand->value);
            stk_decl->push(stk_decl, "int");
            stk_decl->push(stk_decl, "declaration");

            add_tab(fdecl, indent);
            fdecl->add(fdecl, "int %s;\n", right_cell_operand->value);

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
                fstmt->add(fstmt, "if (%s %s %s) goto L%d; L%d:\n", left_operand, expr_type, right_operand, *lx, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s %s %s) goto L%d;\n", left_operand, expr_type, right_operand, *lx);
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
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
            case CONDITION:
                fstmt->add(fstmt, "%s", expr_type);
                break;
            case IFEXPR:
                add_tab(fstmt, indent);
                //printf("indent for if (%s) = %d\n", expr_type, indent);
                fstmt->add(fstmt, "if (%s) goto L%d; L%d:\n", expr_type, *lx, *lx);
                break;
            case IFELSE:
                add_tab(fstmt, indent);
                fstmt->add(fstmt, "if (%s) goto L%d;\n", expr_type, *lx);
                break;
            default:
                fprintf(stderr, "[!] Output type not recognized: arithmetic_t[%d]\n", output_type);
                break;
        }
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

    register const char *operand;

    operand = stk_stmt->get(stk_stmt, from)->value;
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
        uexpr = stk_decl->get(stk_decl, stk_decl->size - 3)->value;
        if (isdigit(stk_stmt->get(stk_stmt, from + 1)->value))
        {
            end_left_operand = from + 2;
            left_operand = strdup(stk_stmt->get(stk_stmt, from + 1)->value);
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
            stk_decl->push(stk_decl, left_cell_operand->value);
            stk_decl->push(stk_decl, "int");
            stk_decl->push(stk_decl, "declaration");

            add_tab(fd, indent);
            fd->add(fd, "int %s;\n", left_cell_operand->value);
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 1, &end_left_operand, fd, fs, left_cell_operand->value, indent);
        }

        if (isdigit(stk_stmt->get(stk_stmt, end_left_operand)->value))
        {
            end_right_operand = end_left_operand + 1;
            right_operand = strdup(stk_stmt->get(stk_stmt, end_left_operand)->value);
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
            stk_decl->push(stk_decl, right_cell_operand->value);
            stk_decl->push(stk_decl, "int");
            stk_decl->push(stk_decl, "declaration");

            add_tab(fd, indent);
            fd->add(fd, "int %s;\n", right_cell_operand->value);
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fd, fs, right_cell_operand->value, indent);
        }

        add_tab(fs, indent);
        fs->add(fs, "%s = %s %s %s;\n", uexpr, left_operand, operand, right_operand);
        *to = end_right_operand;

        return uexpr;
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

void
add_tab (struct buf_t   * b,
         unsigned int   indent)
{
    for (size_t i = 0; i < indent; i++)
        b->add(b, "    ");
}
