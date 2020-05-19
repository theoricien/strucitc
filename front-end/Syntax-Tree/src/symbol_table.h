#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "tree.h"

struct decl{
  type_spe type;
  char* name;
};

struct declaration_list{
  struct decl *current;
  struct declaration_list *next;
};

struct symbol_table_block
{
  char *context;
  declaration_list *declarations;
};

struct symbol_table
{
  symbol_table_block *definition_block;
  symbol_table* next_symbol_table;
};

struct all_tables
{
  symbol_table *table;
  symbol_table *global_table;
};


// Operations on declarations within a block
int is_in(char*, declaration_list *);
type_spe get_type(char* , declaration_list *);
decl *node_to_decl(node_t *);
decl *build_decl(type_t , char *);
void add_declaration(declaration_list *, decl *);
void print_decl(decl*);
void print_declaration_list(declaration_list *);
decl *clone_decl(decl *);
declaration_list *clone_declaration_list(declaration_list *);

// Operations on definitions within a symbol table block
symbol_table_block *init_symbol_table_block();
int is_already_declared(char*, symbol_table_block *);
int is_already_redeclared(char *, symbol_table_block *);
type_spe get_variable_type(char* , symbol_table_block *);
void add_block_declaration(symbol_table_block *, decl *);
symbol_table_block *clone_block(symbol_table_block *);
int is_any_declaration(symbol_table_block *);
void print_block(symbol_table_block *);
void add_all_declarations_to_block(symbol_table_block *, symbol_table_block *);

// Operations on symbol_table
// Each diferent block have his own symbol table
symbol_table *init_symbol_table();
void add_block_to_table(symbol_table *, symbol_table_block *);
symbol_table *clone_symbol_table(symbol_table *);
symbol_table_block *block_exists(symbol_table *, char *);
void print_symbol_table(symbol_table *, int);
all_tables *build_symbol_table(node_t *);
void construct_table(node_t *, symbol_table *, symbol_table *, symbol_table *);

void case_global_declaration_in_construct_table(node_t *, symbol_table *);
void case_program_in_construct_table(node_t *, symbol_table *, symbol_table *, symbol_table *);
void case_init_declarator_list(node_t *, symbol_table *, symbol_table *,type_spe*);
void case_init_global_declarator_list(node_t *, symbol_table *,type_spe*);
void case_tfunc_in_declaration(node_t*,symbol_table*,symbol_table*,type_spe*);
void case_global_tfunc_in_declaration(node_t *,symbol_table *, type_spe *);


#endif
