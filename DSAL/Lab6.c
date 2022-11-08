#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct{
    int top;
    unsigned max;
    int* array;
}Stack;

typedef struct{
    int top;
    unsigned max;
    char* array;
}CharStack;

Stack* newStack(unsigned size);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack,int element);
int pop(Stack* stack);
int peek(Stack* stack);
double evalPrefix(char expr[]);

int char_getPriority(char c);
int char_isEmpty(CharStack* stack);
int char_isFull(CharStack* stack);
void char_push(CharStack* stack,char element);
char char_pop(CharStack* stack);
char char_peek(CharStack* stack);

char* infixToPostfix(char expr[]);
char* infixToPrefix(char expr[]);
char *strrev(char *str);


int main(void)
{
    int i,q,exit=0;
    
    while(!exit){
        printf("Question no.: ");
        scanf("%d",&q);
        if(q==1){
            char expr[100];
            printf("Enter prefix expression: ");
            scanf("%s",expr);
            printf("%.2lf",evalPrefix(expr));
        }
        else if(q==2){
            char expr[100];
            printf("Enter infix expression: ");
            scanf("%s",expr);
            int len = strlen(expr);
            
            printf("%s",infixToPostfix(expr));
        }
        else if(q==3){
            
        }
        else if(q==4){

        }
        else{
            printf("Exitting program");
            exit=1;
            break;
        }
        printf("\n");
    }
    return 0;
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

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int char_isFull(CharStack* stack){
    return stack->top == stack->max - 1;
}
int char_isEmpty(CharStack* stack){
    return stack->top == -1;
}
void char_push(CharStack* stack,char element){
    if(char_isFull(stack)){
        printf("Stack overflow");
        return;
    }
    stack->array[++stack->top] = element;
    printf("Pushing %d to stack\tTop = %d\n",element,stack->top);
}
char char_pop(CharStack* stack){
    if(char_isEmpty(stack)){
        printf("Stack underflow");
    }
    else{
        return stack->array[stack->top--];
    }
}
char char_peek(CharStack* stack){
    if(char_isEmpty(stack)){
        printf("Empty stack");
    }
    else{
        return stack->array[stack->top];
    }
}
CharStack* newExpression(unsigned size){
    CharStack* expr = (CharStack*)malloc(sizeof(CharStack));
    expr->max = size;
    expr->top = -1;
    expr->array = (char*)malloc(size*sizeof(char));
    return expr;
}
int getPriority(char c){
    if(c=='+' || c=='-')return 1;
    else if(c=='*'||c=='/')return 2;
    else if(c=='^')return 3;
    return 0;
}
char* infixToPostfix(char expr[]){
    int i,l = strlen(expr);
    char temp,*result="";
    CharStack* stack = newExpression(l);
    char c;
    strrev(expr);
    for(i=0;i<l;i++){
        c = expr[i];
        if(isalnum(c)){
            strncat(result,&c,1);
        }
        else if(c=='('){
            char_push(stack,c);
        }
        else if(c==')'){
            while(char_peek(stack) != '('){
                strncat(result,&char_pop(stack),1);
            }
            char_pop(stack);
        }
        else{
            while(getPriority(c)<getPriority(char_peek(stack))){
                strncat(result,&char_pop(stack),1);
            }
            char_push(stack,c);
        }
    }
    while(!char_isEmpty(stack)){
        strncat(result,&(char_peek(stack)),1);
        char_pop(stack);
    }
    return result;
}
char* infixToPrefix(char expr[]){

}