#ifndef RDM_H
#define  RDM_H
#include <string.h>
#include <stdio.h>

typedef struct _CSG* CSG_RELATION;
struct _CSG {
  char* course_name;
  int student_id;
  char* student_grade;
};
extern CSG_RELATION new_CSG(char* c, int s, char* g);
extern void free_CSG();
void print_CSG(CSG_RELATION csg){
    printf("%s %d %s\n", csg->course_name, csg->student_id, csg->student_grade);
}

typedef struct _SNAP* SNAP_RELATION;
struct _SNAP  {
  int student_id;
  char* student_name;
  char* student_address;
  int student_phone;
};
extern SNAP_RELATION new_SNAP(int s, char* n, char* a, int p);
extern void free_SNAP();
void print_SNAP(SNAP_RELATION snap){
  printf("%d %s %s %d\n",
    snap->student_id, snap->student_name,
    snap->student_address, snap->student_phone
  );
}

typedef struct _CPQ* CPQ_RELATION;
struct _CPQ {
  char* course_name;
  char* prereq_name;
};
extern CPQ_RELATION new_CPQ(char* c, char* pq);
extern void free_CPQ();
void print_CPQ(CPQ_RELATION cpq){
  printf("%s %s\n", cpq->course_name, cpq->prereq_name);
}

typedef struct _CDH* CDH_RELATION;
struct _CDH {
  char* course_name;
  char* course_day;
  char* course_hour;
};
extern CDH_RELATION new_CDH(char* c, char* d, char* h);
extern void free_CDH();
void print_CDH(CDH_RELATION cdh){
  printf("%s %s %s\n", cdh->course_name, cdh->course_day, cdh->course_hour);
}

typedef struct _CR* CR_RELATION;
struct _CR {
  char* course_name;
  char* course_room;
};
extern CR_RELATION new_CR(char* c, char* r);
extern void free_CR();
void print_CR(CR_RELATION cr){
  printf("%s %s\n", cr->course_name, cr->course_room);
}

#endif
