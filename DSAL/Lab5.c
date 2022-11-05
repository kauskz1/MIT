#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define size 5

typedef struct CHARSTACK{
    char array[size];
    int top;
} charStack;

int char_isEmpty(charStack *stack){
    if(stack->top==-1){
        return 1;
    }
    return 0;
}

int char_isFull(charStack *stack){
    if((stack->top)==size-1){
        return 1;
    }
    else{return 0;}
}

void char_push(charStack *stack){
    if(char_isFull(stack)){
        printf("STACK OVERFLOW:Stack is full!\n");
        return;
    }
    else{
        char ele;
        printf("Enter element: ");
        fflush(stdin);
        scanf(" %c",&ele);
        (stack->array)[++(stack->top)] = ele;
    }
}

char char_pop(charStack *stack){
    if(char_isEmpty(stack)){
        printf("STACK UNDERFLOW:Stack is empty!\n");
    }
    else{
        char temp = (stack->array)[stack->top];
        (stack->array)[(stack->top)--] = '\0';
        printf("Popped %c",temp);
        return temp;
    }
}

int int_isEmpty(int stack){
    return 0;
}

void push(int stack[],int *top,int maxsize,int ele){
    if(*top==maxsize-1){
        printf("Stack full");
        return;
    }
    else{
        stack[++(*top)] = ele;
    }
}

int pop(int stack[],int *top){
    if(*top==-1){
        printf("Empty stack");
    }
    else{
        return stack[(*top)--];
    }
}

int main(void){
    int i,j,q,ch;
    while (1)
    {
        printf("Enter question no.: ");
        scanf("%d",&q);
        if(q==1){
            charStack stack;
            stack.top = -1;
            while(1){
                printf("1:Push\n2:Pop\n3:Display\n4:Exit\n");
                printf("Action: ");
                scanf("%d",&ch);
                if(ch==1){
                    char_push(&stack);
                }
                else if(ch == 2){
                    char_pop(&stack);
                }
                else if(ch == 3){
                    for(i=0;i<size;i++){
                        printf("%c\t",(stack.array)[i]);
                    }
                    printf("\n");
                }
                else{break;}
            }
        }
        else if(q==2){
            printf("Enter the decimal number: ");
            int n;
            scanf("%d",&n);
            /*int digits;
            digits = (int)log10((double)n);
            printf("%d",(int)log10(50));
            printf("%d",digits);*/

            while(n>1){

            }
        }
        else if(q==3){
            char str[99];
            printf("Enter the string");
            scanf("%s",str);
            char s1[strlen(str)],s2[strlen(str)+1];
            int top1=-1, top2 = strlen(str)/2 - 1;
            for(i=0;i<strlen(str)/2;i++){
                break;
            }
        }
        else if(q==4){
            int n,k,top=-1;
            printf("Enter size of array: ");
            scanf("%d",&n);
            int arr[n];
            for(i=0;i<n;i++){
                printf("Enter element: ");
                scanf("%d",&arr[i]);
            }
            for(i=0;i<n;i++){
                printf("%d\t",arr[i]);
            }
            printf("\nEnter k: ");
            scanf("%d",&k);
            int stack[n-k];
            while(k>0){
                for(int i=0;i<n;i++){
                    push(stack,&top,n,arr[i]);
                    if((arr[i]<arr[i+1]) || ( (arr[i+1] < arr[i+2]) && (arr[i]<arr[i+2]) ) ){
                        pop(stack,&top);
                        k--;
                        if(k==0){break;}
                    }
                }
            }
            printf("\n");
            for(i=0;i<n-k;i++){
                printf("%d\t",stack[i]);
            }

        }
        else{break;}
    }
    return 0;
}