import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	static class Point implements Comparable<Point> {
		int x;
		int v;

		public Point(int x, int v) {
			super();
			this.x = x;
			this.v = v;
		}

		@Override
		public int compareTo(Point p) {
			return x - p.x;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", v=" + v + "]";
		}

	}

	void solve() {
		int t = nextInt();
		for (int test = 0; test < t; test++) {
			out.print("Case #" + (test + 1) + ": ");
			int n = nextInt();
			double d = nextDouble();
			Point[] p = new Point[n];
			for (int i = 0; i < n; i++) {
				p[i] = new Point(nextInt(), nextInt());
			}
			out.printf(Locale.US, "%.10f\n", solve(p, d));
		}
	}

	static double solve(Point[] points, double d) {
		Arrays.sort(points);
		double l = 0;
		double r = 1e10;
		double m = (l + r) * .5;
		while (l != m && r != m) {
			double x = Double.NEGATIVE_INFINITY;
			boolean ok = true;
			for (Point p : points) {
				double e;
				if (x < p.x) {
					e = Math.max(x, p.x - m);
				} else {
					if (p.x + m < x) {
						ok = false;
						break;
					}
					e = x;
				}
				x = e + (p.v - 1) * d;
				if (p.x + m < x) {
					ok = false;
					break;
				}
				x += d;
			}
			if (!ok) {
				l = m;
			} else {
				r = m;
			}
			m = (l + r) * .5;
		}
		return l;
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