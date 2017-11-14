#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parsetree.h"
#include "tdp-arith.h"
#include "LinkedList.h"

char* nextInputChar;
LinkedList* stack;
int parseTable[9][16] = {
  /*E*/{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  /*t*/{2, 22,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 },
  /*T*/{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 ,4 },
  /*f*/{6, 6, 5, 23,6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
  /*F*/{0, 0, 0, 0, 8, 0, 7, 7, 7, 7, 7, 7, 7 ,7 ,7 ,7 },
  /*n*/{11,11,11,11,11,11,10,10,10,10,10,10,10,10,10,10},
  /*N*/{0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
  /*D*/{0, 0, 0, 0, 0, 0, 13,14,15,16,17,18,19,20,21,12}
};

bool TDP_matchTerminal(TD_PARSER tdp, char c){
  if(*nextInputChar == c){
    nextInputChar++;
    return true;
  } else {
    return false;
  }
}

char TDP_lookahead(TD_PARSER tdp){
  if(tdp->curr < tdp->length){
    return *nextInputChar;
  }
  return '\0';
}

LinkedList* int_to_production(TD_PARSER tdp, int i){
  //NODE n;
  NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
  switch (i){
    case -1:
      return NULL;
    case 1:
      LinkedList_add_at_front(stack, "t");
      LinkedList_add_at_front(stack, "T");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('T', false);
      n->leftChild->rightSibling = NODE_new('t', false);
      return stack;
    case 2:
      LinkedList_add_at_front(stack, "t");
      LinkedList_add_at_front(stack, "T");
      LinkedList_add_at_front(stack, "+");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('+', true);
      n->leftChild->rightSibling = NODE_new('T', true);
      n->leftChild->rightSibling->rightSibling = NODE_new('t', true);
      return stack;
    case 3:
      LinkedList_add_at_front(stack, "e");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('e', true);
      return stack;
    case 4:
     LinkedList_add_at_front(stack,"f");
     LinkedList_add_at_front(stack,"F");
    //  NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
     n->leftChild = NODE_new('F', false);
     n->leftChild->rightSibling = NODE_new('f', false);
     return stack;
    case 5:
      LinkedList_add_at_front(stack, "f");
      LinkedList_add_at_front(stack, "F");
      LinkedList_add_at_front(stack, "*");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('*', true);
      n->leftChild->rightSibling = NODE_new('F', false);
      n->leftChild->rightSibling->rightSibling = NODE_new('f', true);
      return stack;
    case 6:
      LinkedList_add_at_front(stack, "e");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('e', true);
      return stack;
    case 7:
      LinkedList_add_at_front(stack, "N");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('N', false);
      return stack;
    case 8:
      LinkedList_add_at_front(stack, ")");
      LinkedList_add_at_front(stack, "E");
      LinkedList_add_at_front(stack, "(");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('(', true);
      n->leftChild->rightSibling = NODE_new('E', false);
      n->leftChild->rightSibling->rightSibling = NODE_new(')', true);
      return stack;
    case 9:
      LinkedList_add_at_front(stack, "n");
      LinkedList_add_at_front(stack, "D");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('D', false);
      n->leftChild->rightSibling = NODE_new('n', false);
      return stack;
    case 10:
      LinkedList_add_at_front(stack, "N");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('N', false);
      return stack;
    case 11:
      LinkedList_add_at_front(stack, "e");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('e', true);
      return stack;
    case 12:
      LinkedList_add_at_front(stack, "0");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('0', true);
      return stack;
    case 13:
      LinkedList_add_at_front(stack, "1");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('1', true);
      return stack;
    case 14:
      LinkedList_add_at_front(stack, "2");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('2', true);
      return stack;
    case 15:
      LinkedList_add_at_front(stack, "3");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('3', true);
      return stack;
    case 16:
      LinkedList_add_at_front(stack, "4");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('4', true);
      return stack;
    case 17:
      LinkedList_add_at_front(stack, "5");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('5', true);
      return stack;
    case 18:
      LinkedList_add_at_front(stack, "6");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('6', true);
      return stack;
    case 19:
      LinkedList_add_at_front(stack, "7");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('7', true);
      return stack;
    case 20:
      LinkedList_add_at_front(stack, "8");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('8', true);
      return stack;
    case 21:
      LinkedList_add_at_front(stack, "9");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('9', true);
      return stack;
    case 22:
      LinkedList_add_at_front(stack, "t");
      LinkedList_add_at_front(stack, "T");
      LinkedList_add_at_front(stack, "-");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('-', true);
      n->leftChild->rightSibling = NODE_new('T', false);
      n->leftChild->rightSibling->rightSibling = NODE_new('t', false);
      return stack;
    case 23:
      LinkedList_add_at_front(stack, "f");
      LinkedList_add_at_front(stack, "F");
      LinkedList_add_at_front(stack, "/");
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('/', true);
      n->leftChild->rightSibling = NODE_new('F', false);
      n->leftChild->rightSibling->rightSibling = NODE_new('f', false);
      return stack;
    case 0:
      // NODE n  = PARSETREE_get_left_leaf(tdp->tree->root);
      n->leftChild = NODE_new('e', true);
      return stack;
    default: return stack;
  }
}

int char_to_int(char c){
  switch(c){
    case '+':
      return 0;
    case '-':
      return 1;
    case '*':
      return 2;
    case '/':
      return 3;
    case '(':
      return 4;
    case ')':
      return 5;
    case '1':
      return 6;
    case '2':
      return 7;
    case '3':
      return 8;
    case '4':
      return 9;
    case '5':
      return 10;
    case '6':
      return 11;
    case '7':
      return 12;
    case '8':
      return 13;
    case '9':
      return 14;
    case '0':
      return 15;
    case 'E':
    case 't':
    case 'T':
    case 'f':
    case 'F':
    case 'n':
    case 'N':
    case 'D':
    case 'e':
      return 0;
    default:
      return -1;
  }
}

int syncat_to_int(char c){
  switch (c) {
    case 'E':
      return 0;
    case 't':
      return 1;
    case 'T':
      return 2;
    case 'f':
      return 3;
    case 'F':
      return 4;
    case 'n':
      return 5;
    case 'N':
      return 6;
    case 'D':
      return 7;
    default: return -1;
  }
}

bool isTerminal(char c){
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


TD_PARSER TD_PARSER_new(char* in, int len){
  TD_PARSER tdp = (TD_PARSER)malloc(sizeof(struct _TD_PARSER));
  nextInputChar = in;
  stack = LinkedList_new();
  tdp->curr = 0;
  tdp->length = len;
  tdp->tree = PARSETREE_new(NODE_new('E', false));
  eval(tdp);
  return tdp;
}

void TD_PARSER_free(TD_PARSER tdp){
  LinkedList_free(stack, false);
  if(tdp->tree !=NULL) PARSETREE_free(tdp->tree);
  free(tdp);
}

void TD_PARSER_printTree(TD_PARSER tdp){
  PARSETREE_print(tdp->tree);
}

PARSETREE addProduction(TD_PARSER tdp, char* c){
  int production = parseTable[syncat_to_int(*c)][char_to_int(TDP_lookahead(tdp))];
  if(char_to_int(TDP_lookahead(tdp)) == -1){
    production = 0;
  }
  stack = int_to_production(tdp, production);
  return tdp->tree;
}

PARSETREE eval(TD_PARSER tdp){
  LinkedList_add_at_front(stack, "E");
  while(!LinkedList_is_empty(stack)){
    //LinkedList_print_string_list(stack);
      char* token = LinkedList_pop(stack);
    if(isTerminal(*token)){
      TDP_matchTerminal(tdp, *token);
    } else {
      tdp->tree = addProduction(tdp, token);
    }
  }
  return tdp->tree;
}
