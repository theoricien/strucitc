#include "semantical_check.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


int semantical_check_on_function_declaration_block(node_t *tree, symbol_table_block *block, symbol_table_block *global_block, function_arguments* fa){

  declaration_list *declaration_list = block->declarations;
  int errors = 0;

  if(tree->type == TOP){

    if(tree->leaf->value != NULL){
      if(!strcmp(tree->leaf->value,"void")){
        ;
      }
      else{
        if(tree->opr->left->type == TOP){
          if(!strcmp(tree->opr->left->opr->optype, "function")){
            add_all_arg_count(tree->opr->left->opr->right,get_type_parameter_declaration(tree->opr->left->opr->left),fa);
          }
        }

        if(!strcmp(tree->opr->optype, "=")){
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->left,block,global_block,fa);
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->right,block,global_block,fa);
          errors = errors + check_equal_assignment(tree,block,global_block,fa);
        }
        else if(!strcmp(tree->opr->optype,"declaration")){
          errors = errors + semantical_check_on_declaration(tree,block,global_block,fa);
        }
        else if(!strcmp(tree->opr->optype, "function_definition")){
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->left,block,global_block,fa);
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->right,block,global_block,fa);
        }
        else if(!strcmp(tree->opr->optype, "function")){
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->right,block,global_block,fa);
        }
        // TODO: functions (calls)
        else if(!strcmp(tree->opr->optype, "parameter_declaration")){
          errors = errors + semantical_check_on_parameter_declaration(tree,block,global_block,fa);
        }
        else if(!strcmp(tree->opr->optype,"+") || !strcmp(tree->opr->optype,"-")
                || !strcmp(tree->opr->optype,"*") || !strcmp(tree->opr->optype,"/")){

          check_arithmetical_expression(tree,block,fa);
        }
        else{
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->left,block,global_block,fa);
          errors = errors + semantical_check_on_function_declaration_block(tree->opr->right,block,global_block,fa);
        }
      }
    }
  }
  else if(tree->type == TFUNC){
    errors = errors + semantical_check_on_function_declaration_block(tree->function->arguments,block,global_block,fa);
  }

  return errors;
}






int semantical_check_on_declaration(node_t *tree, symbol_table_block *block, symbol_table_block *global_block, function_arguments *fa){

  declaration_list *declaration_list = block->declarations;
  int errors = 0;

  if(tree->opr->left->type == TID){
    if(!strcmp(tree->opr->left->leaf->value,"void")){
      printf("[Error] Cannot have a variable of type VOID\n");
      errors ++;
    }
  }

  if(tree->type == TOP){
    if(tree->opr->right->type == TOP){
      semantical_check_on_declaration(tree->opr->right,block,global_block,fa);
      if(!strcmp(tree->opr->right->opr->optype,"=")){
        if(tree->opr->right->opr->right != NULL){
          if(tree->opr->right->opr->right->type != TFUNC){
            check_equal_assignment(tree->opr->right,block,global_block,fa);
          }
          else{
            node_t *tmp_equal = tree->opr->right; // for lisibility
            if(tree->opr->left->type == TID && tmp_equal->opr->right->type == TFUNC){
              if(get_type_node(tree->opr->left,block) != get_type_node(tmp_equal->opr->right->function->name,global_block)){
                errors = errors + function_call_check_type(get_type_node(tree->opr->left,block),get_type_node(tmp_equal->opr->right->function->name,global_block));
              }
            }
            else{
              printf("[Error] Need an identifer as left operand of assignment\n");
              errors ++;
            }
            semantical_check_on_function(tree->opr->right->opr->right,block,global_block,fa);
          }
        }else{
          check_equal_assignment(tree->opr->right,block,global_block,fa);
        }
      }
    }
    else if(tree->opr->right->type == TUOP){
      ;
    }
    else if(tree->opr->right->type == TFUNC){
      ;
    }
    else if(is_already_declared(tree->opr->right->leaf->value,block) == 0){
      if(tree->opr->right->type == TCONS){
        if((tree->opr->right->leaf->value[0] == '\"') || (tree->opr->right->leaf->value[0] == '\'')){
          printf("[Error]: strings are not handeled: found %s\n",tree->opr->right->leaf->value);
          errors++;
        }
      }
      else{
        printf("[Error]: undeclared variable: %s in block %s\n",tree->opr->right->leaf->value,block->context);
        if(declaration_list != NULL){
        }
        errors++;
      }
    }
  }
  return errors;
}

