import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class B {

	static String iFileName = "b_small.in";
	static String oFileName = "b_small.out";
	
	public static BigInteger gcd(BigInteger i1, BigInteger i2)	{
		if(i2.compareTo(new BigInteger("0")) == 0)
			return i1;
		return gcd(i2, i1.mod(i2));
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File(iFileName));
		PrintWriter pw = new PrintWriter(new FileOutputStream(oFileName, false));
		//PrintWriter pw = new PrintWriter(System.out);
		int t = s.nextInt();
		for(int tt=1; tt<=t; tt++)	{
			int n = s.nextInt();
			ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
			for(int i=0;i<n;i++) {
				String num = s.next();
				arr.add(new BigInteger(num));
			}
			BigInteger divisor = new BigInteger("-1");
			boolean first = true;
			for(int i=0;i<n;i++)
				for(int j=i+1;j<n;j++) {
					BigInteger cur = arr.get(i).subtract(arr.get(j)).abs();
					if(first) {
						first = false;
						divisor = cur;
					}else 
						divisor = gcd(divisor, cur);
				}
			BigInteger res = null;
			if(arr.get(0).mod(divisor).compareTo(new BigInteger("0")) == 0)
				res = new BigInteger("0");
			else res = arr.get(0).divide(divisor).multiply(divisor).add(divisor).subtract(arr.get(0));
			pw.printf("Case #%d: %s\n", tt, res);
		}
		pw.close();
		s.close();
	}

}
