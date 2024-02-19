#include <stdio.h>
#include <stdlib.h>

// define binary tree node structure
typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// method declarations
TreeNode *createNode(int);
TreeNode *insertNode(TreeNode *, int);
TreeNode *searchNode(TreeNode *, int);
void displayTree(TreeNode *);
void deallocate(TreeNode *);

int main()
{
    TreeNode *root = createNode(100);
    for (int i = 1; i < 10; i++)
    {
        insertNode(root, i * 10);
    }
    displayTree(root);
    printf("\n");

    deallocate(root);
}

TreeNode *createNode(int data)
{
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *insertNode(TreeNode *root, int data)
{
    // if tree is empty
    if (root == NULL)
        return createNode(data);
    if (data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

TreeNode *searchNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return NULL;
    }

    if (root->data == key)
        return root;

    if (key < root->data)
        return searchNode(root->left, key);

    return searchNode(root->right, key);
}

void displayTree(TreeNode *root)
{
    if (root != NULL)
    {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

void deallocate(TreeNode *root)
{
    if (root != NULL)
    {
        deallocate(root->left);
        deallocate(root->right);
        free(root);
    }
}
