#include <stdio.h>
#include "auto-builder.h"
#include "nfa.h"
#include "dfa.h"

//matches exactly the string "ab"
DFA build_match_ab_only(){
  DFA onlyAB = newDFA(4);
  DFA_set_description(onlyAB, "This DFA matches exactly the string 'ab'\n");
  DFA_set_accepting(onlyAB, 2, true);
  DFA_set_transition_all(onlyAB,3,3);
  DFA_set_transition_all(onlyAB,0,3);
  DFA_set_transition_all(onlyAB,2,3);
  DFA_set_transition(onlyAB, 0, 'a', 1);
  DFA_set_transition(onlyAB, 1, 'b', 2);
  return onlyAB;
}

//matches all strings that start with "ab"
DFA build_match_start_ab(){
  DFA startAB = newDFA(4);
  DFA_set_description(startAB, "This DFA matches strings that start with 'ab'\n");
  DFA_set_accepting(startAB, 2, true);
  DFA_set_transition_all(startAB,0,3);
  DFA_set_transition_all(startAB,1,3);
  DFA_set_transition_all(startAB,3,3);
  DFA_set_transition_all(startAB,2,2);
  DFA_set_transition(startAB, 0, 'a', 1);
  DFA_set_transition(startAB, 1, 'b', 2);
  return startAB;
}

//matches strings containing an even number of 1's
DFA build_match_even_1(){
  DFA even1 = newDFA(2);
  DFA_set_description(even1, "This DFA matches binary strings containing an even number of 1's\n");
  DFA_set_accepting(even1, 0, true);
  DFA_set_transition_all(even1,0,0);
  DFA_set_transition_all(even1,1,1);
  DFA_set_transition(even1, 0, '1', 1);
  DFA_set_transition(even1, 1, '1', 0);
  return even1;
}

//matches strings containing an even number of both 1's and 0's
DFA build_match_even_1_0(){
  DFA even10 = newDFA(4);
  DFA_set_description(even10, "This DFA matches binary strings containing an even number of both 1's and 0's\n");
  DFA_set_accepting(even10, 0, true);
  DFA_set_transition_all(even10,0,0);
  DFA_set_transition_all(even10,1,1);
  DFA_set_transition_all(even10,2,2);
  DFA_set_transition_all(even10,3,3);
  DFA_set_transition(even10, 0, '1', 1);
  DFA_set_transition(even10, 0, '0', 2);
  DFA_set_transition(even10, 1, '1', 0);
  DFA_set_transition(even10, 1, '0', 3);
  DFA_set_transition(even10, 2, '1', 3);
  DFA_set_transition(even10, 2, '0', 0);
  DFA_set_transition(even10, 3, '1', 2);
  DFA_set_transition(even10, 3, '0', 1);
  return even10;
}

//match that good good a e s t h e t i c
DFA build_match_a_e_s_t_h_e_t_i_c(){
  DFA aesthetic = newDFA(3);
  DFA_set_description(aesthetic, "This DFA matches strings where all charaters are separated by underscores\n * Eg: a_e_s_t_h_e_t_i_c\n");
  DFA_set_transition_all(aesthetic, 0,1);
  DFA_set_transition_all(aesthetic, 1,2);
  DFA_set_transition_all(aesthetic, 2,2);
  DFA_set_transition(aesthetic, 1, '_' ,0);
  DFA_set_transition(aesthetic, 0, '_' ,2);
  DFA_set_accepting(aesthetic, 1, true);
  return aesthetic;
}

//matches strings that end in "man"
NFA build_match_end_man(){
  NFA endMAN = newNFA(4);
  NFA_set_description(endMAN, "This NFA matches strings that end in 'man'\n");
  NFA_add_transition_all(endMAN, 0,0);
  NFA_add_transition(endMAN, 0, 'm', 1);
  NFA_add_transition(endMAN, 1, 'a', 2);
  NFA_add_transition(endMAN, 2, 'n', 3);
  NFA_set_accepting(endMAN, 3, true);
  return endMAN;
}

//matches strings that are email addresses
NFA build_match_email(){
  NFA email = newNFA(5);
  NFA_set_description(email, "This NFA matches email addresses, aka strings of the format ___@__.__\n");
  NFA_add_transition_all(email, 0,1);
  NFA_add_transition_all(email, 1,1);
  NFA_add_transition_all(email, 2,2);
  NFA_add_transition_all(email, 3,4);
  NFA_add_transition_all(email, 4,4);
  NFA_add_transition(email, 1, '@', 2);
  NFA_add_transition(email, 2, '.', 3);
  NFA_set_accepting(email, 4, true);
  return email;
}

//matches strings containing:
// 2 or more a,g,h,i,o,s,t, or w's
// 3 or more n's
NFA build_match_not_washington(){
  NFA notWash = newNFA (12);
  NFA_set_description(notWash, "This NFA matches strings containing:\n * 2 or more a,g,h,i,o,s,t, or w's\n * 3 or more n's\n");
  NFA_add_transition_all(notWash, 0,0);
  NFA_add_transition_all(notWash, 1,1);
  NFA_add_transition_all(notWash, 2,2);
  NFA_add_transition_all(notWash, 3,3);
  NFA_add_transition_all(notWash, 4,4);
  NFA_add_transition_all(notWash, 5,5);
  NFA_add_transition_all(notWash, 6,6);
  NFA_add_transition_all(notWash, 7,7);
  NFA_add_transition_all(notWash, 8,8);
  NFA_add_transition_all(notWash, 9,9);
  NFA_add_transition_all(notWash, 10,10);
  NFA_add_transition(notWash,0, 'a', 1);
  NFA_add_transition(notWash,1, 'a', 10);
  NFA_add_transition(notWash,0, 'g', 2);
  NFA_add_transition(notWash,2, 'g', 10);
  NFA_add_transition(notWash,0, 'h', 3);
  NFA_add_transition(notWash,3, 'h', 10);
  NFA_add_transition(notWash,0, 'i', 4);
  NFA_add_transition(notWash,4, 'i', 10);
  NFA_add_transition(notWash,0, 'o', 5);
  NFA_add_transition(notWash,5, 'o', 10);
  NFA_add_transition(notWash,0, 's', 6);
  NFA_add_transition(notWash,6, 's', 10);
  NFA_add_transition(notWash,0, 't', 7);
  NFA_add_transition(notWash,7, 't', 10);
  NFA_add_transition(notWash,0, 'n', 8);
  NFA_add_transition(notWash,8, 'n', 9);
  NFA_add_transition(notWash,9, 'n', 10);
  NFA_add_transition(notWash,0, 'w', 11);
  NFA_add_transition(notWash,11, 'w', 10);
  NFA_set_accepting(notWash, 10, true);
  return notWash;
}
