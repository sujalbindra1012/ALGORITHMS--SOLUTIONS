#include <stdio.h>
#include <stdlib.h>
#define size 5

int enqueue(int arr[], int rear, int front)
{
    if ((rear == size - 1 && front == 0) || (rear == front - 1))
    {
        printf("****************************queue is full******************************** \n");
        return rear;
    }
    else
    {
        int val;
        printf("enter the value : ");
        scanf("%d", &val);
        arr[++rear % size] = val;
        return (rear % size);
    }
}

int dequeue(int arr[], int front)
{
    if (front == -1)
    {
        printf("***************************queue is empty********************************** \n");
        return front;
    }
    else
    {
        printf("element : %d ", arr[front]);
        arr[front] = 0;
        front = (front + 1) % size;
        return front;
    }
}

void display(int arr[], int rear, int front)
{
    if (front == -1)
    {
        printf("queue is empty ");
    }
    else
    {
        printf("queue elements are : ");
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("%d ", arr[i]);
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                printf("%d ", arr[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int q[size];
    int rear = -1;
    int front = -1;

    int ch = 0;
    do
    {
        printf("\n  1. Enqueue : \n 2. Dequeue : \n 3. Display : \n 4. Exit : \n");
        printf("\n Enter your choice : ");
        printf("\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            rear = enqueue(q, rear, front);
            if (front == -1 && rear != -1)
            {
                front = 0;
            }
            break;
        case 2:
            front = dequeue(q, front);
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            break;
        case 3:
            display(q, rear, front);
            break;
        case 4:
            exit(0);

        default:
            printf("invalid choice");
        }

    } while (1);
    return 0;
}