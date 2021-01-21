#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble(int A[], int n)
{
    int i, j, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
            flag = 1;
        }

        if (flag == 0)
            break;
    }
}
int main()
{
    int n;
    printf("Enter the total no. of elements :  ");
    scanf("%d", &n);
    int A[n];
    printf("Enter %d elements : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    Bubble(A, n);
    printf("Sorted array using Bubble sort is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", A[i]);
    }
    return 0;
}
