#include <stdio.h>
#include <stdlib.h>

#include "rdm.h"
#include "relations.h"
#include "database-io.h"
#include "database.h"

DATABASE new_DATABASE(char s){
  DATABASE d = (DATABASE)malloc(sizeof(struct _DATABASE));
  d->schema = s;
  d->storage = new_HASHTABLE(s);
  d->index = new_HASHTABLE(s);
  return d;
}

void print_DATABASE(DATABASE d){
  for(int i=0; i<d->storage->size; i++){
    if(d->storage->buckets[i]!=NULL){
      if(d->storage->buckets[i]->contents != NULL){
        print_relation(d->schema, d->storage->buckets[i]->contents);
        BUCKET b = d->storage->buckets[i];
        while(b->next!=NULL){
          b = b->next;
          print_relation(d->schema, b->contents);
        }
      }
    }
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  DATABASE csg;
  DATABASE snap;
  DATABASE cpq;
  DATABASE cdh;
  DATABASE cr;

  csg = new_DATABASE(schema_CSG);
  snap = new_DATABASE(schema_SNAP);
  cpq = new_DATABASE(schema_CPQ);
  cdh = new_DATABASE(schema_CDH);
  cr = new_DATABASE(schema_CR);

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

  // delete_CSG(csg, "CS101", "33333", "*");
  // delete_CSG(csg, "CS101", "12345", "*");
  delete_CSG(csg, "PH100", "12345", "C+");

  const char* flag = "";
  if(argv[1] != NULL) flag = argv[1];
  if(strcmp(flag, "")!=0){
    if(strcmp(flag, "-csg") ==0 || strcmp(flag, "-a")==0) print_DATABASE(csg);
    if(strcmp(flag, "-snap")==0 || strcmp(flag, "-a")==0) print_DATABASE(snap);
    if(strcmp(flag, "-cpq") ==0 || strcmp(flag, "-a")==0) print_DATABASE(cpq);
    if(strcmp(flag, "-cdh") ==0 || strcmp(flag, "-a")==0) print_DATABASE(cdh);
    if(strcmp(flag, "-cr")  ==0 || strcmp(flag, "-a")==0) print_DATABASE(cr);
  }
  return 0;
}
