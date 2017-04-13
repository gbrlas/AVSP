import java.util.*;
import java.math.*;

public class FairWarning {
	public static BigInteger lcm(BigInteger a, BigInteger b) {
		return a.multiply(b).divide(a.gcd(b));
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int C = in.nextInt();
		for (int c=0;c<C;c++) {
			int N = in.nextInt();
			ArrayList<BigInteger> t = new ArrayList<BigInteger>();
			BigInteger gcd = BigInteger.ZERO;
			BigInteger max = BigInteger.ZERO;
			for (int n=0;n<N;n++) {
				BigInteger ti = in.nextBigInteger();
				for (BigInteger bi : t) {
					gcd = bi.subtract(ti).abs().gcd(gcd);
					//System.out.println(ti + " " + bi.subtract(ti).abs() + " gcd=" + gcd);
				}
				if (ti.compareTo(max) > 0) max = ti;
				t.add(ti);
			}
			BigInteger maxDiff = gcd;
			for (BigInteger bi : t) {
				maxDiff = maxDiff.min(bi.mod(gcd));
				//System.out.println(bi + " " + bi.mod(gcd) + " maxDiff=" + maxDiff);
			}
			if (!maxDiff.equals(BigInteger.ZERO))
				maxDiff = gcd.subtract(maxDiff);
			//if (BigInteger.ONE.equals(gcd)) maxDiff = BigInteger.ZERO;
			System.out.println("Case #"+(c+1)+": "+maxDiff);
		}
	}
}

