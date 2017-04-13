//Solution to A for Code Jam qualification round 2 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;
import java.math.*;

public class A
{
	static int T;
	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		T=Integer.parseInt(in.readLine());


		for (int i=1; i<=T; i++)
		{
            int X=Integer.parseInt(in.readLine());
            int[] a=new int[X];
            for (int k=0; k<X; k++)
            {
                String line=in.readLine();
                int b=line.lastIndexOf('1');
                if (b<0) b=0;
                a[k]=b;
            }
            int ans=solve(a);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static int solve(int[] a)
    {
        //for (int i=0; i<a.length; i++) System.out.print(a[i]+" ");
        //System.out.println();    
        int count=0;
        for (int i=0; i<a.length; i++)
        {
            if (a[i]<=i) continue;
            //find one
            int k=i+1;
            for (; k<a.length; k++)
            {
                if (a[k]<=i) break;
            }
            //percolate
            while(k!=i)
            {
                int temp=a[k];
                a[k]=a[k-1];
                a[k-1]=temp;
                k--;
                count++;
            }
        }
        //for (int i=0; i<a.length; i++) System.out.print(a[i]+" ");
        //System.out.println();
        return count;
    }
}