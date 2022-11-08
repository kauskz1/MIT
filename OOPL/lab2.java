import java.util.Scanner;

class lab2{
    public static Scanner sc = new Scanner(System.in);
    public static int[] createArray(){
        System.out.print("Enter number of elements in array: ");
        int n = sc.nextInt();
        int array[] = new int[n];
        for(int i=0;i<n;i++){
            System.out.print("Enter element at index "+i+" :");
            array[i] = sc.nextInt();
        }

        return array;
    }

    public static int[] bubbleSort(int[] array,boolean reverse){
        int n = array.length;
        if(!reverse){
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(array[j]>array[j+1]){
                        int temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
                }
            }
        }
        if(reverse){
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-i-1;j++){
                    if(array[j]<array[j+1]){
                        int temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
                }
            }
        }
        System.out.println("The array in "+ (reverse?"descending":"ascending")+" order is:");
        for(int i=0;i<n;i++){
            System.out.print(array[i]+" ");
        }

        return array;
    }

    public static int[][] createMatrix(int n,int m){
        int matrix[][] = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                System.out.print("Enter element at row "+i+" column "+j+": ");
                matrix[i][j] = sc.nextInt();
            }
        }
        System.out.println("The matrix is:");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                System.out.print(matrix[i][j]+"\t");
            }
            System.out.print("\n");
        }

        return matrix;
    }

	public static void main(String args[]){
        while(true){
            System.out.print("Enter question no.: ");
            int q = sc.nextInt();
            
            if(q==1){
                int arr[] = createArray();
                System.out.print("Ascending or descending? a/d: ");
                char order = sc.next().charAt(0);
                if(order=='a'){
                    bubbleSort(arr, false);
                }
                else if(order=='d' || order=='D'){
                    bubbleSort(arr, true);
                }
            }
            else if(q==2){
                System.out.print("Enter number of elements in array: ");
                int n = sc.nextInt();
                int arr[] = new int[n+1];
                for(int i=0;i<n;i++){
                    System.out.print("Enter element at index "+i+" :");
                    arr[i] = sc.nextInt();
                }

                System.out.print("Enter index to insert element at: ");
                int pos1 = sc.nextInt();
                System.out.print("Enter the element to be inserted: ");
                int ele = sc.nextInt();

                for(int i=n-1;i>=pos1;i--){
                    arr[i+1] = arr[i];
                }
                arr[pos1] = ele;
                System.out.println("The modified array is:");
                for(int i=0;i<arr.length;i++){
                    System.out.print(arr[i]+" ");
                }

                System.out.print("Enter position at which you want to delete element: ");
                int pos2 = sc.nextInt();
                for(int i = pos2 ; i<arr.length-1 ;i++){
                    arr[i] = arr[i+1];
                }

                System.out.println("The modified array is:");
                for(int i=0;i<arr.length-1;i++){
                    System.out.print(arr[i]+" ");
                }
            }
            else if(q==3){
                int arr[] = createArray();
                System.out.print("Enter element to be searched: ");
                int ele = sc.nextInt();
                int flag = 0;
                for(int i= 0;i<arr.length;i++){
                    if(arr[i]==ele){
                        System.out.print("The element is at index: "+i);
                        flag = 1;
                        break;
                    }
                }
                if(flag==0){System.out.println("Element does not exist in array.");}
            }
            else if(q==4){
                System.out.print("Enter number of rows of matrix: ");
                int rows1 = sc.nextInt();
                System.out.print("Enter number of columns of matrix: ");
                int columns1 = sc.nextInt();
                int mat1[][] = createMatrix(rows1, columns1);

                System.out.print("Enter number of rows of matrix: ");
                int rows2 = sc.nextInt();
                System.out.print("Enter number of columns of matrix: ");
                int columns2 = sc.nextInt();
                int mat2[][] = createMatrix(rows2, columns2);

                int newMatrix[][] = new int[rows1][columns1];
                if(rows1==rows2 && columns1==columns2){
                    for(int i=0;i<rows1;i++){
                        for(int j=0;j<columns1;j++){
                            newMatrix[i][j] = mat1[i][j] + mat2[i][j];
                        }
                    }
                    System.out.println("The matrix after addition is:");
                    for(int i=0;i<rows1;i++){
                        for(int j=0;j<columns1;j++){
                            System.out.print(newMatrix[i][j]+"\t");
                        }
                        System.out.print("\n");
                    }
                }
                else{
                    System.out.println("The dimensions of the 2 matrices are different.");
                }
            }
            else{break;}
            System.out.print("\n");
        }
        sc.close();
	}
}