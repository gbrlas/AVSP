import java.io.*;
import java.util.*;
import java.math.*;

public class C
{
    public static int[] S;
	public static void main(String[] args) throws Exception
	{
        makeSeq();

	    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());



		for (int i=1; i<=T; i++)
		{
            String line=in.readLine();
            String[] temp=line.split(" ");
            int A1=Integer.parseInt(temp[0]);
            int A2=Integer.parseInt(temp[1]);            
            int B1=Integer.parseInt(temp[2]);
            int B2=Integer.parseInt(temp[3]);            
            String ans=solve2(A1,A2,B1,B2);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

    //solves small only
	public static String solve(int A1, int A2, int B1, int B2)
    {
        //int[][] a=new int[A2-A1+1][B2-B1+1];
        boolean[][] a=new boolean[A2+1][B2+1];      //false=LOSS, true=WIN
        for (int i=0; i<=A2; i++) a[i][0]=true;
        for (int i=0; i<=B2; i++) a[0][i]=true;
        
        //if all lead to W then L
        //if one leads to L then W
        
        for (int i=1; i<=A2; i++)
        {
            for (int m=1; m<=B2; m++)
            {
                boolean found=false;
                int n1=i;
                int n2=m;
                while(n1>0)
                {
                    n1-=m;
                    if (n1>0 && a[n1][n2]==false)
                    {
                        found=true;
                        break;
                    }
                }
                
                if (found)
                {
                    a[i][m]=true;
                    continue;
                }
                
                n1=i;
                n2=m;
                while(n2>0)
                {
                    n2-=i;
                    if (n2>0 && a[n1][n2]==false)
                    {
                        found=true;
                        break;
                    }
                }
                
                if (found) a[i][m]=true;
                else a[i][m]=false;
            }
        }
        
       // print(a);
       
       for (int i=0; i<=A2; i++)
       {
            int k=0;
            for (; k<=B2; k++)
            {
                if (a[i][k]==false) break;
            }
            //System.out.println(i+": "+k);
            System.out.print(k+",");
       }
       
        
        return "";
	}
	
	public static void print(boolean[][] a)
	{
	   for (int i=0; i<a.length; i++)
	   {
	       for (int k=0; k<a[0].length; k++)
	       {
	           if (a[i][k]) System.out.print("W");
	           else System.out.print("L");
	       }
	       System.out.println();
	   }
	}
	
	public static void makeSeq()
	{
	   int n=1000100;
	   S=new int[n];
	   S[1]=1;
	   for (int i=2; i<n; i++)
	   {
	       S[i]=i+1-S[S[i-1]];
	      // System.out.print(a[i]+",");
	   }
	   //System.out.println();
	}
	
    //solves all
	public static String solve2(int A1, int A2, int B1, int B2)
	{
	   //int total=(A2-A1+1)*(B2-B1+1);
	   int total=0;
	   for (int A=A1; A<=A2; A++)
	   {
	       int start=S[A];
	       int end=start+A-1;
	       for (int B=B1; B<=B2; B++) 
	       {
	           if (B<start || B>end) total++;
	       }
	   }
	   
	   return ""+total;
	}
}

/*
1,2,2,3,4,4,5,5,6,7,7,8,9,9,10,10,11,12,12,13,13,14,15,15,16,17,17,18,18,19,20,20,21,22,22,23,23,24,25,25,26,26,27,28,28,29,30,30,31,31

A019446
a(1)=1; a(n) = n+1 - a(a(n-1)
a(n) = ceiling(n/tau), where tau=(1+sqrt(5))/2.
*/

