#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"
#include "auto-builder.h"
#include "subset-construction.h"
#include "dfa.h"
#include "nfa.h"

void test_wash(){
  NFA notWash = build_match_not_washington();
  DFA notWash_DFA = transform_NFA_to_DFA(notWash);
  DFA_execute(notWash_DFA, "washingtonn");
  DFA_execute(notWash_DFA, "washington");
  freeNFA(notWash);
  freeDFA(notWash_DFA);
}

void test_email(){
  NFA email = build_match_email();
  NFA_execute(email, "test@domain.com");
  NFA_execute(email, "notanemail");
  DFA email_DFA = transform_NFA_to_DFA(email);
  DFA_execute(email_DFA, "test@domain.com");
  DFA_execute(email_DFA, "notanemail");
  freeNFA(email);
  freeDFA(email_DFA);
}

bool parse_YN_to_bool(char yn){
  switch (yn) {
    case 'y':
    case 'Y':
      return true;
    case 'n':
    case 'N':
      return false;
    default:
      return false;
  }
}

void REPL_DFA(DFA dfa){
  printf(" * %s", DFA_get_description(dfa));
  bool continue_loop = true;
  while(continue_loop){
    char input[64];
    char yn;
    printf("%s", " | Enter an input string (up to 64 chars): ");
    scanf(" %s", input);

    printf("%s\n", DFA_execute(dfa, input)?" | ACCEPTED":" | NOT ACCEPTED");

    printf("%s", " | Test another string? [y/n] : " );
    scanf(" %c", &yn);
    continue_loop = parse_YN_to_bool(yn);
  }
  printf(" ------------------------------------\n");
  freeDFA(dfa);
}

void REPL_NFA(NFA nfa){
  printf(" * %s", NFA_get_description(nfa));
  bool continue_loop = true;
  while(continue_loop){
    char input[64];
    char yn;
    printf("%s", " | Enter an input string (up to 64 chars): ");
    scanf(" %s", input);

    printf("%s\n", NFA_execute(nfa, input)?" | ACCEPTED":" | NOT ACCEPTED");

    printf("%s", " | Test another string? [y/n] : " );
    scanf(" %c", &yn);
    continue_loop = parse_YN_to_bool(yn);
  }
  printf(" ------------------------------------\n");
  freeNFA(nfa);
}

int main(int argc, char const *argv[]) {
  printf(" --------------- DFAs ---------------\n");
  REPL_DFA(build_match_ab_only());
  REPL_DFA(build_match_start_ab());
  REPL_DFA(build_match_even_1());
  REPL_DFA(build_match_even_1_0());
  REPL_DFA(build_match_a_e_s_t_h_e_t_i_c());
  printf("\n --------------- NFAs ---------------\n");
  REPL_NFA(build_match_end_man());
  REPL_NFA(build_match_not_washington());
  REPL_NFA(build_match_email());
  printf("\n ----------- NFAs to DFAs -----------\n");
  REPL_DFA(transform_NFA_to_DFA(build_match_end_man()));
  REPL_DFA(transform_NFA_to_DFA(build_match_email()));

  printf("%s", " * THE NEXT NFA IS EXTREMELY LARGE\n * CONVERSION TO DFA MAY TAKE UP TO 10 MINUTES\n * ARE YOU SURE YOU WANT TO CONTINUE? [y/n] : ");
  char yn;
  scanf(" %c", &yn);
  if(parse_YN_to_bool(yn)){
    printf("%s", " * ARE YOU ABSOLUTELY SURE? YOU HAVE 10 MINUTES TO SPARE? [y/n] : ");
    scanf(" %c", &yn);
    if(parse_YN_to_bool(yn)){
      NFA wash = build_match_not_washington();
      REPL_DFA(transform_NFA_to_DFA(wash));
    }
  }
  printf(" --------------- DONE ---------------\n");
}
