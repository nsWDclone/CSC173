#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "rdm.h"

//TODO: collisions
void insert_CSG(DATABASE table, char* c, char* s, char* g){
  CSG_RELATION relation = new_CSG(c,s,g);
  char str[10];
  strcpy(str, c);
  strcat(str, s);
  put_CSG(table->storage, str, relation);
  put_INDEX(table->index, str, new_INDEX(relation));
}

void insert_SNAP(DATABASE table, char* s, char* n, char* a, char* p){
  SNAP_RELATION relation = new_SNAP(s,n,a,p);
  char str[15];
  strcpy(str, s);
  strcat(str, p);
  put_SNAP(table->storage, str, relation);
  put_INDEX(table->index, str, new_INDEX(relation));
}

void insert_CPQ(DATABASE table, char* c, char* pq){
  CPQ_RELATION relation = new_CPQ(c,pq);
  char str[50];
  strcpy(str, c);
  strcat(str, pq);
  put_CPQ(table->storage, str, relation);
  put_INDEX(table->index, str, new_INDEX(relation));
}

void insert_CDH(DATABASE table, char* c, char* d, char* h){
  CDH_RELATION relation = new_CDH(c,d,h);
  char str[7];
  strcpy(str, c);
  strcat(str, d);
  put_CDH(table->storage, str, relation);
}

void insert_CR(DATABASE table, char* c, char* r){
  CR_RELATION relation = new_CR(c,r);
  char str[5];
  strcpy(str, c);
  put_CR(table->storage, str, relation);
  put_INDEX(table->index, str, new_INDEX(relation));
}

CSG_RELATION lookup_CSG(DATABASE table, char* c, char* s, char* g){
  CSG_RELATION r;
  CSG_RELATION last;
  CSG_RELATION result = NULL;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    r = b->contents;
    while (r!=NULL){
      if((strcmp(r->course_name, c)==0 || c[0]=='*')
      && (strcmp(r->student_id, s)==0 || s[0]=='*')
      && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
        if(result==NULL){
          result = new_CSG(
            r->course_name,
            r->student_id,
            r->student_grade);
          last = result;
        } else {
          last->next = new_CSG(
            r->course_name,
            r->student_id,
            r->student_grade);
          last = last->next;
        }
      }
      r = r->next;
    }
  }
  return result;
}

SNAP_RELATION lookup_SNAP(DATABASE table, char* s, char* n, char* a, char* p){
  SNAP_RELATION r;
  SNAP_RELATION last;
  SNAP_RELATION result = NULL;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    r = b->contents;
    while (r!=NULL){
      if((strcmp(r->student_id, s)==0 || s[0]=='*')
      && (strcmp(r->student_name, n)==0 || n[0]=='*')
      && (strcmp(r->student_address, a)==0 || a[0]=='*')
      && (strcmp(r->student_phone, p)==0 || p[0]=='*')){
        if(result==NULL){
          result = new_SNAP(
            r->student_id,
            r->student_name,
            r->student_address,
            r->student_phone);
          last = result;
        } else {
          last->next = new_SNAP(
            r->student_id,
            r->student_name,
            r->student_address,
            r->student_phone);
          last = last->next;
        }
      }
      r = r->next;
    }
  }
  return result;
}

CPQ_RELATION lookup_CPQ(DATABASE table, char* c, char* pq){
  CPQ_RELATION r;
  CPQ_RELATION last;
  CPQ_RELATION result = NULL;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    r = b->contents;
    while(r!=NULL){
      if((strcmp(r->course_name, c)==0 || c[0]=='*')
      && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){
        if(result==NULL){
          result = new_CPQ(
            r->course_name,
            r->prereq_name);
          last = result;
        } else {
          last->next = new_CPQ(
            r->course_name,
            r->prereq_name);
          last = last->next;
        }
      }
      r = r->next;
    }
  }
  return result;
}

CDH_RELATION lookup_CDH(DATABASE table, char* c, char* d, char* h){
  CDH_RELATION r;
  CDH_RELATION last;
  CDH_RELATION result = NULL;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    r = b->contents;
    while(r!=NULL){
      if((strcmp(r->course_name, c)==0 || c[0]=='*')
      && (strcmp(r->course_day, d)==0 || d[0]=='*')
      && (strcmp(r->course_hour, h)==0 || h[0]=='*')){
        if(result==NULL){
          result = new_CDH(
            r->course_name,
            r->course_day,
            r->course_hour);
          last = result;
        } else {
          last->next = new_CDH(
            r->course_name,
            r->course_day,
            r->course_hour);
          last = last->next;
        }
      }
      r = r->next;
    }
  }
  return result;
}

