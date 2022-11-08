#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char* name;
    int roll,marks;
    struct node *next;
}node;

node* create(node* start){
    node *newnode,*ptr;
    char *str = (char*)malloc(20);
    int count=1;
    while(strcmp(str," ")!=0){
        printf("Student %d",count++);
        printf("\nEnter blank space to end");
        printf("\nEnter name: ");
        do{fgets(str,20,stdin);}
        while(strcmp(str," ")==0 || strcmp(str,"\n")==0);
        str[strcspn(str, "\n")] = 0;
        if(strcmp(str," ")==0)break;
        newnode = (node*)malloc(sizeof(node));
        newnode->name = (char*)malloc(20);
        newnode->name = strcpy(newnode->name,str);
        printf("Enter roll no.: ");
        scanf("%d",&newnode->roll);
        printf("Enter marks: ");
        scanf("%d",&newnode->marks);
        newnode->next=NULL;
        if(start==NULL){
            start = newnode;
        }
        else{
            ptr = start;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
        }
    }
    return start;
}

node* display(node* start){
    node *ptr=start;
    while(ptr!=NULL){
        printf("\nName: %s",ptr->name);
        printf("\nRoll no.: %d\nMarks: %d\n",ptr->roll,ptr->marks);
        ptr=ptr->next;
    }
    return start;
}

node* sort(node* start){
    node *ptr=start;
    node *ptr2 = ptr->next;
    char *tempname;
    int temproll,tempmarks;
    while(ptr!=NULL){
        ptr2=ptr->next;
        while(ptr2!=NULL){
            if(ptr->marks < ptr2->marks){
                tempname = ptr->name;
                temproll = ptr->roll;
                tempmarks = ptr->marks;

                ptr->name = ptr2->name;
                ptr->roll = ptr2->roll;
                ptr->marks = ptr2->marks;

                ptr2->name = tempname;
                ptr2->roll = temproll;
                ptr2->marks = tempmarks;
            }
            ptr2=ptr2->next;
        }
    ptr=ptr->next;
    }
    return start;
}

void main(void){
    node* l = NULL;
    l = create(l);
    printf("\nLinked List Data:");
    display(l);

    printf("\nSorted list based on marks:");
    l = sort(l);
    display(l);
    node *sec = l->next;
    printf("\nStudent with econd highest marks");
    printf("\nName: %s",sec->name);
    printf("\nRoll no.: %d\nMarks: %d\n",sec->roll,sec->marks);
}