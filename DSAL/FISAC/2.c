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

node* copy(node* start){
    if(start==NULL)return NULL;
    node *newl = (node*)malloc(sizeof(node));
    newl->data=start->data;
    newl->next= copy(start->next);
    return newl;
}

node *rotate(node* start,int k,int rotateLeft){
    node *head=start;
    node *end=start;
    node *ptr=start;
    while(end->next!=NULL){
        end=end->next;
    }
    if(rotateLeft){
        for(int i=0;i<k;i++){
            ptr = head->next;
            head->next = NULL;
            end->next = head;
            end = end->next;
            head = ptr;
        }
        return head;
    }
    else{
        for(int i=0;i<k;i++){
            ptr = ptr->next;
        }
        node *kthnode = ptr;
        end->next = head;
        head = kthnode->next;
        kthnode->next = NULL;

        return head;
    }
}

void main(void){
    node *l1=NULL,*l2=NULL;
    int k;
    printf("Input the linked list elements\n");
    l1 = createll(l1);
    l2 = copy(l1);

    printf("No. of times to rotate: ");
    scanf("%d",&k);

    printf("Original list:\t");
    display(l1);

    l1 = rotate(l1,k,1);
    printf("\nLeft rotate:\t");
    display(l1);

    printf("\nRight rotate:\t");
    l2 = rotate(l2,k,0);
    display(l2);
}