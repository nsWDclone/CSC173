#ifndef HASHTABLES_H
#define HASHTABLES_H

#define TABLE_SIZE 73

extern int hash(char* str);

typedef struct _BUCKET* BUCKET;
struct _BUCKET{
  void* contents;
  BUCKET next;
  BUCKET prev;
};

typedef struct _HASHTABLE* HASHTABLE;
struct _HASHTABLE{
  char schema;
  int size;
  BUCKET buckets[TABLE_SIZE];
};

extern void put(HASHTABLE h, char* hashstr, void* data);
extern BUCKET get_bucket(HASHTABLE h, char* hashstr);

extern HASHTABLE new_HASHTABLE(char s);
extern BUCKET new_BUCKET(void* contents);

#endif
