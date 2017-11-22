#ifndef RDM_H
#define  RDM_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "LinkedList.h"
#include "relations.h"

extern void insert_CSG(LinkedList* list, char* c, char* s, char* g);
extern void insert_SNAP(LinkedList* list, char* s, char* n, char* a, char* p);
extern void insert_CPQ(LinkedList* list, char* c, char* pq);
extern void insert_CDH(LinkedList* list, char* c, char* d, char* h);
extern void insert_CR(LinkedList* list, char* c, char* r);

extern LinkedList* lookup_CSG(LinkedList* list, char* c, char* s, char* g);
extern LinkedList* lookup_SNAP(LinkedList* list, char* s, char* n, char* a, char* p);
extern LinkedList* lookup_CPQ(LinkedList* list, char* c, char* pq);
extern LinkedList* lookup_CDH(LinkedList* list, char* c, char* d, char* h);
extern LinkedList* lookup_CR(LinkedList* list, char* c, char* r);

extern void delete_CSG(LinkedList* list, char* c, char* s, char* g);
extern void delete_SNAP(LinkedList* list, char* s, char* n, char* a, char* p);
extern void delete_CPQ(LinkedList* list, char* c, char* pq);
extern void delete_CDH(LinkedList* list, char* c, char* d, char* h);
extern void delete_CR(LinkedList* list, char* c, char* r);

extern bool contains_CSG(LinkedList* list, CSG_RELATION csg);
extern bool contains_SNAP(LinkedList* list, SNAP_RELATION snap);
extern bool contains_CPQ(LinkedList* list, CPQ_RELATION cpq);
extern bool contains_CDH(LinkedList* list, CDH_RELATION cdh);
extern bool contains_CR(LinkedList* list, CR_RELATION cr);

#endif
