#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>
#include "dfa.h"


DFA newDFA(int numstates){
  //allocate DFA
  DFA dfa = (DFA)malloc(sizeof(struct dfa));
  //initialize DFA
  dfa->CURR_STATE = 0;
  dfa->NUM_STATES = numstates;
  //allocate transition table
  dfa->TRANSITION_TABLE = (int**)malloc(numstates * sizeof(int*));
  for (int i=0; i<numstates; i++){
    //dfa->TRANSITION_TABLE[i] = (int *)malloc(128 * sizeof(int));
  }
  //initialize transition table
  for(int i=0; i<numstates; i++){
    dfa->TRANSITION_TABLE[i] = (int *)malloc(128 * sizeof(int));
    for(int j=0; j<128; j++){
      dfa->TRANSITION_TABLE[i][j] = 0;
    }
  }
  //allocate acceptance table
  dfa->ACCEPT_TABLE = (bool*)malloc(numstates * sizeof(bool));
  //initialize acceptance table
  for(int i=0; i<numstates; i++){
    dfa->ACCEPT_TABLE[i] = false;
  }
  return dfa;
}

void freeDFA(DFA dfa){
  for (int i = 0; i < dfa->NUM_STATES; i++) {
    free(dfa->TRANSITION_TABLE[i]);
  }
  free(dfa->TRANSITION_TABLE);
  free(dfa->ACCEPT_TABLE);
  free(dfa);
}

int DFAsize(DFA dfa){
  return dfa->NUM_STATES;
}

char* DFA_get_description(DFA dfa){
  return dfa->DESCRIPTION;
}

void DFA_set_description(DFA dfa, char* str){
  dfa->DESCRIPTION = str;
}

int DFA_get_transition(DFA dfa, int src, char sym){
  int n = sym;
  return dfa->TRANSITION_TABLE[src][n];
}

void DFA_set_transition(DFA dfa, int src, char sym, int dst){
  int n = sym;
  dfa->TRANSITION_TABLE[src][n] = dst;
}

void DFA_set_transition_str(DFA dfa, int src, char *str, int dst){
  for(int i=0; i<strlen(str); i++){
    int sym = str[i];
    dfa->TRANSITION_TABLE[src][sym] = dst;
  }
}

void DFA_set_transition_all(DFA dfa, int src, int dst){
  for(int j=0; j<128; j++){
    dfa->TRANSITION_TABLE[src][j] = dst;
  }
}

void DFA_set_accepting(DFA dfa, int state, bool value){
  dfa->ACCEPT_TABLE[state] = value;
}

bool DFA_get_accepting(DFA dfa, int state){
  return dfa->ACCEPT_TABLE[state];
}

bool DFA_execute(DFA dfa, char *input){
  dfa->CURR_STATE = 0;
  for(int i=0; i<strlen(input); i++){
    int cur = dfa->CURR_STATE;
    int sym = input[i];
    dfa->CURR_STATE = DFA_get_transition(dfa, cur, sym);
  }
  //printf("%s\n",DFA_get_accepting(dfa, dfa->CURR_STATE)?"true":"false");
  return DFA_get_accepting(dfa, dfa->CURR_STATE);
}
