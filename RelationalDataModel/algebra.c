#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "algebra.h"
#include "rdm.h"
#include "relations.h"

HASHTABLE unon(HASHTABLE h1, HASHTABLE h2){
  if(h1->schema != h2->schema) return NULL;
  HASHTABLE u = new_HASHTABLE(h1->schema);
  char* key;
  for(int i=0; i<h1->size; i++){
    switch(u->schema){
      case schema_CSG:;
        CSG_RELATION csg = (CSG_RELATION) h1->buckets[i]->contents;
        while(csg!=NULL){
          key = csg->key;
          put_INDEX(u, key, new_INDEX(csg));
          csg = csg->next;
        }
        break;
      case schema_SNAP:;
        SNAP_RELATION snap = (SNAP_RELATION) h1->buckets[i]->contents;
        while(snap!=NULL){
          key = snap->key;
          put_INDEX(u, key, new_INDEX(snap));
          snap = snap->next;
        }
        break;
      case schema_CPQ:;
        CPQ_RELATION cpq = (CPQ_RELATION) h1->buckets[i]->contents;
        while(cpq!=NULL){
          key = cpq->key;
          put_INDEX(u, key, new_INDEX(cpq));
          cpq = cpq->next;
        }
        break;
      case schema_CDH:;
        CDH_RELATION cdh = (CDH_RELATION) h1->buckets[i]->contents;
        while(cdh!=NULL){
          key = cdh->key;
          put_INDEX(u, key, new_INDEX(cdh));
          cdh = cdh->next;
        }
        break;
      case schema_CR:;
        CR_RELATION cr = (CR_RELATION) h1->buckets[i]->contents;
        while(snap!=NULL){
          key = cr->key;
          put_INDEX(u, key, new_INDEX(cr));
          cr = cr->next;
        }
        break;
      default:
        break;
    }
  }
  bool found = false;
  for(int i=0; i<h2->size; i++){
    found = false;
    switch(u->schema){
      case schema_CSG:;
        CSG_RELATION csg = (CSG_RELATION) h2->buckets[i]->contents;
        while(csg!=NULL){
          key = csg->key;
          if(u->buckets[i]->contents == NULL){
            put_INDEX(u, key, new_INDEX(csg));
          } else {
            INDEX x = u->buckets[i]->contents;
            CSG_RELATION csg2 = x->index;
            while(csg2!=NULL){
              if(CSG_equals(csg,csg2)){
                found = true;
                break;
              }
              csg2 = csg2->next;
            }
          }
          if(!found) put_INDEX(u, key, new_INDEX(csg));
          csg = csg->next;
        }
        break;
      case schema_SNAP:;
        SNAP_RELATION snap = (SNAP_RELATION) h2->buckets[i]->contents;
        while(snap!=NULL){
          key = snap->key;
          if(u->buckets[i]->contents == NULL){
            put_INDEX(u, key, new_INDEX(snap));
          } else {
            INDEX x = u->buckets[i]->contents;
            SNAP_RELATION snap2 = x->index;
            while(snap2!=NULL){
              if(SNAP_equals(snap,snap2)){
                found = true;
                break;
              }
              snap2 = snap2->next;
            }
          }
          if(!found) put_INDEX(u, key, new_INDEX(snap));
          snap = snap->next;
        }
        break;
      case schema_CPQ:;
        CPQ_RELATION cpq = (CPQ_RELATION) h2->buckets[i]->contents;
        while(cpq!=NULL){
          key = cpq->key;
          if(u->buckets[i]->contents == NULL){
            put_INDEX(u, key, new_INDEX(cpq));
          } else {
            INDEX x = u->buckets[i]->contents;
            CPQ_RELATION cpq2 = x->index;
            while(cpq2!=NULL){
              if(CPQ_equals(cpq,cpq2)){
                found = true;
                break;
              }
              cpq2 = cpq2->next;
            }
          }
          if(!found) put_INDEX(u, key, new_INDEX(cpq));
          cpq = cpq->next;
        }
        break;
      case schema_CDH:;
        CDH_RELATION cdh = (CDH_RELATION) h2->buckets[i]->contents;
        while(cdh!=NULL){
          key = cdh->key;
          if(u->buckets[i]->contents == NULL){
            put_INDEX(u, key, new_INDEX(cdh));
          } else {
            INDEX x = u->buckets[i]->contents;
            CDH_RELATION cdh2 = x->index;
            while(cdh2!=NULL){
              if(CDH_equals(cdh,cdh2)){
                found = true;
                break;
              }
              cdh2 = cdh2->next;
            }
          }
          if(!found) put_INDEX(u, key, new_INDEX(cdh));
          cdh = cdh->next;
        }
        break;
      case schema_CR:;
        CR_RELATION cr = (CR_RELATION) h2->buckets[i]->contents;
        while(snap!=NULL){
          key = cr->key;
          if(u->buckets[i]->contents == NULL){
            put_INDEX(u, key, new_INDEX(csg));
          } else {
            INDEX x = u->buckets[i]->contents;
            CR_RELATION cr2 = x->index;
            while(cr2!=NULL){
              if(CR_equals(cr,cr2)){
                found = true;
                break;
              }
              cr2 = cr2->next;
            }
          }
          if(!found) put_INDEX(u, key, new_INDEX(cr));
          cr = cr->next;
        }
        break;
      default:
        break;
    }
  }
  return u;
}

