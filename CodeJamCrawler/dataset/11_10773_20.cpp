import java.util.Arrays;
import java.util.Scanner;


public class p1 {

	
	public static void debug(Object... obs)
	{
		System.out.println(Arrays.deepToString(obs));
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			long n = sc.nextLong();
			int pd = sc.nextInt();
			int pg = sc.nextInt();
						
			System.out.println("Case #" + c + ": " + solve(n,pd,pg));
		}
	}
	
	long gcd(long a, long b)
	{
		while(b!=0)
		{
			long t = b;
			b = a%b;
			a = t;
		}
		return a;
	}

	private static String solve(long n, int pd, int pg)
	{
		String br = "Broken";
		String po = "Possible";

		if(pg == 100 && pd != 100)
			return br;
		if(pg == 100 && pd == 100)
			return po;
		if(pg == 0 && pd != 0)
			return br;
		if(pd == 0)
			return po;
		
		
		for(long i=1;i<=n;i++)
		{
			long f = i*(long)pd;
			if(f%100L==0)
			{
				return po;
			}
		}
		return br;
	}
	
}
