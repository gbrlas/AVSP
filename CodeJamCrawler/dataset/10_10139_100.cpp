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
		int t = nextInt();
		for (int i = 0; i < t; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solve2();
		}
	}

	HashMap<String, Integer>[] d;

	void add(String s) {
		StringTokenizer st = new StringTokenizer(s, "/");
		int i = 0;
		while (st.hasMoreTokens()) {
			String dirName = st.nextToken();
			if (d[i] == null) {
				d[i] = new HashMap<String, Integer>();
			}
			if (d[i].containsKey(dirName)) {
				i = d[i].get(dirName);
			} else {
				++curDir;
				d[i].put(dirName, curDir);
				i = curDir;
			}
		}		
	}

	int curDir;

	@SuppressWarnings("unchecked")
	void solve2() {
		d = new HashMap[100000];
		d[0] = new HashMap<String, Integer>();
		int n = nextInt();
		int m = nextInt();
		curDir = 1;
		for (int i = 0; i < n; i++) {
			String s = nextToken();
			add(s);
		}
		int ans1 = curDir;
		for (int i = 0; i < m; i++) {
			String s = nextToken();
			add(s);
		}
		int ans2 = curDir;
		out.println(ans2 - ans1);
	}
}