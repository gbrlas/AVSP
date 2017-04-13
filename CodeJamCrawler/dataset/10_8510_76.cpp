import java.util.Scanner;
import java.math.BigInteger;
import java.util.Arrays;
import java.io.*;

class Main
{
	public static void main (String[] args) throws Exception
	{
		Scanner scn = new Scanner(new File("b.in"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("b.out")));
		int t = scn.nextInt();
		
		for(int tcase = 1; tcase <= t; tcase++)
		{
			int n = scn.nextInt();
			BigInteger [] a = new BigInteger[n];
			BigInteger [] b = new BigInteger[n-1];
			for(int i = 0; i < n; i++)
				a[i] = scn.nextBigInteger();
			Arrays.sort(a);
			for(int i = 0; i < n-1; i++)
				b[i] = a[n-1].subtract(a[i]);
				
			BigInteger x = GCD(b);
			BigInteger ans = a[0].add(x).subtract(new BigInteger("1"))
				.divide(x).multiply(x).subtract(a[0]);
			w.write("Case #" + tcase + ": " + ans + "\n");
		}
		w.close();
	}
	
	static BigInteger GCD(BigInteger [] b)
	{
		if(b.length == 1) return b[0];
		BigInteger x = b[0].gcd(b[1]);
		for(int i = 2; i < b.length; i++)
			x = x.gcd(b[i]);
		return x;
	}
}