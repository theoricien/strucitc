#include "structstmt.h"

struct sn_t *
init_sn (void)
{
    struct sn_t *tmp;

    tmp = (struct sn_t *) malloc (sizeof(struct sn_t));
    assert(tmp != NULL, "Memory error, malloc returns NULL sn_t\n");

    tmp->add = _sn_add;
    tmp->fe = NULL;
    tmp->index = 0;
    tmp->next = NULL;

    return tmp;
}

void
_sn_add (struct sn_t    * sn,
         char           * fe)
{
    struct sn_t *tmp;

    if (sn->fe == NULL)
    {
        sn->fe = strdup(fe);
        sn->index = 1;
        return;
    }

    tmp = sn;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = init_sn();
    tmp->next->fe = strdup(fe);
    tmp->next->index = tmp->index + 1;
}

struct sstmtm_t *
init_sstmtm (void)
{
    struct sstmtm_t *tmp;

    tmp = (struct sstmtm_t *) malloc (sizeof(struct sstmtm_t));
    assert(tmp != NULL, "Memory error, malloc returns NULL sstmtm_t\n");

    tmp->rml = _sstmtm_rml;
    tmp->add = _sstmtm_add;
    tmp->curr = NULL;
    tmp->next = NULL;
    tmp->name = NULL;

    return tmp;
}

void
_sstmtm_add (struct sstmtm_t    * sm,
             struct sn_t        * sn,
             char               * name)
{
    struct sstmtm_t *tmp;

    if (sm->curr == NULL)
    {
        sm->curr = sn;
        sm->name = strdup(name);
        return;
    }

    tmp = sm;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = init_sstmtm();
    tmp->next->curr = sn;
    tmp->next->name = strdup(name);
}

void
_sstmtm_rml (struct sstmtm_t ** sm)
{
    struct sstmtm_t *tmp;

    if ((*sm)->next == NULL)
    {
        *sm = NULL;
        return;
    }

    tmp = *sm;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    tmp->next = NULL;
}
