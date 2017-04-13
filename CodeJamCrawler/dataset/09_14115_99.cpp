//Solution to 'Alien Language' for Code Jam qualification round 2009
//By Dmitry Kamenetsky

import java.io.*;
import java.util.*;

public class Alien
{
	static String[] dic;
	static int L,D,N;
	public static void main(String[] args) throws Exception
	{
		RandomAccessFile in = new RandomAccessFile(args[0],"r");
		String[] temp=(in.readLine()).split(" ");
		L=Integer.parseInt(temp[0]);
		D=Integer.parseInt(temp[1]);
		N=Integer.parseInt(temp[2]);
		dic=new String[D];

		for (int i=0; i<D; i++)
			dic[i]=in.readLine();

		for (int i=1; i<=N; i++)
		{
			int ans=solve(in.readLine());
			System.out.println("Case #"+i+": "+ans);
		}

		in.close();
	}

	public static int solve(String phrase)
	{
		String[] parse=new String[L];
		int cur=0;
		String a="";
		boolean inBrackets=false;
		for (int i=0; i<phrase.length(); i++)
		{
			if (phrase.charAt(i)=='(')
			{
				inBrackets=true;
			}
			else if (phrase.charAt(i)==')')
			{
				inBrackets=false;
				parse[cur]=a;
				cur++;
				a="";
			}
			else
			{
				a+=phrase.charAt(i);
				if (!inBrackets)
				{
					parse[cur]=a;
					cur++;
					a="";
				}
			}
		}
		
		//for (int i=0; i<L; i++) System.out.println(parse[i]);

		int count=0;
		for (int i=0; i<dic.length; i++)
		{
			boolean ok=true;
			for (int k=0; k<L; k++)
			{
				if (parse[k].indexOf(dic[i].charAt(k))<0)
				{
					ok=false;
					break;
				}
			}
			if (ok) count++;
		}

		return count;
	}
}