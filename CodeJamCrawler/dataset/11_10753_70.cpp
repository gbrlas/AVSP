import java.util.Arrays;
import java.util.Scanner;


public class SplittingCandies {

	static final String NO="NO";
	
	static void debug(Object...objects)
	{
		System.out.println(Arrays.deepToString(objects));
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int c = 1; c <= t; c++)
		{
			int n = sc.nextInt();
			
			long[] num = new long[n];
			for (int i = 0; i < n; i++)
			{
				num[i] = sc.nextLong();
			}
			System.out.println("Case #" + c + ": " + solve(num));
		}
	}

	private static String solve(long[] num)
	{
		long z=0;
		long sum=0;
		for(int i=0;i<num.length;i++)
		{
			z=z^num[i];
			sum+=num[i];
		}

		if(z!=0) return NO;
		
		Arrays.sort(num);
		return Long.toString(sum-num[0]);
	}
	
	
}
