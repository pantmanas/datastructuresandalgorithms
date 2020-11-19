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

void enqueueRear(int x)
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

void enqueueFront(int x)
{
    if(!isFull())
    {
        struct Node *inserted = (struct Node *)malloc(sizeof(struct Node));
        inserted->data = x;
        inserted->next = front;
        if(front == NULL)
        {
            front = rear = inserted;
        }
        else
        {
            front = inserted;
        }
    }
    else
    {
        printf("\nqueue is full, cannot add more elements");
    }
}

int dequeueFront()
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

int dequeueRear()
{
    int val = -1;
    if(!isEmpty())
    {
        struct Node *ptr = front;
        struct Node *q = front->next;
        while(q->next != NULL)
        {
            ptr = ptr->next;
            q = q->next;
        }
        val = q->data;
        ptr->next = q->next;
        free(q);
    }
    else
    {
        printf("\nqueue is empty, cannot delete any element");
    }
    return val;
}

int main()
{

    enqueueRear(21);
    enqueueRear(38);
    enqueueRear(20);
    enqueueRear(47);
    enqueueRear(91);
    enqueueRear(76);
    enqueueRear(11);

    linklistTraversal();

    

    printf("\nremoved element is: %d", dequeueFront());
    printf("\nremoved element is: %d", dequeueFront());
    printf("\nremoved element is: %d", dequeueFront());

    printf("\n------------------------------after enqueueFront------------------------------");

    enqueueFront(99);
    enqueueFront(100);
    enqueueFront(101);

    linklistTraversal();

    

    printf("\n------------------------------after dequeueRear------------------------------");

    printf("\nremoved element is: %d", dequeueRear());
    printf("\nremoved element is: %d", dequeueRear());
    printf("\nremoved element is: %d", dequeueRear());

    linklistTraversal();

    return 0;
}