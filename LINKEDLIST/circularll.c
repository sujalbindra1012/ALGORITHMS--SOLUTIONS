#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversell(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element is : %d\n ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    // head=ptr;
    return ptr;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = head;

    printf("before insertion \n");
    traversell(head);
    head = insertAtFirst(head, 2);
    head = insertAtFirst(head, 4);
    head = insertAtFirst(head, 6);
    head = insertAtFirst(head, 8);
    printf("after insertion");
    traversell(head);
    return 0;
}