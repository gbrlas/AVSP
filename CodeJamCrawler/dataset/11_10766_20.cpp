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
		
		for(int i=1;i<=n;i++)
		{
			int f = i*pd;
			if(f%100==0)
			{
				return po;
			}
		}
		return br;
	}
	
}
