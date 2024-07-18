#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void linearsearch(int arr[], int n, int target)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            flag = 1;
            printf("Element found at index - %d", i + 1);
        }
    }
    if (flag == 0)
    {
        printf("Element not found");
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
    linearsearch(arr, n, target);
    // printf("sorted array is : ");
    // printarr(arr, n);
    return 0;
}