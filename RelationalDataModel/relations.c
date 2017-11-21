#include <stdlib.h>
#include <stdio.h>
#include "relations.h"

CSG_RELATION new_CSG(char* c, int s, char* g){
  CSG_RELATION new_csg = (CSG_RELATION)malloc(sizeof(struct _CSG));
  new_csg->course_name = c;
  new_csg->student_id = s;
  new_csg->student_grade = g;
  return new_csg;
}
void print_CSG(CSG_RELATION csg){
    printf("%s %d %s\n", csg->course_name, csg->student_id, csg->student_grade);
}

SNAP_RELATION new_SNAP(int s, char* n, char* a, int p){
  SNAP_RELATION new_snap = (SNAP_RELATION)malloc(sizeof(struct _SNAP));
  new_snap->student_id = s;
  new_snap->student_name = n;
  new_snap->student_address = a;
  new_snap->student_phone = p;
  return new_snap;
}
void print_SNAP(SNAP_RELATION snap){
  printf("%d %s %s %d\n",
    snap->student_id, snap->student_name,
    snap->student_address, snap->student_phone
  );
}

CPQ_RELATION new_CPQ(char* c, char* pq){
  CPQ_RELATION new_cpq = (CPQ_RELATION)malloc(sizeof(struct _CPQ));
  new_cpq->course_name = c;
  new_cpq->prereq_name = pq;
  return new_cpq;
}
void print_CPQ(CPQ_RELATION cpq){
  printf("%s %s\n", cpq->course_name, cpq->prereq_name);
}

CDH_RELATION new_CDH(char* c, char* d, char* h){
  CDH_RELATION new_cdh = (CDH_RELATION)malloc(sizeof(struct _CDH));
  new_cdh->course_name = c;
  new_cdh->course_day = d;
  new_cdh->course_hour = h;
  return new_cdh;
}
void print_CDH(CDH_RELATION cdh){
  printf("%s %s %s\n", cdh->course_name, cdh->course_day, cdh->course_hour);
}

CR_RELATION new_CR(char* c, char* r){
  CR_RELATION new_cr = (CR_RELATION)malloc(sizeof(struct _CR));
  new_cr->course_name = c;
  new_cr->course_room =r;
  return new_cr;
}
void print_CR(CR_RELATION cr){
  printf("%s %s\n", cr->course_name, cr->course_room);
}
