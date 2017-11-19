#include "rdm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

CSG_RELATION csg_table[6];
SNAP_RELATION snap_table[3];
CPQ_RELATION cpq_table[8];
CDH_RELATION cdh_table[6];
CR_RELATION cr_table[3];

CSG_RELATION new_CSG(char* c, int s, char* g){
  CSG_RELATION new_csg = (CSG_RELATION)malloc(sizeof(struct _CSG));
  new_csg->course_name = c;
  new_csg->student_id = s;
  new_csg->student_grade = g;
  return new_csg;
}

SNAP_RELATION new_SNAP(int s, char* n, char* a, int p){
  SNAP_RELATION new_snap = (SNAP_RELATION)malloc(sizeof(struct _SNAP));
  new_snap->student_id = s;
  new_snap->student_name = n;
  new_snap->student_address = a;
  new_snap->student_phone = p;
  return new_snap;
}

CPQ_RELATION new_CPQ(char* c, char* pq){
  CPQ_RELATION new_cpq = (CPQ_RELATION)malloc(sizeof(struct _CPQ));
  new_cpq->course_name = c;
  new_cpq->prereq_name = pq;
  return new_cpq;
}

CDH_RELATION new_CDH(char* c, char* d, char* h){
  CDH_RELATION new_cdh = (CDH_RELATION)malloc(sizeof(struct _CDH));
  new_cdh->course_name = c;
  new_cdh->course_day = d;
  new_cdh->course_hour = h;
  return new_cdh;
}

CR_RELATION new_CR(char* c, char* r){
  CR_RELATION new_cr = (CR_RELATION)malloc(sizeof(struct _CR));
  new_cr->course_name = c;
  new_cr->course_room =r;
  return new_cr;
}

void create_tables(){
  csg_table[0] = new_CSG("CS101", 12345, "A");
  csg_table[1] = new_CSG("CS101", 67890, "B");
  csg_table[2] = new_CSG("EE200", 12345, "C");
  csg_table[3] = new_CSG("CS101", 22222, "B+");
  csg_table[4] = new_CSG("CS101", 33333, "A-");
  csg_table[5] = new_CSG("PH100", 12345, "C+");

  snap_table[0] = new_SNAP(12345, "C. Brown", "12 Apple St.", 5551234);
  snap_table[1] = new_SNAP(67890, "L. Van Pelt", "34 Pear Ave.", 5555678);
  snap_table[2] = new_SNAP(22222, "P. Patty", "56 Grape Blvd.", 5559999);

  cpq_table[0] = new_CPQ("CS101", "CS100");
  cpq_table[1] = new_CPQ("EE200", "EE005");
  cpq_table[2] = new_CPQ("EE200", "CS100");
  cpq_table[3] = new_CPQ("CS120", "CS101");
  cpq_table[4] = new_CPQ("CS121", "CS120");
  cpq_table[5] = new_CPQ("CS205", "CS101");
  cpq_table[6] = new_CPQ("CS206", "CS121");
  cpq_table[7] = new_CPQ("CS206", "CS205");

  cdh_table[0] = new_CDH("CS101", "M", "9AM");
  cdh_table[1] = new_CDH("CS101", "W", "9AM");
  cdh_table[2] = new_CDH("CS101", "F", "9AM");
  cdh_table[3] = new_CDH("EE200", "Tu", "10AM");
  cdh_table[4] = new_CDH("EE200", "W", "1PM");
  cdh_table[5] = new_CDH("EE200", "Th", "10AM");

  cr_table[0] = new_CR("CS101", "Turing Aud.");
  cr_table[1] = new_CR("EE200", "25 Ohm Hall");
  cr_table[2] = new_CR("PH100", "Newton Lab.");
}

int main(int argc, char const *argv[]) {
  create_tables();
  const char* flag = "";
  if(argv[1] != NULL){
    flag = argv[1];
  }
  if(strcmp(flag, "csg")==0 || strcmp(flag, "")==0){
    for(int i=0; i<6; i++){
      print_CSG(csg_table[i]);
    }
  }
  if(strcmp(flag, "snap")==0 || strcmp(flag, "")==0){
    for(int i=0; i<3; i++){
      print_SNAP(snap_table[i]);
    }
  }
  if(strcmp(flag, "cpq")==0 || strcmp(flag, "")==0){
    for(int i=0; i<8; i++){
      print_CPQ(cpq_table[i]);
    }
  }
  if(strcmp(flag, "cdh")==0 || strcmp(flag, "")==0){
    for(int i=0; i<6; i++){
      print_CDH(cdh_table[i]);
    }
  }
  if(strcmp(flag, "cr")==0 || strcmp(flag, "")==0){
    for(int i=0; i<3; i++){
      print_CR(cr_table[i]);
    }
  }
  return 0;
}
