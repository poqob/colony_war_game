#include "../../include/utils/ArrayList.h"

void destroyArrayList(ArrayList *list)
{
    if (list == NULL)
        return;
    else
    {
        free(list->array);
        free(list);
    }
}

void append(ArrayList *list, void *data)
{
    if (list->size >= list->capacity)
    {
        int newCapacity = list->capacity * 2;
        list->array = (void **)realloc(list->array, newCapacity * sizeof(list->dataType));
        list->capacity = newCapacity;
    }

    list->array[list->size] = data;
    list->size++;
}

void *get(const ArrayList *list, int index)
{
    if (index >= 0 && index < list->size)
    {
        return list->array[index];
    }
    else
    {
        printf("Error: Index out of bounds!\n");
        return NULL;
    }
}

int getSize(const ArrayList *list)
{
    return list->size;
}

void display(const ArrayList *list)
{

    printf("List: ");
    for (int i = 0; i < list->size; i++)
    {
        void *data = list->array[i];

        if (data == NULL)
            printf("NULL ");
        else if (list->dataType == INT)
            printf("%d ", *(int *)data);
        else if (list->dataType == CHAR)
            printf("%c ", *(char *)data);
    }
    printf("\n");
}

ArrayList *createArrayList(int initialCapacity, DataType type)
{

    ArrayList *this = malloc(sizeof(ArrayList));
    if (this == NULL)
        return NULL;

    this->dataType = type;

    this->array = malloc(initialCapacity * sizeof(this->dataType));
    if (this->array == NULL)
    {
        free(this);
        return NULL;
    }

    this->size = 0;
    this->capacity = initialCapacity;

    this->append = &append;
    this->destroyArrayList = &destroyArrayList;
    this->display = &display;
    this->get = &get;
    this->getSize = &getSize;

    return this;
}
