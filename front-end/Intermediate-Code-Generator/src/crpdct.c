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
    tmp->clone = _crpdct_clone;

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

struct crpdct_t *
_crpdct_clone (struct crpdct_t *ct)
{
    struct crpdct_t *res;
    struct crpdct_t *tmp;

    res = init_crpcdt();
    tmp = ct;

    while (tmp != NULL)
    {
        res->add(res, tmp->fe, tmp->be);
        tmp = tmp->next;
    }

    return res;
}

/*
 * find_*_of functions return the last
 * occurence else the variable inside
 * a statement refers to the older declaration
 */

char *
find_be_of (struct crpdct_t * ct,
            char            * fe)
{
    struct crpdct_t *tmp;
    char *last_occurence;

    last_occurence = NULL;
    tmp = ct;

    if (!strcmp(tmp->fe, fe))
        last_occurence = tmp->be;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (!strcmp(tmp->fe, fe))
            last_occurence = tmp->be;
    }

    return last_occurence;
}

char *
find_fe_of (struct crpdct_t * ct,
            char            * be)
{
    struct crpdct_t *tmp;
    char *last_occurence;

    last_occurence = NULL;
    tmp = ct;

    if (!strcmp(tmp->be, be))
        last_occurence = tmp->fe;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (!strcmp(tmp->be, be))
            last_occurence = tmp->fe;
    }

    return last_occurence;
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
