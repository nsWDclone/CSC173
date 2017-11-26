#ifndef HASHTABLES_H
#define HASHTABLES_H

#include "relations.h"
#define TABLE_SIZE 73

extern int hash(char* str);

typedef struct _BUCKET* BUCKET;
struct _BUCKET{
  void* contents;
};

typedef struct _HASHTABLE* HASHTABLE;
struct _HASHTABLE{
  char schema;
  int size;
  int entries;
  BUCKET buckets[TABLE_SIZE];
};

typedef struct _INDEX* INDEX;
struct _INDEX{
  void* index;
  INDEX next;
};

extern void put_CSG(HASHTABLE h, char* hashstr, CSG_RELATION data);
extern void put_SNAP(HASHTABLE h, char* hashstr, SNAP_RELATION data);
extern void put_CPQ(HASHTABLE h, char* hashstr, CPQ_RELATION data);
extern void put_CDH(HASHTABLE h, char* hashstr, CDH_RELATION data);
extern void put_CR(HASHTABLE h, char* hashstr, CR_RELATION data);
extern void put_INDEX(HASHTABLE h, char* hashstr, INDEX index);

extern BUCKET get_bucket(HASHTABLE h, char* hashstr);

extern HASHTABLE new_HASHTABLE(char s);
extern BUCKET new_BUCKET(void* contents);
extern INDEX new_INDEX(void* i);

#endif
