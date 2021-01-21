#include <stdio.h>
#include <stdlib.h>
int n;
char s[40];
int weigthAdjacencyMat[40][40], visitedEdges[40][40];
int visitedNodes[40];         //stores  1 if a node has been visited else 0
int storeVisitedNodes[40];    //stores the nodes which have been visited
int numberOfNodesVisited = 0; //stores total no of nodes visited
int totalWeight=0;

struct SmallestEdge      //stores the two nodes across an edge
{
    int x;
    int y;
};

void putInAdjacencyMat(char a[], int b)
{
    for (int k = 0; k < n; k++)
    {
        weigthAdjacencyMat[b][k] = (int)(a[k]) - 48;
    }
}

void MST()
{
    int smallestWeight = 0;
    struct SmallestEdge *small = (struct SmallestEdge *)malloc(sizeof(struct SmallestEdge));
    small->x = 0;
    small->y = 0;
    int tempNode;
    for (int a = 0; a < numberOfNodesVisited; a++)        //find the smallest edge from the visited nodes
    {
        tempNode = storeVisitedNodes[a];        //takes visited node one by one

        for (int i = 0; i < n; i++)
        {
            if (
                tempNode != i &&        //removes loop
                visitedEdges[tempNode][i] != 1 &&     //edge has not already been visited
                (weigthAdjacencyMat[tempNode][i] < smallestWeight || smallestWeight == 0)) //this edge has smallest weight
            {
                smallestWeight = weigthAdjacencyMat[tempNode][i];    //weight of smallest edge
                small->x = tempNode;
                small->y = i;
            }
        }
    }
    visitedEdges[small->x][small->y] = 1;
    visitedEdges[small->y][small->x] = 1;
    printf("Edge (%d,%d) weight %d \n", small->x, small->y, smallestWeight);
    totalWeight = totalWeight+smallestWeight;
    if (visitedNodes[small->x] != 1)
    {
        storeVisitedNodes[numberOfNodesVisited] = small->x;
        visitedNodes[storeVisitedNodes[numberOfNodesVisited]] = 1;
        numberOfNodesVisited++;
    }
    if (visitedNodes[small->y] != 1)
    {
        storeVisitedNodes[numberOfNodesVisited] = small->y;
        visitedNodes[storeVisitedNodes[numberOfNodesVisited]] = 1;
        numberOfNodesVisited++;
    }
    if(numberOfNodesVisited<n)
    MST();
}
void main()
{
    printf("Enter the no of vertices : ");
    scanf("%d", &n);
    printf("Enter the weight Adjacency Matrix in Matrix Form  : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        putInAdjacencyMat(s, i);
    }
    storeVisitedNodes[numberOfNodesVisited] = 0; //0 is the starting point
    visitedNodes[storeVisitedNodes[numberOfNodesVisited]] = 1;
    numberOfNodesVisited++;
    MST();
    printf("Total Weight : %d" , totalWeight);
}