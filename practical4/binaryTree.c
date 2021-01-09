#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};
struct Node* create()
{
    struct Node *newNode;
    int data;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Data : \n");
    scanf("%d", &data);
    if (data == -1)
        return NULL;
    else
    {
        newNode->data = data;
        printf("Enter the left to %d \n", data);
        newNode->left = create();
        printf("Enter the right to %d \n", data);
        newNode->right = create();
        return newNode;
    }
}
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
void main()
{
    struct Node *root;
    root = create();
    printf("Inorder transversal:\n");
    inorder(root);
    printf("\n");
    printf("Preorder transversal:\n");
    preorder(root);
    printf("\n");
    printf("Postorder transversal:\n");
    postorder(root);
    printf("\n");
}
