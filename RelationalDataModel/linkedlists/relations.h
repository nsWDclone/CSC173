#ifndef RELATIONS_H
#define RELATIONS_H

typedef struct _CSG* CSG_RELATION;
  struct _CSG {
    char* course_name;
    char* student_id;
    char* student_grade;
  };
extern CSG_RELATION new_CSG(char* c, char* s, char* g);
extern void free_CSG();
extern void print_CSG(CSG_RELATION csg);

typedef struct _SNAP* SNAP_RELATION;
  struct _SNAP  {
    char* student_id;
    char* student_name;
    char* student_address;
    char* student_phone;
  };
extern SNAP_RELATION new_SNAP(char* s, char* n, char* a, char* p);
extern void free_SNAP();
extern void print_SNAP(SNAP_RELATION snap);

typedef struct _CPQ* CPQ_RELATION;
  struct _CPQ {
    char* course_name;
    char* prereq_name;
  };
extern CPQ_RELATION new_CPQ(char* c, char* pq);
extern void free_CPQ();
extern void print_CPQ(CPQ_RELATION cpq);

typedef struct _CDH* CDH_RELATION;
  struct _CDH {
    char* course_name;
    char* course_day;
    char* course_hour;
  };
extern CDH_RELATION new_CDH(char* c, char* d, char* h);
extern void free_CDH();
extern void print_CDH(CDH_RELATION cdh);

typedef struct _CR* CR_RELATION;
  struct _CR {
    char* course_name;
    char* course_room;
  };
extern CR_RELATION new_CR(char* c, char* r);
extern void free_CR();
extern void print_CR(CR_RELATION cr);

#endif
