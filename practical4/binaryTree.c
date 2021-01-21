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
struct Node *create()
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
                num = (num*10) + (((int)temp[k])- 48 );
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
    for(int k=0;k<count;k++){
        printf("%d \n", data[k]);
    }
}
void main()
{
    // get_array();
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
