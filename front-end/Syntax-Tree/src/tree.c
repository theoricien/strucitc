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


struct node_t *build_list(type_t type, char* context, struct node_t *current, struct node_t *next){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = type;

  tmp->list = (struct list_t *)malloc(sizeof (struct list_t));
  assert (tmp->list != NULL);

  tmp->list->context = context;
  tmp->list->current = current;
  tmp->list->next = next;

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
    stringify(tree->opr->right, tab + 4);
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TS){
    printf("(%s : %s\n","TS",tree->list->context);
    stringify(tree->list->current, tab + 4);
    stringify(tree->list->next, tab + 4);
    print_tab(tab);
    printf(")\n");
  }
  else if(tree->type == TD){
    printf("(%s : %s\n","TD",tree->list->context);
    stringify(tree->list->current, tab + 4);
    stringify(tree->list->next, tab + 4);
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
  else{
    printf("%s : %d\n","unknown error", tree->type);
  }
}