/*
* type_caller: type of the identifer to put the result in;
* type_called: type of the function called
*/

int function_call_check_type(type_t type_caller,type_t type_called){

  int errors = 0;

  if(type_caller == TINT && type_called == FINT){
    return 0;
  }
  if(type_called == FVOID){
    printf("[Error] Can't assign value with void function\n");
    errors++;
  }
  if(type_caller == FINT){
    printf("[Error] Type clash between left operand and function call\n");
    errors++;
  }
  return errors;
}


/*
* tree is supposed to be a TFUNC
*/
int semantical_check_on_function(node_t *tree, symbol_table_block *block, symbol_table_block *global_block){

}


int semantical_check_on_parameter_declaration(node_t *tree, symbol_table_block *block, symbol_table_block *global_block, function_arguments* fa){

  declaration_list *declaration_list = block->declarations;
  int errors = 0;

  errors = errors + semantical_check_on_declaration(tree,block,global_block,fa);
  if(errors != 0){
    printf("[Warning] Function attribute %s override previous declaration",tree->opr->right->leaf->value);
  }

  return errors;
}


/*      ================================================================
*
*       ================================================================
*/

/*
* Assumes to have a TOP with either +, -, *, / as optype
* Checks if operands are correct, and if an identifier is found, check if he is declared;
* Returns the number of errors found (0 if no errors)
*/
int check_arithmetical_expression(node_t *tree,symbol_table_block *block, function_arguments* fa){

  int errors = 0;
  declaration_list *declaration_list = block->declarations;
  if((tree->opr->left->type == TCONS) || (tree->opr->right->type == TCONS)){

    if((tree->opr->left->leaf->value[0] == '\"') || (tree->opr->left->leaf->value[0] == '\'')){
      printf("[Error]: strings are not handeled: found %s\n",tree->opr->left->leaf->value);
      errors ++;
    }
    if((tree->opr->right->leaf->value[0] == '\"') || (tree->opr->right->leaf->value[0] == '\'')){
      printf("[Error]: strings are not handeled: found %s\n",tree->opr->right->leaf->value);
      errors++;
    }
  }
  if((tree->opr->left->type == TCONS) && (tree->opr->right->type == TCONS)){
    return;
  }
  if(tree->opr->left->type == TID){
    if(is_already_declared(tree->opr->left->leaf->value,declaration_list) == 0){
      printf("[Error] : undeclared variable: %s in block %s\n",tree->opr->left->leaf->value,block->context);
      errors++;
    }
    else{
      if(get_variable_type(tree->opr->left->leaf->value,declaration_list) != TINT){
        printf("[Error] : cannot make arithmetic operations on VOID \n");
        errors++;
      }
    }
  }else if(tree->opr->right->type == TID){
    if(is_already_declared(tree->opr->right->leaf->value,declaration_list) == 0){
      printf("[Error] : undeclared variable: %s in block %s\n",tree->opr->right->leaf->value,block->context);
      errors++;
    }
    else{
      if(get_variable_type(tree->opr->right->leaf->value,declaration_list) != TINT){
        printf("[Error] : cannot make arithmetic operations on VOID \n");
        errors++;
      }
    }
    return errors;
  }
  else if((tree->opr->left->type == TOP) || (tree->opr->right->type == TOP)){
    if(get_type_node(tree->opr->left,block) == get_type_node(tree->opr->left,block)){
      return;
    }
    else{
      printf("[Error] : uncompatible types for arithmetic operation \n"); // TODO node to string
      errors++;
    }
  }
}