HASHTABLE inxt(HASHTABLE h1, HASHTABLE h2){
  if(h1->schema != h2->schema) return NULL;
  HASHTABLE x = new_HASHTABLE(h1->schema);
  for(int i=0; i<h1->size; i++){
    switch(h1->schema){
      case schema_CSG:;
        CSG_RELATION csg = (CSG_RELATION)h1->buckets[i]->contents;
        while(csg!=NULL){
          CSG_RELATION csg2= (CSG_RELATION)h2->buckets[hash(csg->key)]->contents;
          while(csg2!=NULL){
            if(CSG_equals(csg, csg2)) put_INDEX(x, csg->key, new_INDEX(csg));
            csg2 = csg2->next;
          }
          csg = csg->next;
        }
      break;
      case schema_SNAP:;
        SNAP_RELATION snap = (SNAP_RELATION)h1->buckets[i]->contents;
        while(snap!=NULL){
          SNAP_RELATION snap2= (SNAP_RELATION)h2->buckets[hash(snap->key)]->contents;
          while(snap2!=NULL){
            if(SNAP_equals(snap, snap2)) put_INDEX(x, snap->key, new_INDEX(snap));
            snap2 = snap2->next;
          }
          snap = snap->next;
        }
      break;
      case schema_CPQ:;
        CPQ_RELATION cpq = (CPQ_RELATION)h1->buckets[i]->contents;
        while(cpq!=NULL){
          CPQ_RELATION cpq2= (CPQ_RELATION)h2->buckets[hash(cpq->key)]->contents;
          while(cpq2!=NULL){
            if(CPQ_equals(cpq, cpq2)) put_INDEX(x, cpq->key, new_INDEX(cpq));
            cpq2 = cpq2->next;
          }
          cpq = cpq->next;
        }
      break;
      case schema_CDH:;
        CDH_RELATION cdh = (CDH_RELATION)h1->buckets[i]->contents;
        while(cdh!=NULL){
          CDH_RELATION cdh2= (CDH_RELATION)h2->buckets[hash(cdh->key)]->contents;
          while(cdh2!=NULL){
            if(CDH_equals(cdh, cdh2)) put_INDEX(x, cdh->key, new_INDEX(cdh));
            cdh2 = cdh2->next;
          }
          cdh = cdh->next;
        }
      break;
      case schema_CR:;
        CR_RELATION cr = (CR_RELATION)h1->buckets[i]->contents;
        while(cr!=NULL){
          CR_RELATION cr2= (CR_RELATION)h2->buckets[hash(cr->key)]->contents;
          while(cr2!=NULL){
            if(CR_equals(cr, cr2)) put_INDEX(x, cr->key, new_INDEX(cr));
            cr2 = cr2->next;
          }
          cr = cr->next;
        }
      break;
    }
  }
  return x;
}

