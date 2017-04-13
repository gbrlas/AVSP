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
		int n = nextInt();
		for (int i = 1; i <= n; i++) {
			out.print("Case #" + i + ": ");
			solve2();
		}
	}

	int inter;
	final int INF = Integer.MAX_VALUE / 3;
	int[][] dp;
	int k;
	int[] cost;
	int[] m;

	int go(int x, int left) {
		if (left > k) {
			left = k;
		}
		if (x >= inter) {
			if (left >= k - m[x - inter]) {
				return 0;
			} else {
				return INF;
			}
		}
		if (dp[x][left] != -1) {
			return dp[x][left];
		}
		int ret = INF;
		if (left > 0) {
			ret = go(x, left - 1);
		}
		ret = Math.min(ret, go(x * 2 + 1, left + 1) + go(x * 2 + 2, left + 1)
				+ cost[x]);
		ret = Math.min(ret, go(x * 2 + 1, left + 1) + go(x * 2 + 2, left + 1)
				+ cost[x]);
		ret = Math.min(ret, go(x * 2 + 1, left) + go(x * 2 + 2, left));
		return dp[x][left] = ret;
	}

	void solve2() {
		k = nextInt();
		inter = (1 << k) - 1;
		dp = new int[1 << (k + 1)][k + 1];
		for (int[] d : dp) {
			Arrays.fill(d, -1);
		}
		m = new int[1 << k];
		for (int i = 0; i < 1 << k; i++) {
			m[i] = nextInt();
		}
		cost = new int[inter];
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < (1 << (k - i - 1)); ++j) {
				cost[(1 << (k - i - 1)) - 1 + j] = nextInt();
			}
		}
		out.println(go(0, 0));
	}
}