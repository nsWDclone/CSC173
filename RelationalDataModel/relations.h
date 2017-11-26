#ifndef RELATIONS_H
#define RELATIONS_H

#include <stdbool.h>

#define schema_CSG  'g'
#define schema_SNAP 'p'
#define schema_CPQ  'q'
#define schema_CDH  'h'
#define schema_CR   'r'
#define schema_ID   'i'
#define schema_CRDH 'd'
#define schema_DH   'D'

#define schema_CSGx  -1
#define schema_SNAPx -2
#define schema_CPQx  -3
#define schema_CDHx  -4
#define schema_CRx   -5
#define schema_IDx   -6
#define schema_CRDHx -7
#define schema_DHx   -8

typedef struct _CSG* CSG_RELATION;
  struct _CSG {
    char* course_name;
    char* student_id;
    char* student_grade;
    char* key;
    CSG_RELATION next;
    CSG_RELATION prev;
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
    char* key;
    SNAP_RELATION next;
    SNAP_RELATION prev;
  };
extern SNAP_RELATION new_SNAP(char* s, char* n, char* a, char* p);
extern void free_SNAP();
extern void print_SNAP(SNAP_RELATION snap);

typedef struct _CPQ* CPQ_RELATION;
  struct _CPQ {
    char* course_name;
    char* prereq_name;
    char* key;
    CPQ_RELATION next;
    CPQ_RELATION prev;
  };
extern CPQ_RELATION new_CPQ(char* c, char* pq);
extern void free_CPQ();
extern void print_CPQ(CPQ_RELATION cpq);

typedef struct _CDH* CDH_RELATION;
  struct _CDH {
    char* course_name;
    char* course_day;
    char* course_hour;
    char* key;
    CDH_RELATION next;
    CDH_RELATION prev;
  };
extern CDH_RELATION new_CDH(char* c, char* d, char* h);
extern void free_CDH();
extern void print_CDH(CDH_RELATION cdh);

typedef struct _CR* CR_RELATION;
  struct _CR {
    char* course_name;
    char* course_room;
    char* key;
    CR_RELATION next;
    CR_RELATION prev;
  };
extern CR_RELATION new_CR(char* c, char* r);
extern void free_CR();
extern void print_CR(CR_RELATION cr);

typedef struct _ID* ID_RELATION;
  struct _ID {
    char* student_id;
    char* key;
    ID_RELATION next;
    ID_RELATION prev;
  };
extern ID_RELATION new_ID(char* s);
extern void free_ID();
extern void print_ID(ID_RELATION id);

typedef struct _CRDH* CRDH_RELATION;
  struct _CRDH{
    char* course_name;
    char* course_room;
    char* course_day;
    char* course_hour;
    char* key;
    CRDH_RELATION next;
    CRDH_RELATION prev;
  };
extern CRDH_RELATION new_CRDH(char* c, char* r, char* d, char* h);
extern void free_CRDH();
extern void print_CRDH(CRDH_RELATION crdh);

typedef struct _DH* DH_RELATION;
  struct _DH{
    char* course_day;
    char* course_hour;
    char* key;
    DH_RELATION next;
    DH_RELATION prev;
  };
  extern DH_RELATION new_DH(char* d, char* h);
  extern void free_DH();
  extern void print_DH(DH_RELATION dh);


extern void print_relation(char s, void* relation);
extern bool CSG_equals(CSG_RELATION r1, CSG_RELATION r2);
extern bool SNAP_equals(SNAP_RELATION r1, SNAP_RELATION r2);
extern bool CPQ_equals(CPQ_RELATION r1, CPQ_RELATION r2);
extern bool CDH_equals(CDH_RELATION r1, CDH_RELATION r2);
extern bool CR_equals(CR_RELATION r1, CR_RELATION r2);
extern bool ID_equals(ID_RELATION r1, ID_RELATION r2);
extern bool CRDH_equals(CRDH_RELATION r1, CRDH_RELATION r2);
extern bool DH_equals(DH_RELATION r1, DH_RELATION r2);
extern bool relation_equals(char schema, void* r1, void* r2);

#endif
