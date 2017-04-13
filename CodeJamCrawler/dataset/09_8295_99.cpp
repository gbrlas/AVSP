import java.io.*;
import java.util.*;

class A
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		int L = in.nextInt(), D = in.nextInt(), N = in.nextInt();
		char[][] dict = new char[D][L];
		in.nextLine();
		for(int i = 0; i < D; i++)
			dict[i] = in.nextLine().toCharArray();
		for(int i = 0; i < N; i++)
		{
			boolean[][] b = new boolean[L][26];
			char[] c = in.nextLine().toCharArray();
			int curr = 0;
			boolean inn = false;
			for(int j = 0; j < c.length; j++)
			{
				if(c[j] == '(')
					inn = true;
				else if(c[j] == ')')
				{
					inn = false;
					curr++;
				}
				else if(inn)
					b[curr][c[j]-'a'] = true;
				else
					b[curr++][c[j]-'a'] = true;
			}
			int ct = 0;
			cob:for(int j = 0; j < D; j++)
			{
				for(int k = 0; k < L; k++)
					if(!b[k][dict[j][k]-'a'])
						continue cob;
				ct++;
			}
			o("Case #"+(i+1)+": "+ct);
		}
		System.exit(0);
	}
	static void o(String s)
	{
		System.out.println(s);
	}
}