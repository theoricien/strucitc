#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


/**
* return 1 if already declared, 0 if not
**/
int is_in(char* name, declaration_list *declaration_list){

  if(declaration_list->current != NULL){
    if(declaration_list->current->name !=NULL){
      if(!strcmp(name,declaration_list->current->name)){
        return 1;
      }
    }
  }
  if(declaration_list->next !=NULL){
    struct declaration_list *tmp = declaration_list;
    while(tmp != NULL){
      if(!strcmp(name,tmp->current->name)){
        return 1;
      }
      tmp = tmp->next;
    }
  }
  return 0; // not found
}

type_spe get_type(char* name, declaration_list *declaration_list){
  if(declaration_list->current->name !=NULL){
    if(!strcmp(name,declaration_list->current->name)){
      return declaration_list->current->type;
    }
  }
  if(declaration_list->next !=NULL){
    struct declaration_list *tmp = declaration_list;
    while(tmp->next !=NULL){
      if(!strcmp(name,tmp->current->name)){
        return tmp->current->type;
      }
      tmp = tmp->next;
    }
  }
  return TNULL; // not found
}

/*
* This function is called when a declaration is found in our tree
* We thus assume to have a TOP node

  For now, works on:  declaration  => int b;
                      function     => int foo(){}
*/

decl *node_to_decl(node_t *tree){

  char *name;
  type_t type;

  // declaration case like: int b;
  //                      : int foo(){}
  if(tree->type == TOP){

    //type
    if(tree->opr->left->type == TID){
      name = tree->opr->left->leaf->value;
    }
    else{
      printf("IN node_to_decl : TOP->left is not a TID \n");
    }

    //name
    if(tree->opr->right->type == TID){
      if(!strcmp(tree->opr->right->leaf->value,"int")){
        type = TINT;
      }
      else{
        type = TVOID;
      }
    }
    else if(tree->opr->right->type == TFUNC){
      // we assume that name is always a TID
      name = tree->opr->right->function->name->leaf->value;
    }
    else {
      printf("IN node_to_decl : TOP->right dont have a valid type \n");
    }

  }

  return build_decl(type,name);

}




decl *build_decl(type_t type, char *name){

  decl *new_declaration = (decl*) malloc(sizeof(struct decl)+1);

  new_declaration->type = type;
  new_declaration->name = name;

  return new_declaration;

}

/**
* Handle multiple declaration_list
**/

void add_declaration(declaration_list *declaration_list, decl *new_declaration){

  //add the new declaration to our list
  if(declaration_list->current == NULL){
    declaration_list->current = clone_decl(new_declaration);
  }
  else if(declaration_list->next == NULL){
    struct declaration_list *new_declaration_list = (struct declaration_list*) malloc(sizeof(struct declaration_list));
    new_declaration_list->current = clone_decl(new_declaration);
    new_declaration_list->next = NULL;
    declaration_list->next = new_declaration_list;
  }
  else{
    struct declaration_list *new_declaration_list = (struct declaration_list*) malloc(sizeof(struct declaration_list));
    new_declaration_list->current = clone_decl(new_declaration);
    new_declaration_list->next = NULL;

    struct declaration_list *tmp = declaration_list->next;
    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = new_declaration_list;

  }
}

void print_decl(decl* decl){
  char type[10];
  if(decl->type == TINT){
    strcpy(type,"int");
  }
  else if(decl->type == FINT){
    strcpy(type,"fint");
  }
  else if(decl->type == FVOID){
    strcpy(type,"fvoid");
  }
  else{
    strcpy(type,"void");
  }
  print_tab(12);
  printf("[*] \t\t %s %s \t\t\n",type,decl->name);
}

void print_declaration_list(declaration_list * list){
  if(list->current != NULL){
    if(list->current->name != NULL){
      print_decl(list->current);
    }
  }
  if(list->next != NULL){
    struct declaration_list* tmp = list->next;
    if(tmp->current != NULL){
      print_decl(tmp->current);
    }
    while(tmp->next != NULL){
      tmp = tmp->next;
      print_decl(tmp->current);
    }
  }
}

decl *clone_decl(decl *declaration){

  decl *new_decl = (struct decl*)malloc(sizeof(struct decl));
  new_decl->type = declaration->type;
  new_decl->name = malloc(strlen(declaration->name) + 1);
  strcpy(new_decl->name,declaration->name);

  return new_decl;

}

