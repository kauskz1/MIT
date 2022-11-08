import java.util.Scanner;

class Table extends Thread{
    String table;
    int num;
    Table(int x){
        this.num = x;
        this.table = "Table of "+x+":";
        start();
    }

    public void run(){
        try{
            for(int i=1;i<11;i++){
                table = table+"\t"+(i*this.num);
                Thread.sleep(100);
            }
        }
        catch(InterruptedException e){
            System.out.println("Interrupted");
        }
        finally{
            System.out.println("Exitting thread");
        }
    }
}

class Tables{
    public Table t1,t2;
    @SuppressWarnings("unused")
    public Tables(int a,int b){
        Table t1 = new Table(a);
        Table t2 = new Table(b);
    }
    Table getTable1(){return t1;}
}

public class Lab9 {
    static Scanner sc = new Scanner(System.in);
    public static void main(String args[]){
        while(true){
            int q;
            System.out.print("Enter question no.: ");
            q = sc.nextInt();
            if(q==1){
                Tables t = new Tables(5,7);
                try{
                    System.out.println("Sleeping for 2 seconds");
                    Thread.sleep(2000);
                }
                catch(InterruptedException e) {
                    System.out.println("Interrupted..");
                }
                System.out.println(t.getTable1());
                //System.out.println(t.t2.table);
            }
            else if(q==2){

            }
            else if(q==3){

            }
            else{break;}
        }
    }
}