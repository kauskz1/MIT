#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    long int phoneNum;
    char *name;
}phoneContact;

void display(phoneContact* arr,int n){
    for(int i=0;i<n;i++){
        printf("Name: %s\n",(arr+i)->name);
        printf("Phone no.: %ld\n", (arr+i)->phoneNum);
    }
}

void Create(phoneContact* arr,int n){
    for(int i=0;i<n;i++){
        printf("Enter phone no.: ");
        scanf("%ld",&(arr+i)->phoneNum);
        printf("Enter name: ");
        (arr+i)->name = (char*)malloc(20);
        scanf("%s", (arr+i)->name);
    }
}

long int FindContact(phoneContact *arr,int n,char *name){
    long int result;
    for(int i=0;i<n;i++){
        if(strcmp(name,(arr+i)->name) == 0){
            result = (arr+i)->phoneNum;
            return result;
        }
    }
    result = -1;
    return result;
}

int main(){
    int n;
    printf("Enter number of entries: ");
    scanf("%d",&n);
    phoneContact *arr = (phoneContact*)calloc(n,sizeof(phoneContact));
    Create(arr,n);
    printf("Displaying contacts:\n");
    display(arr,n);
    char *name1;
    name1 = (char*)malloc(20);
    printf("Enter name to be searched: ");
    scanf("%s",name1);
    long int num = FindContact(arr,n,name1);
    if(num==-1){
        printf("Missing entry");
        arr = realloc(arr,n+1);
        printf("Enter phone no.: ");
        scanf("%ld",&(arr[n].phoneNum));
        n++;
    }
    else{
        printf("Phone no. of searched contact: %ld",num);
    }
    printf("\nDisplaying contacts:\n");
    display(arr,n);
    free(arr);

    return 0;
}
