#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void printn(char* s,int n);
void pyramid(void);

typedef struct{
    int top;
    unsigned max;
    int* array;
}Stack;

Stack* newStack(unsigned size);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack,int element);
int pop(Stack* stack);
int peek(Stack* stack);
double evalPrefix(char expr[]);

int main(void)
{
    char expression[] = "+9*26";
    printf("%.2lf",evalPrefix(expression));   
    
    return 0;
}

/*int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdline,int nCmdShow){
    MessageBox(0,"Hi","Title",0);
    return 0;
}*/

void printn(char* s,int n){
    for(int i=0;i<n;i++){
        printf("%s",s);
    }
}
void pyramid(void){
    int n,i,j,num;
    printf("Enter no. of rows: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++){
        num = i;
        printn(" ",2*(n-i));
        printf("%d ",num);
        for(j=i; j < 2*i-1 ; j++){
            printf("%d ",++num);
        }
        for(j=2*i-1 ; j>i; j--){
            printf("%d ",--num);
        }
        printf("\n");
    }
}
Stack* newStack(unsigned size){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->max = size;
    stack->top = -1;
    stack->array = (int*)malloc(size*sizeof(int));
    return stack;
}
int isFull(Stack* stack){
    return stack->top == stack->max - 1;
}
int isEmpty(Stack* stack){
    return stack->top == -1;
}
void push(Stack* stack,int element){
    if(isFull(stack)){
        printf("Stack overflow");
        return;
    }
    stack->array[++stack->top] = element;
    printf("Pushing %d to stack\tTop = %d\n",element,stack->top);
}
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack underflow");
    }
    else{
        return stack->array[stack->top--];
    }
}
int peek(Stack* stack){
    if(isEmpty(stack)){
        printf("Empty stack");
    }
    else{
        return stack->array[stack->top];
    }
}
double evalPrefix(char expr[]){
    int size = strlen(expr),i;
    Stack* stack = newStack(size);

    for(i = size-1 ; i>=0; i--){
        if(isdigit(expr[i])){
            push(stack, (int)expr[i]-'0');
        }
        else{
            int a = pop(stack);
            int b = pop(stack);

            switch(expr[i]){
                case '+':
                push(stack,a+b);
                break;
                case '-':
                push(stack,a-b);
                break;
                case '*':
                push(stack,a*b);
                break;
                case '/':
                push(stack,a/b);
                break;
            }
        }
    }
    return peek(stack);
}
