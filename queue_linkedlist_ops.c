#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front, *rear = NULL;

void linklistTraversal()
{
    int i = 1;
    struct Node *a = front;
    while(a != NULL)
    {
        printf("\nelement %d in list is: %d", i, a->data);
        a = a->next;
        i++;
    }
}

int isFull()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if(front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int x)
{
    if(!isFull())
    {
        struct Node *inserted = (struct Node *)malloc(sizeof(struct Node));
        inserted->data = x;
        inserted->next = NULL;
        if(front == NULL)
        {
            front = rear = inserted;
        }
        else
        {
            rear->next = inserted;
            rear = inserted;
        }
    }
    else
    {
        printf("\nqueue is full, cannot add more elements");
    }
}

int dequeue()
{
    int val = -1;
    if(!isEmpty())
    {
        struct Node *ptr = front;
        val = front->data;
        front = front->next;
        free(ptr);
    }
    else
    {
        printf("\nqueue is empty, cannot delete any element");
    }
    return val;
}

int main()
{

    enqueue(21);
    enqueue(38);
    enqueue(20);
    enqueue(47);
    enqueue(91);
    enqueue(76);
    enqueue(11);

    linklistTraversal();

    printf("\nremoved element is: %d", dequeue());
    printf("\nremoved element is: %d", dequeue());
    printf("\nremoved element is: %d", dequeue());

    return 0;
}