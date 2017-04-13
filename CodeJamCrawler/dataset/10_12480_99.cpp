import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

/**
 * <p>
 * </p>
 */

/**
 * @author fabrizio
 *
 */
public class FairWarning {

	public BigInteger getMinSeconds(BigInteger[]times) {
		Arrays.sort(times);
		BigInteger[]diffs=new BigInteger[times.length];
		for (int i = 0; i < times.length; i++) {
			diffs[i]=times[i].subtract(times[0]);
		}
		BigInteger gcd=diffs[1];
		for (int i = 2; i < diffs.length; i++) {
			gcd=diffs[i].gcd(gcd);
		}
		BigInteger mod = times[0].mod(gcd);
		if (mod.equals(BigInteger.ZERO)) {
			return BigInteger.ZERO;
		}
		return gcd.subtract(mod);
	}
	
	public static void main(String[] args) throws Exception {
		Scanner sc=new Scanner(new File("B-large.in"));
		PrintWriter p=new PrintWriter("out-b-large.txt");
		int cases=sc.nextInt();
		for (int c = 1;  c <=cases; c++) {
			int ntimes=sc.nextInt();
			BigInteger[]times=new BigInteger[ntimes];
			for (int i = 0; i < times.length; i++) {
				times[i]=sc.nextBigInteger();
			}
			p.println("Case #"+c+": "+new FairWarning().getMinSeconds(times));
		}
		p.close();
	}
}
