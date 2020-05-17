#ifndef SEMANTICAL_CHECK_H
#define SEMANTICAL_CHECK_H
#include "tree.h"

struct arguments{
  char* name;
  type_spe type;
  arguments *next;
};

struct function_arguments{
  char *name;
  int nb;
  type_spe type;
  function_arguments *next;
  arguments *args;
};

int semantical_check_on_function_declaration_block(node_t *,symbol_table_block *, symbol_table_block *, function_arguments*);
int semantical_check_on_declaration(node_t *, symbol_table_block *, symbol_table_block *,function_arguments*);
int semantical_check_on_parameter_declaration(node_t *, symbol_table_block *, symbol_table_block *,function_arguments*);

int check_arithmetical_expression(node_t *, symbol_table_block *, function_arguments*);
int check_equal_assignment(node_t *, symbol_table_block *, symbol_table_block *, function_arguments*);
type_spe get_type_node(node_t *, symbol_table_block *);
type_spe get_type_parameter_declaration(node_t *);
int function_call_check_type(type_t ,type_t );

void add_all_arg_count(node_t*, type_spe, function_arguments*);
void add_all_arg_inter(node_t* , char* , function_arguments* );
void add_one_arg_count(char*, type_spe, function_arguments*);
void add_fun_arg(char *, type_spe , function_arguments *);
arguments *find_arg_in_function(char* , arguments* );
char* get_declaration_name(node_t *);
function_arguments *find_function_in_fa(char*, function_arguments*);
function_arguments *build_function_argument(type_spe);
arguments *build_args();
void print_function_arguments(function_arguments *);
int count_function_arguments(char*, function_arguments *);

void semantical_check(node_t *);
void all_check(node_t *, symbol_table *, symbol_table *, function_arguments*);
#endif
