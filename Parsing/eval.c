#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "eval.h"
#include "rdp-arith.h"
#include "tdp-arith.h"
#include "parsetree.h"
#include "LinkedList.h"

bool labelIsDigit(char c){
  switch (c) {
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
  }
  return false;
}

bool labelIsOperator(char c){
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
      return true;
  }
  return false;
}

int evaluate_subtree(NODE root){
  int result = 0;
  char str[128];
  switch(root->data){
    case 'N':
      return evaluate_subtree(root->leftChild);
    case 'n':
      return evaluate_subtree(root->leftChild);
    case 'D':
      if(root->rightSibling->leftChild->data == 'e') return evaluate_subtree(root->leftChild);
      sprintf(str, "%d%d", evaluate_subtree(root->leftChild), evaluate_subtree(root->rightSibling));
      return atoi(str);
    case 'F':
      if(root->leftChild->data == '('){
        if(root->rightSibling->leftChild->data == 'e') return evaluate_subtree(root->leftChild->rightSibling);
        if(root->rightSibling->leftChild->data == '*')
          return (evaluate_subtree(root->leftChild->rightSibling) * evaluate_subtree(root->rightSibling->leftChild->rightSibling));
        if(root->rightSibling->leftChild->data == '/')
          return (evaluate_subtree(root->leftChild->rightSibling) / evaluate_subtree(root->rightSibling->leftChild->rightSibling));
      }
      if(root->rightSibling->leftChild->data == 'e') return evaluate_subtree(root->leftChild);
      if(root->rightSibling->leftChild->data == '*')
        return (evaluate_subtree(root->leftChild) * evaluate_subtree(root->rightSibling->leftChild->rightSibling));
      if(root->rightSibling->leftChild->data == '/')
        return (evaluate_subtree(root->leftChild) / evaluate_subtree(root->rightSibling->leftChild->rightSibling));
    case 'f':
      return evaluate_subtree(root->leftChild);
    case 'T':
      if(!labelIsOperator(root->rightSibling->leftChild->data)) return evaluate_subtree(root->leftChild);
      if(root->rightSibling->leftChild->data == '+') return (evaluate_subtree(root->leftChild) + evaluate_subtree(root->rightSibling->leftChild->rightSibling));
      if(root->rightSibling->leftChild->data == '-') return (evaluate_subtree(root->leftChild) - evaluate_subtree(root->rightSibling->leftChild->rightSibling));
    case 't':
      return evaluate_subtree(root->leftChild);
    case 'E':
      return evaluate_subtree(root->leftChild);
    case 'e':
      return 0;
    case '0':
      return 0;
    case '1':
      return 1;
    case '2':
      return 2;
    case '3':
      return 3;
    case '4':
      return 4;
    case '5':
      return 5;
    case '6':
      return 6;
    case '7':
      return 7;
    case '8':
      return 8;
    case '9':
      return 9;
    default: break;
  }
  return result;
}

int evaluate_tree(NODE root){
    return evaluate_subtree(root->leftChild);
}
