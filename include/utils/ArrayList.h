#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList ArrayList;

struct ArrayList
{
    int *array;
    int size;
    int capacity;

    void (*destroyArrayList)(ArrayList *);
    void (*append)(ArrayList *, int);
    int (*get)(const ArrayList *, int);
    int (*getSize)(const ArrayList *);
    void (*display)(const ArrayList *);
};

ArrayList *createArrayList(int initialCapacity);
void destroyArrayListt(ArrayList *list);
void append(ArrayList *list, int data);
int get(const ArrayList *list, int index);
int getSize(const ArrayList *list);
void display(const ArrayList *list);

#endif
