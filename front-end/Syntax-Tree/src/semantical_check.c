#include "semantical_check.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>



void semantical_check(node_t *tree){
  symbol_table *table = build_symbol_table(tree);
  all_check(tree,table);
}



void check_type_of_block(node_t *tree, symbol_table_block *block){

  declaration_list *declaration_list = block->declarations;

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
         if(get_type_node(tree->opr->left,block) == get_type_node(tree->opr->left,block)){
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
        if(get_type_node(tree->opr->right,block) != TINT){
          printf("Error : cannot assign %s to non int\n",tree->opr->left->leaf->value);
          errors++;
        }
        check_type_of_block(tree->opr->right,declaration_list);
      }
    }
    else if(!strcmp(tree->opr->optype,"declaration")){
      if(get_type_node(tree->opr->left,block) != TINT){
        //TODO
      }
      else{
        //add_declaration(tree->opr->left,tree->opr->right,declaration_list);
        check_type_of_block(tree->opr->right,declaration_list);
      }
    }
    else if(!strcmp(tree->opr->optype, "block_item_list")){
      check_type_of_block(tree->opr->left,declaration_list);
      check_type_of_block(tree->opr->right,declaration_list);
    }
    else if(!strcmp(tree->opr->optype, "function_definition")){
      check_type_of_block(tree->opr->left,declaration_list);
      check_type_of_block(tree->opr->right,declaration_list);
    }
    else if(!strcmp(tree->opr->optype, "function")){
      ;
    }
  }

  if(errors != 0){
    printf("typecheck failed with %d errors \n",errors);
  }
}



void all_check(node_t *tree, symbol_table *table){
  if(tree->type == TID || tree->type == TCONS){
    return;
  }
  else if(tree->type == TOP){
    if(!strcmp(tree->opr->optype,"function_definition")){

      // get the function's name
      char *tmp_name;
      if(tree->opr->left->type == TOP && !strcmp(tree->opr->left->opr->optype,"function")){
        if(tree->opr->left->opr->right->type == TFUNC){
          tmp_name = malloc(strlen(tree->opr->left->opr->right->function->name->leaf->value));
          strcpy(tmp_name,tree->opr->left->opr->right->function->name->leaf->value);
        }
      }
      symbol_table_block *block = block_exists(table,tmp_name);
      check_type_of_block(tree,block);
    }
    else{
      all_check(tree->opr->left,table);
      all_check(tree->opr->right,table);
    }
  }
  else{
    if(tree->type == TFUNC){
      all_check(tree->function->name,table);
      all_check(tree->function->arguments,table);
    }
  }
}

type_spe get_type_node(node_t *tree, symbol_table_block *block){

  if(tree->type == TOP){
    if(get_type_node(tree->opr->left,block) == get_type_node(tree->opr->right,block)){
      return get_type_node(tree->opr->left,block);
    }
    else{
      return TNULL;
    }
  }
  else if(tree->type == TID){
    if(is_already_declared(tree->leaf->value,block)){
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