declaration_list *clone_declaration_list(declaration_list *list){

  declaration_list *new_list = (struct declaration_list*)malloc(sizeof(struct declaration_list));
  declaration_list *tmp = list;

  if(tmp->current != NULL){
    new_list->current = tmp->current;
  }
  while(tmp->next !=NULL){
    tmp = tmp->next;
    add_declaration(new_list,tmp->current);
  }

  return new_list;

}

/*        =====================================================
*         OPERATIONS ON DEFINITIONS WITHIN A SYMBOL TABLE BLOCK
*         =====================================================
*/

symbol_table_block *init_symbol_table_block(){

  symbol_table_block *tmp = (struct symbol_table_block*) malloc(sizeof(struct symbol_table_block));

  tmp->context = NULL;
  tmp->declarations = NULL;

  return tmp;
}

/**
* return 1 if already declared, 0 if not
**/
int is_already_declared(char *identifier, symbol_table_block *block){
  if(block != NULL){
    if(block->declarations != NULL){
      return is_in(identifier,block->declarations);
    }
  }
  else{
    return 0;
  }
}

type_spe get_variable_type(char *identifier, symbol_table_block *block){
  if(block->declarations != NULL){
    return get_type(identifier,block->declarations);
  }
  else{
    return TNULL;
  }
}

void add_block_declaration(symbol_table_block * block, decl *new_declaration){
  if(block->declarations == NULL){
    block->declarations = (struct declaration_list*)malloc(sizeof(struct declaration_list));
    block->declarations->current = clone_decl(new_declaration);
  }
  else{
    add_declaration(block->declarations,new_declaration);
  }
}

symbol_table_block *clone_block(symbol_table_block *block){

  symbol_table_block *new_block = init_symbol_table_block();
  symbol_table_block *tmp = block;
  new_block->context = malloc(strlen(block->context) + 1);
  strcpy(new_block->context,block->context);
  if(block->declarations != NULL){
    new_block->declarations = clone_declaration_list(block->declarations);
  }

  return new_block;

}

