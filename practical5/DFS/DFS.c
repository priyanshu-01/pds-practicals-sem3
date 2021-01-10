#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;
char s[20];
int AdjacencyMat[20][20];
int Visited[20], Stack[20];
int visitedPointer = -1, stackPointer = -1;

void putInAdjacencyMat(char a[], int b)
{
    for (int k = 0; k < n; k++)
    {
        AdjacencyMat[b][k] = (int)(a[k]) - 48;
    }
}
void printAdjacencyMat()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", AdjacencyMat[i][j]);
        }
        printf("\n");
    }
}
void printResult()
{
    printf("Depth First Search Result for the given graph is : \n");

    for (int i = 0; i <= visitedPointer; i++)
    {
        printf("%d ", Visited[i]);
    }
}
void pop()
{
    Stack[stackPointer] = -1;
    stackPointer--;
}
void push(int j)
{
    visitedPointer++;
    stackPointer++;
    Visited[visitedPointer] = j;
    Stack[stackPointer] = j;
}

int ResultContainsJ(int j)
{
    bool val = false;
    for (int i = 0; i <= visitedPointer; i++)
    {
        if (Visited[i] == j)
        {
            val = true;
            break;
        }
    }
    return val;
}

int DFS(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (AdjacencyMat[i][j] == 1 && !ResultContainsJ(j))
        {
            push(j);
            DFS(j);
            return 0;
        }
    }
    pop();
    if (stackPointer != -1)
    {
        DFS(Stack[stackPointer]);
    }
    return 0;
}

void main()
{
    printf("Enter the no of Vertices : ");
    scanf("%d", &n);
    printf("Enter the Ajacency Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        putInAdjacencyMat(s, i);
    }
    // printAdjacencyMat();
    push(0);
    DFS(0);
    printResult();
}