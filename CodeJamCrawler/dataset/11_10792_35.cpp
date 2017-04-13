import java.util.Arrays;
import java.util.Scanner;

public class p2b {

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
			int n = sc.nextInt();
			int d = sc.nextInt();
			int[] p = new int[n];
			int[] v = new int[n];
			for (int i = 0; i < n; i++)
			{
				p[i] = sc.nextInt();
				v[i] = sc.nextInt();
			}

			System.out.println("Case #" + c + ": " + solve(n, d, p, v));
		}
	}

	private static double solve(int n, int d, int[] p, int[] v)
	{
		int sumv = 0;
		

		double maxmintrav = 0;
		
		for (int i = 0; i < p.length; i++)
		{
			for (int j = i; j < p.length; j++)
			{
				sumv = 0;
				for (int k = i; k <= j; k++)
					sumv += v[k];
				
				double mintrav = Integer.MAX_VALUE;

				double minp = p[i];
				double maxp = p[j];

				double atl = maxp - (sumv - 1) * d;
				double ath = maxp;
				double maxat = minp + (sumv - 1) * d;

				boolean oneIt = false;
				while (ath <= maxat)
				{
					oneIt = true;
					double mint1 = Math.abs(atl - minp);
					double mint2 = Math.abs(ath - maxp);

					mintrav = Math.min(mintrav, Math.max(mint1, mint2));

					atl += 0.5;
					ath += 0.5;
				}
				//debug(minp, maxp, atl, ath, maxat,mintrav);
				
				if(oneIt)
					maxmintrav = Math.max(maxmintrav, mintrav);
			}
		}
		return maxmintrav;
	}

}
