#ifndef DATABASEIO_HLinkedList
#define DATABASEIO_H

#include "database.h"

extern DATABASE read_CSG();
extern DATABASE read_SNAP();
extern DATABASE read_CPQ();
extern DATABASE read_CDH();
extern DATABASE read_CR();

extern void write_CSG(DATABASE database);
extern void write_SNAP(DATABASE database);
extern void write_CPQ(DATABASE database);
extern void write_CDH(DATABASE database);
extern void write_CR(DATABASE database);

#endif
