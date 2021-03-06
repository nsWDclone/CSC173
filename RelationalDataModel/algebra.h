#ifndef ALGEBRA_H
#define ALGEBRA_H

#include "hashtable.h"
#include "database.h"

extern HASHTABLE unon(HASHTABLE h1, HASHTABLE h2);
extern HASHTABLE inxt(HASHTABLE h1, HASHTABLE h2);
extern HASHTABLE diff(HASHTABLE h1, HASHTABLE h2);
extern HASHTABLE slct_c_csg(HASHTABLE h, char* c);
extern HASHTABLE slct_s_csg(HASHTABLE h, char* s);
extern HASHTABLE slct_r_crdh(HASHTABLE h, char* c);
extern HASHTABLE proj_s_csg(HASHTABLE h);
extern HASHTABLE proj_dh_crdh(HASHTABLE h);
extern HASHTABLE join_cr_cdh_course(HASHTABLE cr_table, HASHTABLE cdh_table);
extern char* grade(char* n, char* c, DATABASE csg, DATABASE snap);
extern char* whereis(char* n, char* h, char* d,
  DATABASE snap, DATABASE csg, DATABASE cdh, DATABASE cr);
#endif
