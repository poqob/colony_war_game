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

        switch (list->dataType)
        {
        case CHAR:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(char *));
            break;
        case INT:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(int *));
            break;
        case PTR:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(void *));
            break;
        case _ARRAYLIST:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(ArrayList *));
            break;
        case _COLONY:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(Colony *));
            break;
        case BOOL:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(boolean *));
            break;
        case _STRING:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(String *));
            break;
        default:
            list->array = (void **)realloc(list->array, newCapacity * sizeof(void *));
            break;
        }

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

    switch (this->dataType)
    {
    case CHAR:
        this->array = (void *)malloc(initialCapacity * sizeof(char *));
        break;
    case INT:
        this->array = (void *)malloc(initialCapacity * sizeof(int *));
        break;
    case PTR:
        this->array = (void *)malloc(initialCapacity * sizeof(void *));
        break;
    case _ARRAYLIST:
        this->array = (void *)malloc(initialCapacity * sizeof(ArrayList *));
        break;
    case _COLONY:
        this->array = (void *)malloc(initialCapacity * sizeof(Colony *));
        break;
    case BOOL:
        this->array = (void *)malloc(initialCapacity * sizeof(boolean *));
        break;
    case _STRING:
        this->array = (void *)malloc(initialCapacity * sizeof(String *));
        break;
    default:
        this->array = (void *)malloc(initialCapacity * sizeof(void *));
        break;
    }

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
