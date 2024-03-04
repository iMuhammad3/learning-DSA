#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int);
void traverse(Node *);

int main(void)
{
    Node *root = createNode(100);
    root->left = createNode(61);
    root->right = createNode(39);
    root->left->left = createNode(20);
    root->left->right = createNode(25);
    root->right->left = createNode(30);
    root->right->right = createNode(25);

    traverse(root);

}

Node *createNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory Allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void traverse(Node *node)
{
    if(node != NULL)
    {
        printf("%d ", node->data);
        traverse(node->left);
        traverse(node->right);
    }
}