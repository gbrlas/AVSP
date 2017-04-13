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
public class C {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;
	static List<BigInteger> fairAndSquare;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(C.class.getName() + ".in"));
			out.add(new PrintStream(C.class.getName() + ".out"));
		}
		fairAndSquare = new ArrayList<BigInteger>();
		BigInteger start = new BigInteger("1");
		BigInteger end = new BigInteger("4004009004004");
		while (start.compareTo(end) < 1) {
			if (isSquare(start) && isPalindrome(sqrt(start))) {
				fairAndSquare.add(start);
			}
			start = nextPalindrome(start);
		}

		int T = i();
		li();
		for (int i = 0; i < T; i++) {
			pf("Case #%d: %s\n", i + 1, solve());
		}
		System.out.println("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		String line = li();
		BigInteger start = new BigInteger(line.split(" ")[0]);
		BigInteger end = new BigInteger(line.split(" ")[1]);
		int total = 0;
		for (BigInteger big : fairAndSquare) {
			if (big.compareTo(start) > -1 && big.compareTo(end) < 1) {
				total++;
			}
		}
		return total + "";
	}

	// Only safe for palindrome -> palindrome
	static BigInteger nextPalindrome(BigInteger n) {
		char[] num = n.toString().toCharArray();
		for (int i = 0; i < num.length; i++) {
			if (num[i] != '9') {
				break;
			}
			if (i == num.length - 1) {
				return n.add(BigInteger.ONE).add(BigInteger.ONE);
			}
		}
		StringBuffer sb = new StringBuffer();
		BigInteger firstHalf = null;
		for (int i = 0; i < (num.length + 1) / 2; i++) {
			sb.append(num[i]);
		}
		firstHalf = new BigInteger(sb.toString()).add(BigInteger.ONE);
		StringBuffer next = new StringBuffer(firstHalf.toString());
		StringBuffer next2 = new StringBuffer(next.toString() + next.reverse());
		if (num.length % 2 == 1) {
			next2.deleteCharAt(num.length / 2);
		}
		return new BigInteger(next2.toString());
	}

	static boolean isPalindrome(BigInteger n) {
		char[] num = n.toString().toCharArray();
		for (int i = 0; i <= num.length / 2; i++) {
			if (num[i] != num[num.length - i - 1]) {
				return false;
			}
		}
		return true;
	}

	static boolean isSquare(BigInteger n) {
		return sqrt(n).pow(2).equals(n);
	}

	static BigInteger sqrt(BigInteger n) {
		final int bitLength = n.bitLength();
		BigInteger root = BigInteger.ONE.shiftLeft(bitLength / 2);

		while (!isSqrt(n, root)) {
			root = root.add(n.divide(root)).divide(BigInteger.valueOf(2));
		}
		return root;
	}

	static boolean isSqrt(BigInteger n, BigInteger root) {
		final BigInteger lowerBound = root.pow(2);
		final BigInteger upperBound = root.add(BigInteger.ONE).pow(2);
		return lowerBound.compareTo(n) <= 0 && n.compareTo(upperBound) < 0;
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