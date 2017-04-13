import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static final int MAXP = 1000000;
	final static boolean[] NP = new boolean[MAXP];
	final static int[] PRIMES;
	static {
		int count = MAXP - 2;
		for (int i = 2; i * i < MAXP; i++) {
			if (!NP[i]) {
				for (int j = i * i; j < MAXP; j += i) {
					if (!NP[j]) {
						--count;
						NP[j] = true;
					}
				}
			}
		}
		PRIMES = new int[count];
		for (int i = 2, j = 0; i < MAXP; i++) {
			if (!NP[i]) {
				PRIMES[j++] = i;
			}
		}
	}

	void solve() {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			long n = nextLong();
			out.println("Case #" + (i + 1) + ": " + solve(n));
		}
	}

	static int solve(long n) {
		if (n == 1) {
			return 0;
		}
		int ans = 1;
		for (int i : PRIMES) {
			if ((long) i * i > n) {
				break;
			}
			long e = (long) i * i;
			while (e <= n) {
				e *= i;
				ans++;
			}
		}
		return ans;
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("c.in");
			out = new PrintWriter("c.out");
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}