#include <stdio.h>
#include <stdlib.h>
#include "../../include/utils/LinkedList.h"

void initLinkedList(LinkedList *list)
{
    list->head = NULL;
}

void append(LinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

void prepend(LinkedList *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAfter(Node *node, int data)
{
    if (node == NULL)
    {
        printf("Error: Invalid node!\n");
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = node->next;
    node->next = newNode;
}

void deleteNode(LinkedList *list, int data)
{
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (previous == NULL)
            {
                list->head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Error: Data not found in the list!\n");
}

void displayList(LinkedList *list)
{
    Node *current = list->head;

    if (current == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        printf("List: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

LinkedList *getLinkedList()
{
    LinkedList *newList = (LinkedList *)malloc(sizeof(LinkedList));
    newList->head = NULL;
    return newList;
}

int getNodeData(Node *node)
{
    if (node == NULL)
    {
        printf("Error: Invalid node!\n");
        return -1; // Return an error value or handle the error as desired
    }

    return node->data;
}
