#include <stdio.h>
#include <stdlib.h>

void printarr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void insertionsort(int arr[], int n)
{
    int key,j;
    for(int i=1;i<=n-1;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionsort(arr, n);
    printf("sorted array is : ");
    printarr(arr, n);
    return 0;
}