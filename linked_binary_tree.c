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
    struct Node *n = (struct Node *)malloc(sizeof(struct Node)); //allocate memory in the heap for a new node pointer
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    return n;
}

int main()
{
    /* //manual node allocation
    //allocate memory for the root node in the heap
    struct Node *p = (struct Node *)malloc(sizeof(struct Node)); 
    p->left = NULL;
    p->right = NULL;
    p->data = 2;

    //construct the second node
    struct Node *p1 = (struct Node *)malloc(sizeof(struct Node)); 
    p1->left = NULL;
    p1->right = NULL;
    p1->data = 1;

    //construct the third node
    struct Node *p2 = (struct Node *)malloc(sizeof(struct Node)); 
    p2->left = NULL;
    p2->right = NULL;
    p2->data = 4;

    */

    //create the root node using a function
    struct Node *p = createNode(2);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(4);

    //link the root to its children
    p->left = p1;
    p->right = p2;

    return 0;
}