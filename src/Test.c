#include <stdio.h>
#include "../include/utils/LinkedList.h"

int main()
{
    LinkedList *list = getLinkedList();
    append(list, 10);
    append(list, 20);
    append(list, 30);

    Node *firstNode = list->head;
    printf("Content of first node: %d\n", getNodeData(firstNode));

    // Print the entire linked list
    displayList(list);
    return 0;
}
