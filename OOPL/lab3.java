import java.util.Scanner;

public class lab3 {
    public static Scanner sc = new Scanner(System.in);

    public static class Complex{
        double real;
        double img;

        public Complex(){
            real = 0;
            img = 0;
        }

        public void init(double re,double im){
            real = re;
            img = im;
        }

        public void display(){
            System.out.println(real+" + i"+img);
        }

        public Complex add(Complex c2){
            Complex result = new Complex();
            result.real = this.real + c2.real;
            result.img = this.img + c2.img;

            return result;
        }

        public Complex subtract(Complex c2){
            Complex result = new Complex();
            result.real = this.real - c2.real;
            result.img = this.img - c2.img;

            return result;
        }
    }

    public static class Time{
        int hours,mins,secs;

        public Time(){
            hours = mins = secs = 00;
        }

        public void setTime(int h,int m,int s){
            hours = h;
            mins = m;
            secs = s;
        }

        public void display(){
            System.out.println(hours+":"+mins+":"+secs);
        }

        public Time add(Time t2){
            Time result = new Time();
            result.secs = this.secs + t2.secs;
            if(result.secs >= 60){
                result.secs -= 60;
                result.mins++;
            }
            result.mins += this.mins + t2.mins;
            if(result.mins >= 60){
                result.mins -= 60;
                result.hours++;
            }
            result.hours += this.hours + t2.hours;
            if(result.hours>=24){
                result.hours-=24;
            }
            return result;
        }
        
        public Time subtract(Time t2){
            Time result = new Time();
            result.secs = this.secs - t2.secs;
            if(result.secs < 0){
                result.secs += 60;
                result.mins--;
            }
            result.mins += this.mins - t2.mins;
            if(result.mins < 0){
                result.mins += 60;
                result.hours--;
            }
            result.hours += this.hours - t2.hours;
            if(result.hours<0){
                result.hours+=24;
            }
            return result;
        }
    
        public Time compare(Time t2){
            int secsInFirst = this.hours*60*60 + this.mins*60 + this.secs;
            int secsInSecond = t2.hours*60*60 + t2.mins*60 + t2.secs;
            if(secsInFirst > secsInSecond){
                return this;
            }
            else if(secsInFirst < secsInSecond){return t2;}
            else{
                Time equal = new Time();
                equal.setTime(-1,0,0);
                return equal;
            }
        }
    }

    public static class Mixer{
        int arr[] = new int[99];
        int n;

        void accept(){
            System.out.print("Enter number of elements: ");
            n = sc.nextInt();
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
        }

        Mixer mix(Mixer A){
            Mixer result = new Mixer();

            return result;
        }

        void display(){
            System.out.println("The array is:");
            for(int i=0;i<n;i++){
                System.out.print(arr[i]+" ");
            }
        }
    }

    public static class Stack{
        int arr[],top;

        public Stack(){
            int n = sc.nextInt();
            arr = new int[n];
        }
    }

    public static void main(String args[]){
        while(true){
            System.out.print("Enter question no.: ");
            int q = sc.nextInt();

            if(q==1){
                Complex com1 = new Complex();
                System.out.print("Enter value of real part: ");
                double a = sc.nextDouble();
                System.out.print("Enter value of imaginary part: ");
                double b = sc.nextDouble();
                com1.init(a,b);
                com1.display();

                Complex com2 = new Complex();
                System.out.print("Enter value of real part: ");
                double c = sc.nextDouble();
                System.out.print("Enter value of imaginary part: ");
                double d = sc.nextDouble();
                com2.init(c,d);
                com2.display();
                
                System.out.println("The addition of 2 complex numbers is");
                Complex c3 = com1.add(com2);
                c3.display();

                System.out.println("The subtraction of 2 complex numbers is");
                Complex c4 = com1.subtract(com2);
                c4.display();
                
            }
            else if(q==2){
                Time time1 = new Time();
                System.out.print("Hours: ");
                int h1 = sc.nextInt();
                System.out.print("Minutes: ");
                int m1 = sc.nextInt();
                System.out.print("Seconds: ");
                int s1 = sc.nextInt();

                time1.setTime(h1, m1, s1);
                time1.display();

                Time time2 = new Time();
                System.out.print("Hours: ");
                int h2 = sc.nextInt();
                System.out.print("Minutes: ");
                int m2 = sc.nextInt();
                System.out.print("Seconds: ");
                int s2 = sc.nextInt();
                time2.setTime(h2, m2, s2);
                time2.display();

                Time time3 = time1.add(time2);
                System.out.print("Adding the 2 times = ");
                time3.display();

                Time time4 = time1.subtract(time2);
                System.out.println("Subtracting the 2 times = ");
                time4.display();

                Time comparision = time1.compare(time2);
                if(comparision.hours == -1){System.out.println("Equal times.");}
                else if(comparision == time1){
                    System.out.println("Time 1 is greater");
                }
                else{
                    System.out.println("Time 1 is smaller");
                }

            }
            else if(q==3){
                Mixer m = new Mixer();
                m.accept();
                m.display();

            }
            else if(q==4){

            }
            else{
                System.out.println("Exitting program");
                break;
            }
        }
    }
}
