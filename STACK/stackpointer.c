#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int count = 0;

struct stack
{
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
    s->top = -1;
}

int isfull(st *s)
{
    if (s->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isempty(st *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(st *s, int data)
{
    if (isfull(s))
    {
        printf("stack is full");
    }
    else
    {
        s->top++;
        s->items[s->top] = data;
    }
    count++;
}

void pop(st *s)
{
    if (isempty(s))
    {
        printf("stack is empty");
    }
    else
    {
        printf("element poppped is : %d", s->items[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}

void printstack(st *s)
{
    printf("stack : ");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

int main()
{
    int ch;
    st *s = (st *)malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printf("after pushing \n");
    printstack(s);
    pop(s);

    printf("after popping out \n");
    printstack(s);
}
