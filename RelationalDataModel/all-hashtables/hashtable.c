#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hashtable.h"
#include "rdm.h"
#include "relations.h"

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
}

HASHTABLE new_HASHTABLE(char s){
  HASHTABLE h = (HASHTABLE)malloc(sizeof(struct _HASHTABLE));
  h->schema = s;
  h->entries = 0;
  h->size = TABLE_SIZE;
  //h->buckets = malloc(sizeof(struct _BUCKET)*53);
  for(int i=0; i<TABLE_SIZE; i++){
    h->buckets[i] = new_BUCKET(NULL);
  }
}

INDEX new_INDEX(void* i){
  INDEX ix = (INDEX)malloc(sizeof(struct _INDEX));
  ix->index = i;
  ix->next = NULL;
  return ix;
}

void put_CSG(HASHTABLE h, char* hashstr, CSG_RELATION data){
  // if(lookup_CSG(h, data->course_name, data->student_grade, data->student_grade) != NULL) return;
  BUCKET b = h->buckets[hash(hashstr)];
  if(b->contents == NULL){
    b->contents = data;
  } else {
    CSG_RELATION r = (CSG_RELATION) b->contents;
    while(r->next!=NULL){
      r = r->next;
    }
    r->next = data;
    h->entries++;
    r->next->prev = r;
  }
}

void put_SNAP(HASHTABLE h, char* hashstr, SNAP_RELATION data){
  BUCKET b = h->buckets[hash(hashstr)];
  if(b->contents == NULL){
    b->contents = data;
  } else {
    SNAP_RELATION r = (SNAP_RELATION) b->contents;
    while(r->next!=NULL){
      r = r->next;
    }
    r->next = data;
    h->entries++;
    r->next->prev = r;
  }
}

void put_CPQ(HASHTABLE h, char* hashstr, CPQ_RELATION data){
  BUCKET b = h->buckets[hash(hashstr)];
  if(b->contents == NULL){
    b->contents = data;
  } else {
    CPQ_RELATION r = (CPQ_RELATION) b->contents;
    while(r->next!=NULL){
      r = r->next;
    }
    r->next = data;
    h->entries++;
    r->next->prev = r;
  }
}

void put_CDH(HASHTABLE h, char* hashstr, CDH_RELATION data){
  BUCKET b = h->buckets[hash(hashstr)];
  if(b->contents == NULL){
    b->contents = data;
  } else {
    CDH_RELATION r = (CDH_RELATION) b->contents;
    while(r->next!=NULL){
      r = r->next;
    }
    r->next = data;
    h->entries++;
    r->next->prev = r;
  }
}

void put_CR(HASHTABLE h, char* hashstr, CR_RELATION data){
  BUCKET b = h->buckets[hash(hashstr)];
  if(b->contents == NULL){
    b->contents = data;
  } else {
    CR_RELATION r = (CR_RELATION) b->contents;
    while(r->next!=NULL){
      r = r->next;
    }
    r->next = data;
    h->entries++;
    r->next->prev = r;
  }
}

void put_INDEX(HASHTABLE h, char* hashstr, INDEX index){
  BUCKET b = h->buckets[hash(hashstr)];
  INDEX i = b->contents;
  if(i==NULL){
    i = index;
  } else {
    while(i!=NULL) i = i->next;
    i->next = index;
  }
}

BUCKET get_bucket(HASHTABLE h, char* hashstr){
  return h->buckets[hash(hashstr)];
}
