#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "rdm.h"

void insert_CSG(DATABASE table, char* c, char* s, char* g){
  CSG_RELATION relation = new_CSG(c,s,g);
  char str[10];
  strcpy(str, c);
  strcat(str, s);
  put(table->index, s, relation);
  put(table->storage, str, relation);
}


void insert_SNAP(DATABASE table, char* s, char* n, char* a, char* p){
  SNAP_RELATION relation = new_SNAP(s,n,a,p);
  char str[15];
  strcpy(str, s);
  strcat(str, p);
  put(table->index, n, relation);
  put(table->storage, str, relation);
}

void insert_CPQ(DATABASE table, char* c, char* pq){
  CPQ_RELATION relation = new_CPQ(c,pq);
  char str[5];
  strcpy(str, c);
  put(table->index, pq, relation);
  put(table->storage, str, relation);
}

void insert_CDH(DATABASE table, char* c, char* d, char* h){
  CDH_RELATION relation = new_CDH(c,d,h);
  char str[7];
  strcpy(str, c);
  strcat(str, d);
  put(table->index, c, relation);
  put(table->storage, str, relation);
}

void insert_CR(DATABASE table, char* c, char* r){
  CR_RELATION relation = new_CR(c,r);
  char str[5];
  strcpy(str, c);
  put(table->index, r, relation);
  put(table->storage, str, relation);
}

HASHTABLE lookup_CSG(DATABASE table, char* c, char* s, char* g){
  HASHTABLE result = new_HASHTABLE(schema_CSG);
  CSG_RELATION r;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->student_id, s)==0 || s[0]=='*')
        && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
          char str[10];
          strcpy(str, c);
          strcat(str, s);
          put(result, str, r);
        }
        b = b->next;
      } while (b !=NULL);
    }
  }
  return result;
}

HASHTABLE lookup_SNAP(DATABASE table, char* s, char* n, char* a, char* p){
  HASHTABLE result = new_HASHTABLE(schema_SNAP);
  SNAP_RELATION r;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      r = b->contents;
      do{
        if((strcmp(r->student_id, s)==0 || s[0]=='*')
        && (strcmp(r->student_name, n)==0 || n[0]=='*')
        && (strcmp(r->student_address, a)==0 || a[0]=='*')
        && (strcmp(r->student_phone, p)==0 || p[0]=='*')){
          char str[15];
          strcpy(str, s);
          strcat(str, p);
          put(result, str, r);
        }
        b = b->next;
      } while (b !=NULL);
    }
  }
  return result;
}

HASHTABLE lookup_CPQ(DATABASE table, char* c, char* pq){
  HASHTABLE result = new_HASHTABLE(schema_CPQ);
  CPQ_RELATION r;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      do{
        r = b->contents;
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){
          char str[5];
          strcpy(str, c);
          put(result, str, r);
        }
        b = b->next;
      } while (b!=NULL);
    }
  }
  return result;
}

HASHTABLE lookup_CDH(DATABASE table, char* c, char* d, char* h){
  HASHTABLE result = new_HASHTABLE(schema_CDH);
  CDH_RELATION r;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->course_day, d)==0 || d[0]=='*')
        && (strcmp(r->course_hour, h)==0 || h[0]=='*')){
          char str[7];
          strcpy(str, c);
          strcat(str, d);
          put(result, str, r);
        }
        b = b->next;
      } while (b !=NULL);
    }
  }
  return result;
}

HASHTABLE lookup_CR(DATABASE table, char* c, char* room){
  HASHTABLE result = new_HASHTABLE(schema_CR);
  CR_RELATION r;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->course_room, room)==0 || room[0]=='*')){
          char str[5];
          strcpy(str, c);
          put(result, str, r);
        }
        b = b->next;
      }while (b !=NULL);
    }
  }
  return result;
}

void delete_CSG(DATABASE table, char* c, char* s, char* g){
  CSG_RELATION r;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->student_id, s)==0 || s[0]=='*')
        && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
          BUCKET match = b;
          //TODO: free
          if(match->prev == NULL){
            if(match->next !=NULL){
              match = match->next;
              match->prev = NULL;
            } else match == NULL;
          } else {
            if(match->next == NULL){
              match->prev->next = NULL;
              match = NULL;
            }else{
              match->prev->next = match->next;
              match = NULL;
            }
          }
        }
        b = b->next;
      } while (b !=NULL);
    }
  }
}

void delete_SNAP(DATABASE table, char* s, char* n, char* a, char* p);
void delete_CPQ(DATABASE table, char* c, char* pq);
void delete_CDH(DATABASE table, char* c, char* d, char* h);
void delete_CR(DATABASE table, char* c, char* r);
