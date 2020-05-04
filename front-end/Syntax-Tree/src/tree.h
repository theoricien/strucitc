#ifndef _TREE_H
#define _TREE_H

// types : constant, identifers, operators, unary operator, statement, declarator type, if, for loop, return
typedef enum {TCONS, TID, TOP, TUOP, TS, TD, TT, TIF, TFOR, TRET} type_t;

/// Un noeud pour chaque type:

//constantes et identifiers
struct pexpr_t
{
  char* value;
}; // primary expression type

//operators
struct opr_t
{
  char *optype;
  struct node_t *left;
  struct node_t *right;
};

//unary operator
struct uopr_t
{
  char *optype;
  struct node_t *operand;
};

//statement and declarator list
struct list_t
{
  char *context;
  struct node_t *current;
  struct node_t *next;
};

struct if_t
{
  struct node_t *cond;
  struct node_t *true;
  struct node_t *false;
};

struct for_t
{
  struct node_t *start_statement;
  struct node_t *end_statement;
  struct node_t *forward_expression;
  struct node_t *do_statement;
};


struct node_t
{
  type_t type;

  union{
    struct pexpr_t *leaf; // les constantes et idenfiers sont des terminaux
    struct opr_t *opr;
    struct uopr_t *uopr;
    struct list_t *list;
    struct if_t *if_node;
    struct for_t *for_loop;
  };

};

typedef struct pexpr_t pexpr_t;
typedef struct opr_t opr_t;
typedef struct uopr_t uopr_t;
typedef struct list_t list_t;
typedef struct if_t if_t;
typedef struct for_t for_t;


typedef struct node_t node_t;

node_t *build_leaf(type_t, char*);
node_t *build_opr(char *, node_t*, node_t*);
node_t *build_uopr(char *, node_t *);
node_t *build_list(type_t, char *, node_t *, node_t *);
node_t *build_if(node_t *, node_t *, node_t *);
node_t *build_for(node_t *, node_t *, node_t *, node_t *);


void stringify(node_t *, int);

#endif
