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
public class ProblemD_ {
    public static void main(String[] args) throws FileNotFoundException{
        java.util.Scanner sc=new java.util.Scanner(new java.io.File(args[0]));
        java.io.PrintWriter out=new java.io.PrintWriter(args[0].substring(0,args[0].indexOf("."))+".out");
        
        ProblemD_ problem=new ProblemD_();
        int numCases=sc.nextInt();
        for(int testNum=1;testNum<=numCases;testNum++){
            problem.solve(sc,out,testNum);
        }
        out.close();
        sc.close();
    }
    public void solve(java.util.Scanner sc,java.io.PrintWriter out,int testNumber){
        int n=sc.nextInt();
        double[]naomiArray=new double[n];
        double[]kenArray=new double[n];
        for(int i=0;i<n;i++)
            naomiArray[i]=sc.nextDouble();
        for(int i=0;i<n;i++)
            kenArray[i]=sc.nextDouble();
        java.util.Arrays.sort(naomiArray);
        java.util.Arrays.sort(kenArray);
        System.out.println("Naomi: "+java.util.Arrays.toString(naomiArray));
        System.out.println("Ken: "+java.util.Arrays.toString(kenArray));
        
        //Test for optimal play of deceitful war
        int naomiIndex=0,kenIndex=0;
        int nnn=0,kkk=0;
        while(true){
            boolean c1=kenIndex==n;
            boolean c2=nnn==n;
            if(c1&&c2)
                break;
            if(!c1){
                if(naomiArray[naomiIndex]<kenArray[kenIndex]){
                    naomiIndex++;
                    kenIndex++;
                }else kenIndex++;
            }
            if(!c2){
                if(kenArray[kkk]<naomiArray[nnn]){
                    nnn++;
                    kkk++;
                }else nnn++;
            }
        }
        out.println("Case #"+testNumber+": "+kkk+" "+(n-naomiIndex));
        
    }
}
