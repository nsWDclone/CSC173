#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "relations.h"


CSG_RELATION new_CSG(char* c, char* s, char* g){
  CSG_RELATION new_csg = (CSG_RELATION)malloc(sizeof(struct _CSG));
  new_csg->course_name = c;
  new_csg->student_id = s;
  new_csg->student_grade = g;
  new_csg->next = NULL;
  new_csg->prev = NULL;
  return new_csg;
}
void print_CSG(CSG_RELATION csg){
  int i=0;
  while(csg!=NULL){
    printf("[%d] %s %s %s ", i, csg->course_name, csg->student_id, csg->student_grade);
    csg = csg->next;
    i++;
  }
  printf("\n" );
  // while(csg!=NULL){
  //   printf("%s %s %s\n", csg->course_name, csg->student_id, csg->student_grade);
  //   csg = csg->next;
  // }
}

SNAP_RELATION new_SNAP(char* s, char* n, char* a, char* p){
  SNAP_RELATION new_snap = (SNAP_RELATION)malloc(sizeof(struct _SNAP));
  new_snap->student_id = s;
  new_snap->student_name = n;
  new_snap->student_address = a;
  new_snap->student_phone = p;
  new_snap->next = NULL;
  new_snap->prev = NULL;
  return new_snap;
}
void print_SNAP(SNAP_RELATION snap){
  do{
    printf("%s %s %s %s\n",
      snap->student_id, snap->student_name,
      snap->student_address, snap->student_phone
    );
    snap = snap->next;
  } while (snap!=NULL);
}

CPQ_RELATION new_CPQ(char* c, char* pq){
  CPQ_RELATION new_cpq = (CPQ_RELATION)malloc(sizeof(struct _CPQ));
  new_cpq->course_name = c;
  new_cpq->prereq_name = pq;
  new_cpq->next = NULL;
  new_cpq->prev = NULL;
  return new_cpq;
}
void print_CPQ(CPQ_RELATION cpq){
  do{
    printf("%s %s\n", cpq->course_name, cpq->prereq_name);
    cpq = cpq->next;
  } while (cpq!=NULL);
}

CDH_RELATION new_CDH(char* c, char* d, char* h){
  CDH_RELATION new_cdh = (CDH_RELATION)malloc(sizeof(struct _CDH));
  new_cdh->course_name = c;
  new_cdh->course_day = d;
  new_cdh->course_hour = h;
  new_cdh->next = NULL;
  new_cdh->prev = NULL;
  return new_cdh;
}
void print_CDH(CDH_RELATION cdh){
  do{
    printf("%s %s %s\n", cdh->course_name, cdh->course_day, cdh->course_hour);
    cdh = cdh->next;
  } while (cdh!=NULL);
}

CR_RELATION new_CR(char* c, char* r){
  CR_RELATION new_cr = (CR_RELATION)malloc(sizeof(struct _CR));
  new_cr->course_name = c;
  new_cr->course_room =r;
  new_cr->next = NULL;
  new_cr->prev = NULL;
  return new_cr;
}
void print_CR(CR_RELATION cr){
  do{
    printf("%s %s\n", cr->course_name, cr->course_room);
    cr = cr->next;
  } while(cr!=NULL);
}

void print_relation(char schema, void* relation){
  if(relation==NULL){
    return;
  }
  switch(schema){
    case schema_CSG:
      print_CSG(relation);
      break;
    case schema_SNAP:
      print_SNAP(relation);
      break;
    case schema_CPQ:
      print_CPQ(relation);
      break;
    case schema_CDH:
      print_CDH(relation);
      break;
    case schema_CR:
      print_CR(relation);
      break;
    default:
      break;
  }
}

bool CSG_equals(CSG_RELATION r1, CSG_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->student_id, r2->student_id)==0
  && strcmp(r1->student_grade, r2->student_grade)==0) return true;
  else return false;
}

bool SNAP_equals(SNAP_RELATION r1, SNAP_RELATION r2){
  if(strcmp(r1->student_id, r2->student_id)==0
  && strcmp(r1->student_name, r2->student_name)==0
  && strcmp(r1->student_address, r2->student_address)==0
  && strcmp(r1->student_phone, r2->student_phone)==0) return true;
  else return false;
}

bool CPQ_equals(CPQ_RELATION r1, CPQ_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->prereq_name, r2->prereq_name)==0) return true;
  else return false;
}

bool CDH_equals(CDH_RELATION r1, CDH_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->course_day, r2->course_day)==0
  && strcmp(r1->course_hour, r2->course_hour)==0) return true;
  else return false;
}

bool CR_equals(CR_RELATION r1, CR_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->course_room, r2->course_room)==0) return true;
  else return false;
}
