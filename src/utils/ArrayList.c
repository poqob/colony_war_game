#include <stdio.h>
#include <stdlib.h>
#include "../../include/utils/ArrayList.h"

struct ArrayList
{
    int *array;
    int size;
    int capacity;
};

ArrayList *createArrayList(int initialCapacity)
{
    ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
    list->array = (int *)malloc(initialCapacity * sizeof(int));
    list->size = 0;
    list->capacity = initialCapacity;
    return list;
}

void destroyArrayList(ArrayList *list)
{
    free(list->array);
    free(list);
    printf("list destroyed");
}

void append(ArrayList *list, int data)
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

int get(ArrayList *list, int index)
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

int size(ArrayList *list)
{
    return list->size;
}

void display(ArrayList *list)
{
    printf("List: ");
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}
