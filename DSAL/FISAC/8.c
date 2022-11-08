#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct LinkedList* Node;
typedef struct LinkedList{
    int data;
    Node next;
}LinkedList;
Node create_Node(){
    Node temp = (Node)malloc(sizeof(LinkedList));
    return temp;
}
Node InsertNode(Node head,int val){
    Node temp = create_Node();
    Node end = create_Node();
    temp->data = val;
    temp->next = NULL;
    end = head;
    if(head == NULL){
        head = temp;
        return head;
    }
    while(end->next){
        end = end->next;
    }
    end->next = temp;
    return head;
}
void display(Node head){
    Node temp = create_Node();
    temp = head;
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
void create_List(Node* List){
    int n;
    int val;
    printf("Enter the number of nodes to create: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        printf("Enter data of Node %d: ",i+1);
        scanf("%d",&val);
        *List = InsertNode(*List,val);
    }
}
void Odd_Even_Lists(Node List,Node* List1,Node* List2){
    Node temp = create_Node();
    temp = List;
    int num = 1;
    while(temp != NULL){
        if(num % 2 == 0){
            *List2 = InsertNode(*List2,temp->data);
        }
        else{
            *List1 = InsertNode(*List1,temp->data);
        }
        num++;
        temp = temp->next;
    }
}
int main(){
    Node List = NULL;
    create_List(&List);
    printf("Nodes of original list:\n");
    display(List);
    Node List1 = NULL;
    Node List2 = NULL;
    Odd_Even_Lists(List,&List1,&List2);
    printf("\nDisplaying the elements of LIST-1 followed by LIST-2\n");
    printf("List 1: ");
    display(List1);
    printf("\nList 2: ");
    display(List2);
}