#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "parsetree.h"

/* built using leftmost child-right sibling tree*/

bool NODE_isLeaf(NODE node){
  if(node->leftChild==NULL && node->rightSibling==NULL){
    return true;
  }
  return false;
}

NODE NODE_new(char c, bool term){
  NODE new_node = (NODE)malloc(sizeof(struct _NODE));
  new_node->data = c;
  new_node->terminal = term;
  new_node->leftChild = NULL;
  new_node->rightSibling = NULL;
  return new_node;
}

void NODE_free(NODE n){
  free(n);
}

PARSETREE PARSETREE_new(NODE nroot){
  PARSETREE new_parse_tree = (PARSETREE)malloc(sizeof(struct _PARSETREE));
  new_parse_tree->root = nroot;
  return new_parse_tree;
}

void free_all(NODE root){
  if(root->leftChild!=NULL){
    free_all(root->leftChild);
  }
  if(root->rightSibling!=NULL){
    free_all(root->rightSibling);
  }
  NODE_free(root);
}

void PARSETREE_free(PARSETREE p){
  free_all(p->root);
  free(p);
}



bool PT_isTerminal(char c){
  switch ( c) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '+':
    case '-':
    case '*':
    case '/':
    case '(':
    case ')':
    case 'e':
      return true;
      break;
  }
  return false;
}

void PARSETREE_print(PARSETREE p){
  NODE_print_with_depth(0, p->root);
  printf("\n");
}

void NODE_print_with_depth(int depth, NODE n){
  if(n == NULL){
    return;
  } else {
    for(int i=1; i<=depth; i++){
      printf("  ");
    }
    printf("%c\n", n->data);
  }
  NODE_print_with_depth(depth+1, n->leftChild);
  NODE_print_with_depth(depth, n->rightSibling);
}

NODE PARSETREE_get_left_leaf(NODE root){
  if(root->leftChild!=NULL){
    NODE n1 = PARSETREE_get_left_leaf(root->leftChild);
    if(n1!=NULL) return n1;
  } else if(root->data != 'e' && !PT_isTerminal(root->data)){
    return root;
  }
  if(root->rightSibling!=NULL){
    NODE n2 = PARSETREE_get_left_leaf(root->rightSibling);
    if(n2!=NULL) return n2;
  }
  return NULL;
}
