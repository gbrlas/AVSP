/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


package codejam2014.round0;
import java.io.FileNotFoundException;
/**
 * Jesus is Lord :)
 * @author Essiennta Emmanuel <colourfulemmanuel@gmail.com>
 */
public class ProblemA {
    public static void main(String[] args) throws FileNotFoundException{
        System.out.println(System.getProperty("user.dir"));
        java.util.Scanner sc=new java.util.Scanner(new java.io.File(args[0]));
        java.io.PrintWriter out=new java.io.PrintWriter(args[0].substring(0,args[0].indexOf("."))+".out");
        
        ProblemA problem=new ProblemA();
        int numCases=sc.nextInt();
        for(int testNum=1;testNum<=numCases;testNum++){
            problem.solve(sc,out,testNum);
        }
        out.close();
        sc.close();
    }
    public void solve(java.util.Scanner sc,java.io.PrintWriter out,int testNumber){
        int firstAns=sc.nextInt();
        byte[]freq=new byte[16];
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                int valueRead=sc.nextInt();
                if(i+1==firstAns)
                    freq[valueRead-1]++;
            }
        int secondAns=sc.nextInt();
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                int valueRead=sc.nextInt();
                if(i+1==secondAns)
                    freq[valueRead-1]++;
            }
        int count=0;
        int value=-1;
        for(int i=0;i<freq.length;i++){
            byte x=freq[i];
            if(x==2){
                count++;
                value=i+1;
            }
        }
        out.println("Case #"+testNumber+": "+(count==1?value:count==0?"Volunteer cheated!":"Bad magician!"));
    }
}
