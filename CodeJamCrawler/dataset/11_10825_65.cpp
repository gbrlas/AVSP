import java.util.Arrays;
import java.util.Scanner;


public class p2c {


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
			int n=sc.nextInt();
			long l=sc.nextLong();
			long h=sc.nextLong();
			long fr[]=new long[n];
			for(int i=0;i<n;i++)
				fr[i]=sc.nextLong();
			
			System.out.println("Case #" + c + ": "+solve(l,h,fr,n));
			
		}
	}
	
	private static String solve(long l, long h, long[] fr, int n)
	{
		String no="NO";
	
		for(long at=l;at<=h;at++)
		{
			boolean yes=true;
			for(int i=0;i<n;i++)
			{
				if(fr[i]%at!=0&&at%fr[i]!=0)
				{
					yes=false;
				}
			}
			if(yes)
				return Long.toString(at);
		}
		return no;
		
//		long lcmv=fr[0];
//		for(int i=1;i<n;i++)
//		{
//			lcmv=lcm(lcmv,fr[i]);
//		}
////		if(lcmv > h) return no;
////		if(lcmv < l) 
////		{
////			long f=l/lcmv; 
////		}
//		return Long.toString(lcmv);
	}

	static long gcd(long a, long b)
	{
		while(b!=0)
		{
			long t = b;
			b = a%b;
			a = t;
		}
		return a;
	}
	
	static long lcm(long a,long b)
	{
		return a*b/(gcd(a,b));
	}
}
