import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	void solve() {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			int n = nextInt();
			char[][] c = new char[n][];
			for (int i = 0; i < n; i++) {
				c[i] = nextToken().toCharArray();
			}
			out.println("Case #" + test + ":");
			double[] ans = solve(n, c);
			for (double a : ans) {
				out.println(a);
			}
		}
	}

	static double[] solve(int n, char[][] c) {
		int[] games = new int[n];
		int[] won = new int[n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (c[i][j] == '.') {
					continue;
				}
				games[i]++;
				if (c[i][j] == '1') {
					won[i]++;
				}
			}
		}
		double[] wp = new double[n];
		for (int i = 0; i < n; i++) {
			wp[i] = 1. * won[i] / games[i];
		}
		double[] owp = new double[n];
		for (int i = 0; i < n; i++) {
			double sum = 0;
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) {
					continue;
				}
				if (c[i][j] == '.') {
					continue;
				}
				count++;
				sum += 1. * (won[j] - (c[j][i] - '0')) / (games[j] - 1);
			}
			owp[i] = sum / count;
		}
		double[] oowp = new double[n];
		for (int i = 0; i < n; i++) {
			double sum = 0;
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (i == j || c[i][j] == '.') {
					continue;
				}
				count++;
				sum += owp[j];
			}
			oowp[i] = sum / count;
		}
		double[] ans = new double[n];
		for (int i = 0; i < n; i++) {
			ans[i] = .25 * wp[i] + .5 * owp[i] + .25 * oowp[i];
		}
		return ans;
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("a.in");
			out = new PrintWriter("a.out");
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
		new A().run();
	}
}