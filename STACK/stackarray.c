#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int push(int arr[], int top)
{
    if (top == MAX - 1)
    {
        printf("stack overflow...");
        return top;
    }
    else
    {
        int data;
        printf("enter the data : ");
        scanf("%d", &data);
        top++;
        arr[top] = data;
        return top;
    }
}

int pop(int arr[], int top)
{
    if (top == -1)
    {
        printf("stack underflow...");
        return top;
    }
    else
    {
        printf("deleted element : %d", arr[top]);
        top--;
        return top;
    }
}

void display(int arr[], int top)
{
    if (top == -1)
    {
        printf("stack is empty !!!");
        return;
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d \n ", arr[i]);
        }
    }
}

int main()
{
    int arr[MAX];
    int top = -1;
    int ch;
    do
    {
        printf("\n enter 1 for push : \n enter 2 for pop : \n enter 3 for display : \n enter 4 for exit : \n");
        printf("enter you choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            top = push(arr, top);
            break;
        case 2:
            top = pop(arr, top);
            break;
        case 3:
            display(arr, top);
            break;
        case 4:
            exit(0);
        }
    } while (1);
    return 0;
}