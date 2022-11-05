import java.util.*;
import java.text.*;

class Student 
{
    int reg_no;
    String name;
    GregorianCalendar date;
    short sem;
    float gpa,cgpa;
    Student() 
    {
        reg_no = 0;
        name = "";
        date = new GregorianCalendar();
        sem = 0;
        gpa = 0.f;
        cgpa = 0.f;
    }
    Student(Student s) 
    {
        this.reg_no = s.reg_no;
        this.name = s.name;
        this.date = s.date;
        this.sem = s.sem;
        this.gpa = s.gpa;
        this.cgpa = s.cgpa;
    }
    public void display() 
    {
        SimpleDateFormat dateFormat = new SimpleDateFormat("DD/MM/YYYY"); 
        System.out.println("\n\t       Name : " + name + 
                           "\n\t     Reg No : " + reg_no + 
                           "\n\tDate Joined : " + dateFormat.format(date.getTime()) +
                           "\n\t   Semester : " + sem + 
                           "\n\t        GPA : " + gpa + 
                           "\n\t       CGPA : " + cgpa + 
                           "\n");
    }
    public void input() 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("\n\tEnter Name: ");
        name = sc.nextLine();
        System.out.print("\tEnter Date Joined (DD/MM/YYYY): ");
        date = new GregorianCalendar(sc.nextInt(), sc.nextInt(), sc.nextInt());
        System.out.print("\tEnter Semester: ");
        sem = sc.nextShort();
        System.out.print("\tEnter GPA: ");
        gpa = sc.nextFloat();
        System.out.print("\tEnter CGPA: ");
        cgpa = sc.nextFloat();
        sc.close();
    }
}
class Students 
{
    Student students[];
    int size;
    public Students(int size) 
    {
        this.size = size;
        this.students = new Student[size];
    }
    public void inputAll() 
    {
        for (int i = 0; i < size; ++i) 
        {
            System.out.println("\t\tStudent " + (i+1) + " :");
            students[i] = new Student();
            students[i].input();
            
            SimpleDateFormat dateFormat = new SimpleDateFormat("YY");
            String reg_no = dateFormat.format(students[i].date.getTime());
            reg_no += String.format( "%02d", i+1);
            students[i].reg_no = Integer.parseInt(reg_no);
        }
    }
    public void displayAll() 
    {
        for (Student stud: students)
        {
            stud.display();
        }
    }
    public void list(String str) 
    {
        for (Student stud: students) 
        {
            if (stud.name.contains(str))
            {
                stud.display();
            }
        }
    }
    public void list(char ch) 
    {
        for (Student stud: students) 
        {
            if (stud.name.indexOf(ch) == 0)
            {
                stud.display();
            }
        }
    }
    public void shortenName() 
    {
        for (Student stud: students) 
        {
            String newName = "";
            String lastName = "";
            StringTokenizer st = new StringTokenizer (stud.name);
            while (st.hasMoreTokens())
            {
                lastName = st.nextToken();
                newName += lastName.charAt(0) + ". ";
            }
            newName = newName.substring(0, newName.length() - 3) + lastName;
            stud.name = newName;
        }
    }
    public void sort(String wrt) 
    {
        for (int i = 0; i < size - 1; ++i) 
        {
            int min = i;
            for (int j = i + 1; j < size; ++j) 
            {
                if ((wrt.equals("sem") && (students[j].sem > students[min].sem))|| 
                (wrt.equals("cgpa") && (students[j].cgpa > students[min].cgpa))||
                (wrt.equals("name") && (students[j].name.compareTo(students[min].name))<0))
                {
                    min = j;
                }
                
            }            if (min != i) 
            {
                Student temp = students[i];
                students[i] = students[min];
                students[min] = temp;
            }
        }
    }
}

public class Lab5 {
    public static Scanner sc = new Scanner(System.in);
    public static GregorianCalendar gCal = new GregorianCalendar();

    /*public static class Student{
        int regno;
        String name;
        GregorianCalendar doj;
        short sem;
        float gpa,cgpa;

        int count=1;
    
        public Student(){
            System.out.print("Enter name: ");
            this.name = sc.nextLine();
            System.out.print("Enter date of joining: ");
            int d = sc.nextInt();
            System.out.print("Enter month of joining: ");
            int m = sc.nextInt();
            System.out.print("Enter year of joining: ");
            int y =sc.nextInt();
            this.doj = new GregorianCalendar(d,m,y);

            System.out.print("Semester: ");
            this.sem = sc.nextShort();
            System.out.print("GPA: ");
            this.gpa = sc.nextFloat();
            System.out.print("CGPA: ");
            this.cgpa = sc.nextFloat();

            regno = 0;
        }
    
        public Student(String name,int d,int m,int y,short sem,float gpa,float cgpa){
            this.name = name;
            doj.set(d,m,y);
            this.sem = sem;this.gpa = gpa;this.cgpa = cgpa;


        }
    
        public void display(){
            System.out.println("Name: "+name);
            System.out.println("Date of joining: " + doj.getTime());
            System.out.println("Semester: "+sem);
            System.out.println("GPA: "+gpa+" CGPA: "+cgpa);
        }
    }*/

    public static void main(String args[]){
        int q;
        while(true){
            System.out.print("Enter question no.: ");
            q = sc.nextInt();
            if(q==1){
                Scanner sc = new Scanner(System.in);
                System.out.print("\n\tEnter the number of records: ");
                int size = sc.nextInt();
                Students students = new Students (size);
                students.inputAll();
                sc.nextLine();
                int choice;
                do 
                {
                    System.out.print("\n\t1. Display Records." + 
                                    "\n\t2. Sort wrt Name." +
                                    "\n\t3. Sort wrt Semester (Desceding)." +
                                    "\n\t4. Sort wrt CGPA (Descending)." +
                                    "\n\t5. List all Students whose name begins with a character." +
                                    "\n\t6. List all Students whose name contains a string." +
                                    "\n\t7. Change the names of all students to shortened form." +
                                    "\n\n\t Enter choice: ");
                    choice = sc.nextInt();
                    switch (choice) 
                    {
                        case 1: 
                        students.displayAll();
                        break;
                        case 2: 
                        students.sort("name");
                        System.out.println("\nSorted wrt Name.\n");
                        students.displayAll();
                        break;
                        case 3: 
                        students.sort("sem");
                        System.out.println("\nSorted wrt Semester.\n");
                        students.displayAll();
                        break;
                        case 4: 
                        students.sort("cgpa");
                        System.out.println("\nSorted wrt CGPA.\n");
                        students.displayAll();
                        break;
                        case 5: 
                        System.out.print("\n\tEnter the character: ");
                        char ch = sc.next().charAt(0);
                        students.list(ch);
                        System.out.println("\n\tAll the student names starting with \' " + ch + "\' : \n");
                        students.displayAll();
                        break;
                        case 6: 
                        System.out.print("\n\tEnter the string: ");
                        String subs = sc.next();
                        students.list(subs);
                        System.out.println("\n\tAll the student names containing \' " + subs + "\' : \n");
                        students.displayAll();
                        break;
                        case 7: 
                        students.shortenName();
                        System.out.println("\n\tShortened Name.\n");
                        students.displayAll();
                        break;
                      }
                }
                while (choice != 8);
                sc.close();
                }
                    else if(q==2){
                        System.out.print("Enter a number: ");
                        String num = sc.next();
                        double n = Double.parseDouble(num);
                        DecimalFormat formatter = new DecimalFormat("#,###");
                        System.out.println("Formatted number = " + formatter.format(n));
                    }
                    else{break;}
                }
        
    }
}