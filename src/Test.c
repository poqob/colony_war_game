#include <stdio.h>
#include "../include/utils/ArrayList.h"

int main()
{
    ArrayList *list = createArrayList(10);

    append(list, 10);
    append(list, 20);
    append(list, 30);

    int firstElement = get(list, 0);
    int listSize = size(list);

    display(list);
    destroyArrayList(list);
    // Rest of your code goes here

    return 0;
}
