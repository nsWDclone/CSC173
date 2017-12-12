#include <stdio.h>
#include <stdlib.h>
#include "database-io.h"
#include "relations.h"
#include "rdm.h"

DATABASE read_CSG(){
  DATABASE d = new_DATABASE(schema_CSG);
  FILE* file_ptr = fopen("./data/csg.data", "r");
  char buff[128];
  int entries = atoi(fgets(buff, 128, file_ptr));
  for(int i=0; i<entries; i++){
    char* c = malloc(sizeof(char)*6);
    char* s = malloc(sizeof(char)*6);
    char* g = malloc(sizeof(char)*3);
    fscanf(file_ptr, "%s", c);
    fscanf(file_ptr, "%s", s);
    fscanf(file_ptr, "%s", g);
    insert_CSG(d,new_CSG(c,s,g));
  }
  fclose(file_ptr);
  printf("  Imported data from csg.data\n");
  return d;
}
DATABASE read_SNAP(){
  DATABASE d = new_DATABASE(schema_SNAP);
  FILE* file_ptr = fopen("./data/snap.data", "r");
  char buff[128];
  int entries = atoi(fgets(buff, 128, file_ptr));
  for(int i=0; i<entries; i++){
    char* s = malloc(sizeof(char)*6);
    char* n = malloc(sizeof(char)*128);
    char* a = malloc(sizeof(char)*128);
    char* p = malloc(sizeof(char)*11);
    fscanf(file_ptr, "%s ", s);
    fscanf(file_ptr, "%128[0-9a-zA-z. ], ", n);
    fscanf(file_ptr, "%128[0-9a-zA-z ]. ", a);
    fscanf(file_ptr, "%s", p);
    insert_SNAP(d,new_SNAP(s,n,a,p));
  }
  fclose(file_ptr);
  printf("  Imported data from snap.data\n");
  return d;
}
DATABASE read_CPQ(){
  DATABASE d = new_DATABASE(schema_CPQ);
  FILE* file_ptr = fopen("./data/cpq.data", "r");
  char buff[128];
  int entries = atoi(fgets(buff, 128, file_ptr));
  for(int i=0; i<entries; i++){
    char* c = malloc(sizeof(char)*6);
    char* pq = malloc(sizeof(char)*6);
    fscanf(file_ptr, "%s", c);
    fscanf(file_ptr, "%s", pq);
    insert_CPQ(d,new_CPQ(c,pq));
  }
  fclose(file_ptr);
  printf("  Imported data from cpq.data\n");
  return d;
}

DATABASE read_CDH(){
  DATABASE d = new_DATABASE(schema_CDH);
  FILE* file_ptr = fopen("./data/cdh.data", "r");
  char buff[128];
  int entries = atoi(fgets(buff, 128, file_ptr));
  for(int i=0; i<entries; i++){
    char* c = malloc(sizeof(char)*6);
    char* day = malloc(sizeof(char)*3);
    char* h = malloc(sizeof(char)*5);
    fscanf(file_ptr, "%s", c);
    fscanf(file_ptr, "%s", day);
    fscanf(file_ptr, "%s", h);
    insert_CDH(d,new_CDH(c,day,h));
  }
  fclose(file_ptr);
  printf("  Imported data from cdh.data\n");
  return d;
}

DATABASE read_CR(){
  DATABASE d = new_DATABASE(schema_CR);
  FILE* file_ptr = fopen("./data/cr.data", "r");
  char buff[128];
  int entries = atoi(fgets(buff, 128, file_ptr));
  for(int i=0; i<entries; i++){
    char* c = malloc(sizeof(char)*6);
    char* r = malloc(sizeof(char)*128);
    fscanf(file_ptr, "%s ", c);
    fscanf(file_ptr, "%128[0-9a-zA-z. ]", r);
    insert_CR(d,new_CR(c,r));
  }
  fclose(file_ptr);
  printf("  Imported data from cr.data\n");
  return d;
}

void write_CSG(DATABASE database){
  FILE* file_ptr = fopen("./data/csg.data", "w");
  int entries = database->storage->entries;
  fprintf(file_ptr, "%d\n", entries);
  for(int i=0; i<database->storage->size; i++){
    CSG_RELATION r = (CSG_RELATION) database->storage->buckets[i]->contents;
    while(r!=NULL){
      fprintf(file_ptr, "%s %s %s\n",
        r->course_name, r->student_id, r->student_grade);
      r = r->next;
    }
  }
  fclose(file_ptr);
  printf("  Wrote data to csg.data\n");
}

void write_SNAP(DATABASE database){
  FILE* file_ptr = fopen("./data/snap.data", "w");
  int entries = database->storage->entries;
  fprintf(file_ptr, "%d\n", entries);
  for(int i=0; i<database->storage->size; i++){
    SNAP_RELATION r = (SNAP_RELATION) database->storage->buckets[i]->contents;
    while(r!=NULL){
      fprintf(file_ptr, "%s %s, %s.  %s\n",
        r->student_id, r->student_name, r->student_address, r->student_phone);
      r = r->next;
    }
  }
  fclose(file_ptr);
  printf("  Wrote data to snap.data\n");
}

void write_CPQ(DATABASE database){
  FILE* file_ptr = fopen("./data/cpq.data", "w");
  int entries = database->storage->entries;
  fprintf(file_ptr, "%d\n", entries);
  for(int i=0; i<database->storage->size; i++){
    CPQ_RELATION r = (CPQ_RELATION) database->storage->buckets[i]->contents;
    while(r!=NULL){
      fprintf(file_ptr, "%s %s\n",
        r->course_name, r->prereq_name);
      r = r->next;
    }
  }
  fclose(file_ptr);
  printf("  Wrote data to cpq.data\n");
}

void write_CDH(DATABASE database){
  FILE* file_ptr = fopen("./data/cdh.data", "w");
  int entries = database->storage->entries;
  fprintf(file_ptr, "%d\n", entries);
  for(int i=0; i<database->storage->size; i++){
    CDH_RELATION r = (CDH_RELATION) database->storage->buckets[i]->contents;
    while(r!=NULL){
      fprintf(file_ptr, "%s %s %s\n",
        r->course_name, r->course_day, r->course_hour);
      r = r->next;
    }
  }
  fclose(file_ptr);
  printf("  Wrote data to cdh.data\n");
}

void write_CR(DATABASE database){
  FILE* file_ptr = fopen("./data/cr.data", "w");
  int entries = database->storage->entries;
  fprintf(file_ptr, "%d\n", entries);
  for(int i=0; i<database->storage->size; i++){
    CR_RELATION r = (CR_RELATION) database->storage->buckets[i]->contents;
    while(r!=NULL){
      fprintf(file_ptr, "%s %s\n",
        r->course_name, r->course_room);
      r = r->next;
    }
  }
  fclose(file_ptr);
  printf("  Wrote data to cr.data\n");
}
