#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include <stdio.h>
#include "DataType.h"

/*
    ArrayList is a data structure for managing lists that can store all data types within the enum list in DataType.h.
    It was coded in the planning phase of the project and shaped according to the needs of the project.
*/

typedef struct ArrayList ArrayList;

struct ArrayList
{
    void **array; // void pointer array to make it generic
    int size;
    int capacity;
    DataType dataType;
    void (*destroyArrayList)(ArrayList *);
    void (*append)(ArrayList *, void *);
    void *(*get)(const ArrayList *, int);
    int (*getSize)(const ArrayList *);
    void (*display)(const ArrayList *);
};

ArrayList *createArrayList(int initialCapacity, DataType type);
void destroyArrayList(ArrayList *list);
void append(ArrayList *list, void *data);
void *get(const ArrayList *list, int index);
int getSize(const ArrayList *list);
void display(const ArrayList *list);

#endif
