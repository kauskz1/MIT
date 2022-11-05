package myPackages1.p1;
public class Maximum {
    public static int max(int a,int b,int c){
        return (a>b?(a>c?a:c):(b>c?b:c));
    }
    public static float max(float a,float b,float c){
        return (a>b?(a>c?a:c):(b>c?b:c));
    }
    public static int max(int array[]){
        int m = array[0];
        for(int i:array){
            if(i>m){
                m = i;
            }
        }
        return m;
    }
    public static int max(int matrix[][]){
        int m = matrix[0][0];
        for(int row[]:matrix){
            for(int element:row){
                if(element>m){
                    m = element;
                }
            }
        }
        return m;
    }
}