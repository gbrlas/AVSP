/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam2014.round0;
import java.io.FileNotFoundException;
/**
 * Jesus is Lord :)
 *
 * @author Essiennta Emmanuel <colourfulemmanuel@gmail.com>
 */
public class ProblemB{
    public static void main(String[] args) throws FileNotFoundException{
        java.util.Scanner sc=new java.util.Scanner(new java.io.File(args[0]));
        java.io.PrintWriter out=new java.io.PrintWriter(args[0].substring(0,args[0].indexOf("."))+".out");

        ProblemB problem=new ProblemB();
        int numCases=sc.nextInt();
        for(int testNum=1;testNum<=numCases;testNum++)
            problem.solve(sc,out,testNum);
        out.close();
        sc.close();
    }
    public void solve(java.util.Scanner sc,java.io.PrintWriter out,int testNumber){
        double c=sc.nextDouble();
        double f=sc.nextDouble();
        double x=sc.nextDouble();

        double sumFreq=2;
        double sum=0;
        double min=Double.MAX_VALUE;
        if(c<x)
            while(true){
                double thisSum=sum+x/sumFreq;
                if(min-thisSum<-1e-8)
                    break;
                min=thisSum;
                sum+=c/sumFreq;
                sumFreq+=f;
            }
        else
            min=x/2;
        out.printf("Case #%d: %1.7f%n",testNumber,min);
    }
}
