#ifndef RDM_H
#define  RDM_H
#include <string.h>

typedef struct _CSG* CSG_RELATION;
struct _CSG {
  char course_name[5];
  int student_id;
  char student_grade[2];
};
extern CSG new_CSG(char* c, int s, char* g);
extern void free_CSG();

typedef struct _SNAP* SNAP_RELATION;
struct _SNAP  {
  int student_id;
  string student_name;
  string student_address;
  int student_phone;
};
extern SNAP new_SNAP(int s, string n, string a, int p);
extern void free_SNAP();

typedef struct _CPQ* CPQ_RELATION;
struct _CPQ {
  char course_name[5];
  char prereq_name[5];
};
extern CPR_RELATION new_CPQ(char* c, char* pq);
extern void free_CPQ();

typedef struct _CDH* CDH_RELATION;
struct _CDH {
  char course_name[5];
  char course_day;
  string course_hour;
};
extern CDH_RELATION new_CDH(char* c, char d, string h);
extern void free_CDH();

typedef struct _CR* CR_RELATION;
struct _CR {
  char course_name[5];
  string course_room;
};
extern CR_RELATION new_CR(char* c, string r);
extern void free_CR();

#endif
