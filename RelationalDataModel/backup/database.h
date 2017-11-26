#ifndef DATABASE_H
#define DATABASE_H

#include "hashtable.h"

typedef struct _DATABASE* DATABASE;
struct _DATABASE {
  char schema;
  HASHTABLE storage;
  HASHTABLE index;
};
extern DATABASE new_DATABASE(char s);
extern void print_DATABASE(DATABASE d);
#endif
