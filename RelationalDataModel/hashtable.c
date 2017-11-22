#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

int hash(char* str){
  int hash=0;
  for(int i=0; i<strlen(str); i++){
    hash+=str[i];
  }
  return (hash%53);
}

BUCKET new_BUCKET(void* contents){
  BUCKET b = (BUCKET)malloc(sizeof(BUCKET));
  b->contents = contents;
  b->next = NULL;
}

HASHTABLE new_HASHTABLE(char* s){
  HASHTABLE h = (HASHTABLE)malloc(sizeof(struct _HASHTABLE));
  h->schema = s;
  h->size = 53;
  //h->buckets = malloc(sizeof(struct _BUCKET)*53);
  for(int i=0; i<53; i++){
    h->buckets[i] = new_BUCKET(NULL);
  }
}
