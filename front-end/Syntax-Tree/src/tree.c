#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


////////////////////////////////////////////////

struct node_t *build_leaf(type_t type, char* value){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);


  tmp->type = type;

  tmp->leaf = (struct pexpr_t *)malloc(sizeof (struct pexpr_t));
  assert (tmp->leaf != NULL);


  tmp->leaf->value = (char *)malloc(strlen (value) + 1);
  assert (tmp->leaf->value != NULL);
  strcpy(tmp->leaf->value, value);


  return tmp;

}

struct node_t *build_opr(char *op, struct node_t *left, struct node_t *right){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = TOP;

  tmp->opr = (struct opr_t *)malloc(sizeof (struct opr_t));
  assert (tmp->opr != NULL);

  tmp->opr->optype = (char *)malloc(strlen (op) + 1);
  assert (tmp->opr->optype != NULL);
  strcpy(tmp->opr->optype, op);

  tmp->opr->left = left;
  tmp->opr->right = right;

  return tmp;

}

struct node_t *build_uopr(char* op, struct node_t *operand){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = TUOP;

  tmp->uopr = (struct uopr_t *)malloc(sizeof (struct uopr_t));
  assert (tmp->uopr != NULL);

  tmp->uopr->optype = (char *)malloc(strlen (op) + 1);
  assert (tmp->uopr->optype != NULL);
  strcpy(tmp->uopr->optype, op);

  tmp->uopr->operand = operand;

  return tmp;

}


struct node_t *build_if(struct node_t *condition, struct node_t *if_true, struct node_t *if_false){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = TIF;

  tmp->if_node = (struct if_t *)malloc(sizeof (struct if_t));
  assert (tmp->if_node != NULL);

  tmp->if_node->cond = condition;
  tmp->if_node->true = if_true;
  tmp->if_node->false = if_false;

  return tmp;

}



struct node_t *build_for(struct node_t *start, struct node_t *end, struct node_t *incr, struct node_t *body){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = TFOR;

  tmp->for_loop = (struct for_t *)malloc(sizeof (struct for_t));
  assert (tmp->for_loop != NULL);

  tmp->for_loop->start_statement = start;
  tmp->for_loop->end_statement = end;
  tmp->for_loop->forward_expression = incr;
  tmp->for_loop->do_statement = body;

  return tmp;

}

node_t *build_func(node_t *func_name, node_t *arguments){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  //assert(func_name->type == TCONS || func_name->type == TID);
  tmp->type = TFUNC;

  tmp->function = (struct func_t *)malloc(sizeof (struct func_t));
  assert (tmp->function != NULL);

  tmp->function->name = func_name;
  if(arguments == NULL){
    tmp->function->arguments = build_leaf(TT,"void");
  }
  else{
    tmp->function->arguments = arguments;
  }

  return tmp;

}

node_t *build_struct(node_t * name, node_t * struct_body){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  //assert(func_name->type == TCONS || func_name->type == TID);
  tmp->type = TSTRUCT;

  tmp->struct_node = (struct struct_t *)malloc(sizeof (struct struct_t));
  assert (tmp->function != NULL);

  tmp->struct_node->name = name;;
  tmp->struct_node->struct_declaration = struct_body;

  return tmp;
}

list_t *build_arg_list(node_t* argument){

  struct list_t *new_list = (struct list_t *)malloc(sizeof(struct list_t) + 1);
  new_list->current = argument;
  new_list->next = NULL;

  return new_list;
}

// Pour argument_expression_list ',' assignment_expression
list_t *add_arg_list(list_t *argument ,list_t *list){

  struct list_t *new_list = (struct list_t *)malloc(sizeof(struct list_t) + 1);
  new_list->current = argument->current;
  new_list->next = NULL;

  if(list->next != NULL){

    list_t *tmp = list->next;

    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = new_list;
  }
  else{
    list->next = new_list;
  }
  return list;

}

/**
* return 1 if already declared, 0 if not
**/
int is_already_declared(char* name, declarations *declaration_list){

  int debug = 1;

  if(declaration_list->current != NULL){
    if(declaration_list->current->name !=NULL){
      //if(debug){printf("%s\n",declaration_list->current->name);}
      if(!strcmp(name,declaration_list->current->name)){
        return 1;
      }
    }
  }
  if(declaration_list->next !=NULL){
    declarations *tmp = declaration_list;
    while(tmp !=NULL){
      if(!strcmp(name,tmp->current->name)){
        return 1;
      }
      tmp = tmp->next;
    }
  }
  return 0; // not found
}

