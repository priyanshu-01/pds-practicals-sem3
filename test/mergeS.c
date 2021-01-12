#include <stdio.h>
int arr[30];
int n;

void Merge(int lb, int mid, int ub)
{
    int b[30];
    int i = lb, j = mid + 1, k = 0;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    while (k <= (ub - lb + 1))
    {
        if (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    for (int i = 0; i < k; i++)       //suspect
    {
        arr[lb + i] = b[i];
    }
}
void MergeSort(int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        MergeSort(lb, mid);
        MergeSort(mid + 1, ub);
        Merge(lb, mid, ub);
    }
}

void main()
{
    printf("Input no of elements in the array : ");
    scanf("%d", &n);
    printf("Enter %d numbers : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    MergeSort(0, n - 1);
    printf("The sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}