/*
* Assumes to have a TOP with = as optype
* Checks if operands are correct, and if an identifier is found, check if he is declared;
* Right operand can be a function, an arethmetical operation or an identifer
* Returns the number of errors found (0 if no errors)
*/
int check_equal_assignment(node_t *tree, symbol_table_block *block, symbol_table_block *global_block, function_arguments* fa){

  int errors = 0;
  declaration_list *declaration_list = block->declarations;

  if(tree->opr->right->type == TFUNC){
      ;//TODO
  }else if(tree->opr->left->type == TID){
    if(!is_already_declared(tree->opr->left->leaf->value,declaration_list)){
      printf("[Error] : %s is not declared in block %s\n",tree->opr->left->leaf->value,block->context);
      errors++;
    }
    if(get_type_node(tree->opr->left,block) != get_type_node(tree->opr->right,block)){
      if(get_type_node(tree->opr->left,block) == TINT){
        if(get_type_node(tree->opr->right,block) != TINT){
          if(get_type_node(tree->opr->right,block) == PTRINT){
            printf("[Warning] : make int from pointer without a cast\n",tree->opr->left->leaf->value);
          }
          else{
            printf("[Error] : cannot assign %s to non int\n",tree->opr->left->leaf->value);
            errors++;
          }
        }
      }
    }
  }
  else if(tree->opr->left->type == TUOP){
    if(tree->opr->left->uopr->operand != NULL){
      if(get_type_node(tree->opr->left,block) == PTRINT){
        if(get_type_node(tree->opr->right,block) == TINT){
          printf("[Warning] : make pointer from int without a cast\n",tree->opr->left->leaf->value);
        }
        else{
          printf("[Error] : cannot assign %s to non int\n",tree->opr->left->leaf->value);
          errors++;
        }
      }
    }
  }
  else if(tree->opr->left->type == TCONS){
    printf("[Error]: cannot assign a value to %s\n",tree->opr->left->leaf->value);
    errors++;
  }

  if(tree->opr->right->type == TCONS){
    if((tree->opr->right->leaf->value[0] == '\"') || (tree->opr->right->leaf->value[0] == '\'')){
      printf("[Error]: strings are not handeled: found %s\n",tree->opr->right->leaf->value);
      errors ++;
    }
  }
  if(tree->opr->right->type == TOP){
    semantical_check_on_function_declaration_block(tree->opr->right,block,global_block,fa);
  }
  return errors;
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
    if((tree->leaf->value[0] == '\"') || (tree->leaf->value[0] == '\'')){
      printf("[Error]: strings are not handeled: found %s\n",tree->leaf->value);
    }
    return TINT;
  }
  else if(tree->type == TFUNC){
    if(is_already_declared(tree->function->name,block)){
      if(block->declarations != NULL){
        return get_type(tree->function->name,block->declarations);
      }
    }
  }
  else if(tree->type == TUOP){
    if(!strcmp(tree->uopr->optype,"pointer")){
      if(get_type_node(tree->uopr->operand,block) == TINT){
        return PTRINT;
      }
      else{
        return PTRVOID;
      }
    }
    else if(!strcmp(tree->uopr->optype,"pointer_direct_declarator")){
      if(get_type_node(tree->uopr->operand,block) == TINT){
        return PTRINT;
      }
      else{
        return PTRVOID;
      }
    }
  }
  return TNULL;
}


type_spe get_type_parameter_declaration(node_t *tree){
  if(tree->type == TID){
    if(!strcmp(tree->leaf->value,"int")){
      return TINT;
    }
  }else if(tree->type == TUOP){
    if(!strcmp(tree->uopr->optype,"pointer_direct_declarator")){
      return PTRINT;
    }
  }else if(tree->type == TOP){
    if(!strcmp(tree->opr->optype,"parameter_declaration")){
      if(tree->opr->left->type == TID){
        if(!strcmp(tree->opr->left->leaf->value,"int")){
          if(tree->opr->right->type == TID){
            return TINT;
          }
          else if(tree->opr->right->type == TUOP){
            return PTRINT;
          }
        }
        else{ // case void
          if(tree->opr->right->type == TID){
            return TVOID;
            printf("[Error] Got an argument of type VOID.\n");
          }
          else if(tree->opr->right->type == TUOP){
            return PTRVOID;
          }
        }
      }
      else{
        return TNULL;
      }
    }
  }
  return TNULL;
}





