#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* createll(node* start){
    node *newnode,*ptr;
    int num;
    printf("Enter -1 to end\n");
    printf("Enter the data: ");
    scanf("%d",&num);
    while(num!=-1){
        newnode = (node*)malloc(sizeof(node));
        newnode->data = num;
        if(start==NULL){
            newnode->next = NULL;
            start = newnode;
        }
        else{
            ptr = start;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
}

node* display(node* start){
    node* ptr = start;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    return start;
}

node* merge(node* l1,node* l2){
    node *ptr1=l1;
    node *ptr2=l2;
    node *l3,*new,*ptr;
    l3 = NULL;
    while(ptr1!=NULL || ptr2!=NULL){
        new = (node*)malloc(sizeof(node));
        if(ptr2==NULL){
            new->data = ptr1->data;
            ptr1 = ptr1->next;
        }
        if(ptr1==NULL){
            new->data = ptr2->data;
            ptr2 = ptr2->next;
        }
        if(ptr1&&ptr2){
            if(ptr1->data <= ptr2->data){
                new->data = ptr1->data;
                ptr1 = ptr1->next;
            }
            else{
                new->data = ptr2->data;
                ptr2 = ptr2->next;
            }
        }
        new->next = NULL;
        if(l3==NULL)l3=new;
        else{
            ptr = l3;
            while(ptr->next!=NULL)ptr = ptr->next;

            ptr->next = new;
        }
    }
    l1=l3;
    return l1;
}

void main(void){
    node* l1 = NULL;
    node* l2 = NULL;
    int i;
    printf("Input first linked list\n");
    l1 = createll(l1);
    printf("\nInput second linked list\n");
    l2 = createll(l2);
    printf("LIST 1: ");
    display(l1);
    printf("\nLIST 2: ");
    display(l2);

    printf("\nAfter merging\nLIST 1: ");
    l1 = merge(l1,l2);
    display(l1);
}