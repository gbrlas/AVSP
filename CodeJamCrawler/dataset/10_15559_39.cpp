import java.io.*;
import java.util.*;
import java.math.*;

public class A
{
	public static void main(String[] args) throws Exception
	{
	    int T;	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());

		for (int i=1; i<=T; i++)
		{
            String line=in.readLine();
            String[] temp=line.split(" ");
            int N=Integer.parseInt(temp[0]);
            int K=Integer.parseInt(temp[1]);
            char[][] a=new char[N][N];
            for (int k=0; k<N; k++)
                a[k]=in.readLine().toCharArray();      
            String ans=solve(a,K);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

    //solves small only
	public static String solve(char[][] a, int K)
    {
        //char[][] b=new char[N][N];
        int N=a.length;
        //gravity
        for (int i=0; i<N; i++)
        {
            for (int k=N-1; k>=0; k--)
            {
                if (a[i][k]=='.') continue;
                
                int cur=k;
                while(cur<N-1)
                {
                    if (a[i][cur+1]=='.')
                    {
                        char c=a[i][cur];
                        a[i][cur]=a[i][cur+1];
                        a[i][cur+1]=c;
                    }
                    cur++;
                }
            }
        }
        
        //print(a);
        boolean red=find(a,K,'R');
        boolean blue=find(a,K,'B');
        
        if (red && blue) return "Both";
        if (!red && !blue) return "Neither";
        if (red) return "Red";
        return "Blue";
	}
	
	public static boolean find(char[][] a, int K, char c)
	{
	   //row
	   int N=a.length;
	   for (int i=0; i<N; i++)
	   {
	       for (int k=0; k<N; k++)
	       {
	           if (a[i][k]==c && N-k>=K)
	           {
	               boolean ok=true;
	               for (int m=1; m<K; m++)
	                   if (a[i][k+m]!=c)
	                   {
	                       ok=false;
	                       break;
	                   }
	                   
	               if (ok) return true;
	           }
	       }
	   }
	   
	   //col
	   for (int i=0; i<N; i++)
	   {
	       for (int k=0; k<N; k++)
	       {
	           if (a[k][i]==c && N-k>=K)
	           {
	               boolean ok=true;
	               for (int m=1; m<K; m++)
	                   if (a[k+m][i]!=c)
	                   {
	                       ok=false;
	                       break;
	                   }
	                   
	               if (ok) return true;
	           }
	       }
	   }
	   
	   //diag1
	   for (int i=0; i<N; i++)
	   {
	       for (int k=0; k<N; k++)
	       {
	           if (a[i][k]==c && N-k>=K && N-i>=K)
	           {
	               boolean ok=true;
	               for (int m=1; m<K; m++)
	                   if (a[i+m][k+m]!=c)
	                   {
	                       ok=false;
	                       break;
	                   }
	                   
	               if (ok) return true;
	           }
	       }
	   }
	   
	   //diag2
	   for (int i=0; i<N; i++)
	   {
	       for (int k=0; k<N; k++)
	       {
	           if (a[i][k]==c && k>=K-1 && N-i>=K)
	           {
	               boolean ok=true;
	               for (int m=1; m<K; m++)
	                   if (a[i+m][k-m]!=c)
	                   {
	                       ok=false;
	                       break;
	                   }
	                   
	               if (ok) return true;
	           }
	       }
	   }
	   
	   return false;
	}
	
    public static void print(char[][] a)
    {
        for (int i=0; i<a.length; i++)
        {
            for (int k=0; k<a.length; k++)
                System.out.print(a[i][k]);
            System.out.println();
        }
        System.out.println();
    }
}

