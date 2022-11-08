#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node* display(node* start){
    node* ptr = start;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    return start;
}

node* fib(int n){
    node *ptr,*new,*preptr,*prepreptr;
    node* l = (node*)malloc(sizeof(node));
    
    for(int i=1;i<=n;i++){
        if(i==1){
            l->data=0;
            l->next=NULL;
        }
        else if(i==2){
            new = (node*)malloc(sizeof(node));
            new->data = 1;
            new->next = NULL;
            l->next = new;
        }
        else{
            ptr = l;
            for(int j=1 ; j<=i-1 ; j++){
                if(j==i-1)preptr = ptr;
                if(j==i-2)prepreptr = ptr;
                if(ptr->next)ptr = ptr->next;
            }
            new = (node*)malloc(sizeof(node));
            new->data = preptr->data + prepreptr->data;
            new->next = NULL;
            ptr->next = new;
        }
    }
    return l;
}

void main(void){
    int n;
    node *l1 = NULL;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Generated list:\n");

    l1 = fib(n);
    display(l1);
}