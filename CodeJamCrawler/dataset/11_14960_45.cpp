import java.io.*;
import java.util.*;
import java.math.*;

public class Bsmall implements Runnable {

	void solve() {
		int t = nextInt();
		for (int test = 0; test < t; test++) {
			int n = nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = nextInt();
			}
			out.println("Case #" + (test + 1) + ": " + solve(a));
		}
	}

	static int solve(int[] a) {
		if (a.length == 0) {
			return 0;
		}
		Arrays.sort(a);
		int n = a.length;
		int[] dp = new int[1 << n];
		dp[0] = Integer.MAX_VALUE;
		for (int i = 1; i < 1 << n; i++) {
			for (int j = i; j > 0; j = (j - 1) & i) {
				int last = Integer.MIN_VALUE;
				boolean bad = false;
				for (int k = 0; k < n; k++) {
					if (((j >> k) & 1) == 0) {
						continue;
					}
					if (last != Integer.MIN_VALUE) {
						if (last + 1 != a[k]) {
							bad = true;
							break;
						}
					}
					last = a[k];
				}
				if (!bad) {
					dp[i] = Math.max(dp[i],
							Math.min(dp[i ^ j], Integer.bitCount(j)));
				}
			}
		}
		return dp[(1 << n) - 1];
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("bsmall.in");
			out = new PrintWriter("bsmall.out");
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
		new Bsmall().run();
	}
}