#include "declarations.h"

void
declaration (struct stack_t     * stk_decl,
             struct crpdct_t    * ct,
			 FILE 			    * of,
			 unsigned int       * v)
{
	char *type;
	char vvar[256];
	unsigned int vx = *v;
	size_t i = stk_decl->size;

    while (i > 0)
    {
        i -= 2;
        type = stk_decl->get(stk_decl, i)->value;

        sprintf(vvar, "v%d", vx);

        if (!strcmp(type, "int"))
        {
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s %s;\n", type, vvar);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
        }
        else if (!strcmp(type, "void *"))
        {
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s %s;\n", type, vvar);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
        }
        else if (!strcmp(type, "void p"))
        {
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s %s;\n", "void *", vvar);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
        }
        else if (!strcmp(type, "int *"))
        {
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s %s;\n", "int", vvar);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
            vx++;
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s %s = &v%d;\n", "void *", vvar, vx - 1);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
        }
        else if (!strcmp(type, "int p"))
        {
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s v%d;\n", "int", vx);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
            vx++;
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s v%d = &v%d;\n", "void *", vx, vx - 1);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
            vx++;
            sprintf(vvar, "v%d", vx);
            fprintf(of, "%s v%d;\n", "void *", vx);
            ct->add(ct, stk_decl->get(stk_decl, i - 1)->value, vvar);
        }
        vx++;
        i--;
    }
    *v = vx;
}
