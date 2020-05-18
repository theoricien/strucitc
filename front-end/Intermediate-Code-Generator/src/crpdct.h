#ifndef CRPDCT_H
#define CRPDCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/* Table de correspondance */
/* front-end - back-end*/
struct crpdct_t
{
    char            * fe;
    char            * be;
    struct crpdct_t * next;
    void            (*add) (struct crpdct_t *, char *, char *);
    void            (*rm_last) (struct crpdct_t **);
    struct crpdct_t *(*clone) (struct crpdct_t *);
};

struct crpdct_t *init_crpcdt (void);
void _crpdct_add (struct crpdct_t *, char *, char *);
void _crpdct_rml (struct crpdct_t **);
struct crpdct_t * _crpdct_clone (struct crpdct_t *);
char *find_be_of (struct crpdct_t *, char *);
char *find_fe_of (struct crpdct_t *, char *);
void print_ct (struct crpdct_t *);

#endif // CRPDCT_H
