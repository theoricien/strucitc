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
            FILE 		    * fdecl,
            FILE 		    * fstmt,
            unsigned int    * v)
{
    char *type;
    unsigned int idx;

    for (size_t i = 0; i < stk_stmt->size; i++)
    {
        type = stk_stmt->get(stk_stmt, i)->value;
        /* expr -> .... -> ;*/
        /* The semicolon is the end of an expr */
        if (!strcmp(type, "expr"))
        {
            idx = search_next_semicolon(stk_stmt, i);
            arithmetic_gen(stk_decl, stk_stmt, ct, i, idx, fdecl, fstmt, v);
        }
        /*
        else if (!strcmp(type, "if"))
        {
        }
        else if (!strcmp(type, "while"))
        {
        }
        else if (!strcmp(type, "for"))
        {

        }*/
        i = idx;
    }
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
                FILE            * fdecl,
                FILE            * fstmt,
                unsigned int    * vx)
{
    register const char *expr_type;
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
            !strcmp(assignement_type, "/"))
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

                fprintf(fdecl, "int %s;\n", left_cell_operand->value);
                /* left_operand = v0l */
                left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 4, &end_left_operand, fdecl, fstmt, left_cell_operand->value);
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
                fprintf(fdecl, "int %s;\n", right_cell_operand->value);

                /* right_operand = v0r */
                right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value);
            }

            to = end_right_operand + 1;

            fprintf(fstmt, "%s = %s %s %s;\n", variable_name, left_operand, assignement_type, right_operand);
        }
        else if (isdigit(assignement_type))
        {
            fprintf(fstmt, "%s = %s;\n", variable_name, assignement_type);
        }
    }
    else if (!strcmp(expr_type, "==") ||
             !strcmp(expr_type, "!=") ||
             !strcmp(expr_type, "<=") ||
             !strcmp(expr_type, ">=") ||
             !strcmp(expr_type, "<") ||
             !strcmp(expr_type, ">"))
    {
        register const char *assignement_type;
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

            fprintf(fdecl, "int %s;\n", left_cell_operand->value);
            /* left_operand = v0l */
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 2, &end_left_operand, fdecl, fstmt, left_cell_operand->value);
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
            fprintf(fdecl, "int %s;\n", right_cell_operand->value);

            /* right_operand = v0r */
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fdecl, fstmt, right_cell_operand->value);
        }

        to = end_right_operand + 1;

        fprintf(fstmt, "%s %s %s", left_operand, expr_type, right_operand);
    }
}

char *
to_one_addr (struct stack_t  * stk_decl,
             struct stack_t  * stk_stmt,
             struct crpdct_t * ct,
             unsigned int    from,
             unsigned int    * to,
             FILE            * fd,
             FILE            * fs,
             char            * vname)
{
    /* Inside an expression */

    register const char *operand;

    operand = stk_stmt->get(stk_stmt, from)->value;
    if (!strcmp(operand, "+") ||
        !strcmp(operand, "-") ||
        !strcmp(operand, "*") ||
        !strcmp(operand, "/"))
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

            fprintf(fd, "int %s;\n", left_cell_operand->value);
            left_operand = to_one_addr(stk_decl, stk_stmt, ct, from + 1, &end_left_operand, fd, fs, left_cell_operand->value);
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

            fprintf(fd, "int %s;\n", right_cell_operand->value);
            right_operand = to_one_addr(stk_decl, stk_stmt, ct, end_left_operand, &end_right_operand, fd, fs, right_cell_operand->value);
        }

        fprintf(fs, "%s = %s %s %s;\n", uexpr, left_operand, operand, right_operand);
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
