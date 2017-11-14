#ifndef TDP_ARITH_H
#define TDP_ARITH_H

#include "LinkedList.h"

typedef struct _TD_PARSER* TD_PARSER;

struct _TD_PARSER{
  int curr;
  int length;
  PARSETREE tree;
};

extern LinkedList* stack;
extern char* nextInputChar;
extern bool TDP_matchTerminal(TD_PARSER tdp, char c);
extern char TDP_lookahead(TD_PARSER tdp);
extern TD_PARSER TD_PARSER_new(char* in, int len);
extern void TD_PARSER_free(TD_PARSER tdp);
extern void TD_PARSER_printTree(TD_PARSER tdp);
extern PARSETREE eval(TD_PARSER tdp);
#endif
