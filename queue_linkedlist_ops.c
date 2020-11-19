#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};



void enqueue(struct Node *r, int x)
{
    if(!isFull(q))
    {
        struct Node *q = (struct Node *)malloc(sizeof(struct Node));
        q->data = x;
        q->next = r;
         

    }
    else
    {
        printf("\nqueue is full, cannot add more elements");
    }
}

int main()
{
    struct Node *queue = (struct Node *)malloc(sizeof(struct Node));
    queue = NULL;

    enqueue(queue, 21);
    enqueue(queue, 38);
    enqueue(queue, 20);
    enqueue(queue, 47);
    enqueue(queue, 91);
    enqueue(queue, 76);
    enqueue(queue, 11);

    printf("\nremoved element is: %d", dequeue(queue));
    printf("\nremoved element is: %d", dequeue(queue));
    printf("\nremoved element is: %d", dequeue(queue));

    return 0;
}