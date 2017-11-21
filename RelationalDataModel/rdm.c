#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "rdm.h"

void insert(LinkedList* list, void* relation){
  if(LinkedList_contains(list, relation) == true){
    printf(" -- Duplicate Entry -- ");
  } else {
    LinkedList_add_at_end(list, relation);
  }
}

void lookup_CSG(LinkedList* list, CSG_RELATION csg){}
void lookup_SNAP(LinkedList* list, SNAP_RELATION snap){}
void lookup_CPQ(LinkedList* list, CPQ_RELATION cpq){}
void lookup_CDH(LinkedList* list, CDH_RELATION cdh){}
void lookup_CR(LinkedList* list, CR_RELATION cr){}

void delete_CSG(LinkedList* list, CSG_RELATION csg){}
void delete_SNAP(LinkedList* list, SNAP_RELATION snap){}
void delete_CPQ(LinkedList* list, CPQ_RELATION cpq){}
void delete_CDH(LinkedList* list, CDH_RELATION cdh){}
void delete_CR(LinkedList* list, CR_RELATION cr){}
