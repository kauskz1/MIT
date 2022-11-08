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

node* even(node *start){
    node *ptr = start;
    node *l=NULL;
    node *ptr2,*newnode;
    while(ptr!=NULL){
        if(ptr->data%2 == 0){
            int newData = ptr->data * ptr->data * ptr->data;
            newnode = (node*)malloc(sizeof(node));
            newnode->data = newData;
            newnode->next = NULL;
            if(l==NULL)l=newnode;
            else{
                ptr2 = l;
                while(ptr2->next != NULL)ptr2 = ptr2->next;
                ptr2->next = newnode;
            }
        }
        ptr = ptr->next;
    }
    return l;
}

node* odd(node *start){
    node *ptr = start;
    node *l=NULL;
    node *ptr2,*newnode;
    while(ptr!=NULL){
        if(ptr->data%2 != 0){
            int newData = ptr->data * ptr->data * ptr->data;
            newnode = (node*)malloc(sizeof(node));
            newnode->data = newData;
            newnode->next = NULL;
            if(l==NULL)l=newnode;
            else{
                ptr2 = l;
                while(ptr2->next != NULL)ptr2 = ptr2->next;
                ptr2->next = newnode;
            }
        }
        ptr = ptr->next;
    }
    return l;
}

void main(void){
    node *l1 = NULL;
    l1 = createll(l1);
    printf("Original List: ");
    display(l1);

    node *l2 = even(l1);
    node *l3 = odd(l1);

    printf("\nList with cube of even numbers: ");
    display(l2);

    printf("\nList with cube of odd numbers: ");
    display(l3);
}