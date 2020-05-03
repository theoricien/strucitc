#ifndef _TREE_H
#define _TREE_H

typedef enum {TCONS, TID, TOP, TUOP} type_t; // types : constant, identifers, operators

/// Un noeud pour chaque type:

//constantes et identifiers
struct pexpr_t
{
  char* value;
}; // primary expression type

//operators
struct opr_t
{
  char optype;
  struct node_t *left;
  struct node_t *right;
};

struct uopr_t{
  char optype;
  struct node_t *operand;
};


struct node_t
{
  type_t type;

  union{
    struct pexpr_t *leaf; // les constantes et idenfiers sont des terminaux
    struct opr_t *opr;
    struct uopr_t *uopr;
  };

};

//constantes et identifiers
typedef struct pexpr_t pexpr_t;

//operators
typedef struct opr_t opr_t;

typedef struct uopr_t uopr_t;


typedef struct node_t node_t;

node_t *build_leaf(type_t, char*);
node_t *build_opr(char, node_t*, node_t*);
node_t *build_uopr(char, node_t *);

void stringify(node_t *, int);

#endif
