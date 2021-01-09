#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

void insertNodeAtEnd(int n)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    tail->next = new_node;
    new_node->value = n;
    new_node->next = NULL;
    tail = new_node;
}
void insertNodeAtBeginning(int n)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->next = head;
    new_node->value = n;
    head = new_node;
}

void printTheNodes()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d  ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int cont = 0;
    int n;
    int input;

    printf("enter a number : ");
    scanf("%d", &n);
    head = (struct Node *)malloc(sizeof(struct Node));
    head->value = n;
    head->next = NULL;

    tail = head;

    while (cont == 0)
    {
        printf("Enter your choice : \n 1- Insert at beginning \n 2- Insert at end \n 0- Quit \n");

        scanf("%d", &input);
        if (input == 0)
        {
            cont = 1;
            printf("The result is : \n");
            printTheNodes();
            return 0;
        }
        else
        {
            printf("enter a number : ");
            scanf("%d", &n);
            if(input==1)
            insertNodeAtBeginning(n);
            else if(input==2)
            insertNodeAtEnd(n);
            printTheNodes();
        }
    }
}