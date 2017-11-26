#ifndef DATABASEIO_HLinkedList
#define DATABASEIO_H

extern DATABASE read_CSG();
extern DATABASE read_SNAP();
extern DATABASE read_CPQ();
extern DATABASE read_CDH();
extern DATABASE read_CR();

extern void write_CSG();
extern void write_SNAP();
extern void write_CPQ();
extern void write_CDH();
extern void write_CR();

#endif
