#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int binarysearch(int arr[], int low, int high, int target)
{
    int mid = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid + 1;
        }
        else if (arr[mid] < target)
        {
            return binarysearch(arr, mid + 1, high , target);
        }
        else if (arr[mid > target])
        {
            return binarysearch(arr, low, mid - 1, target);
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("enter number of elements of array : ");
    scanf("%d", &n);
    int arr[10];
    printf("enter the sorted elements in array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Array is : ");
    printarr(arr, n);
    printf("\n");
    int target;
    printf("enter the value needs to find : ");
    scanf("%d", &target);
    int found = binarysearch(arr, 0, n, target);
    if (found == -1)
    {
        printf("element is not present");
    }
    else
    {
        printf("element is present at index : %d", found);
    }

    return 0;
}