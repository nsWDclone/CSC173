#include <stdio.h>
#include <stdlib.h>

#include "rdm.h"
#include "algebra.h"
#include "relations.h"
#include "database-io.h"
#include "database.h"

DATABASE csg;
DATABASE snap;
DATABASE cpq;
DATABASE cdh;
DATABASE cr;

DATABASE new_DATABASE(char s){
  DATABASE d = (DATABASE)malloc(sizeof(struct _DATABASE));
  d->schema = s;
  d->storage = new_HASHTABLE(s);
  d->index = new_HASHTABLE(0);
  return d;
}

void print_DATABASE(DATABASE d){
  for(int i=0; i<d->storage->size; i++){
    if(d->storage->buckets[i]->contents != NULL){
      print_relation(d->schema, d->storage->buckets[i]->contents);
    }
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  const char* flag = "";
  if(argv[1] != NULL) flag = argv[1];

  if((strcmp(flag, "-io")==0)
  || (strcmp(flag, "-i")==0)){
    printf("Reading data from files...\n");
    csg  = read_CSG();
    snap = read_SNAP();
    cpq  = read_CPQ();
    cdh  = read_CDH();
    cr   = read_CR();
    printf("Done.\n");
  } else {
    csg  = new_DATABASE(schema_CSG);
    snap  = new_DATABASE(schema_SNAP);
    cpq  = new_DATABASE(schema_CPQ);
    cdh  = new_DATABASE(schema_CDH);
    cr  = new_DATABASE(schema_CR);

    insert_CSG(csg, new_CSG("CS101", "12345", "A"));
    insert_CSG(csg, new_CSG("CS101", "67890", "B"));
    insert_CSG(csg, new_CSG("EE200", "12345", "C"));
    insert_CSG(csg, new_CSG("CS101", "33333", "A-"));
    insert_CSG(csg, new_CSG("PH100", "12345", "C+"));

    insert_SNAP(snap, new_SNAP("12345", "C. Brown", "12 Apple St.", "5551234"));
    insert_SNAP(snap, new_SNAP("67890", "L. Van Pelt", "34 Pear Ave.", "5555678"));
    insert_SNAP(snap, new_SNAP("22222", "P. Patty", "56 Grape Blvd.", "5559999"));

    insert_CPQ(cpq, new_CPQ("CS101", "CS100"));
    insert_CPQ(cpq, new_CPQ("EE200", "EE005"));
    insert_CPQ(cpq, new_CPQ("EE200", "CS100"));
    insert_CPQ(cpq, new_CPQ("CS120", "CS101"));
    insert_CPQ(cpq, new_CPQ("CS121", "CS120"));
    insert_CPQ(cpq, new_CPQ("CS205", "CS101"));
    insert_CPQ(cpq, new_CPQ("CS206", "CS121"));
    insert_CPQ(cpq, new_CPQ("CS206", "CS205"));

    insert_CDH(cdh, new_CDH("CS101", "M", "9AM"));
    insert_CDH(cdh, new_CDH("CS101", "W", "9AM"));
    insert_CDH(cdh, new_CDH("CS101", "F", "9AM"));
    insert_CDH(cdh, new_CDH("EE200", "Tu", "10AM"));
    insert_CDH(cdh, new_CDH("EE200", "W", "1PM"));
    insert_CDH(cdh, new_CDH("EE200", "Th", "10AM"));

    insert_CR(cr, new_CR("CS101", "Turing Aud."));
    insert_CR(cr, new_CR("EE200", "25 Ohm Hall"));
    insert_CR(cr, new_CR("PH100", "Newton Lab."));
  }

  printf("\nRELATIONS:\n----------------------------------\n");
  printf("CSG:\n");
  print_DATABASE(csg);
  printf("SNAP:\n");
  print_DATABASE(snap);
  printf("CPQ:\n");
  print_DATABASE(cpq);
  printf("CDH:\n");
  print_DATABASE(cdh);
  printf("CR:\n");
  print_DATABASE(cr);

  const char* flag2 = "";
  if(argv[2] != NULL) flag2 = argv[2];
  if(strcmp(flag2, "-test")==0){
    printf("BASIC OPERATIONS:\n----------------------------------\n");
    //8.2
    printf("8.2 - lookup(CS101, 12345, *, CSG)\n");
    print_CSG(lookup_CSG(csg, "CS101","12345","*"));
    printf("\n8.2 - lookup(CS205, CS120, CPQ)\n");
    print_CPQ(lookup_CPQ(cpq, "CS205","CS120"));
    printf("\n8.2 - delete(EE200, *, CR)\n");
    delete_CR(cr, "EE200", "*");
    printf("\n8.2 - insert(CS205, CS120, CPQ)\n");
    insert_CPQ(cpq, new_CPQ("CS205", "CS120"));
    printf("\n8.2 - insert(CS205, CS101, CPQ)\n");
    insert_CPQ(cpq, new_CPQ("CS205", "CS101"));
    printf("\n");

  printf("COMPLEX QUERY:\n----------------------------------\n");
    printf("C. Brown's grade in CS101: %s\n", grade("C. Brown", "CS101", csg, snap));
    printf("At 9AM on Fridays, C. Brown is in: %s\n\n",
      whereis("C. Brown", "9AM", "F", snap, csg, cdh , cr));


    printf("RELATIONAL ALGEBRA:\n----------------------------------\n");
    //8.12
    printf("8.12 - select(course=CS101, CSG)\n");
    HASHTABLE u = slct_c_csg(csg->storage, "CS101");
    for(int i=0; i<u->size; i++){
      if(u->buckets[i]->contents != NULL){
        INDEX x = (INDEX)u->buckets[i]->contents;
        if(x!=NULL) print_relation(u->schema, x->index);
      }
    }
    printf("\n");

    //8.13
    printf("8.13 - project(id, select(course=CS101, CSG))\n");
    HASHTABLE v = proj_s_csg(slct_c_csg(csg->storage, "CS101"));
    for(int i=0; i<v->size; i++){
      if(v->buckets[i]->contents != NULL){
        INDEX x = (INDEX)v->buckets[i]->contents;
        if(x!=NULL) print_relation(v->schema, x->index);
      }
    }
    printf("\n");

    //8.14
    printf("8.14 - join(CR, CDH, course=course)\n");
    HASHTABLE w = join_cr_cdh_course(cr->storage, cdh->storage);
    for(int i=0; i<w->size; i++){
      if(w->buckets[i]->contents != NULL){
        INDEX x = (INDEX)w->buckets[i]->contents;
        if(x!=NULL) print_relation(w->schema, x->index);
      }
    }
    printf("\n");

    //8.15
    printf("8.15 - project(date-hour, select(room=Turing Aud., join(CR, CDH, course=course)))\n");
    HASHTABLE z = proj_dh_crdh(slct_r_crdh(join_cr_cdh_course(cr->storage, cdh->storage), "Turing Aud."));
    for(int i=0; i<z->size; i++){
      if(z->buckets[i]->contents != NULL){
        INDEX x = (INDEX)z->buckets[i]->contents;
        if(x!=NULL) print_relation(z->schema, x->index);
      }
    }
    printf("\n");
    printf("RELATIONS:\n----------------------------------\n");
    printf("CSG:\n");
    print_DATABASE(csg);
    printf("SNAP:\n");
    print_DATABASE(snap);
    printf("CPQ:\n");
    print_DATABASE(cpq);
    printf("CDH:\n");
    print_DATABASE(cdh);
    printf("CR:\n");
    print_DATABASE(cr);
  }

  if((strcmp(flag, "-io")==0)
  || (strcmp(flag, "-o")==0)){
    printf("Writing data to files...\n");
    write_CSG(csg);
    write_SNAP(snap);
    write_CPQ(cpq);
    write_CDH(cdh);
    write_CR(cr);
    printf("Done.\n");
  }
  return 0;
}
