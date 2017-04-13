import java.io.*;
import java.util.*;
import java.math.*;

public class A2
{
	public static void main(String[] args) throws Throwable
	{
		StreamTokenizer in = new StreamTokenizer(new BufferedReader(new FileReader("A-small.in")));
		// BufferedReader in = new BufferedReader(new FileReader("A-small.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));
		in.nextToken();
		int t = (int)in.nval, iter = 0;
		while(t-->0)
		{
			iter++;
			in.nextToken();
			int M = (int)in.nval;
			in.nextToken();
			boolean V = 1==(int)in.nval;
			boolean[] node = new boolean[M+1];
			boolean[] chg = new boolean[(M-1)/2+1];
			int ct = 0;
			for(int i = 1; i <= M; i++)
			{
				in.nextToken();
				node[i] = 1==(int)in.nval;
				if(i <= (M-1)/2)
				{
					in.nextToken();
					chg[i] = 1==(int)in.nval;
					if(chg[i])
						ct++;
				}
			}
			int[] locchg = new int[ct];
			int x = 0;
			ct = 0;
			for(int i = 1; i <= (M-1)/2; i++)
				if(chg[i])
					locchg[ct++] = i;
			x = Integer.MAX_VALUE;
			for(int i = 0; i < (1<<ct); i++)
			{
				int num = Integer.bitCount(i);
				if(num > x)
					continue;
				for(int j = 0; j < ct; j++)
					if((i&(1<<j)) != 0)
						node[locchg[j]] ^= true;
				boolean[] cuh = new boolean[M+1];
				for(int j = M; j > (M-1)/2; j--)
					cuh[j] = node[j];
				for(int j = (M-1)/2; j > 0; j--)
					cuh[j] = node[j]?cuh[j*2]&&cuh[j*2+1]:cuh[j*2]||cuh[j*2+1];
				if(cuh[1]==V)
					x = num;
				for(int j = 0; j < ct; j++)
					if((i&(1<<j)) != 0)
						node[locchg[j]] ^= true;
			}
			out.println("Case #"+iter+": "+(x==Integer.MAX_VALUE?"IMPOSSIBLE":x));
		}
		out.close();
		System.exit(0);
	}
}