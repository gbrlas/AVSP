import java.io.*;
import java.math.*;
import java.util.*;

public class C {
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

	long solve2() {
		int r = nextInt();
		int k = nextInt();
		int n = nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		int[] was = new int[n];
		long[] money = new long[n];
		int cur = 1;
		int prefix = -1, period = -1;
		long allMoney = 0;
		int beginningOfPeriod = -1;
		for (int i = 0;;) {
			if (was[i] > 0) {
				prefix = was[i] - 1;
				period = cur - was[i];
				beginningOfPeriod = i;
				break;
			}
			was[i] = cur++;
			int j = i;
			long sum = 0;
			int kol = 0;
			while (kol < n && sum + a[j] <= k) {
				sum += a[j];
				j = (j + 1) % n;
				++kol;
			}
			if (was[j] == 0) {
				money[j] = money[i] + sum;
			}
			allMoney += sum;
			i = j;
		}
		long ans = money[beginningOfPeriod];
		ans += (allMoney - money[beginningOfPeriod]) * ((r - prefix) / period);
		int y = (r - prefix) % period;
		for (int i = beginningOfPeriod, w = 0; w < y; ++w) {
			int j = i;
			long sum = 0;
			int kol = 0;
			while (kol < n && sum + a[j] <= k) {
				sum += a[j];
				j = (j + 1) % n;
				++kol;
			}
			ans += sum;
			i = j;
		}
		return ans;
	}
}