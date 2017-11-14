#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "parsetree.h"
#include "rdp-arith.h"
#include "tdp-arith.h"
#include "eval.h"
#include "LinkedList.h"

int main(int argc, char const *argv[]) {

  ///*
  printf("%s\n", "RECURSIVE DESCENT PARSING:");
  char* input = (char*)malloc(65);
  printf("%s", "Enter an input string (up to 64 chars): ");
  fgets(input, 65, stdin);

  RD_PARSER rdp = RD_PARSER_new(input, 65);
  if(rdp->tree !=NULL){
    RD_PARSER_printTree(rdp);
    printf("RESULT: %d\n", evaluate_tree(rdp->tree->root));
  } else printf("%s\n", "ERROR: Invalid expression");
  free(input);
  if(rdp!=NULL) RD_PARSER_free(rdp);

  printf("%s\n", "TABLE DRIVEN PARSING:");
  char* input2 = (char*)malloc(65);
  printf("%s", "Enter an input string (up to 64 chars): ");
  fgets(input2, 65, stdin);

  TD_PARSER tdp = TD_PARSER_new(input2 , 65);
  if(tdp->tree != NULL){
    TD_PARSER_printTree(tdp);
    printf("RESULT: %d\n", evaluate_tree(tdp->tree->root));
  } else printf("%s\n", "ERROR: Invalid expression");
  free(input2);
  if(tdp!=NULL) TD_PARSER_free(tdp);
  //*/

  /*
  printf("%s\n", "RECURSIVE DESCENT PARSING:");
  char* yn = (char*)malloc(16);
  yn[0] = 'y';
  RD_PARSER rdp;

  while(yn[0] == 'y'){
    char* input = (char*)malloc(65);
    printf("%s", "Enter an input string (up to 64 chars): ");
    fgets(input, 65, stdin);
    //scanf(" %s ", input);

    rdp = RD_PARSER_new(input, 65);
    if(rdp->tree !=NULL){
      RD_PARSER_printTree(rdp);
      printf("RESULT: %d\n", evaluate_tree(rdp->tree->root));
    } else printf("%s\n", "ERROR: Invalid expression");
    free(input);
    fflush(stdin);
    printf("Try another expression? [y/n] : ");
    //scanf(" %c ", &yn);
    fgets(yn, 1, stdin);
  }
  if(rdp!=NULL) RD_PARSER_free(rdp);

  printf("%s\n", "TABLE DRIVEN PARSING:");
  char* ny = (char*)malloc(16);
  ny[0] = 'y';
  TD_PARSER tdp;

  while(ny[0] == 'y'){
    char* input2 = (char*)malloc(65);
    printf("%s", "Enter an input string (up to 64 chars): ");
    fgets(input2, 65, stdin);
    //scanf(" %s", input2);

    tdp = TD_PARSER_new(input2 , 65);
    if(tdp->tree != NULL){
      TD_PARSER_printTree(tdp);
      printf("RESULT: %d\n", evaluate_tree(tdp->tree->root));
    } else printf("%s\n", "ERROR: Invalid expression");
    free(input2);
    printf("Try another expression? [y/n] : ");
    //scanf(" %c ", &ny);
    fgets(ny, 1, stdin);
  }
  if(tdp!=NULL) TD_PARSER_free(tdp);
  //*/
  return 0;
}
