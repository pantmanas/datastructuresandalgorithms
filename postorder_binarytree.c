#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

struct Node * createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postOrder(struct Node *x)
{
    if(x != NULL)
    {
        postOrder(x->left);
        postOrder(x->right);
        printf("%d ", x->data);
    }
}

int main()
{
    struct Node * p = createNode(4);
    struct Node * p1 = createNode(1);
    struct Node * p2 = createNode(5);
    struct Node * p3 = createNode(2);
    struct Node * p4 = createNode(6);

    p->left = p1;
    p->right = p4;
    p1->left = p2;
    p1->right = p3;

    postOrder(p);

    return 0;
}