import java.util.Scanner;
import java.util.ArrayList;

class Stack<T>{
    ArrayList<T> s;
    int top = -1;
    int size;

    Stack(int n){
        size = n;
        s = new ArrayList<T>(size);
    }

    void push(T x){
        if(top++ == size){System.out.println("Stack overflow");return;}
        if(s.size()>top)s.set(top,x);
        else s.add(x);
    }
    T pop(){
        if(top==-1){System.out.println("Stack underflow");return null;}
        else{
            T data = s.get(top);
            s.remove(top--);
            return data;
        }
    }
    void display(){
        for(T i:s){
            if((i.getClass().getName() == "student")){
                ((student) i).display();
            }
            if((i.getClass().getName() == "Employee")){
                ((Employee) i).display();
            }
        }
    }
}

class student{
    String name;
    int rollno;
    student(String n,int r){
        name =n;
        rollno=r;
    }
    public void display(){
        System.out.println("Name: "+name);
        System.out.println("Roll no.: "+rollno);
    }
}

class Employee{
    String name;
    int id;
    Employee(String n,int i){
        name =n;
        id =i;  
    }
    void display(){
        System.out.println("Name: "+name);
        System.out.println("Id: "+id);
    }
}

class node<T>{
    T data;
    node<T> next;
    
    node(T data){
        this.data = data;
        next = null;
    }
}

class list<T>{
    node <T> head;
    list(){
        head = null;
    }

    void insertNode(T data){
        node<T> node1 = new node<T>(data);
        if(head==null)head=node1;
        else{
            node<T> list = head;
            while(list.next!=null)list=list.next;
            list.next = node1;
        }
    }

    void display(){
        node<T> node1 = head;
        while(node1!=null){
            System.out.print(node1.data+"\t");
            node1=node1.next;
        }
    }
}

public class Lab10 {
    static <T> void print(T x){System.out.print(x);}
    static <T> void println(T x){System.out.println(x);}
    static Scanner sc = new Scanner(System.in);

    static <T> void exchange(T arr[],int a,int b){
        T temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    static <T> void display(T arr[]){
        for(T i:arr){
            print(i+"\t");
        }
        print("\n");
    }

    public static void main(String args[]){
        while(true){
            print("Question no.: ");
            int q = sc.nextInt(),n,ch=0;
            if(q==1){
                println("Choose type of array");
                String t = sc.next();                
                print("Enter no. of elements in array: ");
                n = sc.nextInt();
                if(t.equalsIgnoreCase("integer")){
                    Integer arr[] = new Integer[n];
                    for(int i=0;i<n;i++){
                        print("Enter element at index "+i+": ");
                        arr[i] = sc.nextInt();
                    }
                    print("Enter index to swap: ");
                    int a=sc.nextInt(),b=sc.nextInt();
                    println("Original array:");
                    display(arr);
                    exchange(arr,a,b);
                    println("New array:");
                    display(arr);
                }
                else if(t.equalsIgnoreCase("string")){
                    String arr[] = new String[n];
                    for(int i=0;i<n;i++){
                        print("Enter element at index "+i+": ");
                        arr[i] = sc.next();
                    }
                    print("Enter index to swap: ");
                    int a=sc.nextInt(),b=sc.nextInt();
                    println("Original array:");
                    display(arr);
                    exchange(arr,a,b);
                    println("New array:");
                    display(arr);
                }
                else if(t.equalsIgnoreCase("double")){
                    Double arr[] = new Double[n];
                    for(int i=0;i<n;i++){
                        print("Enter element at index "+i+": ");
                        arr[i] = sc.nextDouble();
                    }
                    print("Enter index to swap: ");
                    int a=sc.nextInt(),b=sc.nextInt();
                    println("Original array:");
                    display(arr);
                    exchange(arr,a,b);
                    println("New array:");
                    display(arr);
                }
            }
            else if(q==2){
                print("Enter Stack size: ");
                n = sc.nextInt();
                Stack<student> studentStack = new Stack<>(n);
                Stack<Employee> employeeStack = new Stack<>(n);
                student temp1;
                Employee temp2;
                while(ch!=-1){
                    println("1.Push Student\n2.Pop Student\n3.Push Employee\n4.Pop Employee\n5.Display");
                    ch = sc.nextInt();
                    if (ch == 1) {
                        System.out.print("Enter student's name ");
                        String t = sc.next();
                        System.out.print("Enter student's roll number ");
                        temp1 = new student(t, sc.nextInt());
                        studentStack.push(temp1);
                    }
                    else if (ch == 2) {
                        temp1 = studentStack.pop();
                        if(temp1!=null)System.out.println("Popped: Name: "+temp1.name+"\tRoll No: "+temp1.rollno);
                    }
                    else if (ch == 3) {
                        System.out.print("Enter employee's name ");
                        String t = sc.next();
                        System.out.print("Enter employee's id ");
                        temp2 = new Employee(t, sc.nextInt());
                        employeeStack.push(temp2);
                    }
                    else if (ch == 4) {
                        temp2 = employeeStack.pop();
                        if(temp2!=null)System.out.println("Popped: Name: "+temp2.name+"\tRoll No: "+temp2.id);
                    }
                    else if(ch == 5){
                        println("Student stack:");
                        studentStack.display();
                        println("Employee stack:");
                        employeeStack.display();
                    }
                    else{ch=-1;break;}
                }
            }
            else if(q==3){
                println("1.Integer linked list\n2.String linked list");
                int type = sc.nextInt();
                print("Enter length of linked list: ");
                n = sc.nextInt();
                if(type==1){
                    list<Integer> list1 = new list<>();
                    for(int i=0;i<n;i++){
                        print("Enter data: ");
                        list1.insertNode(sc.nextInt());
                    }
                    println("Linked list:");
                    list1.display();
                }
                else if(type==2){
                    list<String> list1 = new list<>();
                    for(int i=0;i<n;i++){
                        print("Enter data: ");
                        list1.insertNode(sc.next());
                    }
                    println("Linked list:");
                    list1.display();
                }
                else{print("Invalid");}
            }
            else if(q==4){

            }
            else{q=-1;break;}
        }
        sc.close();
    }
}