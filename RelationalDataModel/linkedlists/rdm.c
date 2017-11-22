#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "rdm.h"

void insert_CSG(LinkedList* list, char* c, char* s, char* g){
  CSG_RELATION r = new_CSG(c,s,g);
  if(contains_CSG(list , r)) printf("** Duplicate\n");
  else LinkedList_add_at_end(list, r);
}

void insert_SNAP(LinkedList* list, char* s, char* n, char* a, char* p){
  SNAP_RELATION r = new_SNAP(s,n,a,p);
  if(contains_SNAP(list , r)) printf("** Duplicate\n");
  else LinkedList_add_at_end(list, r);
}

void insert_CPQ(LinkedList* list, char* c, char* pq){
  CPQ_RELATION r = new_CPQ(c,pq);
  if(contains_CPQ(list , r)) printf("** Duplicate\n");
  else LinkedList_add_at_end(list, r);
}

void insert_CDH(LinkedList* list, char* c, char* d, char* h){
  CDH_RELATION r = new_CDH(c,d,h);
  if(contains_CDH(list , r)) printf("** Duplicate\n");
  else LinkedList_add_at_end(list, r);
}

void insert_CR(LinkedList* list, char* c, char* r){
  CR_RELATION rel = new_CR(c,r);
  if(contains_CR(list , rel)) printf("** Duplicate\n");
  else LinkedList_add_at_end(list, rel);
}

LinkedList* lookup_CSG(LinkedList* list, char* c, char* s, char* g){
  LinkedList* results = LinkedList_new();
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CSG_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->student_id, s)==0 || s[0]=='*')
    && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
      LinkedList_add_at_end(results, r);
    }
  }
  return results;
}

LinkedList* lookup_SNAP(LinkedList* list, char* s, char* n, char* a, char* p){
  LinkedList* results = LinkedList_new();
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    SNAP_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->student_name, s)==0 || s[0]=='*')
    && (strcmp(r->student_address, n)==0 || n[0]=='*')
    && (strcmp(r->student_id, a)==0 || a[0]=='*')
    && (strcmp(r->student_phone, p)==0 || p[0]=='*')){
      LinkedList_add_at_end(results, r);
    }
  }
  return results;
}

LinkedList* lookup_CPQ(LinkedList* list, char* c, char* pq){
  LinkedList* results = LinkedList_new();
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CPQ_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){
      LinkedList_add_at_end(results, r);
    }
  }
  return results;
}

LinkedList* lookup_CDH(LinkedList* list, char* c, char* d, char* h){
  LinkedList* results = LinkedList_new();
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CDH_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->course_day, d)==0 || d[0]=='*')
    && (strcmp(r->course_hour, h)==0 || h[0]=='*')){
      LinkedList_add_at_end(results, r);
    }
  }
  return results;
}

LinkedList* lookup_CR(LinkedList* list, char* c, char* r){
  LinkedList* results = LinkedList_new();
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CR_RELATION rel = LinkedListIterator_next(i);
    if((strcmp(rel->course_name, c)==0 || c[0]=='*')
    && (strcmp(rel->course_room, r)==0 || r[0]=='*')){
      LinkedList_add_at_end(results, rel);
    }
  }
  return results;
}

void delete_CSG(LinkedList* list, char* c, char* s, char* g){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CSG_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->student_id, s)==0 || s[0]=='*')
    && (strcmp(r->student_grade, g)==0 || g[0]=='*')){
      LinkedList_remove(list, r);
    }
  }
}

void delete_SNAP(LinkedList* list, char* s, char* n, char* a, char* p){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    SNAP_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->student_name, s)==0 || s[0]=='*')
    && (strcmp(r->student_address, n)==0 || n[0]=='*')
    && (strcmp(r->student_id, a)==0 || a[0]=='*')
    && (strcmp(r->student_phone, p)==0 || p[0]=='*')){
      LinkedList_remove(list, r);
    }
  }
}

void delete_CPQ(LinkedList* list, char* c, char* pq){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CPQ_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->prereq_name, pq)==0 || pq[0]=='*')){
      LinkedList_remove(list, r);
    }
  }
}

void delete_CDH(LinkedList* list, char* c, char* d, char* h){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CDH_RELATION r = LinkedListIterator_next(i);
    if((strcmp(r->course_name, c)==0 || c[0]=='*')
    && (strcmp(r->course_day, d)==0 || d[0]=='*')
    && (strcmp(r->course_hour, h)==0 || h[0]=='*')){
      LinkedList_remove(list, r);
    }
  }
}

void delete_CR(LinkedList* list, char* c, char* r){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CR_RELATION rel = LinkedListIterator_next(i);
    if((strcmp(rel->course_name, c)==0 || c[0]=='*')
    && (strcmp(rel->course_room, r)==0 || r[0]=='*')){
      LinkedList_remove(list, rel);
    }
  }
}

bool contains_CSG(LinkedList* list, CSG_RELATION csg){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CSG_RELATION r = LinkedListIterator_next(i);
    if(strcmp(r->course_name, csg->course_name)==0
    && strcmp(r->student_id, csg->student_id)==0
    && strcmp(r->student_grade, csg->student_grade)==0) return true;
  }
  return false;
}

bool contains_SNAP(LinkedList* list, SNAP_RELATION snap){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    SNAP_RELATION r = LinkedListIterator_next(i);
    if(strcmp(r->student_name, snap->student_name)==0
    && strcmp(r->student_address, snap->student_address)==0
    && strcmp(r->student_id,snap->student_id)==0
    && strcmp(r->student_phone,snap->student_phone)==0) return true;
  }
  return false;
}

bool contains_CPQ(LinkedList* list, CPQ_RELATION cpq){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CPQ_RELATION r = LinkedListIterator_next(i);
    if(strcmp(r->course_name, cpq->course_name)==0
    && strcmp(r->prereq_name, cpq->prereq_name)==0)
      return true;
  }
  return false;
}

bool contains_CDH(LinkedList* list, CDH_RELATION cdh){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
  CDH_RELATION r = LinkedListIterator_next(i);
  if(strcmp(r->course_name, cdh->course_name)==0
  && strcmp(r->course_day, cdh->course_day)==0
  && strcmp(r->course_hour, cdh->course_hour)==0) return true;
  }
  return false;
}

bool contains_CR(LinkedList* list, CR_RELATION cr){
  LinkedListIterator* i = LinkedList_iterator(list);
  while(LinkedListIterator_has_next(i)){
    CR_RELATION r = LinkedListIterator_next(i);
    if(strcmp(r->course_name, cr->course_name)==0
    && strcmp(r->course_room, cr->course_room)==0) return true;
  }
  return false;
}
