#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "relations.h"


CSG_RELATION new_CSG(char* c, char* s, char* g){
  CSG_RELATION new_csg = (CSG_RELATION)malloc(sizeof(struct _CSG));
  new_csg->course_name = c;
  new_csg->student_id = s;
  new_csg->student_grade = g;
  new_csg->key = malloc(sizeof(char)*11);
  char str[10];
  strcpy(str, c);
  strcat(str, s);
  strcpy(new_csg->key, str);
  new_csg->next = NULL;
  new_csg->prev = NULL;
  return new_csg;
}
void print_CSG(CSG_RELATION csg){
  if(csg==NULL)return;
  while(csg!=NULL){
    printf("%s %s %s\n", csg->course_name, csg->student_id, csg->student_grade);
    csg = csg->next;
  }
}

SNAP_RELATION new_SNAP(char* s, char* n, char* a, char* p){
  SNAP_RELATION new_snap = (SNAP_RELATION)malloc(sizeof(struct _SNAP));
  new_snap->student_id = s;
  new_snap->student_name = n;
  new_snap->student_address = a;
  new_snap->student_phone = p;
  new_snap->key = malloc(sizeof(char)*16);
  char str[15];
  strcpy(str, s);
  strcat(str, p);
  strcpy(new_snap->key, str);
  new_snap->next = NULL;
  new_snap->prev = NULL;
  return new_snap;
}
void print_SNAP(SNAP_RELATION snap){
  if(snap==NULL)return;
  do{
    printf("%s %s %s %s\n",
      snap->student_id, snap->student_name,
      snap->student_address, snap->student_phone
    );
    snap = snap->next;
  } while (snap!=NULL);
}

CPQ_RELATION new_CPQ(char* c, char* pq){
  CPQ_RELATION new_cpq = (CPQ_RELATION)malloc(sizeof(struct _CPQ));
  new_cpq->course_name = c;
  new_cpq->prereq_name = pq;
  new_cpq->key = malloc(sizeof(char)*11);
  char str[10];
  strcpy(str, c);
  strcat(str, pq);
  strcpy(new_cpq->key, str);
  new_cpq->next = NULL;
  new_cpq->prev = NULL;
  return new_cpq;
}
void print_CPQ(CPQ_RELATION cpq){
  if(cpq==NULL)return;
  do{
    printf("%s %s\n", cpq->course_name, cpq->prereq_name);
    cpq = cpq->next;
  } while (cpq!=NULL);
}

CDH_RELATION new_CDH(char* c, char* d, char* h){
  CDH_RELATION new_cdh = (CDH_RELATION)malloc(sizeof(struct _CDH));
  new_cdh->course_name = c;
  new_cdh->course_day = d;
  new_cdh->course_hour = h;
  new_cdh->key = malloc(sizeof(char)*8);
  char str[7];
  strcpy(str, c);
  strcat(str, d);
  strcpy(new_cdh->key, str);
  new_cdh->next = NULL;
  new_cdh->prev = NULL;
  return new_cdh;
}
void print_CDH(CDH_RELATION cdh){
  if(cdh==NULL)return;
  do{
    printf("%s %s %s\n", cdh->course_name, cdh->course_day, cdh->course_hour);
    cdh = cdh->next;
  } while (cdh!=NULL);
}

CR_RELATION new_CR(char* c, char* r){
  CR_RELATION new_cr = (CR_RELATION)malloc(sizeof(struct _CR));
  new_cr->course_name = c;
  new_cr->course_room =r;
  new_cr->key = malloc(sizeof(char)*6);
  strcpy(new_cr->key, c);
  new_cr->next = NULL;
  new_cr->prev = NULL;
  return new_cr;
}
void print_CR(CR_RELATION cr){
  if(cr==NULL)return;
  do{
    printf("%s %s\n", cr->course_name, cr->course_room);
    cr = cr->next;
  } while(cr!=NULL);
}

ID_RELATION new_ID(char* s){
  ID_RELATION new_id = (ID_RELATION)malloc(sizeof(struct _ID));
  new_id->student_id = s;
  new_id->key = s;
  new_id->next = NULL;
  new_id->prev = NULL;
  return new_id;
}

void print_ID(ID_RELATION id){
  if(id==NULL)return;
  do{
    printf("%s\n", id->student_id);
    id = id->next;
  } while(id!=NULL);
}

CRDH_RELATION new_CRDH(char* c, char* r, char* d, char* h){
  CRDH_RELATION crdh = (CRDH_RELATION)malloc(sizeof(struct _CRDH));
  crdh->course_name = c;
  crdh->course_room = r;
  crdh->course_day = d;
  crdh->course_hour = h;
  crdh->key = malloc(sizeof(char*));
  char str[7];
  strcpy(str, c);
  strcat(str, d);
  strcpy(crdh->key, str);
  crdh->next = NULL;
  crdh->prev = NULL;
  return crdh;
}

