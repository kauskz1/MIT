#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LinkedList* Node;
typedef struct LinkedList{
    char name[20];
    int count;
    Node next;
}LinkedList;
Node create_Node(){
    Node temp = (Node)malloc(sizeof(LinkedList));
    return temp;
}
Node InsertNode(Node head,char name[]){
    Node temp = create_Node();
    Node rear = create_Node();
    rear = head;
    strcpy(temp->name,name);
    temp->count = 1;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return head;
    }
    while(rear->next){
        rear = rear->next;
    }
    rear->next = temp;
    return head;
}
void display(Node head){
    Node temp = create_Node();
    temp = head;
    while(temp){
        printf("{%s} -> ",temp->name);
        temp = temp->next;
    }
}
void mod_display(Node head){
    Node temp = create_Node();
    temp = head;
    while(temp){
        printf("{%s,%d} -> ",temp->name,temp->count);
        temp = temp->next;
    }
}
Node create(Node List){
    int exit = 1;
    char name[20];
    while(exit == 1){
        printf("Enter the Name of Student: ");
        scanf("%s",name);
        List = InsertNode(List,name);
        printf("Enter 0 to Exit or 1 to Continue: ");
        scanf("%d",&exit);
    }
    return List;
}
void Search(Node* List){
    Node curr = create_Node();
    curr = *List;
    Node next = NULL;
    Node prev = NULL;
    while(curr != NULL){
        prev = curr;
        next = curr->next;
        while(next != NULL){
            if(strcmp(curr->name,next->name)==0){
                curr->count++;
                prev->next = next->next;
                free(next);
                next = prev;
            }
            prev = next;
            next = next->next;
        }
    curr = curr->next;
    }
}
int main(){
    Node List = NULL;
    List = create(List);
    printf("List :");
    display(List);
    Search(&List);
    printf("\nAfter modification: ");
    mod_display(List);
}