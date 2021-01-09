#include <stdio.h>

struct Account
{
    char name[20];
    int number;  
    int balance;
};

int main()
{
    struct Account myStruct;
    printf("enter details of account %d: \n", 1);

    printf("enter name : ");
    // scanf("%s", &myStruct.name);
    gets(myStruct.name);

    printf("enter number :");
    scanf("%d", &myStruct.number);
    
    printf("enter balance :");
    scanf("%d", &myStruct.balance);

    printf("details entered are : \n");
    printf("name : %s \n", myStruct.name);
    printf("number : %d \n", myStruct.number);
    printf("balance : %d \n", myStruct.balance);
}