/*  ===================================================================
*                   FUNCTIONS ON FUNCTION'S ARGUMENTS
*   ===================================================================
*/

/*
* Function to call when you find a TFUNC in declaration
* We suppose that tree is of type TFUNC
*/
void add_all_arg_count(node_t *tree, type_spe type, function_arguments *fa){

  if(tree->type != TFUNC){
    return;
  }
  char *fname = tree->function->name->leaf->value;
  add_one_arg_count(fname,type,fa);

  if(tree->function->arguments->type = TOP){
    if(!strcmp(tree->function->arguments->opr->optype,"parameter_declaration")){
      node_t *type_char = tree->function->arguments->opr->left->leaf;
      add_fun_arg(get_declaration_name(tree->function->arguments),get_type_parameter_declaration(type_char),fa);
    }
    else if(!strcmp(tree->function->arguments->opr->optype,"parameter_list")){
      add_all_arg_inter(tree->function->arguments->opr->left,fname,fa);
      add_all_arg_inter(tree->function->arguments->opr->right,fname,fa);
    }
  }
}

void add_all_arg_inter(node_t* tree, char* name, function_arguments* fa){

  if(tree->type != TOP){
    return;
  }
  if(tree->type = TOP){
    if(!strcmp(tree->opr->optype,"parameter_declaration")){
      add_fun_arg(get_declaration_name(tree),get_type_parameter_declaration(tree->opr->left->leaf),fa);
    }
    else if(!strcmp(tree->function->arguments->opr->optype,"parameter_list")){
      add_all_arg_inter(tree->opr->left,name,fa);
      add_all_arg_inter(tree->opr->right,name,fa);
    }
  }
}

/*
* Add a new function_argument on our next
* Called when a new function is declared
*/
void add_one_arg_count(char *name, type_spe type, function_arguments *fa){
  function_arguments *tmp_fa = find_function_in_fa(name,fa);
  if(tmp_fa != NULL){
    printf("[Error]: Redefining function %s within a same range\n",name);
  }
  else{
    tmp_fa = fa;
    while (tmp_fa->next != NULL) {
      if(tmp_fa->name != NULL){
        tmp_fa = tmp_fa->next;
      }else{
        break;
      }
    }
    tmp_fa->next = build_function_argument(TNULL);
    tmp_fa->name = (char*)malloc(strlen(name)+1);
    strcpy(tmp_fa->name,name);
    tmp_fa->nb = 0;
    tmp_fa->type = type;

  }

}

/*
* Add an arguments at fa->arguments
*/
void add_fun_arg(char *name, type_spe type, function_arguments *fa){
  arguments *tmp_arg = fa->args;
  if(fa->args != NULL){

    tmp_arg = find_arg_in_function(name,fa->args);
    if(tmp_arg != NULL){
      printf("[Error]: Redefining argument %s in function %s\n",name,fa->name);
    }else{
      tmp_arg = fa->args;
      while (tmp_arg->next != NULL){
        tmp_arg = tmp_arg->next;
      }
      if(name != NULL){
        tmp_arg->name = (char*)malloc(strlen(name));
        strcpy(tmp_arg->name,name);
        tmp_arg->type = type;
        tmp_arg->next = build_args();
        fa->nb = fa->nb + 1;
      }
    }
  }
  else{
    fa->args = build_args();
    if(name != NULL){
      fa->args->name = (char*)malloc(strlen(name) +1);
      strcpy(fa->args->name,name);
    }
    fa->args->type = type;
  }
}



arguments *find_arg_in_function(char* name, arguments* args){

  if(args != NULL){
    if(args->name !=NULL){
      if(!strcmp(name,args->name)){
        return args;
      }
    }
    if(args->next != NULL){
      return find_arg_in_function(name,args->next);
    }
    else{
      return NULL;
    }
  }
  else{
    return NULL;
  }
}

