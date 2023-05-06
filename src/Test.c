#include <stdio.h>
#include "../include/utils/ArrayList.h"

int main()
{
    ArrayList *list = createArrayList(10);

    list->append(list, 10);
    list->append(list, 20);
    list->append(list, 30);

    int firstElement = list->get(list, 0);
    int listSize = list->getSize(list);

    list->display(list);
    list->destroyArrayList(list);

    return 0;
}
