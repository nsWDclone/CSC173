#include "rdm.h";
#include <stdlib.h>
#include <string.h>

CSG_RELATION csg_table[6] = {
  new_CSG("CS101", 12345, "A"),
  new_CSG("CS101", 67890, "B"),
  new_CSG("EE200", 12345, "C"),
  new_CSG("CS101", 22222, "B+"),
  new_CSG("CS101", 33333, "A-"),
  new_CSG("PH100", 12345, "C+")
};

CSG_RELATION new_CSG(char* c, int s, char* g){
  CSG_RELATION new_csg = (CSG_RELATION)malloc(sizeof(struct _CSG));
  new_csg->course_name = c;
  new_csg->student_id = s;
  new_csg->student_grade = g;
  return new_csg;
}

int main(int argc, char const *argv[]) {



  return 0;
}
