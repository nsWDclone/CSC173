#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "subset-construction.h"
#include "LinkedList.h"
#include "dfa.h"
#include "nfa.h"
#include "IntSet.h"

DFA transform_NFA_to_DFA(NFA nfa){
  IntSet set = IntSet_new();

  LinkedList* state_labels = LinkedList_new();
  IntSet_add(set, 0);
  LinkedList_add_at_front(state_labels, set);


  int list_index = -1;
  int list_size = 1;


  //create linked list of intsets to be dfa state labels
  IntSet it_set;
  IntSet set2;
    do{
      list_size = LinkedList_size(state_labels);
      list_index++;
      it_set = LinkedList_element_at(state_labels, list_index);
      for(int char_id=0; char_id<128; char_id++){
        IntSetIterator iterator = IntSet_iterator(it_set);
        set2 = IntSet_new();

        while(IntSetIterator_has_next(iterator)){
          IntSet_union(set2,NFA_get_transitions(
            nfa, IntSetIterator_next(iterator), char_id));
        }
        free(iterator);
        //add if not already in linked list
        if((!LinkedList_contains(state_labels, set2)) &&
        (!IntSet_is_empty(set2))){
          LinkedList_add_at_end(state_labels, set2);
        }
      }
    } while((LinkedList_size(state_labels) != list_size) ||
      (list_index + 1) != LinkedList_size(state_labels));

  //initialize DFA
  int dfa_numstates = LinkedList_size(state_labels);
  DFA dfa = newDFA(dfa_numstates);

  //set DFAs arcs
  for(int i=0; i<DFAsize(dfa); i++){
    IntSet set4 = LinkedList_element_at(state_labels, i);
    for(int j=0; j<128; j++){
      IntSetIterator set_iterator = IntSet_iterator(set4);
      IntSet set5 = IntSet_new();
      while(IntSetIterator_has_next(set_iterator)){
        IntSet_union(set5, NFA_get_transitions(nfa, IntSetIterator_next(set_iterator), j));
      }
      int curr = 0;
      while(!IntSet_equals(set5, LinkedList_element_at(state_labels, curr))){
        //printf("%d\n", curr);
        curr++;
      }
      DFA_set_transition(dfa, i, j, curr);
      IntSet_free(set5);
      free(set_iterator);
    }
  }

  //set DFAs accepting states
  int dfa_state_index = 0;
  LinkedListIterator* accept_iterator = LinkedList_iterator(state_labels);
  while(LinkedListIterator_has_next(accept_iterator)){
    IntSet set = LinkedListIterator_next(accept_iterator);
    IntSetIterator set_iterator = IntSet_iterator(set);
    while(IntSetIterator_has_next(set_iterator)){
      int curr = IntSetIterator_next(set_iterator);
      if(NFA_get_accepting(nfa, curr)){
        DFA_set_accepting(dfa, dfa_state_index, true);
      }
    }
    free(set_iterator);
    dfa_state_index++;
  }
  free(accept_iterator);
  LinkedList_free(state_labels, true);
  DFA_set_description(dfa, NFA_get_description(nfa));
  return dfa;
}
