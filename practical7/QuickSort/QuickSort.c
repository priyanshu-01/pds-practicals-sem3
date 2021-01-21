#include <stdio.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int A[], int lb, int ub)
{
    int pivot = A[lb];
    int start = lb, end = ub;
    do
    {
        do
        {
            start++;
        } while (A[start] <= pivot);
        do
        {
            end--;
        } while (A[end] > pivot);
        if (start < end)
            swap(&A[start], &A[end]);
    } while (start < end);
    swap(&A[lb], &A[end]);
    return end;
}
void quicksort(int A[], int lb, int ub)
{
    int end;
    if (lb < ub)
    {
        end = partition(A, lb, ub);
        quicksort(A, lb, end);
        quicksort(A, end + 1, ub);
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
    quicksort(A, 0, n-1);
    printf("Sorted array using quick sort is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", A[i]);
    }
    return 0;
}
