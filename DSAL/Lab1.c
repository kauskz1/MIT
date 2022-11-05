#include <stdio.h>

double Add(double arr[],int n){
	int i;
	double sum=0;

	for(i=0;i<n;i++){
		sum+= arr[i];
	}
	return sum;
}

int Lsearch(int arr[],int n,int ele){
	int i,pos;
	for(i=0;i<n;i++){
		if(arr[i]==ele){
			return i;
		}
	}
}

int secLargest(int arr[],int n){
	int i,largest,secondLargest;
	largest = arr[0];
	secondLargest = arr[0];
	for(i=1;i<n;i++){
		if(arr[i]>largest){
			secondLargest = largest;
			largest = arr[i];
		}
		else if(arr[i]>secondLargest){
			secondLargest = arr[i];
		}
	}
	return secondLargest;
}

int mMatrix(int r1,int c1,int arr1[r1][c1],int r2,int c2,int arr2[r2][c2]){
	int newArr[r1][c2],i,j,k;
	if(c1 != r2){
		printf("Cannot multiply these matrices.");
		return 1;
	}


	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			newArr[i][j] = 0;
			for(k=0;k<c1;k++){
				newArr[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}

	printf("Product of the 2 matrices:\n");
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			printf("%d\t",newArr[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	int q,i,j,n,element;

	while(1){
		printf("Question no.: ");
		scanf("%d",&q);
		if(q==1){
			printf("Enter number of elements: ");
			scanf("%d",&n);
			double arr[n];
			for(i=0;i<n;i++){
				printf("Enter element: ");
				scanf("%lf",&arr[i]);
			}
			printf("Sum of elements in array = %.2lf",Add(arr,n));
		}

		else if(q==2){
			printf("Enter number of elements: ");
			scanf("%d",&n);
			int arr[n];
			for(i=0;i<n;i++){
				printf("Enter element: ");
				scanf("%d",&arr[i]);
			}
			printf("Element to be searched for: ");
			scanf("%d",&element);
			if(Lsearch(arr,n,element)){printf("The element %d is present at index: %d",element, Lsearch(arr,n,element));}
			else{printf("Element %d does not exist in the array",element);}	
		}
		else if(q==3){
			int r1,c1,r2,c2;
			printf("Enter no. of rows of first matrix: ");
			scanf("%d",&r1);
			printf("Enter no. of columns of first matrix: ");
			scanf("%d",&c1);
			int arr1[r1][c1];
			for(i=0;i<r1;i++){
				for(j=0;j<c1;j++){
					printf("Enter element at row %d and column %d: ",i,j);
					scanf("%d",&arr1[i][j]);
				}
			}
			printf("Enter no. of rows of second matrix: ");
			scanf("%d",&r2);
			printf("Enter no. of columns of second matrix: ");
			scanf("%d",&c2);
			int arr2[r2][c2];
			for(i=0;i<r2;i++){
				for(j=0;j<c2;j++){
					printf("Enter element at row %d and column %d: ",i,j);
					scanf("%d",&arr2[i][j]);
				}
			}

			printf("1st matrix:\n");
			for(i=0;i<r1;i++){
				for(j=0;j<c1;j++){
					printf("%d\t",arr1[i][j]);
				}
				printf("\n");
			}
			printf("2nd matrix\n");
			for(i=0;i<r2;i++){
				for(j=0;j<c2;j++){
					printf("%d\t",arr2[i][j]);
				}
				printf("\n");
			}

			mMatrix(r1,c1,arr1,r2,c2,arr2);
		}
		else if(q==4){
			printf("Enter number of elements: ");
			scanf("%d",&n);
			int arr[n];
			for(i=0;i<n;i++){
				printf("Enter element: ");
				scanf("%d",&arr[i]);
			}
			printf("2nd Largest element: %d",secLargest(arr,n));
		}
		else{
			printf("Exitting program\n");
			break;
		}
		printf("\n");
	}

	return 0;
}