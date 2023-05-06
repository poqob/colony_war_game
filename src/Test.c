#include <stdio.h>
#include "../include/utils/ArrayList.h"
#include "../include/utils/DataType.h"

int main()
{

    ArrayList *list = createArrayList(10, INT);
    ArrayList *clist = createArrayList(10, CHAR);

    // Append integer elements
    int a = 1, b = 2, c = 3;

    // append char elements
    char c_a = 'a', c_b = 'b', c_c = 'c';
    list->append(list, &a);
    list->append(list, &b);
    list->append(list, &c);

    clist->append(clist, &c_a);
    clist->append(clist, &c_b);
    clist->append(clist, &c_c);

    // Get an element
    int *element = (int *)list->get(list, 2);
    printf("Element at index 2: %d\n", *element);

    // Display the list
    list->display(list);

    clist->display(clist);
    clist->destroyArrayList(clist);

    // Clean up
    list->destroyArrayList(list);
    return 0;
}