import java.io.*;
import java.util.*;

public class A
{
	public static void main(String[] args) throws Throwable
	{
		Scanner in = new Scanner(System.in);
		int t = Integer.parseInt(in.nextLine());
		for(int i = 1; i <= t; i++)
		{
			int n = Integer.parseInt(in.nextLine());
			int[] x = new int[n];
			for(int j = 0; j < n; j++)
			{
				char[] q = in.nextLine().toCharArray();
				int last = -1;
				for(int k = 0; k < n; k++)
					if(q[k]=='1')
						last = k;
				x[j] = last;
			}
			int curr = 0, swap = 0;
			whop:while(curr < n)
			{
				for(int j = curr; j < n; j++)
					if(x[j] <= curr)
					{
						for(int k = j-1; k >= curr; k--)
						{
							int tt = x[k];
							x[k] = x[k+1];
							x[k+1] = tt;
							swap++;
						}
						curr++;
						continue whop;
					}
			}
			System.out.println("Case #"+i+": "+swap);
		}
		System.exit(0);
	}
}