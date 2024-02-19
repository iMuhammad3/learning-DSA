#include <stdio.h>
#include <stdlib.h>

// define binary tree node structure
typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//method declarations
TreeNode *createNode(int);
TreeNode *insertNode(TreeNode *, int);
TreeNode *searchNode(TreeNode *, int);

int main()
{
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
    if(root == NULL) return createNode(data);
    if(data <= root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else 
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

TreeNode *searchNode(TreeNode *root, int data)
{

}
