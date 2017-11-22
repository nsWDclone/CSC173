#ifndef DATABASEIO_H
#define DATABASEIO_H

extern LinkedList* read_CSG();
extern LinkedList* read_SNAP();
extern LinkedList* read_CPQ();
extern LinkedList* read_CDH();
extern LinkedList* read_CR();

extern void write_CSG();
extern void write_SNAP();
extern void write_CPQ();
extern void write_CDH();
extern void write_CR();

#endif
