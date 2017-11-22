#ifndef HASHTABLES_H
#define HASHTABLES_H

#include "LinkedList.h"

extern int hash(char* str);

typedef struct _BUCKET* BUCKET;
struct _BUCKET{
  void* contents;
  BUCKET next;
};

typedef struct _HASHTABLE* HASHTABLE;
struct _HASHTABLE{
  char* schema;
  int size;
  BUCKET buckets[53];
};

extern HASHTABLE new_HASHTABLE(char* s);
extern BUCKET new_BUCKET(void* contents);

#endif
