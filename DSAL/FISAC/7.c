#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct LinkedList* Node;
typedef struct LinkedList{
 char str[20];
 Node next;
}LinkedList;
Node create_Node(){
 Node temp = (Node)malloc(sizeof(LinkedList));
 return temp;
}
Node InsertNode(Node head,char str[]){
 Node temp = create_Node();
 Node tail = create_Node();
 strcpy(temp->str,str);
 temp->next = NULL;
 tail = head;
 if(head == NULL){
 head = temp;
 return head;
 }
 while(tail->next){
 tail = tail->next;
 }
 tail->next = temp;
 return head;
}
Node display(Node head){
 Node temp = create_Node();
 temp = head;
 while(temp){
 printf("%s ",temp->str);
 temp = temp->next;
 }
}
void create_List(Node* List){
 int n;
 char str[20];
 printf("Enter the number of nodes to create: ");
 scanf("%d",&n);
 for(int i = 0; i < n; i++){
 printf("Enter data of Node %d: ",i+1);
 scanf("%s",str);
 *List = InsertNode(*List,str);
 }
}
int isPalin(char str[]){
 int n = strlen(str);
 for(int i = 0; i < n; i++){
 if(str[i] == str[n-i-1]){
 continue;
 }
 else{
 return 0;
 }
 }
 return 1;
}
void Palin_NotPalin_Lists(Node List,Node* List1,Node* List2){
 Node temp = List;
 while(temp != NULL){
 if(isPalin(temp->str)){
 *List1 = InsertNode(*List1,temp->str);
 }
 else{
 *List2 = InsertNode(*List2,temp->str);
 }
 temp = temp->next;
 }
}
int main(){
 Node List = NULL;
 Node PSLIST = NULL;
 Node NPSLIST = NULL;
 create_List(&List);
 Palin_NotPalin_Lists(List,&PSLIST,&NPSLIST);
 printf("\nOriginal List: ");
 display(List);
 printf("\nPalindrome List (PSLIST)\n");
 display(PSLIST);
 printf("\nNon-Palindrome List (NPSLIST)\n");
 display(NPSLIST);
} 
