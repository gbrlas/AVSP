
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Abhishek
 */
public class CCAlpha {
     public static void main(String[] args)throws Exception
     {FileReader f=new FileReader("C:/Users/Abhishek/Downloads/B-small-practice.in");
    FileWriter fw=new FileWriter("CookieClipherAlpha.txt");   
      PrintWriter B=new PrintWriter(fw);
    Scanner s= new Scanner(f);
   int T=s.nextInt();
    for(int i=1;i<=T;i++)
    {double C=s.nextDouble();
    double F=s.nextDouble();
    double X=s.nextDouble();
    double time=time(C,F,X);
    
    B.println("Case #"+i+": "+time+" "+"\n");
    }
   
    
 
 B.close();
 fw.close();
  }
     static double time(double C,double F,double X)
     {double t=0,ft=0,time=10*X;
     int i=0;
     boolean b=true;
     
     while(b!=false)
     {ft=ft+C/(i*F+2)-t;
     t=X/(((i+1)*F)+2);
     ft=ft+t;
     if(ft<time)
      time=ft;
     else break;
     i++;}
     if(time>X/2)
         time=X/2;
     return time;}
}
