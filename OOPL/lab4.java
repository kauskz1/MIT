import java.util.Random;
import java.util.Scanner;

public class lab4 {
    public static Scanner sc = new Scanner(System.in);

    public static class Complex{
        double real;
        double img;

        public Complex(){
            real = 0;
            img = 0;
        }

        public Complex(double real,double img){
            this.real = real;
            this.img = img;
        }
        
        public void display(){
            System.out.println(real+" + i"+img);
        }
    }

    public static class Time{
        int hours,mins,secs;

        public Time(){
            hours = mins = secs = 00;
        }

        public Time(int h,int m,int s){
            hours = h;
            mins = m;
            secs = s;
        }

        public void display(){
            System.out.println(hours+":"+mins+":"+secs);
        }
    }
    
    public static class Account{
        String name;
        int accountNo;
        String type;
        float balance;
        static float rate;

        public Account(String n,int no,String t,float b,float r){
            this.name = n;
            this.accountNo = no;
            this.type = t;
            this.balance = b;
            rate = r;
        }

        public void deposit(float amount){
            if(amount>=0){
                this.balance += amount;
                System.out.println("Depositing Rs."+amount);
            }
        }

        public void withdraw(float amount){
            if(balance < amount){
                System.out.println("Not enough balance.");
            }
            else{
                this.balance -= amount;
                System.out.println("Withdrawing Rs."+amount);
            }
        }

        public void display(){
            System.out.println("Name: "+ this.name);
            System.out.println("Account No.: "+this.accountNo);
            System.out.println("Type: "+this.type);
            System.out.println("Balance: Rs."+this.balance);
            System.out.println("Rate of interest: "+ rate +"%");
        }

        static public void displayRate(){
            System.out.println("Rate of interest = "+rate+"%");
        }
    }

    public static class Counter{
        static int count = 0;

        public Counter(){
            System.out.println("New Counter created");
            count++;
        }

        static public void showCount(){
            System.out.println("Count = " + count);
        }
    }

    public static void main(String args[]){
        while(true){
            System.out.print("Enter question no.: ");
            int q = sc.nextInt();

            if(q==1){
                System.out.print("Enter value of real part: ");
                double a = sc.nextDouble();
                System.out.print("Enter value of imaginary part: ");
                double b = sc.nextDouble();
                Complex com1 = new Complex(a,b);
                com1.display();

                System.out.print("Enter value of real part: ");
                double c = sc.nextDouble();
                System.out.print("Enter value of imaginary part: ");
                double d = sc.nextDouble();
                Complex com2 = new Complex(c,d);
                com2.display();
                
                
                
            }
            else if(q==2){
                Time time1 = new Time();
                System.out.print("Hours: ");
                int h1 = sc.nextInt();
                System.out.print("Minutes: ");
                int m1 = sc.nextInt();
                System.out.print("Seconds: ");
                int s1 = sc.nextInt();
                Time time2 = new Time(h1,m1,s1);
                time1.display();
                time2.display();

            }
            else if(q==3){
                Random random = new Random();
                System.out.print("Enter name: ");
                String name = sc.next();
                int accNo = random.nextInt(1000);
                System.out.print("Credit or Debit(c/d); ");
                char t = sc.next().charAt(0);
                String type;
                if(t=='c'){type = "Credit";}
                else{type = "Debit";}
                float randomRate = Float.parseFloat("10");
                Account acc1 = new Account(name,accNo,type,Float.parseFloat("0"),randomRate);
                while(true){
                    System.out.print("1:Deposit\n2:Withdrawl\n3:Display\n4:Display rate\nChoose from the options: ");
                    int choice = sc.nextInt();
                    float amount;
                    switch(choice){
                        case 1:
                        System.out.print("Enter amount: ");
                        amount = sc.nextFloat();
                        acc1.deposit(amount);
                        break;
                        case 2:
                        System.out.print("Enter amount");
                        amount = sc.nextFloat();
                        acc1.withdraw(amount);
                        break;
                        case 3:
                        acc1.display();
                        break;
                        case 4:
                        Account.displayRate();
                        break;
                        default:
                        break;
                    } 
                    if(choice>4)break;
                }
            }
            else if(q==4){
                Counter.showCount();
                //Counter c1 = new Counter();
                //Counter c2 = new Counter();
                Counter.showCount();
            }
            else{
                System.out.println("Exitting program");
                break;
            }
        }
    }
}