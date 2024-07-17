#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubblesort(arr, n);
    printf("sorted array is : ");
    printarr(arr, n);
    return 0;
}