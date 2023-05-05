#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

struct ARRAYLIST
{
    int *array;
    int size;
    int capacity;

    // struct ARRAYLIST (*createArrayList)(int initialCapacity);
    void (*destroyArrayList)(struct ARRAYLIST *);
    void (*append)(struct ARRAYLIST *, int data);
    int (*get)(struct ARRAYLIST *, int index);
    int (*getSize)(struct ARRAYLIST *);
    void (*display)(struct ARRAYLIST *);
};

typedef struct ARRAYLIST *ArrayList;

ArrayList createArrayList(int initialCapacity);
void destroyArrayList(ArrayList);
void append(ArrayList, int data);
int get(const ArrayList, int index);
int getSize(ArrayList);
void display(const ArrayList);

#endif