/*
* Return 1 if declarations, 0 if there are not
*/
int is_any_declaration(symbol_table_block *block){

  if(block->context == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

void print_block(symbol_table_block *block){
  print_tab(4);
  printf("[*****] \t\t Bloc %s \t\t\n",block->context);
  symbol_table_block *tmp = block;
  print_declaration_list(block);
}

void add_all_declarations_to_block(symbol_table_block *block, symbol_table_block *new_block){
  if((block != NULL) && (new_block != NULL)){
    declaration_list *new_tmp = new_block->declarations;
    if(block->declarations == NULL){
      block->declarations = (struct declaration_list*)malloc(sizeof(struct declaration_list));
    }
    while (new_tmp->next != NULL) {
      add_declaration(block->declarations,new_tmp->current);
      new_tmp = new_tmp->next;
    }
    add_declaration(block->declarations,new_tmp->current);
  }
}



/*        =====================================================
*         OPERATIONS ON DEFINITIONS WITHIN A SYMBOL TABLE
*         =====================================================
*/

symbol_table *init_symbol_table(){

  symbol_table *tmp = (struct symbol_table*) malloc(sizeof(struct symbol_table));

  tmp->definition_block = init_symbol_table_block();
  tmp->next_symbol_table = NULL;

  return tmp;

}

/*
* Return 1 if exists, 0 otherwise
*/
symbol_table_block *block_exists(symbol_table *table, char *block_name){
  if(table->definition_block != NULL){
    if(table->definition_block->context != NULL){
      if(!strcmp(table->definition_block->context,block_name)){
        return table->definition_block;
      }
    }
    if(table->next_symbol_table != NULL){
      symbol_table *tmp = table->next_symbol_table;

      while(tmp != NULL){
        if(tmp->definition_block != NULL){
          if(tmp->definition_block->context != NULL){
            if(!strcmp(tmp->definition_block->context,block_name)){
              return tmp->definition_block;
            }
          }
        }
        tmp = tmp->next_symbol_table;
      }
    }
    return NULL;
  }
  else{
    return NULL;
  }
}

void print_symbol_table(symbol_table *table, int indent){
  printf("[*******] \t\t Printing symbol table \t\t [*******]\n");
  if(table->definition_block != NULL){
      print_block(table->definition_block);
  }
  symbol_table *tmp = table;
  while(tmp->next_symbol_table != NULL){
    tmp = tmp->next_symbol_table;
    if(tmp->definition_block != NULL){
      print_block(tmp->definition_block);
    }
    else{
      printf("error in print_symbol_table\n");
    }
  }

  printf("[*******] \t\t End of symbol table \t\t [*******]\n");

}

void add_block_to_table(symbol_table *table, symbol_table_block *block){
  if(!is_any_declaration(table->definition_block)){
    table->definition_block = clone_block(block);
  }
  else if(table->next_symbol_table == NULL){
    symbol_table *new_table = init_symbol_table();
    new_table->definition_block = clone_block(block);
    new_table->next_symbol_table = NULL;
    table->next_symbol_table = new_table;
  }
  else{
    symbol_table *new_table = init_symbol_table();
    new_table->definition_block = clone_block(block);
    new_table->next_symbol_table = NULL;

    symbol_table *tmp = table->next_symbol_table;
    while(tmp->next_symbol_table != NULL){
      tmp = tmp->next_symbol_table;
    }
    tmp->next_symbol_table = new_table;
  }

}

symbol_table *clone_symbol_table(symbol_table *table){

  symbol_table *new_table = init_symbol_table();
  symbol_table *tmp = table;
  if(tmp->definition_block != NULL){
    new_table->definition_block = clone_block(tmp->definition_block);
  }
  while (tmp->next_symbol_table != NULL) {
    tmp = tmp->next_symbol_table;
    add_block_to_table(table,tmp->definition_block);
  }

  return new_table;
}



/*        =====================================================
*                     LETS BUILD OUR SYMBOL TABLE
*         =====================================================
*/

all_tables *build_symbol_table(node_t *tree){

  symbol_table *table = init_symbol_table();
  symbol_table *global_table = init_symbol_table();
  global_table->definition_block->context = (char *)malloc(strlen("global") +1);
  strcpy(global_table->definition_block->context,"global");

  symbol_table *print_table = init_symbol_table();
  symbol_table *print_first_index = print_table;

  construct_table(tree,table,global_table,print_table);

  all_tables *tables = (struct all_tables*)malloc(sizeof(struct all_tables));
  tables->table = print_table;
  tables->global_table = global_table;

  //print_symbol_table(print_table,0);
  return tables;

}


/*
*   global table is used to print the table at the end
*/

void construct_table(node_t *tree, symbol_table *table, symbol_table *global_table, symbol_table *print_table){
  if(tree->type == TID || tree->type == TCONS){
    return;
  }
  if(tree->type == TFUNC){
    construct_table(tree->function->arguments,table,global_table,print_table);
  }

  if(tree->type == TOP){
    if(!strcmp(tree->opr->optype,"function_definition")){
      symbol_table *new_table;
      decl *tmp;
      if(is_any_declaration(table->definition_block)){
         new_table = init_symbol_table();
      }
      else{
        new_table = table;
      }
      symbol_table_block *new_block = init_symbol_table_block();
      if(tree->opr->left->type == TOP && !strcmp(tree->opr->left->opr->optype,"function")){
        if(tree->opr->left->opr->right->type == TFUNC){
          new_block->context = malloc(strlen(tree->opr->left->opr->right->function->name->leaf->value));
          strcpy(new_block->context,tree->opr->left->opr->right->function->name->leaf->value);
          if(!strcmp(tree->opr->left->opr->left->leaf->value,"int")){
            tmp = build_decl(FINT,tree->opr->left->opr->right->function->name->leaf->value);
          }
          else{
            tmp = build_decl(FVOID,tree->opr->left->opr->right->function->name->leaf->value);
          }
        }
      }

      add_block_to_table(new_table,new_block);
      add_block_to_table(print_table,new_block);
      //print_symbol_table(global_table,0);
      add_all_declarations_to_block(block_exists(new_table,new_block->context),global_table->definition_block);
      add_all_declarations_to_block(block_exists(print_table,new_block->context),global_table->definition_block);


      add_block_declaration(global_table->definition_block,tmp);
      //printf("%s\n",global_table->definition_block->declarations->current->name);
      //printf("\n\n\n");
      construct_table(tree->opr->left,new_table,global_table,print_table);
      construct_table(tree->opr->right,new_table,global_table,print_table); // ICI QUE VOID

    }



    else if(!strcmp(tree->opr->optype, "parameter_declaration")){
      if(tree->opr->left->type == TOP){
        construct_table(tree->opr->left,table,global_table,print_table);
      }
      if(tree->opr->right->type == TOP){
        construct_table(tree->opr->right,table,global_table,print_table);
      }
      if((tree->opr->left->type == TID) && (tree->opr->right->type == TID)){

        decl *tmp;
        if(!strcmp(tree->opr->left->leaf->value,"int")){
          tmp = build_decl(TINT,tree->opr->right->leaf->value);
        }
        else{
          tmp = build_decl(TVOID,tree->opr->right->leaf->value);
        }

        add_block_declaration(table->definition_block,tmp);
        //add_block_declaration(global_table->definition_block,tmp);

        symbol_table_block *tmp_block;
        if(block_exists(print_table,table->definition_block->context) != NULL){
          tmp_block = block_exists(print_table,table->definition_block->context);
          add_block_declaration(tmp_block,tmp);
        }else{
          add_block_declaration(print_table->definition_block,tmp);
        }
      }
    }



    else if(!strcmp(tree->opr->optype,"declaration")){
      if(tree->opr->left->type == TID && tree->opr->right->type == TID){
        decl *tmp;
        if(!strcmp(tree->opr->left->leaf->value,"int")){
          tmp = build_decl(TINT,tree->opr->right->leaf->value);
        }
        else{
          tmp = build_decl(TVOID,tree->opr->right->leaf->value);
        }

        add_block_declaration(table->definition_block,tmp);

        symbol_table_block *tmp_block;
        if(block_exists(print_table,table->definition_block->context) != NULL){
          tmp_block = block_exists(print_table,table->definition_block->context);
          add_block_declaration(tmp_block,tmp);
        }else{
          add_block_declaration(print_table->definition_block,tmp);
        }

      }
      //declaration of type: int i = 0;
      else if(tree->opr->left->type == TID && tree->opr->right->type == TOP){
        decl *tmp;

        if(!strcmp(tree->opr->left->leaf->value,"int")){
          tmp = build_decl(TINT,tree->opr->right->opr->left->leaf->value);

        }
        else{
          tmp = build_decl(TVOID,tree->opr->right->opr->left->leaf->value);
        }

        add_block_declaration(table->definition_block,tmp);

        symbol_table_block *tmp_block;
        if(block_exists(print_table,table->definition_block->context) != NULL){
          tmp_block = block_exists(print_table,table->definition_block->context);
          add_block_declaration(tmp_block,tmp);
        }else{
          add_block_declaration(print_table->definition_block,tmp);
        }
      }
      ;
    }
    else if(!strcmp(tree->opr->optype,"program")){
      case_program_in_construct_table(tree,table,global_table,print_table);
    }

    else{
      construct_table(tree->opr->left,table,global_table,print_table);
      construct_table(tree->opr->right,table,global_table,print_table);
    }
  }
}








void case_program_in_construct_table(node_t *tree, symbol_table *table, symbol_table *global_table, symbol_table *print_table){

  if(tree->opr->left->type == TOP && tree->opr->right->type == TOP){

    if(!strcmp(tree->opr->left->opr->optype,"declaration")){
      case_global_declaration_in_construct_table(tree->opr->left,global_table);
    }
    else{
      construct_table(tree->opr->left,table,global_table,print_table);
    }
    if(!strcmp(tree->opr->right->opr->optype,"declaration")){
      case_global_declaration_in_construct_table(tree->opr->right,global_table);
    }
    else{
      construct_table(tree->opr->right,table,global_table,print_table);
    }
  }
  else{
    printf("??\n");
  }
}

void case_global_declaration_in_construct_table(node_t *tree, symbol_table *global_table){
  //printf("%d\n",tree->opr->left->type);
  if(tree->opr->left->type == TID && tree->opr->right->type == TID){
    decl *tmp;
    if(!strcmp(tree->opr->left->leaf->value,"int")){
      tmp = build_decl(TINT,tree->opr->right->leaf->value);
    }
    else{
      tmp = build_decl(TVOID,tree->opr->right->leaf->value);
    }
    add_block_declaration(global_table->definition_block,tmp);
  }
  //declaration of type: int i = 0;
  else if(tree->opr->left->type == TID && tree->opr->right->type == TOP){
    decl *tmp;

    if(!strcmp(tree->opr->left->leaf->value,"int")){
      tmp = build_decl(TINT,tree->opr->right->opr->left->leaf->value);

    }
    else{
      tmp = build_decl(TVOID,tree->opr->right->opr->left->leaf->value);
    }
    add_block_declaration(global_table->definition_block,tmp);
  }
}
