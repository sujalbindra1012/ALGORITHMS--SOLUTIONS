#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int a[10], b[10];
    int i = 0, j = 0, k = 0;
    for (i = low; i <= mid; i++)
    {
        a[k++] = arr[i];
    }
    k = 0;
    for (i = mid + 1; i <= high; i++)
    {
        b[k++] = arr[i];
    }
    i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k++] = a[i++];
    }
    while (j < n2)
    {
        arr[k++] = b[j++];
    }
}

int mergesort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergesort(arr, low, mid);
        mergesort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    printf("enter number of elements of array : ");
    scanf("%d", &n);
    int arr[10];
    printf("enter the elements of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Unsorted array is : ");
    printarr(arr, n);
    printf("\n");
    mergesort(arr, 0, n - 1);
    printf("sorted array is : ");
    printarr(arr, n);
    return 0;
}