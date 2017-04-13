import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class FairAndSquare {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static void solve() throws Exception {
		// System.err.println();
		// System.err.println("TEST " + test);

		long A = nextInt();
		long B = nextInt();
				
		// Solve.
		
		// Find lower bound.
		long lowA = (long)Math.ceil(Math.sqrt(A));
		long lowB = (long)Math.sqrt(B);
		
		long i = lowA;
		long count = 0;
		while (i <= lowB) {
			if (isPalindrom(i)) {
				if (isPalindrom(i*i)) {
					count++;
				}
			}
			i++;
		}		

		// System.err.print("FOOD");
		// System.err.println();

		 printCase();
		 out.println(count);
	}
	
	static boolean isPalindrom(long in) {
		String inStr = Long.toString(in);
		if (inStr.length() > 1) {
			int halfLen = inStr.length() / 2;

			for (int i = 0; i < halfLen; i++) {
				if (inStr.charAt(i) != inStr.charAt(inStr.length() - 1 - i)) {
					return false;
				} else {
					return true;
				}
			}			
		} else {
			return true;
		}		
		return false;
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			// Handle the empty line.
			String line = in.readLine();
			if ((line == null) || line.isEmpty()) {
				return "";
			}
			tok = new StringTokenizer(line);
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			in = new BufferedReader(
					new FileReader(
							"D:\\Workspaces\\eclipse_workspace\\codejam\\CodeJam\\src\\C-small-attempt0.in"));
			// out = new PrintWriter(new OutputStreamWriter(System.out));
			out = new PrintWriter(
					new FileWriter(
							"D:\\Workspaces\\eclipse_workspace\\codejam\\CodeJam\\src\\C-small-attempt0.out"));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}
