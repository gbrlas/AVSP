import java.io.*;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new A().run();
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

	void solve() {
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve2();
		}
	}

	int getIt(int n, int x) {
		if (x < n) {
			return x + 1;
		}
		return 2 * n - x - 1;
	}

	void solve2() {
		int n = nextInt();
		int[][] a = new int[2 * n - 1][2 * n - 1];
		for (int[] b : a) {
			Arrays.fill(b, -1);
		}
		for (int i = 0; i < 2 * n - 1; i++) {
			int x = getIt(n, i);
			int y = n - x;
			for (int j = 1; j <= 2 * x - 1; j++) {
				if (j % 2 == 1) {
					a[i][y + j - 1] = nextInt();
				}
			}
		}
		// for (int k = n;; k++) {
		// for (int x = 0; x <= (k - n) * 2; ++x) {
		// int d1 = Math.min(getIt(k, x + 1), getIt(k, x + 2 * n - 2));
		// loop: for (int y = 0; y < d1; y++) {
		// for (int i = 0; i < 2 * n - 1; i++) {
		// int e = getIt(n, i);
		// for (int j = 0; j < e; j++) {
		// int ii = i + x;
		// int jj = j + y;
		// int iN = 2 * k - 2 - ii - x;
		// int jN = jj - y;
		// if (iN >= 0 && iN < 2 * n - 1 && jN < a[iN].length
		// && jN >= 0) {
		// if (a[i][j] != a[iN][jN]) {
		// continue loop;
		// }
		// }
		// int d2 = ii < k ? ii + 1 : ii - k;
		// iN = i;
		// jN = d2 - jj - 1 - y;
		// if (iN >= 0 && iN < 2 * n - 1 && jN < a[iN].length
		// && jN >= 0) {
		// if (a[i][j] != a[iN][jN]) {
		// continue loop;
		// }
		// }
		// }
		// }
		// out.println(k * k - n * n);
		// return;
		// }
		// }
		// }
		for (int k = n;; k++) {
			int[][] b = new int[2 * k - 1][2 * k - 1];
			for (int i = 0; i < b.length; i++) {
				Arrays.fill(b[i], -1);
			}
			for (int i = 0; i <= (k - n) * 2; i++) {
				int x = getIt(k, i);
				int y = k - x;
				for (int j = 0; j <= (k - n) * 2; j++) {
					if ((i + j) % 2 != (k - n) % 2) {
						continue;
					}
					for (int i1 = 0; i1 < 2 * n - 1; i1++) {
						for (int j1 = 0; j1 < 2 * n - 1; j1++) {
							b[i + i1][j + j1] = a[i1][j1];
						}
					}
					boolean ok = true;
					loop: for (int i1 = 0; i1 < 2 * k - 1; i1++) {
						int e1 = getIt(k, i1);
						int e2 = k - e1;
						for (int j1 = 0; j1 < e2; j1++) {
							if (b[i1][j1] != -1) {
								ok = false;
								break loop;
							}
						}
						for (int j1 = 2 * k - 2; j1 >= 2 * k - 1 - e2; --j1) {
							if (b[i1][j1] != -1) {
								ok = false;
								break loop;
							}
						}
					}
					if (ok) {
						loop: for (int i1 = 0; i1 < k; i1++) {
							for (int j1 = 0; j1 < 2 * k - 1; j1++) {
								if (b[i1][j1] != -1
										&& b[2 * k - 2 - i1][j1] != -1
										&& b[i1][j1] != b[2 * k - 2 - i1][j1]) {
									ok = false;
									break loop;
								}
							}
						}
					}
					if (ok) {
						loop: for (int i1 = 0; i1 < 2 * k - 1; i1++) {
							for (int j1 = 0; j1 < k; j1++) {
								if (b[i1][j1] != -1
										&& b[i1][2 * k - 2 - j1] != -1
										&& b[i1][j1] != b[i1][2 * k - 2 - j1]) {
									ok = false;
									break loop;
								}
							}
						}
					}
					if (ok) {
						out.println(k * k - n * n);
						return;
					}
					for (int i1 = 0; i1 < 2 * n - 1; i1++) {
						for (int j1 = 0; j1 < 2 * n - 1; j1++) {
							b[i + i1][j + j1] = -1;
						}
					}
				}
			}
		}
	}
}