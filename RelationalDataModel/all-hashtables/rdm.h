#ifndef RDM_H
#define  RDM_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "hashtable.h"
#include "database.h"
#include "relations.h"

extern void insert_CSG(DATABASE table, char* c, char* s, char* g);
extern void insert_SNAP(DATABASE table, char* s, char* n, char* a, char* p);
extern void insert_CPQ(DATABASE table, char* c, char* pq);
extern void insert_CDH(DATABASE table, char* c, char* d, char* h);
extern void insert_CR(DATABASE table, char* c, char* r);

extern CSG_RELATION lookup_CSG(DATABASE table, char* c, char* s, char* g);
extern SNAP_RELATION lookup_SNAP(DATABASE table, char* s, char* n, char* a, char* p);
extern CPQ_RELATION lookup_CPQ(DATABASE table, char* c, char* pq);
extern CDH_RELATION lookup_CDH(DATABASE table, char* c, char* d, char* h);
extern CR_RELATION lookup_CR(DATABASE table, char* c, char* r);

extern void delete_CSG(DATABASE table, char* c, char* s, char* g);
extern void delete_SNAP(DATABASE table, char* s, char* n, char* a, char* p);
extern void delete_CPQ(DATABASE table, char* c, char* pq);
extern void delete_CDH(DATABASE table, char* c, char* d, char* h);
extern void delete_CR(DATABASE table, char* c, char* r);

#endif
