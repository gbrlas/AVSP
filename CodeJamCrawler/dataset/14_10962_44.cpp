import java.util.*;
import java.io.*;
import java.math.*;

import static java.util.Arrays.*;
import static java.lang.Math.*;
import static java.util.Collections.*;
import static java.lang.System.out;

public class Main {
	static boolean LOCAL = System.getSecurityManager() == null;
	Scanner in = new Scanner(System.in);

	void run() {
		int t = in.nextInt();
		for (int i = 1; i <= t; i++) {
			out.printf("Case #%d: ", i);
			solve();
		}
	}
	private void solve() {
		int n = in.nextInt();
		double[] a = new double[n];
		double[] b = new double[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextDouble();
		}
		for (int i = 0; i < n; i++) {
			b[i] = in.nextDouble();
		}
		sort(a);
		sort(b);
		a = reverse(a);
		b = reverse(b);
		int t = 0, i = 0, ta = 0, tb = 0;
		while (t < n) {
			while (t < n && a[i] > b[t]) {
				i++; t++; ta++;
			}
			while (t < n && a[i] <= b[t]) t++;
		}
		t = 0; i = 0;
		while (t < n) {
			while (t < n && b[i] > a[t]) {
				i++; t++; tb++;
			}
			while (t < n && b[i] <= a[t]) t++;
		}
		out.println(ta + " " + (n - tb));
	}
	
	private double[] reverse(double[] ds) {
		double[] res = new double[ds.length];
		for (int i = 0; i < ds.length; i++) {
			res[i] = ds[ds.length - i - 1];
		}
		return res;
	}
	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		if (LOCAL) {
			try {
				System.setIn(new FileInputStream("./../in"));
				System.setOut(new PrintStream("./../out"));
			} catch (IOException e) {
				LOCAL = false;
			}
		}
		long start = System.nanoTime();
		new Main().run();
		if (LOCAL)
			System.err.printf("[Time %.6fs]%n",
					(System.nanoTime() - start) * 1e-9);
	}
}

class Scanner {
	BufferedReader br;
	StringTokenizer st;

	Scanner(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		eat("");
	}

	private void eat(String string) {
		st = new StringTokenizer(string);
	}

	String nextLine() {
		try {
			return br.readLine();
		} catch (IOException e) {
			return null;
		}
	}

	boolean hasNext() {
		while (!st.hasMoreTokens()) {
			String s = nextLine();
			if (s == null)
				return false;
			eat(s);
		}
		return true;
	}

	String next() {
		hasNext();
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}
}

