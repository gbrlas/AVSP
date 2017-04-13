import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QD {
	static int limit = 10;
	static long[] f = new long[11];
	static long[][] c = new long[11][11];
	static long[][] d = new long[11][11];
	static double[] e = new double[11];

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		calculate();
		int t = Integer.parseInt(r.readLine());
		int n, k;
		StringTokenizer st;
		for (int i = 0; i < t; i++) {
			n = Integer.parseInt(r.readLine());
			// k is number of elements that are not sorted yet
			k = n;
			st = new StringTokenizer(r.readLine(), " ");
			for (int j = 0; j < n; j++) {
				if (Integer.parseInt(st.nextToken()) == j + 1) {
					k--;
				}
			}
			System.out.print("Case #" + (i + 1) + ": ");
			System.out.format("%1$.6f\n", solve(k));
		}
		pw.flush();
	}

	private static void calculate() {
		// f(n) = n!
		f[0] = 1;
		for (int i = 1; i <= limit; i++) {
			f[i] = f[i - 1] * i;
		}
		// c(n, m) = n!/(m!*(n-m)!)
		for (int i = 0; i <= limit; i++) {
			for (int j = 0; j <= i; j++) {
				c[i][j] = f[i] / f[j] / f[i - j];
			}
		}
		d[0][0] = 1;
		d[1][0] = 0;
		// d(n + 2, 0) = (n + 1)*(d(n + 1, 0) + d(n, 0))
		for (int i = 2; i <= limit; i++) {
			d[i][0] = (i - 1) * (d[i - 1][0] + d[i - 2][0]);
		}
		// d(n, m) = c(n, m) * d(n - m, 0)
		for (int i = 0; i <= limit; i++) {
			for (int j = 1; j <= i; j++) {
				d[i][j] = c[i][j] * d[i - j][0];
			}
		}
		//
		e[0] = 0.0;
		e[1] = 0.0;
		for (int i = 2; i <= limit; i++) {
			e[i] = 0.0;
			e[i] = f[i];
			for (int k = 1; k <= i; k++) {
				e[i] += e[i - k] * d[i][k];
			}
			e[i] /= f[i] - d[i][0];
		}
	}

	private static double solve(int k) {
		return e[k];
	}
}
