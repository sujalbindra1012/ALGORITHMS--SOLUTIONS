#include <stdio.h>
#include <stdlib.h>


//in this we did node insertion in four ways :
// insert at begin
// insert at end
// insert at pos
// insert at index

struct Node
{
    int data;
    struct Node *next;
};

void traversell(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is : %d\n ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    ptr->data = data;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
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
    third->next = NULL;

    printf("Linked list before insertion \n");
    traversell(head);

    // head = insertAtFirst(head, 5);
    // head = insertAtIndex(head, 25, 2);
    // head = insertAtEnd(head, 50);
    head = insertAfterNode(head, third, 35);
    printf("Linked list after insertion \n");
    traversell(head);
}