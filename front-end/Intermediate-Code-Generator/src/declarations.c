#include "declarations.h"

void
declaration (struct stack_t     * stk_decl,
             struct crpdct_t    * ct,
             struct buf_t 	    * of,
             unsigned int       * v,
             unsigned int       indent)
{
    char *declaration_type;
  	char *type;
  	unsigned int vx = *v;
  	unsigned int step;
  	size_t i = 0;

    while (i < stk_decl->size)
    {
        /**
         * i + 0 = otype
         * i + 1 = name (can be fundecl/declaration/...)
         * i + 2 = UB
         */
        step = 0;
        declaration_type = search_declaration_type(stk_decl, i, &step);
        type = stk_decl->get(stk_decl, i)->value;

        if (!strcmp(declaration_type, "declaration"))
        {
            variable_declaration(stk_decl, ct, of, &vx, indent, i + 1, type);
        }
        else if (!strcmp(declaration_type, "fundecl"))
        {
            function_declaration(stk_decl, ct, of, &vx, indent, i, type);
        }
        //printf("i += %d\n", step);
        i += step + 1;
    }
    *v = vx;
}

char *
search_declaration_type (struct stack_t * stk_decl,
                         unsigned int   i,
                         unsigned int   * step)
{
    *step = i;
    if (!strcmp(stk_decl->get(stk_decl, i)->value, "extern")) // ==
        i++;
    i += 2;
    *step = i - *step;
    for (size_t k = i; k < stk_decl->size; k++)
    {
        if (!strcmp(stk_decl->get(stk_decl, k)->value, "declaration") ||
            !strcmp(stk_decl->get(stk_decl, k)->value, "fundecl"))
        {
            return stk_decl->get(stk_decl, k)->value;
        }
        *step = *step + 1;
    }
    return (char *) NULL;
}

void
variable_declaration (struct stack_t     * stk_decl,
                      struct crpdct_t    * ct,
                      struct buf_t 	     * of,
                      unsigned int       * v,
                      unsigned int       indent,
                      unsigned int       i,
                      char               * type)
{
    unsigned int vx = *v;
  	char vvar[256];

    sprintf(vvar, "v%d", vx);
    add_tab(of, indent);

    if (!strcmp(type, "int"))
    {
        of->add(of, "%s %s;\n", type, vvar);
        ct->add(ct, stk_decl->get(stk_decl, i)->value, vvar);
    }
    else
    {
        of->add(of, "void *%s;\n", vvar);
        ct->add(ct, stk_decl->get(stk_decl, i)->value, vvar);
    }

    vx++;
    *v = vx;
}

void
function_declaration (struct stack_t     * stk_decl,
                      struct crpdct_t    * ct,
                      struct buf_t 	     * of,
                      unsigned int       * v,
                      unsigned int       indent,
                      unsigned int       i,
                      char               * type)
{
    int extrn;
    char *ot_ret;
    char *fun_name;
    struct buf_t *args;

    args = init_buf();
    extrn = 0;
    if (!strcmp(stk_decl->get(stk_decl, i)->value, "extern"))
    {
        extrn = 1;
        i++;
    }

    ot_ret = stk_decl->get(stk_decl, i)->value;
    if (strcmp(ot_ret, "int") && // !=
        strcmp(ot_ret, "void")) // !=
    {
        ot_ret = (char* ) calloc (strlen("void *") + 2, 1);
        strcpy(ot_ret, "void *");
    }

    fun_name = stk_decl->get(stk_decl, i + 1)->value;

    i = i + 2;
    if (!strcmp(stk_decl->get(stk_decl, i)->value, "void"))
    {
        if (extrn)
            of->add(of, "extern ");
        of->add(of, "%s %s (void);\n", ot_ret, fun_name);
        return;
    }
    while (strcmp(stk_decl->get(stk_decl, i)->value, "fundecl")) // !=
    {
        char *type;

        type = stk_decl->get(stk_decl, i)->value;
        if (strcmp(type, "int"))
        {
            type = (char* ) calloc (strlen("void *") + 2, 1);
            strcpy(type, "void *");
        }

        args->add(args, "%s", type);
        i++;

        if (strcmp(stk_decl->get(stk_decl, i)->value, "fundecl")) // !=
            args->add(args, ", ");
    }

    if (extrn)
        of->add(of, "extern ");
    of->add(of, "%s %s (%s);\n", ot_ret, fun_name, args->string);
}
