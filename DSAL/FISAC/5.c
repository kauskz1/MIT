#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* input(node* start,int n){
    node *newnode,*ptr;
    int num;
    for(int i=1;i<=n;i++){
        printf("Enter data of node %d: ",i);
        scanf("%d",&num);
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

node* deleteNode(node* start,node* nodeToBeDeleted){
    if(nodeToBeDeleted == start){
        start = start->next;
        nodeToBeDeleted = NULL;
        return start;
    }
    node* end = start,*preptr=start;
    while(end->next!=NULL){
        end = end->next;
        if(preptr->next->next!=NULL)preptr=preptr->next;
    }
    if(nodeToBeDeleted == end){
        preptr->next = NULL;
        return start;
    }
    preptr=start;
    while(preptr->next!=nodeToBeDeleted){
        preptr=preptr->next;
    }
    preptr->next = nodeToBeDeleted->next;
    return start;
}

node* deleteKey(node* start,int key){
    node* ptr=start;
    while(ptr!=NULL){
        if(ptr->data == key*key){
            start=deleteNode(start,ptr);
        }
        ptr = ptr->next;
    }
    return start;
}

void main(void){
    node *l1 = NULL;
    int n,key;
    printf("Enter number of nodes to create: ");
    scanf("%d",&n);
    l1 = input(l1,n);
    printf("Data in list before deletion: ");
    display(l1);

    printf("\nEnter value of key to be considered for deletion: ");
    scanf("%d",&key);
    l1 = deleteKey(l1,key);
    printf("Data in the final list after deletion: ");
    display(l1);
}