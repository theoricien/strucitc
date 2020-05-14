#include "crpdct.h"

struct crpdct_t *
init_crpcdt (void)
{
    struct crpdct_t *tmp;

    tmp = (struct crpdct_t *) malloc (sizeof(struct crpdct_t));
    assert(tmp != NULL, "Memory error, malloc returns NULL\n");

    tmp->fe = NULL;
    tmp->be = NULL;
    tmp->next = NULL;
    tmp->add = _crpdct_add;

    return tmp;
}

void
_crpdct_add (struct crpdct_t    * ct,
             char               * fe,
             char               * be)
{
    assert(ct != NULL, "NULL crpdct_t passed as argument");

    /* 0 element */
	if (ct->fe == NULL)
	{
		ct->fe = strdup(fe);
		ct->be = strdup(be);
    }
	else
	{
	    struct crpdct_t *tmp;

	    tmp = ct;
	    while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = init_crpcdt();
        tmp->next->fe = strdup(fe);
        tmp->next->be = strdup(be);
	}
}

char *
find_be_of (struct crpdct_t * ct,
            char            * fe)
{
    struct crpdct_t *tmp;

    tmp = ct;

    if (!strcmp(tmp->fe, fe))
        return tmp->be;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (!strcmp(tmp->fe, fe))
            return tmp->be;
    }

    return (char *) NULL;
}

char *
find_fe_of (struct crpdct_t * ct,
            char            * be)
{
    struct crpdct_t *tmp;

    tmp = ct;

    if (!strcmp(tmp->be, be))
        return tmp->fe;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (!strcmp(tmp->be, be))
            return tmp->fe;
    }

    return (char *) NULL;
}

void
print_ct (struct crpdct_t *ct)
{
	struct crpdct_t *tmp;
	tmp = ct;

	printf("\n--   FE   --  BE  --\n");
	while (tmp != NULL)
	{
        printf("-- %s -- %s --\n", tmp->fe, tmp->be);
		tmp = tmp->next;
	}
	printf("----------------------\n");
}
