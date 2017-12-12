#ifndef PARSETREE_H
#define PARSETREE_H

#include <stdbool.h>

typedef struct _PARSETREE* PARSETREE;
typedef struct _NODE* NODE;

struct _PARSETREE{
  NODE root;
};

struct _NODE {
  char data;
  bool terminal;
  NODE leftChild;
  NODE rightSibling;
};

extern NODE NODE_new(char n, bool term);
extern void NODE_free(NODE n);
extern PARSETREE PARSETREE_new(NODE root);
extern void PARSETREE_free(PARSETREE p);
extern void PARSETREE_print(PARSETREE p);
extern void NODE_print_with_depth(int depth, NODE n);
extern NODE PARSETREE_get_left_leaf(NODE root);

#endif
