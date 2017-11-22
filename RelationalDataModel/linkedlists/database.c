#include <stdio.h>

#include "rdm.h"
#include "database-io.h"
#include "hashtable.h"

LinkedList* csg_list = NULL;
LinkedList* snap_list = NULL;
LinkedList* cpq_list= NULL;
LinkedList* cdh_list = NULL;
LinkedList* cr_list = NULL;

void populate_tables(){
  insert_CSG(csg_list, "CS101", "12345", "A");
  insert_CSG(csg_list, "CS101", "67890", "B");
  insert_CSG(csg_list, "EE200", "12345", "C");
  insert_CSG(csg_list, "CS101", "22222", "B+");
  insert_CSG(csg_list, "CS101", "33333", "A-");
  insert_CSG(csg_list, "PH100", "12345", "C+");

  insert_SNAP(snap_list, "12345", "C. Brown", "12 Apple St.", "5551234");
  insert_SNAP(snap_list, "67890", "L. Van Pelt", "34 Pear Ave.", "5555678");
  insert_SNAP(snap_list, "22222", "P. Patty", "56 Grape Blvd.", "5559999");

  insert_CPQ(cpq_list, "CS101", "CS100");
  insert_CPQ(cpq_list, "EE200", "EE005");
  insert_CPQ(cpq_list, "EE200", "CS100");
  insert_CPQ(cpq_list, "CS120", "CS101");
  insert_CPQ(cpq_list, "CS121", "CS120");
  insert_CPQ(cpq_list, "CS205", "CS101");
  insert_CPQ(cpq_list, "CS206", "CS121");
  insert_CPQ(cpq_list, "CS206", "CS205");

  insert_CDH(cdh_list, "CS101", "M", "9AM");
  insert_CDH(cdh_list, "CS101", "W", "9AM");
  insert_CDH(cdh_list, "CS101", "F", "9AM");
  insert_CDH(cdh_list, "EE200", "Tu", "10AM");
  insert_CDH(cdh_list, "EE200", "W", "1PM");
  insert_CDH(cdh_list, "EE200", "Th", "10AM");

  insert_CR(cr_list, "CS101", "Turing Aud.");
  insert_CR(cr_list, "EE200", "25 Ohm Hall");
  insert_CR(cr_list, "PH100", "Newton Lab.");
}

int main(int argc, char const *argv[]) {
  csg_list = LinkedList_new();
  snap_list = LinkedList_new();
  cpq_list = LinkedList_new();
  cdh_list = LinkedList_new();
  cr_list = LinkedList_new();
  populate_tables();

  //delete_CDH(cdh_list, "CS101", "*", "*");

  // LinkedList* res = lookup_CDH(cdh_list, "CS101", "*", "*");
  // LinkedListIterator* i_cpq = LinkedList_iterator(res);
  // while(LinkedListIterator_has_next(i_cpq)){
  //   print_CDH(LinkedListIterator_next(i_cpq));
  // }

  const char* flag = "";
  if(argv[1] != NULL){
    flag = argv[1];
  }

  if(strcmp(flag, "-s")!=0){
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
  }
  return 0;
}
