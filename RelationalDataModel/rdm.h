#ifndef RDM_H
#define  RDM_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "hashtable.h"
#include "relations.h"

extern void insert_CSG(HASHTABLE table, char* c, char* s, char* g);
extern void insert_SNAP(HASHTABLE table, char* s, char* n, char* a, char* p);
extern void insert_CPQ(HASHTABLE table, char* c, char* pq);
extern void insert_CDH(HASHTABLE table, char* c, char* d, char* h);
extern void insert_CR(HASHTABLE table, char* c, char* r);

extern HASHTABLE lookup_CSG(HASHTABLE table, char* c, char* s, char* g);
extern HASHTABLE lookup_SNAP(HASHTABLE table, char* s, char* n, char* a, char* p);
extern HASHTABLE lookup_CPQ(HASHTABLE table, char* c, char* pq);
extern HASHTABLE lookup_CDH(HASHTABLE table, char* c, char* d, char* h);
extern HASHTABLE lookup_CR(HASHTABLE table, char* c, char* r);

extern void delete_CSG(HASHTABLE table, char* c, char* s, char* g);
extern void delete_SNAP(HASHTABLE table, char* s, char* n, char* a, char* p);
extern void delete_CPQ(HASHTABLE table, char* c, char* pq);
extern void delete_CDH(HASHTABLE table, char* c, char* d, char* h);
extern void delete_CR(HASHTABLE table, char* c, char* r);

#endif
