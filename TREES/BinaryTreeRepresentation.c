#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*left;
    struct node*right;
};

struct node*createnode(int data){
    struct node*n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
}

int main(){
    //constructing root node
    // struct node*p;
    // p=(struct node*)malloc(sizeof(struct node));
    // p->data=2;
    // p->left=NULL;
    // p->right=NULL;

    
    // struct node*p1;
    // p1=(struct node*)malloc(sizeof(struct node));
    // p1->data=1;
    // p1->left=NULL;
    // p1->right=NULL;

    // struct node*p2;
    // p2=(struct node*)malloc(sizeof(struct node));
    // p2->data=3;
    // p2->left=NULL;
    // p2->right=NULL;

    // p->left=p1;
    // p->right=p2;

//other way to make tree

    struct node *p=createnode(2);
    struct node *p1=createnode(1);
    struct node *p2=createnode(4);

    p->left=p1;
    p->right=p2;
    return 0;


}