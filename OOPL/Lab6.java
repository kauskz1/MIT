import java.util.*;

class Date{
    public int day,month,year;
}

class Person{
    private String name;
    //private Date birthDate;
    private int day,month,year;
    
    public Person(String name,int day,int month,int year){
        this.name = name;
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public Person(){
        //name="";
        //birthDate.day=birthDate.month=birthDate.year=0;
    }

    void setName(String name){
        this.name = name;
    }

    void setDate(int d,int m,int y){
        this.day = d;
        this.month = m;
        this.year = y;
    }

    String getName(){
        return name;
    }

    int[] getDOB(){
        int dob[] = {day,month,year};
        return dob;
    }
}

class CollegeGraduate extends Person{
    private double cgpa;
    private int yearOfGraduation;

    public CollegeGraduate(String name,int d,int m,int y,double cgpa,int year){
        setName(name);
        setDate(d,m,y);
        this.cgpa = cgpa;
        this.yearOfGraduation = year;
    }

    double getCgpa(){
        return cgpa;
    }

    int getYearOfGraduation(){
        return yearOfGraduation;
    }
}

class Building{
    private int sqFoot,stories;

    void setSqFoot(int x){
        sqFoot = x;
    }
    void setStories(int s){
        stories = s;
    }
    int getSqFoot(){
        return sqFoot;
    }
    int getStories(){
        return stories;
    }
}

class House extends Building{
    private int bedR,bathR;

    void setBedR(int x){
        bedR = x;
    }
    void setBathR(int x){
        bathR = x;
    }
    int getBedR(){
        return bedR;
    }
    int getBathR(){
        return bathR;
    }
}

class School extends Building{
    private int classR;
    private String grade;
    void setClassR(int x){
        classR = x;
    }
    void setGrade(String x){
        grade = x;
    }
    int getClassR(){
        return classR;
    }
    String getGrade(){
        return grade;
    }
}

abstract class Figure{
    int x,y;
    abstract double area();
}

class Rectangle extends Figure{
    Rectangle(int a,int b){
        this.x = a;
        this.y = b;
    }
    double area(){return this.x*this.y;}
}

class Square extends Figure{
    Square(int a){
        this.x = this.y = a;
    }
    double area(){return this.x*this.x;}
}

class Triangle extends Figure{
    Triangle(int b,int h){
        this.x = b;
        this.y = h;
    }
    double area(){return this.x/2*this.y;}
}

public class Lab6 {
    static Scanner sc = new Scanner(System.in);

    static void println(String s){
        System.out.println(s);
    }
    static void print(String s){
        System.out.print(s);
    }
    public static void main(String args[]){
        int q;
        outer:while(true){
            print("Question no.: ");
            q = sc.nextInt();
            switch(q){
                case 1: 
                CollegeGraduate person = new CollegeGraduate("A", 5, 3, 2003,9.5,2025);
                println("Name: " + person.getName());
                println("DOB: " + person.getDOB()[0] + "/" + person.getDOB()[1] + "/" + person.getDOB()[2]);
                println("CGPA: " + person.getCgpa());
                println("Year of Graduation: " + person.getYearOfGraduation());

                Person p = new Person();
                p.setDate(1,1,1);
                p.setName("ABC");
                println("Name:" + p.getName() +" was born on " + p.getDOB()[0]+"/"+p.getDOB()[1]+"/"+p.getDOB()[2]);
                break;

                case 2:
                Building b = new Building();
                b.setSqFoot(1000);
                b.setStories(5);
                println("Building is "+b.getSqFoot()+"ft and has "+b.getStories()+" stories");

                House h = new House();
                h.setBedR(4);
                h.setBathR(2);
                println("House has "+h.getBedR()+"bedrooms and "+h.getBathR()+" bathrooms");

                School s = new School();
                s.setClassR(20);
                s.setGrade("Elementary");
                println(s.getGrade()+" school has "+s.getClassR()+" classrooms");
                break;

                case 3:
                //Rectangle r = new Rectangle(10,20);
                //Figure.area();
                break;

                case 4:

                break;

                default:
                break outer;
            }
        }
    }
}