#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "rdm.h"

void insert_CSG(HASHTABLE table, char* c, char* s, char* g){
  CSG_RELATION relation = new_CSG(c,s,g);
  char str[10];
  strcpy(str, c);
  strcat(str, s);
  if(table->buckets[hash(str)]->contents == NULL){
    table->buckets[hash(str)]->contents = relation;
  } else {
    BUCKET b = table->buckets[hash(str)];
    while(b->next!=NULL){
      b = b->next;
    }
    b->next = new_BUCKET(relation);
  }
}


void insert_SNAP(HASHTABLE table, char* s, char* n, char* a, char* p){
  SNAP_RELATION relation = new_SNAP(s,n,a,p);
  char str[15];
  strcpy(str, s);
  strcat(str, p);
  if(table->buckets[hash(str)]->contents == NULL){
    table->buckets[hash(str)]->contents = relation;
  } else {
    BUCKET b = table->buckets[hash(str)];
    while(b->next!=NULL){
      b = b->next;
    }
    b->next = new_BUCKET(relation);
  }
}

void insert_CPQ(HASHTABLE table, char* c, char* pq){
  CPQ_RELATION relation = new_CPQ(c,pq);
  char str[5];
  strcpy(str, c);
  if(table->buckets[hash(str)]->contents == NULL){
    table->buckets[hash(str)]->contents = relation;
  } else {
    BUCKET b = table->buckets[hash(str)];
    while(b->next!=NULL){
      b = b->next;
    }
    b->next = new_BUCKET(relation);
  }
}

void insert_CDH(HASHTABLE table, char* c, char* d, char* h){
  CDH_RELATION relation = new_CDH(c,d,h);
  char str[7];
  strcpy(str, c);
  strcat(str, d);
  if(table->buckets[hash(str)]->contents == NULL){
    table->buckets[hash(str)]->contents = relation;
  } else {
    BUCKET b = table->buckets[hash(str)];
    while(b->next!=NULL){
      b = b->next;
    }
    b->next = new_BUCKET(relation);
  }
}

void insert_CR(HASHTABLE table, char* c, char* r){
  CR_RELATION relation = new_CR(c,r);
  char str[5];
  strcpy(str, c);
  if(table->buckets[hash(str)]->contents == NULL){
    table->buckets[hash(str)]->contents = relation;
  } else {
    BUCKET b = table->buckets[hash(str)];
    while(b->next!=NULL){
      b = b->next;
    }
    b->next = new_BUCKET(relation);
  }
}

/*
HASHTABLE* lookup_CSG(HASHTABLE table, char* c, char* s, char* g){
  HASHTABLE* results = LinkedList_new();
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->student_id, s)==0 || s[0]=='*')
    && (strcmp(r->student_grade, g)==0 || g[0]=='*')){}
  return results;
}

HASHTABLE* lookup_SNAP(HASHTABLE table, char* s, char* n, char* a, char* p){
  HASHTABLE* results = LinkedList_new();
    if((strcmp(r->student_name, s)==0 || s[0]=='*')
    && (strcmp(r->student_address, n)==0 || n[0]=='*')
    && (strcmp(r->student_id, a)==0 || a[0]=='*')
    && (strcmp(r->student_phone, p)==0 || p[0]=='*')){}
  return results;
}

HASHTABLE* lookup_CPQ(HASHTABLE table, char* c, char* pq){
    CPQ_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){}
  return results;
}

HASHTABLE* lookup_CDH(HASHTABLE table, char* c, char* d, char* h){
  HASHTABLE* results = LinkedList_new();
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->course_day, d)==0 || d[0]=='*')
    && (strcmp(r->course_hour, h)==0 || h[0]=='*')){}
  return results;
}

HASHTABLE* lookup_CR(HASHTABLE table, char* c, char* r){
  HASHTABLE* results = LinkedList_new();
    if((strcmp(rel->course_name, c)==0 || c[0]=='*')
    && (strcmp(rel->course_room, r)==0 || r[0]=='*')){
  return results;
}

void delete_CSG(HASHTABLE table, char* c, char* s, char* g){
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->student_id, s)==0 || s[0]=='*')
    && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
}

void delete_SNAP(HASHTABLE table, char* s, char* n, char* a, char* p){
    if((strcmp(r->student_name, s)==0 || s[0]=='*')
    && (strcmp(r->student_address, n)==0 || n[0]=='*')
    && (strcmp(r->student_id, a)==0 || a[0]=='*')
    && (strcmp(r->student_phone, p)==0 || p[0]=='*')){}
}

void delete_CPQ(HASHTABLE table, char* c, char* pq){
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){}
}

void delete_CDH(HASHTABLE table, char* c, char* d, char* h){
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->course_day, d)==0 || d[0]=='*')
    && (strcmp(r->course_hour, h)==0 || h[0]=='*')){}
}
*/