void print_CRDH(CRDH_RELATION crdh){
  if(crdh==NULL)return;
  do{
    printf("%s %s %s %s\n",
      crdh->course_name, crdh->course_room,
      crdh->course_day, crdh->course_hour
    );
    crdh = crdh->next;
  } while (crdh!=NULL);
}

DH_RELATION new_DH(char* d, char* h){
  DH_RELATION dh = (DH_RELATION)malloc(sizeof(struct _DH));
  dh->course_day = d;
  dh->course_hour = h;
  dh->key = malloc(sizeof(char*));
  char str[7];
  strcpy(str, d);
  strcat(str, h);
  strcpy(dh->key, str);
  dh->next = NULL;
  dh->prev = NULL;
  return dh;
}

void print_DH(DH_RELATION dh){
  if(dh==NULL)return;
  do{
    printf("%s %s\n",
      dh->course_day, dh->course_hour);
    dh = dh->next;
  } while (dh!=NULL);
}

void print_relation(char schema, void* relation){
  if(relation==NULL){
    return;
  }
  switch(schema){
    case schema_CSG:
    case schema_CSGx:
      print_CSG(relation);
      break;
    case schema_SNAP:
    case schema_SNAPx:
      print_SNAP(relation);
      break;
    case schema_CPQ:
    case schema_CPQx:
      print_CPQ(relation);
      break;
    case schema_CDH:
    case schema_CDHx:
      print_CDH(relation);
      break;
    case schema_CR:
    case schema_CRx:
      print_CR(relation);
      break;
    case schema_ID:
    case schema_IDx:
      print_ID(relation);
      break;
    case schema_CRDH:
    case schema_CRDHx:
      print_CRDH(relation);
      break;
    case schema_DH:
    case schema_DHx:
      print_DH(relation);
      break;
    default:
      break;
  }
}

bool relation_equals(char schema, void* r1, void* r2){
  switch(schema){
    case schema_CSG:
    case schema_CSGx:
      return CSG_equals((CSG_RELATION)r1, (CSG_RELATION)r2);
    case schema_SNAP:
    case schema_SNAPx:
      return SNAP_equals((SNAP_RELATION)r1, (SNAP_RELATION)r2);
    case schema_CPQ:
    case schema_CPQx:
      return CPQ_equals((CPQ_RELATION)r1, (CPQ_RELATION)r2);
    case schema_CDH:
    case schema_CDHx:
      return CDH_equals((CDH_RELATION)r1, (CDH_RELATION)r2);
    case schema_CR:
    case schema_CRx:
      return CR_equals((CR_RELATION)r1, (CR_RELATION)r2);
    case schema_ID:
    case schema_IDx:
      return ID_equals((ID_RELATION)r1, (ID_RELATION)r2);
    case schema_CRDH:
    case schema_CRDHx:
      return CRDH_equals((CRDH_RELATION)r1, (CRDH_RELATION)r2);
    case schema_DH:
    case schema_DHx:
      return DH_equals((DH_RELATION)r1, (DH_RELATION)r2);
    default:
      return false;
  }
}

bool CSG_equals(CSG_RELATION r1, CSG_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->student_id, r2->student_id)==0
  && strcmp(r1->student_grade, r2->student_grade)==0) return true;
  else return false;
}

bool SNAP_equals(SNAP_RELATION r1, SNAP_RELATION r2){
  if(strcmp(r1->student_id, r2->student_id)==0
  && strcmp(r1->student_name, r2->student_name)==0
  && strcmp(r1->student_address, r2->student_address)==0
  && strcmp(r1->student_phone, r2->student_phone)==0) return true;
  else return false;
}

bool CPQ_equals(CPQ_RELATION r1, CPQ_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->prereq_name, r2->prereq_name)==0) return true;
  else return false;
}

bool CDH_equals(CDH_RELATION r1, CDH_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->course_day, r2->course_day)==0
  && strcmp(r1->course_hour, r2->course_hour)==0) return true;
  else return false;
}

bool CR_equals(CR_RELATION r1, CR_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->course_room, r2->course_room)==0) return true;
  else return false;
}

bool ID_equals(ID_RELATION r1, ID_RELATION r2){
  if(strcmp(r1->student_id, r2->student_id)==0) return true;
  else return false;
}

bool CRDH_equals(CRDH_RELATION r1, CRDH_RELATION r2){
  if(strcmp(r1->course_name, r2->course_name)==0
  && strcmp(r1->course_room, r2->course_room)==0
  && strcmp(r1->course_day, r2->course_day)==0
  && strcmp(r1->course_hour, r2->course_hour)==0) return true;
  else return false;
}

bool DH_equals(DH_RELATION r1, DH_RELATION r2){
  if(strcmp(r1->course_day, r2->course_day)==0
  && strcmp(r1->course_hour, r2->course_hour)==0) return true;
  else return false;
}
