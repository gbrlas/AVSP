import java.io.*;
import java.util.*;
import java.math.*;

public class A implements Runnable {

	static class Walkway implements Comparable<Walkway> {
		int b;
		int e;
		int w;

		public Walkway(int b, int e, int w) {
			super();
			this.b = b;
			this.e = e;
			this.w = w;
		}

		@Override
		public int compareTo(Walkway a) {
			return w - a.w;
		}
	}

	void solve() {
		int testsNumber = nextInt();
		for (int curTest = 0; curTest < testsNumber; curTest++) {
			int length = nextInt();
			int walkingSpeed = nextInt();
			int runningSpeed = nextInt();
			int timeToRun = nextInt();
			int n = nextInt();
			Walkway[] a = new Walkway[n];
			for (int i = 0; i < n; i++) {
				a[i] = new Walkway(nextInt(), nextInt(), nextInt());
			}
			out.println("Case #" + (curTest + 1) + ": "
					+ solve(length, walkingSpeed, runningSpeed, timeToRun, a));
		}
	}

	static final double EPS = 1e-7;

	static int compare(double a, double b) {
		return Math.abs(a - b) < EPS ? 0 : Double.compare(a, b);
	}

	static double solve(int length, int walkingSpeed, int runningSpeed,
			int timeToRun, Walkway[] a) {
		Arrays.sort(a);
		double leftTime = timeToRun;
		double ret = 0;
		int leftDist = length;
		for (Walkway w : a) {
			leftDist -= (w.e - w.b);
		}
		{
			Walkway w = new Walkway(0, leftDist, 0);
			int v = runningSpeed + w.w;
			double dist = leftTime * v;
			if (compare(w.e - w.b, dist) >= 0) {
				ret += leftTime + (w.e - w.b - dist) / (walkingSpeed + w.w);
				leftTime = 0;				
			} else {
				double time = 1. * (w.e - w.b) / (runningSpeed + w.w);
				leftTime -= time;
				ret += time;
			}
		}
		for (Walkway w : a) {
			int v = runningSpeed + w.w;
			double dist = leftTime * v;
			if (compare(w.e - w.b, dist) >= 0) {
				ret += leftTime + (w.e - w.b - dist) / (walkingSpeed + w.w);
				leftTime = 0;				
			} else {
				double time = 1. * (w.e - w.b) / (runningSpeed + w.w);
				leftTime -= time;
				ret += time;
			}
		}		
		return ret;
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