#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int m, n;
int isColored[20];
char s[20];
int adjacencyMat[20][20];
int numberOfVerticesColored = 0;

void putInAdjacencyMat(char a[], int b)
{
    for (int k = 0; k < n; k++)
    {
        adjacencyMat[b][k] = (int)(a[k]) - 48;
    }
}

bool canBeColored(int y, int a)
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (adjacencyMat[y][i] == 1 && isColored[i] == a) // check if i,isPlaced[i] is safe from y,a; if not -> bool = false, break;
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void Color(int y)
{
    // printf("%d",y);
    if (y < n && y >= 0)
        for (int a = isColored[y] + 1; a <= m; a++)
        {
            if (a <= m && canBeColored(y, a))
            {
                isColored[y] = a;
                numberOfVerticesColored++;
                Color(y + 1);
                break;
            }
            else if (a == m + 1)
            {
                isColored[y] = 0;
                numberOfVerticesColored--;
                Color(y - 1);
            }
        }
}
void main()
{
    printf("Enter the number of maximum colors : ");
    scanf("%d", &m);
    printf("Enter the no of vertices : ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix in Matrix Form  : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        putInAdjacencyMat(s, i);
    }
    for (int i = 0; i < 20; i++)
        isColored[i] = 0;
    Color(0);
    if (numberOfVerticesColored < n)
        printf("Solution does not exist");
    else
    {
        printf("Solution Exists. The following colors are assigned : ");
        for (int i = 0; i < numberOfVerticesColored; i++)
            printf("%d ", isColored[i]);
    }
}