#include <stdio.h>

struct Account
{
    char name[20];
    int number;
    float balance;
};

int main()
{
    int a;
    char str[20];
    struct Account arr[2];
    // printf("null is %d", arr[2] );

    // printf("enter a no. \n");
    // scanf("%d", &a);
    // printf("entered number is %d \n",a);
    // printf("enter a string : \n");
    // scanf("%s",str);
    // printf("entered string is %s", str);

        // printf("enter number :");
        // scanf("%d", arr[0].number);


    for (int i = 0; i < 2; i++)
    {
        printf("enter details of account %d: \n", i);

        // printf("enter name : ");
        // scanf("%s", arr[i].name);

        printf("enter number :");
        scanf("%d", arr[i].number);

        printf("enter balance :");
        scanf("%f", arr[i].balance);
    }
    printf("details entered are : \n");
    for (int i = 0; i < 2; i++)
    {
        printf("name : %s \n", arr[i].name);
        printf("number : %d \n", arr[i].number);
        printf("balance : %f \n", arr[i].balance);
    }
}