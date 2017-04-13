import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class A {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(A.class.getName() + ".in"));
			out.add(new PrintStream(A.class.getName() + ".out"));
		}
		int T = i();
		li();
		for (int i = 0; i < T; i++) {
			pf("Case #%d: %s\n", i + 1, solve());
		}
		d("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		String nums = li();
		BigInteger r = new BigInteger(nums.split(" ")[0]);
		BigInteger t = new BigInteger(nums.split(" ")[1]);

		BigInteger sum = BigInteger.ZERO;
		BigInteger two = new BigInteger("2");

		for (long i = 0;; i++) {
			sum = sum.add(r.add(BigInteger.ONE).pow(2));
			sum = sum.subtract(r.pow(2));
			if (sum.compareTo(t) < 1) {
				r = r.add(two);
			} else {
				return i + "";
			}
		}
	}

	static void p(String x) {
		for (PrintStream ps : out) {
			ps.print(x);
		}
	}

	static void pl(String x) {
		for (PrintStream ps : out) {
			ps.println(x);
		}
	}

	static void pf(String format, Object... args) {
		for (PrintStream ps : out) {
			ps.printf(format, args);
		}
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static void d(String x) {
		System.out.println(x);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}