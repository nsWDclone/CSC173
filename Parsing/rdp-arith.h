#ifndef RDP_ARITH_H
#define RDP_ARITH_H

#include "parsetree.h"

typedef struct _RD_PARSER* RD_PARSER;

struct _RD_PARSER{
  int curr;
  int length;
  PARSETREE tree;
};

extern char* nextInputChar;
extern bool matchTerminal(RD_PARSER rdp, char c);
extern char lookahead(RD_PARSER rdp);
extern RD_PARSER RD_PARSER_new(char* in, int len);
extern void RD_PARSER_free(RD_PARSER rdp);
extern void RD_PARSER_printTree(RD_PARSER rdp);
extern PARSETREE E(RD_PARSER rdp);
extern PARSETREE TT(RD_PARSER rdp);
extern PARSETREE T(RD_PARSER rdp);
extern PARSETREE FT(RD_PARSER rdp);
extern PARSETREE F(RD_PARSER rdp);
extern PARSETREE N(RD_PARSER rdp);
extern PARSETREE NT(RD_PARSER rdp);
extern PARSETREE D(RD_PARSER rdp);

#endif
