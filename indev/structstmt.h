#ifndef STRUCTSTMT_H
#define STRUCTSTMT_H

#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* Structure Node */
struct sn_t
{
    char            * fe; /* the case struct->item becomes fe = "item" */
    unsigned int    index; /* index * 4 = size to add to get this struct element */
    struct sn_t     * next;

    void            (*add) (struct sn_t *, char *);
};

/* Structure Statement Manager */
struct sstmtm_t
{
    struct sn_t     * curr;
    struct sstmtm_t * next;
    char            * name;

    void            (*add) (struct sstmtm_t *, struct sn_t *, char *);
    /* Remove Last */
    void            (*rml) (struct sstmtm_t **);
};

struct sn_t *init_sn (void);
void _sn_add (struct sn_t *, char *);

struct sstmtm_t *init_sstmtm (void);
void _sstmtm_add (struct sstmtm_t *, struct sn_t *, char *);
void _sstmtm_rml (struct sstmtm_t **);

#endif // STRUCTSTMT_H
