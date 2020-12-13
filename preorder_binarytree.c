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

void preOrder(struct Node *x)
{
    if(x != NULL)
    {
        printf("%d ", x->data);
        preOrder(x->left);
        preOrder(x->right);
    }
}

int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);

    return 0;
}