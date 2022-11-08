#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* nodeptr;
typedef struct{
    char data;
    nodeptr next;
}node;
node* display(node* linkedList)
{
    if(linkedList==NULL)
    {
        printf("Linked List empty \n");
        return linkedList;
    }
    node* ptr;
    ptr=linkedList;
    while(ptr->next!=NULL)
    {
        printf("%c ,",ptr->data);
        ptr=ptr->next;
    }
    printf("%c\n",ptr->data);
    return linkedList;
    }
node* insert(node* linkedList,char m)
{
    node* newnode;
    node* ptr;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=m;
    if(linkedList==NULL)
    {
        newnode->next=NULL;
        linkedList=newnode;
    }
    else{
        ptr=linkedList;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
    }
    return linkedList;
}
void allVowels(node* linkedList)
{
    node* ptr;
    node* pre;
    ptr=linkedList;
    pre=linkedList;
    if(linkedList->data=='a'|| linkedList->data=='e'|| linkedList->data=='i'|| linkedList->data=='o'|| linkedList->data=='u'|| linkedList->data=='A' || linkedList->data=='E'|| linkedList->data=='I'|| linkedList->data=='O'|| linkedList->data=='U'){

    linkedList=linkedList->next;}
    while(ptr->next!=NULL)
    {
    if(ptr->data=='a'|| ptr->data=='e'|| ptr->data=='i'|| ptr->data=='o'|| ptr->data=='u'|| ptr->data=='A' || ptr->data=='E'|| ptr->data=='I'|| ptr->data=='O'|| ptr->data=='U'){

    pre->next=ptr->next;}
    pre=ptr;
    ptr=ptr->next;
    }
    printf("New Linked List is:\n");
    linkedList=display(linkedList);
    return;
}
int main()
{
    node* linkedList;
    linkedList=(node*)malloc(sizeof(node));
    linkedList=NULL;
    char ch[100];
    printf("Enter your name:\n");
    scanf("%s",&ch);
    for(int i=0;i<strlen(ch);i++)
    linkedList=insert(linkedList,ch[i]);
    printf("Name in Linked List is:\n");
    linkedList=display(linkedList);
    allVowels(linkedList);
} 