import java.io.*;
import java.util.*;

public class B implements Runnable {
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

	void solve() {
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
			solve2();
		}
	}

	void solve2() {
		int n = nextInt();
		int k = nextInt();
		int b = nextInt();
		int t = nextInt();
		int[] x = new int[n];
		int[] v = new int[n];
		for (int i = 0; i < n; i++) {
			x[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			v[i] = nextInt();
		}
		boolean[] can = new boolean[n];
		int all = 0;
		for (int i = 0; i < n; i++) {
			can[i] = (b - x[i] <= v[i] * t);
			if (can[i]) {
				++all;
			}
		}
		if (all < k) {
			out.println("IMPOSSIBLE");
			return;
		}
		int i = n - 1;
		int ans = 0;
		while (k > 0) {
			if (!can[i]) {
				for (int j = i - 1; j >= 0; --j) {
					if (can[j]) {
						for (int r = j; r < i; r++) {
							can[r] = false;
							++ans;
						}
						break;
					}
				}
				can[i] = true;
			}
			--i;
			--k;
		}
		out.println(ans);
	}
}