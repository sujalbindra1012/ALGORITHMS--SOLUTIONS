#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int linearsearch(int arr[], int n, int target)
{

    if (n < 0)
    {
        return -1;
    }
    if (arr[n - 1] == target)
    {
        return n - 1;
    }
    return linearsearch(arr, n - 1, target);
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
    int found = linearsearch(arr, n, target);
    if (found == -1)
    {
        printf("element is not present");
    }
    else
    {
        printf("element is present at index : %d", found + 1);
    }
    // printf("sorted array is : ");
    // printarr(arr, n);
    return 0;
}