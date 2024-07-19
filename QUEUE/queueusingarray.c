#include <stdio.h>
#include <stdlib.h>
#define size 5

int insert(int arr[], int rear)
{
    if (rear == size - 1)
    {
        printf("queue is full");
    }
    else
    {
        printf("enter the element : ");
        int val;
        scanf("%d", &val);
        arr[++rear] = val;
    }
    return rear;
}

int delete(int arr[], int front)
{
    if (front == -1)
    {
        printf("queue is empty \n");
    }
    else
    {
        printf(" deleted element : %d \n ", arr[front]);
        arr[front] = 0;
        front++;
    }
    return front;
}

void display(int arr[], int front, int rear)
{
    if (front == -1)
    {
        printf("queue is empty \n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[size];
    int front = -1;
    int rear = -1;
    int choice = 0;

    do
    {
        printf("\n enter 1 for insert : \n enter 2 for delete : \n enter 3 for display : \n enter 4 for exit : \n");
        printf("enter your choice : ");
        scanf("\n %d ", &choice);

        switch (choice)
        {
        case 1:
            rear = insert(arr, rear);
            if (front == -1 && rear != -1)
            {
                front++;
            }
            break;

        case 2:
            front = delete (arr, front);
            if (front > rear)
            {
                front = rear - 1;
            }
            break;

        case 3:
            display(arr, front, rear);
            break;

        case 4:
            exit(0);
            break;
        }
    } while (1);
    return 0;
}