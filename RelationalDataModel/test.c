#include <stdio.h>

#include "rdm.h"

LinkedList* csg_list = NULL;
LinkedList* snap_list = NULL;
LinkedList* cpq_list= NULL;
LinkedList* cdh_list = NULL;
LinkedList* cr_list = NULL;

void create_tables(){
  csg_list = LinkedList_new();
  snap_list = LinkedList_new();
  cpq_list = LinkedList_new();
  cdh_list = LinkedList_new();
  cr_list = LinkedList_new();

  insert(csg_list, new_CSG("CS101", 12345, "A"));
  insert(csg_list, new_CSG("CS101", 12345, "A"));
  // insert(csg_list, new_CSG("CS101", 67890, "B"));
  // insert(csg_list, new_CSG("EE200", 12345, "C"));
  // insert(csg_list, new_CSG("CS101", 22222, "B+"));
  // insert(csg_list, new_CSG("CS101", 33333, "A-"));
  // insert(csg_list, new_CSG("PH100", 12345, "C+"));
  //
  // insert(snap_list, new_SNAP(12345, "C. Brown", "12 Apple St.", 5551234));
  // insert(snap_list, new_SNAP(67890, "L. Van Pelt", "34 Pear Ave.", 5555678));
  // insert(snap_list, new_SNAP(22222, "P. Patty", "56 Grape Blvd.", 5559999));
  //
  // insert(cpq_list, new_CPQ("CS101", "CS100"));
  // insert(cpq_list, new_CPQ("EE200", "EE005"));
  // insert(cpq_list, new_CPQ("EE200", "CS100"));
  // insert(cpq_list, new_CPQ("CS120", "CS101"));
  // insert(cpq_list, new_CPQ("CS121", "CS120"));
  // insert(cpq_list, new_CPQ("CS205", "CS101"));
  // insert(cpq_list, new_CPQ("CS206", "CS121"));
  // insert(cpq_list, new_CPQ("CS206", "CS205"));
  //
  // insert(cdh_list, new_CDH("CS101", "M", "9AM"));
  // insert(cdh_list, new_CDH("CS101", "W", "9AM"));
  // insert(cdh_list, new_CDH("CS101", "F", "9AM"));
  // insert(cdh_list, new_CDH("EE200", "Tu", "10AM"));
  // insert(cdh_list, new_CDH("EE200", "W", "1PM"));
  // insert(cdh_list, new_CDH("EE200", "Th", "10AM"));
  //
  // insert(cr_list, new_CR("CS101", "Turing Aud."));
  // insert(cr_list, new_CR("EE200", "25 Ohm Hall"));
  // insert(cr_list, new_CR("PH100", "Newton Lab."));
}

int main(int argc, char const *argv[]) {
  create_tables();

  const char* flag = "";
  if(argv[1] != NULL){
    flag = argv[1];
  }
  if(strcmp(flag, "csg")==0 || strcmp(flag, "")==0){
    LinkedListIterator* i_csg = LinkedList_iterator(csg_list);
    while(LinkedListIterator_has_next(i_csg)){
      print_CSG((CSG_RELATION)LinkedListIterator_next(i_csg));
    }
  }
  if(strcmp(flag, "snap")==0 || strcmp(flag, "")==0){
    LinkedListIterator* i_snap = LinkedList_iterator(snap_list);
    while(LinkedListIterator_has_next(i_snap)){
      print_SNAP(LinkedListIterator_next(i_snap));
    }
  }
  if(strcmp(flag, "cpq")==0 || strcmp(flag, "")==0){
    LinkedListIterator* i_cpq = LinkedList_iterator(cpq_list);
    while(LinkedListIterator_has_next(i_cpq)){
      print_CPQ(LinkedListIterator_next(i_cpq));
    }
  }
  if(strcmp(flag, "cdh")==0 || strcmp(flag, "")==0){
    LinkedListIterator* i_cdh = LinkedList_iterator(cdh_list);
    while(LinkedListIterator_has_next(i_cdh)){
      print_CDH(LinkedListIterator_next(i_cdh));
    }
  }
  if(strcmp(flag, "cr")==0 || strcmp(flag, "")==0){
    LinkedListIterator* i_cr = LinkedList_iterator(cr_list);
    while(LinkedListIterator_has_next(i_cr)){
      print_CR(LinkedListIterator_next(i_cr));
    }
  }
  return 0;
}
