import java.util.*;
import myPackages1.p1.*;

interface Series{
    int getNext();
    void reset();
    void setStart(int x);
}

class ByTwos implements Series{
    int num=0;
    public int getNext(){
        num+=2;
        return num;
    }
    public void reset(){
        num=0;
    }
    public void setStart(int x){
        num=x;
    }
}

class Student{
    public int rollno,marks;
    static Scanner sc = new Scanner(System.in);
    public int putNumber(){return rollno;}
    public void getNumber(){
        System.out.print("Enter roll no.: ");
        rollno = sc.nextInt();
    }
    public int putMarks(){return marks;}
    public void getMarks(){
        System.out.print("Enter marks: ");
        marks = sc.nextInt();
    }
}

interface Sports{
    char putGrade();
}

class Result extends Student implements Sports{
    char grade;
    static Scanner sc = new Scanner(System.in);
    public char putGrade(){return grade;}
    public void getGrade(){
        System.out.print("Enter marks: ");
        grade = sc.next().charAt(0);
    }
    public void printResult(){
        System.out.println(this.putNumber()+" Final results\nMarks: "+this.putMarks()+"\nGrade: "+ this.putGrade());
    }
}

public class Lab7 {
    static void println(String x){
        System.out.println(x);
    }
    static void print(String x){
        System.out.print(x);
    }
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[]){
        int q,ch,a,b,c,n,i,j;
        while(true){
            print("Enter question no.: ");
            q = sc.nextInt();
            if(q==1){
                Building b1 = new Building();
                b1.setSqFoot(500);
                b1.setStories(4);
                println("Building is "+b1.getSqFoot()+"ft and has "+b1.getStories()+" stories");

                House h = new House();
                h.setBathR(2);
                h.setBedR(4);
                println("House has "+h.getBedR()+" bedrooms and "+h.getBathR()+" bathrooms");

                School s = new School();
                s.setClassR(15);
                s.setGrade("Elementary");
                println(s.getGrade()+" school has "+s.getClassR()+" classrooms");
            }
            else if(q==2){
                println("1.Integers\n2.Floats\n3.Array\n4.Matrix");
                print("Enter choice: ");
                ch = sc.nextInt();
                switch(ch){
                    case 1:
                    print("Enter 3 integers: ");
                    a=sc.nextInt();b=sc.nextInt();c=sc.nextInt();
                    println("Max = "+Maximum.max(a,b,c));
                    break;

                    case 2:
                    print("Enter 3 floats: ");
                    float f1=sc.nextFloat(),f2=sc.nextFloat(),f3=sc.nextFloat();
                    println("Max = "+Maximum.max(f1,f2,f3));
                    break;
                    
                    case 3:
                    print("Enter size of array:");
                    n=sc.nextInt();
                    int array[] = new int[n];
                    for(i=0;i<n;i++){
                        print("Enter element at index "+i+": ");
                        array[i]=sc.nextInt();
                    }
                    println("Max = "+Maximum.max(array));
                    break;

                    case 4:
                    print("Enter rows of matrix:");
                    int r=sc.nextInt();
                    print("Enter columns of matrix:");
                    c=sc.nextInt();
                    int matrix[][] = new int[r][c];
                    for(i=0;i<r;i++){
                        for(j=0;j<c;j++){
                            matrix[i][j]=sc.nextInt();
                        }
                    }
                    println("Max = "+Maximum.max(matrix));
                    break;
                }
            }
            else if(q==3){
                ByTwos s1 = new ByTwos();
                s1.setStart(2);
                for(i=0;i<10;i++){
                    print(Integer.toString(s1.getNext())+"\t");
                    if(i==7)s1.reset();
                }
            }
            else if(q==4){
                Result result = new Result();
                result.getNumber();
                result.getMarks();
                result.getGrade();
                result.printResult();
            }
        }    
    }
}
