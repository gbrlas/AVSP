import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new C().run();
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

	void solve() {
		c = new long[MAXN + 1][MAXN + 1];
		c[0][0] = 1;
		for (int i = 1; i <= MAXN; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
			}
		}
		dp = new long[MAXN + 1][MAXN + 1];
		dp[2][1] = 1;
		for (int i = 3; i <= MAXN; i++) {
			dp[i][1] = 1;
			for (int j = 2; j < i; j++) {
				for (int k = 1; k < j; k++) {
					dp[i][j] = (dp[i][j] + dp[j][k] * c[i - j - 1][j - k - 1])
							% MOD;
				}
			}
		}
		int t = nextInt();
		for (int i = 1; i <= t; i++) {
			out.print("Case #" + i + ": ");
			solve2();
		}
	}

	long[][] dp, c;
	final int MOD = 100003;
	final int MAXN = 500;

	void solve2() {
		int n = nextInt();
		long ans = 0;
		for (int i = 1; i < n; i++) {
			ans += dp[n][i];
			ans %= MOD;
		}
		out.println(ans);
	}
}