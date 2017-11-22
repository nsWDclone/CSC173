#include <stdio.h>

#include "rdm.h"
#include "database-io.h"
#include "hashtable.h"

HASHTABLE csg;
HASHTABLE snap;
HASHTABLE cpq;
HASHTABLE cdh;
HASHTABLE cr;

int main(int argc, char const *argv[]) {
  csg = new_HASHTABLE("csg");
  snap = new_HASHTABLE("snap");
  cpq = new_HASHTABLE("cpq");
  cdh = new_HASHTABLE("cdh");
  cr = new_HASHTABLE("cr");

  insert_CSG(csg, "CS101", "12345", "A");
  insert_CSG(csg, "CS101", "67890", "B");
  insert_CSG(csg, "EE200", "12345", "C");
  insert_CSG(csg, "CS101", "22222", "B+");
  insert_CSG(csg, "CS101", "33333", "A-");
  insert_CSG(csg, "PH100", "12345", "C+");

  insert_SNAP(snap, "12345", "C. Brown", "12 Apple St.", "5551234");
  insert_SNAP(snap, "67890", "L. Van Pelt", "34 Pear Ave.", "5555678");
  insert_SNAP(snap, "22222", "P. Patty", "56 Grape Blvd.", "5559999");

  insert_CPQ(cpq, "CS101", "CS100");
  insert_CPQ(cpq, "EE200", "EE005");
  insert_CPQ(cpq, "EE200", "CS100");
  insert_CPQ(cpq, "CS120", "CS101");
  insert_CPQ(cpq, "CS121", "CS120");
  insert_CPQ(cpq, "CS205", "CS101");
  insert_CPQ(cpq, "CS206", "CS121");
  insert_CPQ(cpq, "CS206", "CS205");

  insert_CDH(cdh, "CS101", "M", "9AM");
  insert_CDH(cdh, "CS101", "W", "9AM");
  insert_CDH(cdh, "CS101", "F", "9AM");
  insert_CDH(cdh, "EE200", "Tu", "10AM");
  insert_CDH(cdh, "EE200", "W", "1PM");
  insert_CDH(cdh, "EE200", "Th", "10AM");

  insert_CR(cr, "CS101", "Turing Aud.");
  insert_CR(cr, "EE200", "25 Ohm Hall");
  insert_CR(cr, "PH100", "Newton Lab.");


  const char* flag = "";
  if(argv[1] != NULL) flag = argv[1];
  if(strcmp(flag, "-s")!=0){
    if(strcmp(flag, "csg")==0 || strcmp(flag, "")==0){
      for(int i=0; i<csg->size; i++){
        if(csg->buckets[i]->contents != NULL){
          print_CSG(csg->buckets[i]->contents);
          BUCKET b = csg->buckets[i];
          while(b->next!=NULL){
            b = b->next;
            print_CSG(b->contents);
          }
        }
      }
      printf("\n");
    }
    if(strcmp(flag, "snap")==0 || strcmp(flag, "")==0){
      for(int i=0; i<snap->size; i++){
        if(snap->buckets[i]->contents != NULL){
          print_SNAP(snap->buckets[i]->contents);
          BUCKET b = snap->buckets[i];
          while(b->next!=NULL){
            b = b->next;
            print_SNAP(b->contents);
          }
        }
      }
      printf("\n");
    }
    if(strcmp(flag, "cpq")==0 || strcmp(flag, "")==0){
      for(int i=0; i<cpq->size; i++){
        if(cpq->buckets[i]->contents != NULL){
          print_CPQ(cpq->buckets[i]->contents);
          BUCKET b = cpq->buckets[i];
          while(b->next!=NULL){
            b = b->next;
            print_CPQ(b->contents);
          }
        }
      }
      printf("\n");
    }
    if(strcmp(flag, "cdh")==0 || strcmp(flag, "")==0){
      for(int i=0; i<cdh->size; i++){
        if(cdh->buckets[i]->contents != NULL){
          print_CDH(cdh->buckets[i]->contents);
          BUCKET b = cdh->buckets[i];
          while(b->next!=NULL){
            b = b->next;
            print_CDH(b->contents);
          }
        }
      }
      printf("\n");
    }
    if(strcmp(flag, "cr")==0 || strcmp(flag, "")==0){
      for(int i=0; i<cr->size; i++){
        if(cr->buckets[i]->contents != NULL){
          print_CR(cr->buckets[i]->contents);
          BUCKET b = cr->buckets[i];
          while(b->next!=NULL){
            b = b->next;
            print_CR(b->contents);
          }
        }
      }
    }
    printf("\n");
  }
  return 0;
}
