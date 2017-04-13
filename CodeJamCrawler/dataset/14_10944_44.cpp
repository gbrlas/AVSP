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
		int[] is = new int[4];
		for (int i = 0; i < 4; i++) {
			if (i + 1 == n) {
				for (int j = 0; j < 4; j++) {
					is[j] = in.nextInt(); 
				}
			} else {
				for (int j = 0; j < 4; j++) in.next();
			}
		}
		int m = in.nextInt();
		int[] js = new int[4];
		for (int i = 0; i < 4; i++) {
			if (i + 1 == m) {
				for (int j = 0; j < 4; j++) {
					js[j] = in.nextInt(); 
				}
			} else {
				for (int j = 0; j < 4; j++) in.next();
			}
		}
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (contains(js, is[i])) cnt++;
		}
		if (cnt == 0) out.println("Volunteer cheated!");
		else if (cnt > 1) out.println("Bad magician!");
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (is[i] == js[j]) out.println(is[i]);
				}
			}
		}
	}

	private boolean contains(int[] js, int i) {
		for (int j : js) if (j == i) return true;
		return false;
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

