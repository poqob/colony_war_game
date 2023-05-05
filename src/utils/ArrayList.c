#include <stdio.h>
#include <stdlib.h>
#include "../../include/utils/ArrayList.h"

ArrayList createArrayList(int initialCapacity)
{
    ArrayList this;

    this = (ArrayList)malloc(sizeof(ArrayList));
    this->array = (int *)malloc(initialCapacity * sizeof(int));
    this->size = 0;
    this->capacity = initialCapacity;
    this->destroyArrayList = &destroyArrayList;
    this->append = &append;

    this->display = &display;
    this->get = &get;
    this->getSize = &getSize;
    return this;
}

void destroyArrayList(ArrayList list)
{
    free(list->array);
    free(list);
    printf("ArrayList destroyed.\n");
}

void append(ArrayList list, int data)
{
    if (list->size >= list->capacity)
    {
        // Resize the array if it's full
        int newCapacity = list->capacity * 2;
        list->array = (int *)realloc(list->array, newCapacity * sizeof(int));
        list->capacity = newCapacity;
    }

    list->array[list->size] = data;
    list->size++;
}

int get(const ArrayList list, int index)
{
    if (index >= 0 && index < list->size)
    {
        return list->array[index];
    }
    else
    {
        printf("Error: Index out of bounds!\n");
        return -1; // Return an error value or handle the error as desired
    }
}

int getSize(ArrayList list)
{
    return list->size;
}

void display(const ArrayList list)
{
    printf("List: ");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}
