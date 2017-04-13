//Solution to 'Welcome to Code Jam' for Code Jam qualification round 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;

public class Welcome
{
	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		int N=Integer.parseInt(in.readLine());

		for (int i=1; i<=N; i++)
		{
			long ans=solve(in.readLine());
			String ans2=""+ans;
			while(ans2.length()<4) ans2="0"+ans2;
			System.out.println("Case #"+i+": "+ans2);
		}

		in.close();
	}

	public static long solve(String a)
	{
		String text="welcome to code jam";
		long[][] b=new long[text.length()][a.length()];

		for (int i=0; i<a.length(); i++)
			if (a.charAt(i)==text.charAt(text.length()-1))
				b[text.length()-1][i]=1;

		for (int i=text.length()-2; i>=0; i--)
		{
			for (int k=0; k<a.length(); k++)
			{
				if (a.charAt(k)!=text.charAt(i)) continue;
				long sum=0;
				for (int m=k+1; m<a.length(); m++)
				{
					if (a.charAt(m)==text.charAt(i+1))
						//sum=sum+b[i+1][m];
						sum=(sum+b[i+1][m])%10000;
				}
				b[i][k]=sum;
			}
		}

		long total=0;
		for (int k=0; k<a.length(); k++)
			if (a.charAt(k)==text.charAt(0))
				//total+=b[0][k];
				total=(total+b[0][k])%10000;

		return total;
	}
}