#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void binarysearch(int arr[], int n, int target)
{
    int i = 0;
    int low = 0;
    int high = n - 1;
    int flag = 0;
    int mid = 0;

    while (low < high)
    {
        int mid = (low + (high - low) / 2);
        if (arr[mid] == target)
        {
            printf("element found at index : %d", mid + 1);
            flag = 1;
            break;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    if (flag == 0)
    {
        printf("element not found");
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
    printf("Array is : ");
    printarr(arr, n);
    printf("\n");
    int target;
    printf("enter the value needs to find : ");
    scanf("%d", &target);
    binarysearch(arr, n, target);
    // printf("sorted array is : ");
    // printarr(arr, n);
    return 0;
}