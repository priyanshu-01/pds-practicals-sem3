#include <stdio.h>
#include <stdlib.h>
int data[100], ch;
int count = 0;

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

void insert(int d, struct Node *a)
{
    if (d <= a->data)
    {
        if (a->left == NULL)
        {
            struct Node *newNode;
            newNode = (struct Node *)malloc(sizeof(struct Node));
            a->left = newNode;
            newNode->data = d;
            newNode->right = NULL;
            newNode->left = NULL;
        }
        else
            insert(d, a->left);
    }
    else
    {
        if (a->right == NULL)
        {
            struct Node *newNode;
            newNode = (struct Node *)malloc(sizeof(struct Node));
            a->right = newNode;
            newNode->data = d;
            newNode->left = NULL;
            newNode->right = NULL;
        }
        else
            insert(d, a->right);
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
void get_array()
{
    FILE *InputFile;
    InputFile = fopen("input.txt", "r");

    char temp[10];
    int c = 0;
    int num = 0;
    while ((ch = fgetc(InputFile)) != -1)
    {
        if (ch == ' ')
        {
            for (int k = 0; k < c; k++)
            {
                num = (num * 10) + (((int)temp[k]) - 48);
            }
            data[count++] = num;
            num = 0;
            c = 0;
        }
        else
        {
            temp[c++] = ch;
        }
    }
    fclose(InputFile);
    printf("Elements are : ");
    for (int k = 0; k < count; k++)
    {
        printf("%d ", data[k]);
    }
    printf("\n");

}
void main()
{
    get_array();

    struct Node *root;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = data[0];
    root->left = NULL;
    root->right = NULL;

    for (int k = 1; k < count; k++)
        insert(data[k], root);

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
