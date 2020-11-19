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
    if(r->rear == r->size - 1)
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
        r->rear = r->rear + 1;
        r->arr[r->rear] = x;
    }
    else
    {
        printf("\nqueue is full, cannot perform enqueue");
    }
}

int dequeue(struct Queue *r)
{
    if(!isEmpty(r))
    {
        r->front = r->front + 1;
        int x = r->arr[r->front];
        return x;
    }
    else
    {
        printf("\nqueue is empty, cannot dequeue anymore elements");
        return 0;
    }
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.front = q.rear = -1;
    //q.arr = (int *)malloc(q->size * sizeof(int));

    enqueue(&q, 32);
    enqueue(&q, 56);
    enqueue(&q, 21);
    enqueue(&q, 39);
    //enqueue(&q, 44);
    //enqueue(&q, 75);

    printf("\nremoved element is: %d", dequeue(&q));
    printf("\nremoved element is: %d", dequeue(&q));
    printf("\nremoved element is: %d", dequeue(&q));
    printf("\nremoved element is: %d", dequeue(&q));
    printf("\nremoved element is: %d", dequeue(&q));

    return 0;
}