#include <stdio.h>
#include <stdlib.h>

void Reverse(int *num,int n){
    int i,temp;
    int *first;
    int *last = (num+n-1);
    for(first=num;first<=last ; first++,last--){
        temp = *last;
        *last = *first;
        *first = temp;
    }
    for(i=0;i<n;i++){
        printf("%d",num[i]);
    }
}

int Smallest(int* array,int n){
    int smallest = *array;

    for(int i=0; i<n; i++){
        if(smallest>array[i]){
            smallest = array[i];
        }
    }

    return smallest;
}

void add(int *a,int *b){
    printf("%d",*a+*b);
}

int* biggest(int a,int b,int c){
    int bigVar = (a>b?(a>c?a:c):(b>c)?b:c);
    int *big = &bigVar;
    return big;
}

int main(void){
    int q,i,n;
    while(1){
        printf("Enter question no.: ");
        scanf("%d",&q);
        if(q==1){
            printf("Enter the length: ");
            scanf("%d",&n);
            int arr[n];
            for(int i=0;i<n;i++){
                printf("Enter element at index %d: ",i);
                scanf("%d",&arr[i]);
            }
            Reverse(arr,n);            
        }
        else if(q==2){
            printf("Enter the length: ");
            scanf("%d",&n);
            int *arr = (int*)calloc(n,sizeof(int));
            for(int i=0;i<n;i++){
                printf("Enter element at index %d: ",i);
                scanf("%d",&arr[i]);
            }
            int smallest = Smallest(arr,n);
            printf("Smallest element is %d",smallest);
        }
        else if(q==3){
            int x = 5,y=10,z=20;
            int *px = &x,*py = &y, *pz = &z;
            int **ppx = &px;
            add(px,py);
            printf("\nBiggest number is: %d",*biggest(x,y,z));
            printf("\nx = %d\npointer to x = %p\npointer to pointer to x = %p",x,px,ppx);
        }
        else if(q==4){
            int j;
            int r1,r2,c1,c2;
            printf("Enter number of rows and columns: ");
            scanf("%d %d",&r1,&c1);
            int *m1 = (int*)calloc(r1,sizeof(int));
            int *m2 = (int*)calloc(r2,sizeof(int));
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    m1 = (int*)calloc(c1,sizeof(int));
                    printf("Row %d Column %d : ",i,j);
                    scanf("%d",(m1+i)+j);
                }
            }
            for(i=0;i<r1;i++){
                for(j=0;j<c1;j++){
                    m1 = (int*)calloc(c1,sizeof(int));
                    printf("Row %d Column %d : ",i,j);
                    scanf("%d",(m1+i)+j);
                }
            }
        }
        else{
            printf("Exitting");
            break;
        }
        printf("\n");
    }

    return 0;
}