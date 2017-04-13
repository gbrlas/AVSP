import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class CookieClickerAlpha {
	
	public static double Sum(Stack<Double> DS){
		double sum=0;
		//Object var;
		for(double s : DS){
			sum+=s;
		}
		return sum;
	}
	 @SuppressWarnings("null")
	public static void main(String[] args) throws IOException {
		 FileWriter f = new FileWriter(new File("CookieClickerAlpha.out"));
		 Scanner s = new Scanner(new FileInputStream("CookieClickerAlpha.in"));
		 int counts = s.nextInt();
		 
		 System.out.println(counts);
		double C,F,X,R;
		int CountFarm=0;
		double temp;
		double prev=9999999,current=1;
		int counter=1;
		 for(int t=0;t<counts;t++){
			 CountFarm=0;
			 System.out.print("Case #"+(t+1)+": ");
             f.write("Case #"+(t+1)+": ");
             C=s.nextDouble();
             F=s.nextDouble();
             X=s.nextDouble();
             //double[] db = new double[];
             double fs = 2;
             List<Double> db;
             Stack<Double> sd = new Stack<Double>();
             sd.push(X/fs);
             prev=Sum(sd);
            
             ////////////
             for(;;){
             sd.pop();
             sd.push(C/fs);
             CountFarm++;
             fs+=F;
             sd.push(X/fs);
             current=Sum(sd);
            // System.out.println(sd);
             DecimalFormat df = new DecimalFormat("#.0000000");
             if(prev>current) prev=current;
             else {
            	 System.out.println(df.format(prev)); 
            	 f.write(String.valueOf(df.format(prev))); 
            	 break;
            	 }
             }
            // System.out.println(C+" "+X+" "+F);
			 f.write("\n");
		 }
		 f.close();
	 }
}
