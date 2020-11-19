#include<stdlib.h>
#include<stdio.h>

//insert at the begining
//insert at index
//insert at the end
//insert after a node

struct Node
{
    int data;
    struct Node *next;
};

void displayLinkedList(struct Node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        ++i;
        printf("element %d is %d\n", i, ptr->data);
        ptr = ptr->next;
    }
}

struct Node * insertBeginning(struct Node *ptr, struct Node *newNode)
{
    newNode->next = ptr;
    return newNode;
}

void insertAtIndex(struct Node *ptr, struct Node *newNode, int index)
{
    int i = 0;
    while (i < index-1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void insertAtEnd(struct Node *ptr, struct Node *newNode)
{

    while (ptr != NULL)
    {
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            ptr->next = newNode;
            newNode->next = NULL;
            break;
        }
    }
}

void insertAfterNode(struct Node *ptr, struct Node *existingNode, struct Node *newNode)
{
    newNode->next = existingNode->next;
    existingNode->next = newNode;
}

int main()
{
    struct Node *head, *second, *third, *fourth, *element;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    element = (struct Node *)malloc(sizeof(struct Node));
    element->data = 3;

    head->data = 7;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 22;
    third->next = fourth;

    fourth->data = 55;
    fourth->next = NULL;

    printf("List before insertion - \n");
    displayLinkedList(head);
    
    //head = insertBeginning(head, element);
    
    //int index = 2;
    //insertAtIndex(head, element, index);

    //insertAtEnd(head, element);

    insertAfterNode(head, fourth, element);

    printf("\nList after insertion - \n");
    displayLinkedList(head);
    return 0;
}