/*
* Called when on a TOP: parameter_declaration
*/
char* get_declaration_name(node_t *tree){
  if (tree->type == TOP) {
    if(tree->opr->right->type == TID){
      return tree->opr->right->leaf->value;
    }
    else if(tree->opr->right->type == TUOP){
      if(tree->opr->right->uopr->operand->type == TID){
        return tree->opr->right->uopr->operand->leaf->value;
      }else{
        return NULL;;
      }
    }
    else{
      return NULL;
    }
  }else{
    return NULL;
  }
}
/*
* Return the pointer on the corresponding name in fa
*/
function_arguments *find_function_in_fa(char *name, function_arguments *fa){

  if(fa != NULL){
    if(fa->name !=NULL){
      if(!strcmp(name,fa->name)){
        return fa;
      }
    }
    if(fa->next != NULL){
      return find_function_in_fa(name,fa->next);
    }
    else{
      return NULL;
    }
  }
  else{
    return NULL;
  }

}

function_arguments *build_function_argument(type_spe type){

  function_arguments *f = (struct function_arguments*)malloc(sizeof(struct function_arguments));
  f->name = NULL;
  f->nb = 0;
  f->next = NULL;
  f->args = build_args();
  f->type = type;

  return f;
}

arguments *build_args(){
  arguments *a = (struct arguments*)malloc(sizeof(struct arguments));
  a->name = NULL;
  a->type = TNULL;
  a->next = NULL;

  return a;
}

int count_function_arguments(char *func_name, function_arguments *fa){

  return 0;
}

void print_function_arguments(function_arguments *fa){
  if(fa->name !=NULL){
    printf("func name : %s, type: %d, nb of args: %d\n",fa->name,fa->type,fa->nb);
    if(fa->args !=NULL){
      arguments *a = fa->args;
      if(a->name !=NULL){
        printf("arg name: %s, arg type: %d\n",a->name,a->type);
        a = a->next;
      }
      while(a->name != NULL){
        printf("arg name: %s, arg type: %d\n",a->name,a->type);
        a = a->next;
      }
    }
    function_arguments *tmp_fa = fa->next;
    if(tmp_fa->name != NULL){
      print_function_arguments(tmp_fa);
    }
  }
}



/*      ================================================================
*
*       ================================================================
*/

void all_check(node_t *tree, symbol_table *table, symbol_table* global_table, function_arguments* fa){

  int errors = 0;
  symbol_table_block *global_block = global_table->definition_block;

  if((tree->type == TID) || (tree->type == TCONS)){
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
      if(block == NULL && tmp_name != NULL){
        printf("Error in all check: block is null (name : %s)\n",tmp_name);
      }
      else{

        //errors = errors + semantical_check_on_function_declaration_block(tree->opr->left,block,global_block,fa);
        errors = errors + semantical_check_on_function_declaration_block(tree,block,global_block,fa);
      }
    }
    else if(!strcmp(tree->opr->optype,"declaration")){
      errors = errors + semantical_check_on_declaration(tree,global_block,global_block,fa);
    }
    else if(!strcmp(tree->opr->optype,"=")){
      check_equal_assignment(tree,global_table->definition_block,global_block,fa);
    }
    else if(!strcmp(tree->opr->optype,"+") || !strcmp(tree->opr->optype,"-")
            || !strcmp(tree->opr->optype,"*") || !strcmp(tree->opr->optype,"/")){
      check_arithmetical_expression(tree,global_table->definition_block,fa);
    }
    else{
      all_check(tree->opr->left,table,global_table,fa);
      all_check(tree->opr->right,table,global_table,fa);
    }
  }
  else{
    if(tree->type == TFUNC){
      all_check(tree->function->name,table,global_table,fa);
      all_check(tree->function->arguments,table,global_table,fa);
    }
    else{
      printf("not supposed to be here\n");
    }
  }
}


void semantical_check(node_t *tree){
  all_tables *tables = build_symbol_table(tree);
  symbol_table *table = tables->table;
  symbol_table *global_table = tables->global_table;
  print_symbol_table(global_table,0);
  printf("\n");
  function_arguments *fa = build_function_argument(TNULL);
  all_check(tree,table,global_table,fa);
  printf("\n\n");
  print_function_arguments(fa);
}