HASHTABLE diff(HASHTABLE h2, HASHTABLE h1){
  if(h1->schema != h2->schema) return NULL;
  HASHTABLE x = new_HASHTABLE(h1->schema);
  bool found = false;
  for(int i=0; i<h1->size; i++){
    found = false;
    switch(h1->schema){
      case schema_CSG:;
        CSG_RELATION csg = (CSG_RELATION)h1->buckets[i]->contents;
        while(csg!=NULL){
          CSG_RELATION csg2= (CSG_RELATION)h2->buckets[hash(csg->key)]->contents;
          while(csg2!=NULL){
            if(CSG_equals(csg, csg2))found=true;
            csg2 = csg2->next;
          }
          if(!found) put_INDEX(x, csg->key, new_INDEX(csg));
          csg = csg->next;
        }
      break;
      case schema_SNAP:;
        SNAP_RELATION snap = (SNAP_RELATION)h1->buckets[i]->contents;
        while(snap!=NULL){
          SNAP_RELATION snap2= (SNAP_RELATION)h2->buckets[hash(snap->key)]->contents;
          while(snap2!=NULL){
            if(SNAP_equals(snap, snap2))found = true;
            snap2 = snap2->next;
          }
          if(!found) put_INDEX(x, snap->key, new_INDEX(snap));
          snap = snap->next;
        }
      break;
      case schema_CPQ:;
        CPQ_RELATION cpq = (CPQ_RELATION)h1->buckets[i]->contents;
        while(cpq!=NULL){
          CPQ_RELATION cpq2= (CPQ_RELATION)h2->buckets[hash(cpq->key)]->contents;
          while(cpq2!=NULL){
            if(CPQ_equals(cpq, cpq2))found = true;
            cpq2 = cpq2->next;
          }
          if(!found) put_INDEX(x, cpq->key, new_INDEX(cpq));
          cpq = cpq->next;
        }
      break;
      case schema_CDH:;
        CDH_RELATION cdh = (CDH_RELATION)h1->buckets[i]->contents;
        while(cdh!=NULL){
          CDH_RELATION cdh2= (CDH_RELATION)h2->buckets[hash(cdh->key)]->contents;
          while(cdh2!=NULL){
            if(CDH_equals(cdh, cdh2))found = true;
            cdh2 = cdh2->next;
          }
          if(!found) put_INDEX(x, cdh->key, new_INDEX(cdh));
          cdh = cdh->next;
        }
      break;
      case schema_CR:;
        CR_RELATION cr = (CR_RELATION)h1->buckets[i]->contents;
        while(cr!=NULL){
          CR_RELATION cr2= (CR_RELATION)h2->buckets[hash(cr->key)]->contents;
          while(cr2!=NULL){
            if(CR_equals(cr, cr2))found = true;
            cr2 = cr2->next;
          }
          if(!found) put_INDEX(x, cr->key, new_INDEX(cr));
          cr = cr->next;
        }
      break;
    }
  }
  return x;
}

HASHTABLE slct_c_csg(HASHTABLE h, char* c){
  HASHTABLE selection = new_HASHTABLE(schema_CSGx);
  for(int i=0; i<h->size; i++){
    CSG_RELATION r = NULL;
    if(h->schema <= 0){
      INDEX x = (INDEX)h->buckets[i]->contents;
      if(x!=NULL){
        r = x->index;
      }
    } else {
      r = (CSG_RELATION)h->buckets[i]->contents;
    }
    while(r!=NULL){
      if(strcmp(r->course_name, c)==0){
        put_INDEX(selection, r->key, new_INDEX(r));
      }
      r = r->next;
    }
  }
  return selection;
}

HASHTABLE slct_s_csg(HASHTABLE h, char* s){
  HASHTABLE selection = new_HASHTABLE(schema_CSGx);
  for(int i=0; i<h->size; i++){
    CSG_RELATION r = NULL;
    if(h->schema <= 0){
      INDEX x = (INDEX)h->buckets[i]->contents;
      if(x!=NULL){
        r = x->index;
      }
    } else {
      r = (CSG_RELATION)h->buckets[i]->contents;
    }
    while(r!=NULL){
      if(strcmp(r->student_id, s)==0){
        put_INDEX(selection, r->key, new_INDEX(r));
      }
      r = r->next;
    }
  }
  return selection;
}

