import java.io.*;
import java.math.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		new B().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
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

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	void solve() {
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			out.println(solve2());
		}
	}

	BigInteger solve2() {
		int n = nextInt();
		BigInteger[] a = new BigInteger[n];
		for (int i = 0; i < n; i++) {
			a[i] = new BigInteger(nextToken());
		}
		BigInteger z = BigInteger.ZERO;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				z = z.gcd(a[i].subtract(a[j]).abs());
			}
		}
		return z.subtract(a[0].mod(z)).mod(z);
	}
}