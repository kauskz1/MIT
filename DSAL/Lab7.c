#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int front,rear,size;
    char **str;
}strqueue;

int strisEmpty(strqueue *q){
  if (q->front == -1) return 1;
  return 0;
}

int strisFull(strqueue *q){
    if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == q->size - 1)) return 1;
    return 0;
}

void strinsertcq(strqueue *q,char* ele){
    if(strisFull(q)){
        printf("\nQueue is full.");
        return;
    }
    else{
        if(q->front==-1)
            q->front=0;
        q->rear = (q->rear+1) % q->size;
        q->str[q->rear] = (char*)malloc(20);
        q->str[q->rear] = ele;
        printf("\nInserted %s",ele);
    }
}

char* strdeletecq(strqueue *q){
    char *del;
    if(strisEmpty(q)){
        printf("\nQueue is empty.");
    }
    else{
        del = q->str[q->front];
        if(q->front==q->rear){
            q->front = q->rear =-1;
        }
        else{
            q->front = (q->front+1)%q->size;
        }
        printf("\nDeleted element: %s",del);
        return del;
    }
}

void strdisplaycq(strqueue *q){
    if(strisEmpty(q)){
        printf("Empty queue");
        return;
    }
    for(int i=q->front ; i<q->rear ; i=(i+1)%q->size){
        printf("%s\t", q->str[i]);
    }
}

void main(void){
    int ques,ch,num;
    printf("Enter question no.: ");
    scanf("%d",&ques);
    char *s = (char*)malloc(20);
    while(1){
        if(ques==1){
            strqueue *q = (strqueue*)malloc(sizeof(strqueue));
            q->rear = -1;q->front = -1;
            q->size = 5;
            q->str = (char**)calloc(q->size,20);
            while(1){
                printf("\n1.Insert\n2.Delete\n3.Display");
                printf("\n%d %d",q->rear,q->front);
                printf("\nEnter option: ");
                scanf("%d",&ch);
                if(ch==1){
                    printf("Enter element: ");
                    scanf("%s",s);
                    strinsertcq(q,s);
                }
                else if(ch==2){
                    strdeletecq(q);

                }
                else if(ch==3){
                    printf("Displaying queue:\n");
                    strdisplaycq(q);
                }
                else{break;}
                printf("%s",q->str[0]);
            }
        }
        else if(ques==2){

        }
        else if(ques==3){

        }
        else if(ques==4){

        }
        else{break;}
    }
}