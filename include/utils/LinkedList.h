#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;

} LinkedList;

void initLinkedList(LinkedList *list);
void append(LinkedList *list, int data);
void prepend(LinkedList *list, int data);
void insertAfter(Node *node, int data);
void deleteNode(LinkedList *list, int data);
void displayList(LinkedList *list);

#endif
