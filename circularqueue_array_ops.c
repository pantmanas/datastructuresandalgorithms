#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *r)
{
    if((r->rear + 1) % r->size == r->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Queue *r)
{
    if(r->front == r->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *r, int x)
{
    if(!isFull(r))
    {
        r->rear = (r->rear + 1) % r->size;
        r->arr[r->rear] = x;
    }
    else
    {
        printf("\nqueue is full, cannot execute enqueue");
    }
}

int dequeue(struct Queue *r)
{
    if(!isEmpty(r))
    {
        r->front = (r->front + 1) % r->size;
        int x = r->arr[r->front];
        return x;
    }
    else
    {
        printf("\nqueue is empty, cannot execute dequeue");
    }
    return 0;
}

int main()
{
    struct Queue *q;
    q->size = 8;
    q->front = q->rear = 0; //what used to be -1 in case of the linear queue

    enqueue(q, 21);
    enqueue(q, 38);
    enqueue(q, 20);
    enqueue(q, 47);
    enqueue(q, 91);
    enqueue(q, 76);
    enqueue(q, 11);
    enqueue(q, 35); // this element cannot be added because we can only have size-1 elements in the queue, the front position remains empty

    
    printf("\nremoved element is: %d", dequeue(q));
    printf("\nremoved element is: %d", dequeue(q));
    printf("\nremoved element is: %d", dequeue(q));
    
    return 0;
}