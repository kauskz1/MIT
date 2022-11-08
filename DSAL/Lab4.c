#include <stdio.h>
#include <string.h>
int fib(int n){
    if(n == 0){return 0;}
    else if(n==1){return 1;}
    else{return fib(n-1)+fib(n-2);}
}

void copy(char *str1, char *str2,int index){
    str2[index] = str1[index];
    if(str1[index] == '\0'){return;}
    copy(str1,str2,index+1);
}

int palin(char* str, int s,int e){
    if(s==e){return 1;}
    if(str[s]!=str[e]){return 0;}

    if(s<e+1){
        return palin(str,s+1,e-1);
    }
    return 1;
}
void check(char word[],int index){
    int len = strlen(word) - (index+1);
    if(word[index] == word[len]){
        if(index+1==len || index==len){
            printf("Palindrome");
            return;
        }
        check(word,index+1);
    }
    else{printf("Not palindrome");}
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main(void){
    int n,i,j,q;
    while(1){
        printf("Enter question no.: ");
        scanf("%d",&q);
        if(q==1){
            printf("Enter value of n: ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                printf("%d ",fib(i));
            }
        }
        else if(q==2){
            char str1[100] = "Welcome to Manipal";
            char str2[100];
            copy(str1,str2,0);
            printf("%s",str2);
        }
        else if(q==3){
            char str[100];
            printf("Enter string: ");
            scanf("%s",str);
            check(str,0);
            /*int isPalin = palin(str,0,strlen(str)-1);
            if(isPalin==1){printf("Palindrome");}
            else if(isPalin==2){printf("Not a palindrome");}*/
        }
        else if(q==4){
            int n = 4;
            towerOfHanoi(n,'A','C','B');
        }
        else{break;}
        printf("\n");
    }

    return 0;
}