#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "parsetree.h"
#include "rdp-arith.h"

char* nextInputChar;

char lookahead(RD_PARSER rdp){
  if(rdp->curr < rdp->length){
    return *nextInputChar;
  }
  return '\0';
}

RD_PARSER RD_PARSER_new(char* in, int len){
  RD_PARSER rdp = (RD_PARSER)malloc(sizeof(struct _RD_PARSER));
  nextInputChar = in;
  rdp->curr = 0;
  rdp->length = len;
  rdp->tree = E(rdp);
  return rdp;
}

void RD_PARSER_free(RD_PARSER rdp){
  if(rdp->tree!=NULL) PARSETREE_free(rdp->tree);
  free(rdp);
}

bool matchTerminal(RD_PARSER rdp, char c){
  if(*nextInputChar == c){
    nextInputChar++;
    return true;
  } else {
    return false;
  }
}

void RD_PARSER_printTree(RD_PARSER rdp){
  PARSETREE_print(rdp->tree);
}

bool isDigit(char c){
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
      return true;
      break;
  }
  return false;
}

PARSETREE E(RD_PARSER rdp){
  //printf("%s\n", "E");
  PARSETREE p = PARSETREE_new(NODE_new('E', false));

  PARSETREE p1 = T(rdp);
  if(p1 == NULL) return NULL;

  PARSETREE p2 = TT(rdp);
  if(p2 == NULL) return NULL;

  p->root->leftChild = p1->root;
  p->root->leftChild->rightSibling = p2->root;
  return p;
}

PARSETREE T(RD_PARSER rdp){
  //printf("%s\n", "T");
  PARSETREE p = PARSETREE_new(NODE_new('T', false));

  PARSETREE p1 = F(rdp);
  if(p1 == NULL) return NULL;

  PARSETREE p2 = FT(rdp);
  if(p2 == NULL) return NULL;

  p->root->leftChild = p1->root;
  p->root->leftChild->rightSibling = p2->root;
  return p;
}

PARSETREE TT(RD_PARSER rdp){
  PARSETREE p = PARSETREE_new(NODE_new('t', false));
  char c = lookahead(rdp);
  //printf("%s %c\n", "TT", c);
  if(matchTerminal(rdp, '+') || matchTerminal(rdp, '-')){

    PARSETREE p1 = T(rdp);
    if(p1 == NULL) return NULL;

    PARSETREE p2 = TT(rdp);
    if(p2 == NULL) return NULL;

    p->root->leftChild = NODE_new(c, true);
    p->root->leftChild->rightSibling = p1->root;
    p->root->leftChild->rightSibling->rightSibling = p2->root;
  } else {
    p->root->leftChild = NODE_new('e', true);
  }
  return p;
}

PARSETREE F(RD_PARSER rdp){
  PARSETREE p = PARSETREE_new(NODE_new('F', false));
  //printf("%s %c\n", "F", c);
  if(matchTerminal(rdp, '(')){

    PARSETREE p1 = E(rdp);
    if(p1 == NULL) return NULL;

    if(!matchTerminal(rdp, ')')) return NULL;

    p->root->leftChild = NODE_new('(', true);
    p->root->leftChild->rightSibling = p1->root;
    p->root->leftChild->rightSibling->rightSibling = NODE_new(')', true);
  } else {
    PARSETREE p2 = N(rdp);
    if(p2 == NULL) return NULL;
    p->root->leftChild = p2->root;
  }
  return p;
}

PARSETREE FT(RD_PARSER rdp){
  PARSETREE p = PARSETREE_new(NODE_new('f', false));
  char c = lookahead(rdp);
  //printf("%s %c\n", "FT", c);
  if(matchTerminal(rdp, '*') || matchTerminal(rdp, '/')){

    PARSETREE p1 = F(rdp);
    if(p1 == NULL) return NULL;

    PARSETREE p2 = FT(rdp);
    if(p2 == NULL) return NULL;

    p->root->leftChild = NODE_new(c, true);
    p->root->leftChild->rightSibling = p1->root;
    p->root->leftChild->rightSibling->rightSibling = p2->root;
  } else {
    p->root->leftChild = NODE_new('e', true);
  }
  return p;
}

PARSETREE N(RD_PARSER rdp){
  //printf("%s\n", "N");
  PARSETREE p = PARSETREE_new(NODE_new('N', false));

  PARSETREE p1 = D(rdp);
  if(p1 == NULL) return NULL;

  PARSETREE p2 = NT(rdp);
  if(p2 == NULL) return NULL;

  p->root->leftChild  = p1->root;
  p->root->leftChild->rightSibling = p2->root;
  return p;
}

PARSETREE NT(RD_PARSER rdp){
  //printf("%s\n", "NT");
  PARSETREE p = PARSETREE_new(NODE_new('n', false));
  if(isDigit(lookahead(rdp))){
    PARSETREE p1 = N(rdp);
    if(p1 == NULL) return NULL;

    p->root->leftChild = p1->root;
  } else {
    p->root->leftChild = NODE_new('e', true);
  }
  return p;
}

PARSETREE D(RD_PARSER rdp){
  PARSETREE p = PARSETREE_new(NODE_new('D', false));
  char c = lookahead(rdp);
  //printf("%s %c\n", "D", c);
  switch (c) {
    case '0':
      matchTerminal(rdp, '0');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '1':
      matchTerminal(rdp, '1');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '2':
      matchTerminal(rdp, '2');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '3':
      matchTerminal(rdp, '3');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '4':
      matchTerminal(rdp, '4');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '5':
      matchTerminal(rdp, '5');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '6':
      matchTerminal(rdp, '6');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '7':
      matchTerminal(rdp, '7');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '8':
      matchTerminal(rdp, '8');
      p->root->leftChild = NODE_new(c, true);
      break;
    case '9':
      matchTerminal(rdp, '9');
      p->root->leftChild = NODE_new(c, true);
      break;
    default:
      return NULL;
      break;
  }
  return p;
}
