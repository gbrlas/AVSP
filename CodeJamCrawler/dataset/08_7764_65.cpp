import java.io.*;
import java.util.*;
import java.math.*;

public class B
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
			int N = (int)in.nval;
			in.nextToken();
			int M = (int)in.nval;
			int[] cust = new int[M];
			for(int i = 0; i < M; i++)
			{
				in.nextToken();
				int num = (int)in.nval;
				for(int j = 0; j < num; j++)
				{
					in.nextToken();
					int a = 1<<((int)in.nval-1);
					in.nextToken();
					int b = (int)in.nval;
					b *= 10;
					cust[i] |= (a<<b);
				}
			}
			int bestRR = -1, bestVal = 1000000, sent = 1<<20;
				for(int A = 1<<0; A < sent; A<<=10)
				for(int B = 1<<1; B < sent; B<<=10)
				for(int C = 1<<2; C < sent; C<<=10)
				for(int D = 1<<3; D < sent; D<<=10)
				for(int E = 1<<4; E < sent; E<<=10)
				for(int F = 1<<5; F < sent; F<<=10)
				for(int G = 1<<6; G < sent; G<<=10)
				for(int H = 1<<7; H < sent; H<<=10)
				for(int I = 1<<8; I < sent; I<<=10)
				p:for(int J = 1<<9; J < sent; J<<=10)
				{
					int rr = A|B|C|D|E|F|G|H|I|J;
					int val = Integer.bitCount(rr>>10);
					if(val < bestVal)
					{
						for(int i = 0; i < M; i++)
							if((rr&cust[i])==0)
								continue p;
						bestVal = val;
						bestRR = rr;
					}
				}
			if(bestRR == -1)
				out.println("Case #"+iter+": IMPOSSIBLE");
			else
			{
				out.print("Case #"+iter+": ");
				for(int i = 10; i < 10+N; i++)
					out.print((((1<<i)&bestRR)>>i)+" ");
				out.println();
			}
		}
		out.close();
		System.exit(0);
	}
}