#ifndef _TREE_H
#define _TREE_H

// types : constant, identifers, operators, unary operator, statement, declarator type, type types, if,
//for loop, return, function, struct
typedef enum {TCONS, TID, TOP, TUOP, TS, TD, TT, TIF, TFOR, TRET, TFUNC, TSTRUCT} type_t;
typedef enum {TINT,TVOID,TNULL,PTRINT,PTRVOID,FINT,FVOID} type_spe;
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

struct list_t
{
  struct node_t *current;
  struct list_t * next;
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

struct func_t
{
  struct node_t *name;
  struct node_t *arguments;
};

struct abstract_t{
  struct node_t *ret_type;
  struct node_t *arguments;
};

struct struct_t
{
  struct node_t *name;
  struct node_t *struct_declaration;
};


struct node_t
{
  type_t type;

  union{
    struct pexpr_t *leaf; // les constantes et idenfiers sont des terminaux
    struct opr_t *opr;
    struct uopr_t *uopr;
    struct struct_t *struct_node;
    struct if_t *if_node;
    struct for_t *for_loop;
    struct func_t *function;
  };

};

typedef struct pexpr_t pexpr_t;
typedef struct opr_t opr_t;
typedef struct uopr_t uopr_t;
typedef struct list_t list_t;
typedef struct if_t if_t;
typedef struct for_t for_t;
typedef struct func_t func;
typedef struct struct_t struct_t;

typedef struct decl decl;
typedef struct declaration_list declaration_list;
typedef struct symbol_table_block symbol_table_block;
typedef struct symbol_table symbol_table;
typedef struct all_tables all_tables;
typedef struct arguments arguments;
typedef struct function_arguments function_arguments;

typedef struct node_t node_t;

node_t *build_leaf(type_t, char*);
node_t *build_opr(char *, node_t*, node_t*);
node_t *build_uopr(char *, node_t *);
//node_t *build_list(type_t, char *, node_t *, node_t *);
node_t *build_func(node_t *,node_t*);
list_t *build_arg_list(node_t*);
list_t *add_arg_list(list_t*,list_t*);
node_t *build_struct(node_t *, node_t *);
node_t *build_if(node_t *, node_t *, node_t *);
node_t *build_for(node_t *, node_t *, node_t *, node_t *);

//void check_all_types(node_t *);
//void check_type(node_t *, declarations *);

void print_tab(int);
void stringify(node_t *, int);

#endif