HASHTABLE slct_r_crdh(HASHTABLE h, char* room){
  HASHTABLE selection = new_HASHTABLE(schema_CRDHx);
  for(int i=0; i<h->size; i++){
    CRDH_RELATION r = NULL;
    if(h->schema <= 0){
      INDEX x = (INDEX)h->buckets[i]->contents;
      if(x!=NULL){
        r = x->index;
      }
    } else {
      r = (CRDH_RELATION)h->buckets[i]->contents;
    }
    while(r!=NULL){
      if(strcmp(r->course_room, room)==0){
        put_INDEX(selection, r->key, new_INDEX(r));
      }
      r = r->next;
    }
  }
  return selection;
}

HASHTABLE proj_s_csg(HASHTABLE h){
  HASHTABLE projection = new_HASHTABLE(schema_IDx);
  for(int i=0; i<h->size; i++){
    CSG_RELATION r=NULL;
    if(h->schema <= 0){
      INDEX x = (INDEX)h->buckets[i]->contents;
      if(x!=NULL){
        r = x->index;
      }
    } else r = h->buckets[i]->contents;
    while(r!=NULL){
      put_INDEX(projection, r->student_id, new_INDEX(new_ID(r->student_id)));
      r = r->next;
    }
  }
  return projection;
}

HASHTABLE proj_dh_crdh(HASHTABLE h){
  HASHTABLE projection = new_HASHTABLE(schema_DHx);
  for(int i=0; i<h->size; i++){
    CRDH_RELATION r=NULL;
    if(h->schema <= 0){
      INDEX x = (INDEX)h->buckets[i]->contents;
      if(x!=NULL){
        r = x->index;
      }
    } else r = h->buckets[i]->contents;
    while(r!=NULL){
      put_INDEX(projection, r->key, new_INDEX(new_DH(r->course_day, r->course_hour)));
      r = r->next;
    }
  }
  return projection;
}

HASHTABLE join_cr_cdh_course(HASHTABLE cr_table, HASHTABLE cdh_table){
  HASHTABLE join = new_HASHTABLE(schema_CRDHx);
  for(int i=0; i<cdh_table->size; i++){
    CDH_RELATION cdh;
    if(cdh_table->schema <= 0){
      INDEX x = (INDEX)cdh_table->buckets[i]->contents;
      if(x!=NULL) {
        cdh = x->index;
      }
    } else cdh = cdh_table->buckets[i]->contents;
    while(cdh!=NULL){
      CR_RELATION cr = cr_table->buckets[hash(cdh->course_name)]->contents;
      while(cr!=NULL){
        if(strcmp(cdh->course_name, cr->course_name)==0){
          put_INDEX(join, cdh->key, new_INDEX(
            new_CRDH(
              cr->course_name,
              cr->course_room,
              cdh->course_day,
              cdh->course_hour
            )));
        }
        cr = cr->next;
      }
      cdh = cdh->next;
    }
  }
  return join;
}

char* grade(char* n, char* c, DATABASE csg_data, DATABASE snap_data){
  SNAP_RELATION snap = lookup_SNAP(snap_data, "*", n, "*", "*");
  CSG_RELATION csg = lookup_CSG(csg_data, c, snap->student_id, "*");
  return csg->student_grade;
}

char* whereis(char* n, char* h, char* d,
DATABASE snap, DATABASE csg, DATABASE cdh, DATABASE cr){
  SNAP_RELATION snap_r = lookup_SNAP(snap,"*",n,"*","*");
  HASHTABLE courses = slct_s_csg(csg->storage, snap_r->student_id);
  for (int i=0; i<courses->size; i++) {
    CSG_RELATION csg_r = courses->buckets[i]->contents;
    while(csg_r!=NULL){
      CDH_RELATION cdh_r = lookup_CDH(cdh, csg_r->course_name, d, h);
      while(cdh_r!=NULL){
        CR_RELATION cr_r = lookup_CR(cr, cdh_r->course_name, "*");
        if(cr_r!=NULL)return cr_r->course_room;
        cdh_r = cdh_r->next;
      }
      csg_r = csg_r->next;
    }
  }
  return "No results";
}
