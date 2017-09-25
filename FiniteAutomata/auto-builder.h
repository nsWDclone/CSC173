#ifndef AUTO_BUILDER_H
#define AUTO_BUILDER_H

#include "dfa.h"
#include "nfa.h"

extern DFA build_match_ab_only();
extern DFA build_match_start_ab();
extern DFA build_match_even_1();
extern DFA build_match_even_1_0();
extern DFA build_match_a_e_s_t_h_e_t_i_c();
extern NFA build_match_end_man();
extern NFA build_match_email();
extern NFA build_match_not_washington();

#endif