CR_RELATION lookup_CR(DATABASE table, char* c, char* room){
  CR_RELATION r;
  CR_RELATION last;
  CR_RELATION result = NULL;
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    r = b->contents;
    while (r !=NULL){
      if((strcmp(r->course_name, c)==0 || c[0]=='*')
      && (strcmp(r->course_room, room)==0 || room[0]=='*')){
        if(result==NULL){
          result = new_CR(
            r->course_name,
            r->course_room);
          last = result;
        } else {
          last->next = new_CR(
            r->course_name,
            r->course_room);
          last = last->next;
        }
      }
      r = r->next;
    }
  }
  return result;
}

void delete_CSG(DATABASE table, char* c, char* s, char* g){
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      CSG_RELATION r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->student_id, s)==0 || s[0]=='*')
        && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
          table->storage->entries--;
          if(r->prev==NULL && r->next==NULL){
            b->contents = NULL;
            r = r->next;
          } else if(r->prev==NULL && r->next!=NULL){
            r->next->prev = NULL;
            r = r->next;//*r = *(r->next);
          } else if(r->prev!=NULL && r->next==NULL){
            r->prev->next = NULL;
            r = r->next;
          } else {
            r->next->prev = r->prev;
            r->prev->next = r->next;
            r = r->next;
          }
        } else r = r->next;
      } while (r!=NULL);
    }
  }
}

void delete_SNAP(DATABASE table, char* s, char* n, char* a, char* p){
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      SNAP_RELATION r = b->contents;
      do{
        if((strcmp(r->student_id, s)==0 || s[0]=='*')
        && (strcmp(r->student_name, n)==0 || n[0]=='*')
        && (strcmp(r->student_address, a)==0 || a[0]=='*')
        && (strcmp(r->student_phone, p)==0 || p[0]=='*')){
          table->storage->entries--;
          if(r->prev==NULL && r->next==NULL){
            b->contents = NULL;
            r = r->next;
          } else if(r->prev==NULL && r->next!=NULL){
            r->next->prev = NULL;
            r = r->next;//*r = *(r->next);
          } else if(r->prev!=NULL && r->next==NULL){
            r->prev->next = NULL;
            r = r->next;
          } else {
            r->next->prev = r->prev;
            r->prev->next = r->next;
            r = r->next;
          }
        } else r = r->next;
      } while (r!=NULL);
    }
  }
}

void delete_CPQ(DATABASE table, char* c, char* pq){
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      CPQ_RELATION r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){
          table->storage->entries--;
          if(r->prev==NULL && r->next==NULL){
            b->contents = NULL;
            r = r->next;
          } else if(r->prev==NULL && r->next!=NULL){
            r->next->prev = NULL;
            r = r->next;//*r = *(r->next);
          } else if(r->prev!=NULL && r->next==NULL){
            r->prev->next = NULL;
            r = r->next;
          } else {
            r->next->prev = r->prev;
            r->prev->next = r->next;
            r = r->next;
          }
        } else r = r->next;
      } while (r!=NULL);
    }
  }
}

void delete_CDH(DATABASE table, char* c, char* d, char* h){
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      CDH_RELATION r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->course_day, d)==0 || d[0]=='*')
        && (strcmp(r->course_hour, h)==0 || h[0]=='*')){
          table->storage->entries--;
          if(r->prev==NULL && r->next==NULL){
            b->contents = NULL;
            r = r->next;
          } else if(r->prev==NULL && r->next!=NULL){
            r->next->prev = NULL;
            r = r->next;//*r = *(r->next);
          } else if(r->prev!=NULL && r->next==NULL){
            r->prev->next = NULL;
            r = r->next;
          } else {
            r->next->prev = r->prev;
            r->prev->next = r->next;
            r = r->next;
          }
        } else r = r->next;
      } while (r!=NULL);
    }
  }
}

void delete_CR(DATABASE table, char* c, char* room){
  for(int i=0; i<table->storage->size; i++){
    BUCKET b = table->storage->buckets[i];
    if(b->contents != NULL){
      CR_RELATION r = b->contents;
      do{
        if((strcmp(r->course_name, c)==0 || c[0]=='*')
        && (strcmp(r->course_room, room)==0 || room[0]=='*')){
          table->storage->entries--;
          if(r->prev==NULL && r->next==NULL){
            b->contents = NULL;
            r = r->next;
          } else if(r->prev==NULL && r->next!=NULL){
            r->next->prev = NULL;
            r = r->next;//*r = *(r->next);
          } else if(r->prev!=NULL && r->next==NULL){
            r->prev->next = NULL;
            r = r->next;
          } else {
            r->next->prev = r->prev;
            r->prev->next = r->next;
            r = r->next;
          }
        } else r = r->next;
      } while (r!=NULL);
    }
  }
}
