#include<stdio.h>
#include<stdlib.h>

//deleting the first node
//deleting a node in between on the basis of an index
//deleting the last node
//delete the node with a key

struct Node
{
    int data;
    struct Node *next;
};

void linkedlistTraversal(struct Node *ptr)
{   
    int i = 0;
    while (ptr != NULL)
    {
        ++i;
        printf("element %d is %d\n", i, ptr->data);
        ptr = ptr->next;
    }
}

struct Node * deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node * deleteIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    int i = 0;
    while (i < index-1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

struct Node * deleteLastNode(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

struct Node * deleteValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    if (ptr->data == value)
    {
        head = ptr->next;
        free(ptr);
    }
    else
    {
        while(q != NULL)
        {
            if (q->data == value)
            {
                ptr->next = q->next;
            }
            ptr = ptr->next;
            q = q->next;
        }
    }   
    free(q);
    return head;
}

int main()
{
    struct Node *first, *second, *third, *fourth, *head;
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    head = (struct Node *)malloc(sizeof(struct Node));

    first->data = 3;
    first->next = second;

    second->data = 9;
    second->next = third;

    third->data = 13;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    head = first;

    printf("Linked list before deleting a node -\n");
    linkedlistTraversal(head);
    
    printf("\nLinked list after deleting a node -\n");
    //head = deleteFirstNode(head);
    
    //int index = 2;
    //head = deleteIndex(head, index);

    //head = deleteLastNode(head);

    int value = 3;
    head = deleteValue(head, value);

    linkedlistTraversal(head);
    
    return 0;
}

