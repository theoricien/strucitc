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

struct node_t *build_opr(char op, struct node_t *left, struct node_t *right){

  printf("entering build_opr \n");

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = TOP;

  tmp->opr = (struct opr_t *)malloc(sizeof (struct opr_t));
  assert (tmp->opr != NULL);

  tmp->opr->optype = op;
  tmp->opr->left = left;
  tmp->opr->right = right;

  return tmp;

}

struct node_t *build_uopr(char op, struct node_t *operand){

  struct node_t *tmp = (struct node_t *)malloc(sizeof (struct node_t));
  assert (tmp != NULL);

  tmp->type = TUOP;

  tmp->uopr = (struct uopr_t *)malloc(sizeof (struct uopr_t));
  assert (tmp->uopr != NULL);

  tmp->uopr->optype = op;
  tmp->uopr->operand = operand;

  return tmp;

}

void print_tab(int n){
  for(int i = 0; i < n; i++){
    printf(" ");
  }
}

void stringify(node_t * tree, int tab){

  print_tab(tab);

  if(tree->type == TID){
    printf("(%s : %s) \n","TID",tree->leaf->value);
  }
  else if(tree->type == TCONS){
    printf("(%s : %s) \n","TCONS",tree->leaf->value);
  }
  else if(tree->type == TUOP){
    printf("(%s : %c\n","TUOP",tree->uopr->optype);
    stringify(tree->uopr->operand,tab + 1);
    print_tab(tab);
    printf(")\n");
  }
  else{
    printf("(%s : %c\n","TOP",tree->opr->optype);
    stringify(tree->opr->left, tab + 1);
    stringify(tree->opr->right, tab + 1);
    print_tab(tab);
    printf(")\n");
  }
}
