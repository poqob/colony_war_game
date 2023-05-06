#include <stdio.h>
#include "../include/utils/ArrayList.h"
#include "../include/utils/DataType.h"

int main()
{

    ArrayList *list = createArrayList(10, INT);

    // Append integer elements
    int a = 1, b = 2, c = 3;
    list->append(list, &a);
    list->append(list, &b);
    list->append(list, &c);

    // Get an element
    int *element = (int *)list->get(list, 2);
    printf("Element at index 2: %d\n", *element);

    // Display the list
    list->display(list);

    // Clean up
    list->destroyArrayList(list);
    return 0;
}