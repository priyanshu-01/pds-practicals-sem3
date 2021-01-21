#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n;
int isPlaced[20]; //stores safely placed positon of each queen
int numberOfQueensPlaced = 0;
bool isSafe(int y, int x)
{
    bool flag = true;
    for (int i = 0; i < numberOfQueensPlaced; i++)
    {
        if (i == y || isPlaced[i] == x || abs(y - i) == abs(x - isPlaced[i])) // check if i,isPlaced[i] is safe from y,x; if not -> bool = false, break;
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void Place(int y)
{
    // printf("%d",y);
    if (y < n && y >= 0)
        for (int a = isPlaced[y] + 1; a <= n; a++)
        {
            if (a < n && isSafe(y, a))
            {
                isPlaced[y] = a;
                numberOfQueensPlaced++;
                Place(y + 1);
                break;
            }
            else if (a == n)
            {
                isPlaced[y] = -1;
                numberOfQueensPlaced--;
                Place(y - 1);                  // BACKTRACKING
                break;
            }
        }
}
void main()
{
    printf("Enter the number of queens to be placed : ");
    scanf("%d", &n);
    for (int i = 0; i < 20; i++)
        isPlaced[i] = -1;
    Place(0);
    for (int i = 0; i < numberOfQueensPlaced; i++)
    {
        for (int j = 0; j < numberOfQueensPlaced; j++)
            if (j == isPlaced[i])
                printf("%d ", 1);
            else
                printf("0 ");
        printf("\n");
    }
    if(numberOfQueensPlaced<n)
    printf("Solution does not exist");
}