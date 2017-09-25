#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#include "IntSet.h"
#include "nfa.h"


NFA newNFA(int numstates){
  //allocate NFA
  NFA nfa = (NFA)malloc(sizeof(struct nfa));

  //initialize NFA
  nfa->CURR_STATES = NULL;
  nfa->NUM_STATES = numstates;

  //allocate transition table
  nfa->TRANSITION_TABLE = (IntSet**)malloc(numstates * sizeof(IntSet*));
  for (int i=0; i<numstates; i++){
    nfa->TRANSITION_TABLE[i] = (IntSet *)malloc(128 * sizeof(IntSet));
  }

  //initialize transition table
  for(int i=0; i<numstates; i++){
    for(int j=0; j<128; j++){
      nfa->TRANSITION_TABLE[i][j] = IntSet_new();
    }
  }

  //allocate acceptance table
  nfa->ACCEPT_TABLE = (bool*)malloc(numstates * sizeof(bool));

  //initialize acceptance table
  for(int i=0; i<numstates; i++){
    nfa->ACCEPT_TABLE[i] = false;
  }

  return nfa;
}

void freeNFA(NFA nfa){
  for (int i = 0; i < nfa->NUM_STATES; i++) {
    for(int j=0; j<128; j++){
      IntSet_free(nfa->TRANSITION_TABLE[i][j]);
    }
    free(nfa->TRANSITION_TABLE[i]);
  }
  free(nfa->TRANSITION_TABLE);
  IntSet_free(nfa->CURR_STATES);
  free(nfa->ACCEPT_TABLE);
  free(nfa);
}

void resetNFA(NFA nfa){
  if(nfa->CURR_STATES != NULL){
    IntSet_free(nfa->CURR_STATES);
  }
  nfa->CURR_STATES = IntSet_new();
  IntSet_add(nfa->CURR_STATES, 0);
}

int NFA_size(NFA nfa){
  return nfa->NUM_STATES;
}

char* NFA_get_description(NFA nfa){
  return nfa->DESCRIPTION;
}

void NFA_set_description(NFA nfa, char* str){
  nfa->DESCRIPTION = str;
}

IntSet NFA_get_transitions(NFA nfa, int src, char sym){
  int n = sym;
  return (nfa->TRANSITION_TABLE)[src][n];
}

void NFA_add_transition(NFA nfa, int src, char sym, int dst){
  int n = sym;
  if(!IntSet_contains(nfa->TRANSITION_TABLE[src][n], dst)){
    IntSet_add(nfa->TRANSITION_TABLE[src][n], dst);
  }
}

void NFA_add_transition_str(NFA nfa, int src, char *str, int dst){
  for(int i=0; i<strlen(str); i++){
    int sym = str[i];
    if(!IntSet_contains(nfa->TRANSITION_TABLE[src][sym], dst)){
      IntSet_add(nfa->TRANSITION_TABLE[src][sym], dst);
    }
  }
}

void NFA_add_transition_all(NFA nfa, int src, int dst){
  for(int j=0; j<128; j++){
    if(!IntSet_contains(nfa->TRANSITION_TABLE[src][j], dst)){
      IntSet_add(nfa->TRANSITION_TABLE[src][j], dst);
    }
  }
}

void NFA_set_accepting(NFA nfa, int state, bool value){
  nfa->ACCEPT_TABLE[state] = value;
}

bool NFA_get_accepting(NFA nfa, int state){
  return nfa->ACCEPT_TABLE[state];
}

bool NFA_execute(NFA nfa, char *input){
  resetNFA(nfa);
  IntSet temp;
  for(int i=0; i<strlen(input); i++){
    int sym = input[i];

    temp = IntSet_new();
    IntSetIterator curr_iterator = IntSet_iterator(nfa->CURR_STATES);

    while(IntSetIterator_has_next(curr_iterator)){
      int cur = IntSetIterator_next(curr_iterator);
      IntSet_union(temp, NFA_get_transitions(nfa, cur, sym));
    }
    free(curr_iterator);
    IntSet_free(nfa->CURR_STATES);
    nfa->CURR_STATES = temp;
    IntSet_union(nfa->CURR_STATES, temp);
  }
  bool accepted = false;
  IntSetIterator accept_iterator = IntSet_iterator(nfa->CURR_STATES);
  while(IntSetIterator_has_next(accept_iterator)){
    int cur = IntSetIterator_next(accept_iterator);
    if(nfa->ACCEPT_TABLE[cur]==true){
      // printf("%s\n", "ACCEPTED" );
      accepted = true;
    }
  }
  // printf("%s\n",accepted?"true":"false");
  free(accept_iterator);
  return accepted;
}
