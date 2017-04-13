import java.io.*;
import java.util.Scanner;
import java.lang.String;

public class Alien {
	public static void main(String args[]) throws IOException
	{
		int L,N,D;
		int i,j,k;
		int[] sum;
		int[] msum;
		String[] lan = new String[5000];
		String[] inlan = new String[500];

		Scanner scanner = new Scanner(System.in);
		L=scanner.nextInt();
		D=scanner.nextInt();
		N=scanner.nextInt();
		
		for (i=0;i<D;i++)
		{
			//read the correct tokens
			lan[i]=scanner.next();
		}
		for (i=0;i<N;i++)
		{
			//read the incorrect tokens
			inlan[i]=scanner.next();
		}
		char[] chr = new char[L];
		String[] str = new String[L];
		sum = new int[N];
		msum = new int[N];
		
		for(i=0;i<N;i++)
		{
			//for every inlan
			//transfer inlan[i] to str[L]
			int t;
			for(t=0;t<L;t++)
			{
				if(inlan[i].startsWith("("))
				{
					inlan[i]=inlan[i].substring(1);
					str[t]=inlan[i].substring(0, inlan[i].indexOf(")"));
					inlan[i]=inlan[i].substring(inlan[i].indexOf(")")+1);
				}
				else
				{
					str[t]=inlan[i].substring(0, 1);
					inlan[i]=inlan[i].substring(1);
				}
			}
			////
			for(j=0;j<D;j++)
			{
				//for every lan
				lan[j].getChars(0, L, chr, 0);
				for(k=0;k<L;k++)
				{
					//for every letter in every lan
					if(str[k].indexOf(chr[k])!=-1)
						sum[i]++;
					else
						break;
				}
				if (sum[i]==L)
				{
					msum[i]++;
					sum[i]=0;
				}
				else
					sum[i]=0;
			}
		}
			
		
		for(i=0;i<N;i++)
		{
			System.out.println("Case #"+(i+1)+": "+msum[i]);
		}
		
	}

}
