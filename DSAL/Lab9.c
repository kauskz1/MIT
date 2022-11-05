#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* cnode(){
    return (node*)malloc(sizeof(node));
}

node* createLinkedList(node* head){
    node *ptr,*new;
    int num=0;
    printf("Enter -1 to exit.\n");
    while(num!=-1){
        printf("Enter data: ");
        scanf("%d",&num);
        if(num==-1)break;
        new = cnode();
        new->data = num;
        new->next = NULL;
        if(!head){
            head = new;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next = new;
        }
    }
    return head;
}

void displayList(node* head){
    node *ptr=head;
    while(ptr){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

node* deleteData(node* head,int key){
    node *temp,*ptr;
    
    if(head->data == key){
        temp = head;
        head = head->next;
        free(temp);
    }
    else{
        ptr = head;
        while(ptr->next!=NULL){
            if(ptr->data == key){
                temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
                break;
            }
            else{
                ptr=ptr->next;
            }
        }
    }
    return head;
}

node* deleteNode(node* head,node* nodeToBeDeleted){
    node *temp,*ptr;
    
    if(nodeToBeDeleted == head){
        temp = head;
        head = head->next;
        free(temp);
    }
    else{
        ptr = head;
        while(ptr->next!=NULL){
            if(ptr == nodeToBeDeleted){
                temp = ptr->next;
                ptr->next = ptr->next->next;
                free(temp);
                break;
            }
            else{
                ptr=ptr->next;
            }
        }
    }
    return head;
}

node* listUnion(node* n1,node* n2){
    node *result = cnode();
    node *ptr = n1;
    result = n1;
    while(ptr->next!=NULL){ptr = ptr->next;}
    ptr->next = n2;
    node* ptr2 = result;
    while(ptr2!=NULL){
        result = deleteData(result,ptr2->data);

        ptr2 = ptr2->next;
    }
    return result;
}

node* intersection(node* n1,node* n2){

}

void main(void){
    int q=0;
    node* list=NULL;
    while(q>=0&&q<5){
        printf("Enter question no.: ");
        scanf("%d",&q);
        if(q==1){
            node* list1 = NULL;
            node* list2 = NULL;
            printf("Input first linked list\n");
            list1 = createLinkedList(list1);
            printf("Input second linked list\n");
            list2 = createLinkedList(list2);
            printf("LIST1\n");
            displayList(list1);
            printf("LIST2\n");
            displayList(list2);
            printf("Union of LIST1 and LIST2:\n");
            node* listun = listUnion(list1,list2);
            displayList(listun);
        }
        else if(q==2){

        }
        else if(q==3){

        }
        else if(q==4){

        }
        else{break;}
    }
}