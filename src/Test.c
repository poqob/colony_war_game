#include <stdio.h>
#include "../include/utils/ArrayList.h"

int main()
{
    ArrayList list = createArrayList(10);

    list->append(list, 10);
    list->append(list, 20);
    list->append(list, 30);
    int listSize = getSize(list);

    int firstElement = get(list, 0);

    list->display(list);
    destroyArrayList(list);

    printf("sss");

    return 0;
}
