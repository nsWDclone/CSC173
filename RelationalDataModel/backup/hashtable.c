#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"

int hash(char* str){
  int hash=0;
  for(int i=0; i<strlen(str); i++){
    hash+=str[i];
  }
  return (hash%TABLE_SIZE);
}

BUCKET new_BUCKET(void* contents){
  BUCKET b = (BUCKET)malloc(sizeof(BUCKET));
  b->contents = contents;
  b->next = NULL;
  b->prev = NULL;
}

HASHTABLE new_HASHTABLE(char s){
  HASHTABLE h = (HASHTABLE)malloc(sizeof(struct _HASHTABLE));
  h->schema = s;
  h->size = TABLE_SIZE;
  //h->buckets = malloc(sizeof(struct _BUCKET)*53);
  for(int i=0; i<TABLE_SIZE; i++){
    h->buckets[i] = new_BUCKET(NULL);
  }
}

void put(HASHTABLE h, char* hashstr, void* data){
  BUCKET b = h->buckets[hash(hashstr)];
  if(b->contents == NULL){
    b->contents = data;
  } else {
    while(b->next!=NULL){
      b = b->next;
    }
    b->next = new_BUCKET(data);
    b->next->prev = b;
  }
}

BUCKET get_bucket(HASHTABLE h, char* hashstr){
  return h->buckets[hash(hashstr)];
}
