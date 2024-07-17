// Insertion in this list can be divided into the following categories:

// Case 1: Deleting the first node.

// Case 2: Deleting the node at the index.

// Case 3: Deleting the last node.

// Case 4: Deleting the first node with a given value.
#include <stdio.h>
#include <stdlib.h>

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

struct Node *deletionAtFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *deletionAtIndex(struct Node *head, int index)
{
    // struct Node * ptr=head;
    // for(int i=0;i<index-1;i++){
    //     ptr=ptr->next;
    // }
    // ptr->next=ptr->next->next;
    // return head;

    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct Node *deletionAtLast(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(q);
    return head;
}

struct Node *deletionByValue(struct Node *head, int value)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        q = q->next;
        ptr = ptr->next;
    }
    if (q->data == value)
    {
        ptr->next = q->next;
        free(q);
    }

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

    printf("Before deletion \n");
    traversell(head);
    // head = deletionAtFirst(head);
    // head=deletionAtIndex(head,1);
    // head = deletionAtLast(head);
    head = deletionByValue(head, 20);
    printf("After Deletion of node \n ");
    traversell(head);
    return 0;
}