type_spe get_variable_type(char* name, declarations *declaration_list){
  if(declaration_list->current->name !=NULL){
    if(!strcmp(name,declaration_list->current->name)){
      return declaration_list->current->type;
    }
  }
  if(declaration_list->next !=NULL){
    declarations *tmp = declaration_list;
    while(tmp->next !=NULL){
      if(!strcmp(name,tmp->current->name)){
        return tmp->current->type;
      }
      tmp = tmp->next;
    }
  }
  return TNULL; // not found
}

/**
* Handle multiple declarations
**/

void add_declaration(node_t *type_node, node_t *name, declarations *declaration_list){

  decl *new_declaration = (decl*) malloc(sizeof(struct decl)+1);

  //Build new declaration: add declaration name (right node of opr)
  // /!\ not especially a leaf
  // Doing this first because of the return if name already exists
  if(name->type == TID){
    if(!is_already_declared(name->leaf->value,declaration_list)){
      new_declaration->name = (char *)malloc(strlen(name->leaf->value) + 1);
      assert (new_declaration->name != NULL);
      strcpy(new_declaration->name, name->leaf->value);
    }
    else{
      printf("Error: %s is already declared \n",name->leaf->value);
      return;
    }
  }
  // A modifier pour avoir plusieurs top à la suite... TODO
  else if(name->type == TOP){ // non terminal

    if(is_already_declared(name->opr->left->leaf->value,declaration_list) == 0){
      new_declaration->name = (char *)malloc(strlen(name->opr->left->leaf->value) + 1);
      assert (new_declaration->name != NULL);
      strcpy(new_declaration->name, name->opr->left->leaf->value);
    }
    else{
      printf("Error: %s is already declared \n",name->opr->left->leaf->value);
      return;
    }
  }

  // add type (left node of opr)
  if(type_node->type == TID){
    if(!strcmp(type_node->leaf->value,"int")){
      new_declaration->type = TINT;
    }
    else{
      new_declaration->type = TVOID;
    }
  }

  //add the new declaration to our list
  if(declaration_list->current == NULL){
    declaration_list->current = new_declaration;
  }
  else if(declaration_list->next == NULL){
    declarations *new_declaration_list = (declarations*) malloc(sizeof(struct declarations));
    new_declaration_list->current = new_declaration;
    new_declaration_list->next = NULL;
    declaration_list->next = new_declaration_list;
  }
  else{
    declarations *new_declaration_list = (declarations*) malloc(sizeof(struct declarations));
    new_declaration_list->current = new_declaration;
    new_declaration_list->next = NULL;

    declarations *tmp = declaration_list->next;
    while(tmp->next != NULL){
      tmp = tmp->next;
    }
    tmp->next = new_declaration_list;
  }

}

/**
* Retourne le type d'un noeud. Si le type est contradictoire , retourne TNULL
**/

type_spe get_type_node(node_t *tree, declarations *declaration_list){

  if(tree->type == TOP){
    if(get_type_node(tree->opr->left,declaration_list) == get_type_node(tree->opr->right,declaration_list)){
      return get_type_node(tree->opr->left,declaration_list);
    }
    else{
      return TNULL;
    }
  }
  else if(tree->type == TID){
    if(is_already_declared(tree->leaf->value,declaration_list)){
      return TINT;
    }
    else{
      return TNULL;
    }
  }
  else if(tree->type == TCONS){
    return TINT;
  }
  return TNULL;
}

void check_all_types(node_t *tree){

  declarations *declaration_list = (struct declarations*)malloc(sizeof(struct declarations));
  declaration_list->current = NULL;
  declaration_list->next = NULL;
  check_type(tree,declaration_list);
}

