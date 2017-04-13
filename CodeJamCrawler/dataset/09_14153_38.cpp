//Solution to B for Code Jam qualification round 1C 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;
import java.math.*;

public class B
{
	static int N;
	public static void main(String[] args) throws Exception
	{	
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		N=Integer.parseInt(in.readLine());


		for (int i=1; i<=N; i++)
		{
            String[] temp=(in.readLine()).split(" ");
            int P=Integer.parseInt(temp[0]);
            int Q=Integer.parseInt(temp[1]);
            String[] temp2=(in.readLine()).split(" ");
            int[] p=new int[Q];
            for (int k=0; k<Q; k++)
                p[k]=Integer.parseInt(temp2[k]);
            int ans=solve(P,p);
            System.out.println("Case #"+i+": "+ans);
        }

		in.close();
	}

	public static int solve(int P, int[] p)
    {
        int[] p2=new int[p.length];
        for (int i=0; i<p2.length; i++) p2[i]=p[i]-1;
        
        int min=Integer.MAX_VALUE;
        
        do
        {
            boolean[] a=new boolean[P];            
            Arrays.fill(a,true);
            int score=0;
            for (int i=0; i<p2.length; i++)
            {
                a[p2[i]]=false;
                score+=simulate(a,p2[i]);
            }
            
            min=Math.min(min,score);
        }
        while(nextPermutation(p2));
    
    
        return min;
    }
    
    public static int simulate(boolean[] a, int rel)
    {
        int count=0;
        for (int i=rel+1; i<a.length; i++)
        {
            if (!a[i]) break;
            count++;
        }
        for (int i=rel-1; i>=0; i--)
        {
            if (!a[i]) break;
            count++;
        }
        return count;
    }
    
    
	//elements in a have to be sorted in ascending order	//changes the elements to achieve the next permutation	//returns false if there are no more permutations	public static boolean nextPermutation(int[] a)	{		int N=a.length;		int i=N-2;		for (; i>=0; i--)			if (a[i]<a[i+1])				break;		if (i<0) return false;				for (int j=N-1; j>=i; j--)		{			if (a[j]>a[i])			{				int temp=a[i];				a[i]=a[j];				a[j]=temp;				break;					}		}		for (int j=i+1; j<(N+i+1)/2; j++)		//reverse from a[i+1] to a[N-1]		{			int temp=a[j];			a[j]=a[N+i-j];			a[N+i-j]=temp;		}		return true;	}    
}