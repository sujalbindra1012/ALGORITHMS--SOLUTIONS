#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void insert(struct node * root,int key){
    struct node*prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("Cannot inser %d ,Already exist ",key);
            return;
        }
        if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node*new=createnode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }

}

int main()
{
    struct node *p = createnode(30);
    struct node *p1 = createnode(20);
    struct node *p2 = createnode(40);
    struct node *p3 = createnode(10);
    struct node *p4 = createnode(25);
    struct node *p5 = createnode(35);
    struct node *p6 = createnode(45);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    printf("inorder traversal : ");
    inorder(p);
    printf("\n");
    insert(p,5);
    insert(p,27);
    printf("inorder traversal : ");
    inorder(p);
    return 0;
}