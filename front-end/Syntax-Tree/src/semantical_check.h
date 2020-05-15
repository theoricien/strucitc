#ifndef SEMANTICAL_CHECK_H
#define SEMANTICAL_CHECK_H
#include "tree.h"

void check_type_of_block(node_t *,symbol_table_block *);
void semantical_check(node_t *);
void all_check(node_t *, symbol_table *);
type_spe get_type_node(node_t *, symbol_table_block *);
#endif
