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
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve2();
			System.err.println("test #" + (i + 1));
		}
	}

	void solve2() {
		int r = nextInt();
		boolean[][] has = new boolean[300][300];
		for (int i = 0; i < r; i++) {
			int x1 = nextInt();
			int y1 = nextInt();
			int x2 = nextInt();
			int y2 = nextInt();
			for (int x = x1; x <= x2; x++) {
				for (int y = y1; y <= y2; y++) {
					has[x][y] = true;
				}
			}
		}
		int ans = 0;
		boolean[][] has2 = new boolean[300][300];
		while (true) {
			boolean ok = false;
			loop: for (int i = 0; i < has.length; i++) {
				for (int j = 0; j < has[i].length; j++) {
					if (has[i][j]) {
						ok = true;
						break loop;
					}
				}
			}
			if (!ok) {
				break;
			}
			++ans;
			for (int i = 0; i < has.length; i++) {
				for (int j = 0; j < has[i].length; j++) {
					if (has[i][j]) {
						if ((i == 0 || !has[i - 1][j])
								&& (j == 0 || !has[i][j - 1])) {
							has2[i][j] = false;
						} else {
							has2[i][j] = true;
						}
					} else {
						if ((i != 0 && has[i - 1][j])
								&& (j != 0 && has[i][j - 1])) {
							has2[i][j] = true;
						} else {
							has2[i][j] = false;
						}
					}
				}
			}
			boolean[][] temp = has;
			has = has2;
			has2 = temp;
		}
		out.println(ans);
	}
}