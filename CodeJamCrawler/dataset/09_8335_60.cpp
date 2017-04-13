import java.util.*;
import java.io.*;
public class A1A
{
	static boolean ih[][] = new boolean[9][1000000];
	static boolean ph[][] = new boolean[9][1000000];
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("lookup.txt")));
		for(int i = 0; i < 9; i++)
			ph[i][1] = ih[i][1] = true;
		for(int j = 2; j < 1000000; j++)
			for(int i = 0; i < 9; i++)
				isHappy(j, i+2);
		int T = Integer.parseInt(in.nextLine());
		woof:for(int q = 1; q <= T; q++)
		{
			String[] p = in.nextLine().trim().split(" ");
			int[] x = new int[p.length];
			for(int i = 0; i < x.length; i++)
				x[i] = Integer.parseInt(p[i]);
			kaz:for(int i = 2; i < 1000000000; i++)
			{
				for(int j = 0; j < x.length; j++)
					if(!isHappyCD(i, x[j]))
						continue kaz;
				out.println("Case #"+q+": "+i);
				System.out.println(q);
				continue woof;
			}
			System.out.println("never");
		}
		out.close();
	}
	static boolean isHappyCD(int x, int r)
	{
		int xcpy = x, nn = 0;
		while(x > 0)
		{
			int tmp = x%r;
			nn += tmp*tmp;
			x /= r;
		}
		return isHappy(nn, r);
	}
	static boolean isHappy(int x, int r)
	{
		if(ph[r-2][x] == true)
			return ih[r-2][x];
		ph[r-2][x] = true;
		int xcpy = x, nn = 0;
		while(x > 0)
		{
			int tmp = x%r;
			nn += tmp*tmp;
			x /= r;
		}
		return ih[r-2][xcpy] = isHappy(nn, r);
	}
}