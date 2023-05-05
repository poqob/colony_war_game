#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

typedef struct ArrayList ArrayList;

ArrayList *createArrayList(int initialCapacity);
void destroyArrayList(ArrayList *list);
void append(ArrayList *list, int data);
int get(ArrayList *list, int index);
int size(ArrayList *list);
void display(ArrayList *list);

#endif