void check_type(node_t *tree, declarations *declaration_list){


  int errors = 0;
  if(tree->type == TOP){
    // verify arithmeticals expressions
    if(!strcmp(tree->opr->optype, "+") || !strcmp(tree->opr->optype, "-") ||
     !strcmp(tree->opr->optype, "*") || !strcmp(tree->opr->optype, "/") ){
       if((tree->opr->left->type == TCONS) && (tree->opr->right->type == TCONS)){
         return;
       }
       if(tree->opr->left->type == TID){
         if(is_already_declared(tree->opr->left->leaf->value,declaration_list) == 0){
           printf("Error : undeclared variable: %s \n",tree->opr->left->leaf->value);
           errors++;
         }
         else{
           if(get_variable_type(tree->opr->left->leaf->value,declaration_list) != TINT){
             printf("Error : cannot make arithmetic operations on VOID \n");
             errors++;
           }
         }
       }else if(tree->opr->right->type == TID){
         if(is_already_declared(tree->opr->right->leaf->value,declaration_list) == 0){
           printf("Error : undeclared variable: %s \n",tree->opr->right->leaf->value);
           errors++;
         }
         else{
           if(get_variable_type(tree->opr->right->leaf->value,declaration_list) != TINT){
             printf("Error : cannot make arithmetic operations on VOID \n");
             errors++;
           }
         }
       }
       else if((tree->opr->left->type == TOP) || (tree->opr->right->type == TOP)){
         if(get_type_node(tree->opr->left,declaration_list) == get_type_node(tree->opr->left,declaration_list)){
           return;
         }
         else{
           printf("Error : uncompatible types for arithmetic operation \n");
           errors++;
         }
       }
    }
    else if(!strcmp(tree->opr->optype, "=")){
      if(tree->opr->left->type == TFUNC){
          ;//TODO
      }else if(tree->opr->left->type == TID){
        if(!is_already_declared(tree->opr->left->leaf->value,declaration_list)){
          printf("Error : %s is not declared \n",tree->opr->left->leaf->value);
          errors++;
        }
        if(get_type_node(tree->opr->right,declaration_list) != TINT){
          printf("Error : cannot assign %s to non int\n",tree->opr->left->leaf->value);
          errors++;
        }
        check_type(tree->opr->right,declaration_list);
      }
    }
    else if(!strcmp(tree->opr->optype,"declaration")){
      if(get_type_node(tree->opr->left,declaration_list) != TINT){
        //TODO 
      }
      else{
        add_declaration(tree->opr->left,tree->opr->right,declaration_list);
        check_type(tree->opr->right,declaration_list);
      }
    }
    else if(!strcmp(tree->opr->optype, "block_item_list")){
      check_type(tree->opr->left,declaration_list);
      check_type(tree->opr->right,declaration_list);
    }
    else if(!strcmp(tree->opr->optype, "function_definition")){
      check_type(tree->opr->left,declaration_list);
      check_type(tree->opr->right,declaration_list);
    }
    else if(!strcmp(tree->opr->optype, "function")){
      ;
    }
  }
  /*
  if(errors != 0){
    printf("typecheck failed with %d errors \n",errors);
  }*/
}


void print_tab(int n){
  for(int i = 0; i < n; i++){
    printf(" ");
  }
}

void stringify(node_t * tree, int tab){

  print_tab(tab);
  //printf("%d\n",tree->type);

  if(tree->type == TID){
    printf("(%s : %s) \n","TID",tree->leaf->value);
  }
  else if(tree->type == TCONS){
    printf("(%s : %s) \n","TCONS",tree->leaf->value);
  }
  else if(tree->type == TUOP){
    printf("(%s : %s\n","TUOP",tree->uopr->optype);
    stringify(tree->uopr->operand,tab + 4);
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TOP){
    printf("(%s : %s\n","TOP",tree->opr->optype);
    stringify(tree->opr->left, tab + 4);
    if(tree->opr->right != NULL){
      stringify(tree->opr->right, tab + 4);
    }
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TT){
    printf("(%s : %s) \n","TID",tree->leaf->value);
  }
  else if(tree->type == TIF){
    printf("(%s)\n","TIF");
    stringify(tree->if_node->cond, tab + 4);
    stringify(tree->if_node->true, tab + 4);
    if(tree->if_node->false != NULL){
      stringify(tree->if_node->false, tab + 4);
    }
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TFOR){
    printf("(%s :\n","TFOR");
    stringify(tree->for_loop->start_statement, tab + 4);
    stringify(tree->for_loop->end_statement, tab + 4);
    stringify(tree->for_loop->forward_expression, tab + 4);
    stringify(tree->for_loop->do_statement, tab + 4);
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TRET){
    printf("(%s : %s) \n","TID",tree->leaf->value);
  }
  else if(tree->type == TFUNC){
    printf("(%s :\n","TFUNC");
    stringify(tree->function->name, tab + 4);
    stringify(tree->function->arguments, tab + 4);
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TSTRUCT){
    printf("(%s :\n","TSTRUCT");
    if(tree->struct_node->name != NULL){
      stringify(tree->struct_node->name, tab + 4);
    }
    if(tree->struct_node->struct_declaration != NULL){
      stringify(tree->struct_node->struct_declaration, tab + 4);
    }
    print_tab(tab);
    printf(")\n");
  }
  else{
    printf("%s : %d\n","unknown error", tree->type);
  }
}
