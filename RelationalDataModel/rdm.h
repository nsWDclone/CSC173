#ifndef RDM_H
#define  RDM_H

#include <string.h>
#include <stdio.h>

#include "LinkedList.h"
#include "relations.h"

extern void insert(LinkedList* list, void* data);
extern void lookup_CSG(LinkedList* list, CSG_RELATION csg);
extern void lookup_SNAP(LinkedList* list, SNAP_RELATION snap);
extern void lookup_CPQ(LinkedList* list, CPQ_RELATION cpq);
extern void lookup_CDH(LinkedList* list, CDH_RELATION cdh);
extern void lookup_CR(LinkedList* list, CR_RELATION cr);
extern void delete_CSG(LinkedList* list, CSG_RELATION csg);
extern void delete_SNAP(LinkedList* list, SNAP_RELATION snap);
extern void delete_CPQ(LinkedList* list, CPQ_RELATION cpq);
extern void delete_CDH(LinkedList* list, CDH_RELATION cdh);
extern void delete_CR(LinkedList* list, CR_RELATION cr);

#endif
