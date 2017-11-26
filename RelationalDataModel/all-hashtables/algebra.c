#include <stdlib.h>
#include "algebra.h"
#include "relations.h"

HASHTABLE unon(HASHTABLE h1, HASHTABLE h2){
  HASHTABLE u = new_HASHTABLE(h1->schema);
  if(h1->schema != h2->schema) return u;
  for(int i=0; i<h1->size; i++){
    
  }
  return u;
}

HASHTABLE inxt();
HASHTABLE diff();
HASHTABLE proj();
HASHTABLE slct();
HASHTABLE join();
