import java.util.*;
import java.math.*;
import java.io.*;

public class Main 
{
	int t, n, i, iCas = 1, j;
	String str;
	BigInteger []num = new BigInteger[1008];
	BigInteger []tmp = new BigInteger[1008];
	BigInteger gg = new BigInteger("0");
	BigInteger ret = new BigInteger("0");
	Main() throws FileNotFoundException
	{
		File file = new File("B-small-attempt0.in");
		File outFile = new File("B-small-attempt0.out");
		Scanner cin = new Scanner(file);
		PrintWriter cout = new PrintWriter(outFile);
		//Scanner cin = new Scanner(System.in);
		t = cin.nextInt();
		while (t > 0)
		{
			t--;
			if (cin.hasNext())
				n = cin.nextInt();
			for (i = 0; i < n; ++i)
			{
				if (cin.hasNext())
					str = cin.next();
				num[i] = new BigInteger(str);
			}
			Arrays.sort(num, 0, n);
			for (i = 1; i < n; ++i)
				tmp[i] = num[i].subtract(num[i - 1]);
			gg = tmp[1];
			for (i = 2; i < n; ++i)
				gg = gg.gcd(tmp[i]);
			if (gg.compareTo(BigInteger.ZERO) == 0)
			{
				cout.println("Case #" + iCas + ": " + ret);
				iCas++;
				continue;
			}
			ret = num[0].divide(gg);
			ret = ret.multiply(gg);
			if (ret.compareTo(num[0]) == 0)
			{
				ret = num[0].divide(gg);
			}
			else
			{
				ret = num[0].divide(gg);
				ret = ret.add(BigInteger.ONE);
			}
			ret = ret.multiply(gg);
			ret = ret.subtract(num[0]);
		//	System.out.println("Case #" + iCas + ": " + ret);
			cout.println("Case #" + iCas + ": " + ret);
			iCas++;
		}
		cin.close();
		cout.close();
	}
	public static void main(String args[]) throws FileNotFoundException
	{
		new Main();
	}
}
