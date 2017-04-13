import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static class Vector {
		long a;
		long b;

		public Vector(long a, long b) {
			super();
			this.a = a;
			this.b = b;
		}

		public Vector add(Vector v) {
			return new Vector(a + v.a, b + v.b);
		}

		public Vector subtract(Vector v) {
			return new Vector(a - v.a, b - v.b);
		}

		public Vector multiply(long c) {
			return new Vector(a * c, b * c);
		}

		@Override
		public String toString() {
			return "Vector [a=" + a + ", b=" + b + "]";
		}

		public boolean isZero() {
			return a == 0 && b == 0;
		}
	}

	void solve() {
		int testsNumber = nextInt();
		for (int curTest = 0; curTest < testsNumber; curTest++) {
			int n = nextInt();
			int m = nextInt();
			int d = nextInt();
			int[][] a = new int[n][m];
			for (int i = 0; i < n; i++) {
				char[] c = nextToken().toCharArray();
				for (int j = 0; j < m; j++) {
					a[i][j] = c[j] - '0' + d;
				}
			}
			out.println("Case #" + (curTest + 1) + ": " + solve(n, m, a));
		}
	}

	static String solve(int n, int m, int[][] a) {
		Vector[][] sum = new Vector[n][m];
		Vector[][] b = new Vector[n][m];
		long[][] sumD = new long[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x = 2 * i + 1;
				int y = 2 * j + 1;
				sumD[i][j] = a[i][j];
				b[i][j] = sum[i][j] = new Vector(x * a[i][j], y * a[i][j]);
				if (i > 0) {
					sum[i][j] = sum[i][j].add(sum[i - 1][j]);
					sumD[i][j] += sumD[i - 1][j];
				}
				if (j > 0) {
					sum[i][j] = sum[i][j].add(sum[i][j - 1]);
					sumD[i][j] += sumD[i][j - 1];
				}
				if (i > 0 && j > 0) {
					sum[i][j] = sum[i][j].subtract(sum[i - 1][j - 1]);
					sumD[i][j] -= sumD[i - 1][j - 1];
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = Math.max(ans, 3);; k++) {
					if (i - k + 1 < 0 || j - k + 1 < 0) {
						break;
					}
					int i2 = i - k + 1;
					int j2 = j - k + 1;
					int xc = 2 * i + 1 - k + 1;
					int yc = 2 * j + 1 - k + 1;
					Vector v = getSum(sum, i2, j2, i, j);
					v = v.subtract(b[i2][j2]);
					v = v.subtract(b[i2][j]);
					v = v.subtract(b[i][j2]);
					v = v.subtract(b[i][j]);
					long d = (getSum(sumD, i2, j2, i, j) - a[i2][j2] - a[i][j]
							- a[i2][j] - a[i][j2]);
					v = v.subtract(new Vector(xc * d, yc * d));
					if (v.isZero()) {
						ans = Math.max(ans, k);
					}
				}
			}
		}
		return ans < 3 ? "IMPOSSIBLE" : ans + "";
	}

	static long getSum(long[][] sumD, int i2, int j2, int i, int j) {
		long ret = sumD[i][j];
		if (i2 > 0) {
			ret -= sumD[i2 - 1][j];
		}
		if (j2 > 0) {
			ret -= sumD[i][j2 - 1];
		}
		if (i2 > 0 && j2 > 0) {
			ret += sumD[i2 - 1][j2 - 1];
		}
		return ret;
	}

	static Vector getSum(Vector[][] sum, int i2, int j2, int i, int j) {
		Vector ret = sum[i][j];
		if (i2 > 0) {
			ret = ret.subtract(sum[i2 - 1][j]);
		}
		if (j2 > 0) {
			ret = ret.subtract(sum[i][j2 - 1]);
		}
		if (i2 > 0 && j2 > 0) {
			ret = ret.add(sum[i2 - 1][j2 - 1]);
		}
		return ret;
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		try {
			sc = new FastScanner("b.in");
			out = new PrintWriter("b.out");
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
		new B().run();
	}
}