import java.util.*;
import java.math.*;
import java.io.*;

public class Main implements Runnable {
	public static void main(String[] args) {
		new Thread(new Main()).start();
	}

	StringTokenizer st;
	PrintWriter out;
	BufferedReader br;
	boolean eof = false, in_out = false, std = false;

	private String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	private String nextLine() {
		String ret = "";
		try {
			ret = br.readLine();
		} catch (Exception e) {
			ret = "";
		}
		if (ret == null) {
			eof = true;
			return "$";
		}
		return ret;
	}

	private String nextString() {
		return nextToken();
	}

	private int nextInt() {
		return Integer.parseInt(nextToken());
	}

	private long nextLong() {
		return Long.parseLong(nextToken());
	}

	private double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	private BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	private static double EPS = 1e-12;
	String INFILE = "patience.in", OUTFILE = "patience.out";

	private void solve() {
		int T = nextInt();
		for (int www = 1; www <= T; ++www) {
			int n = nextInt();
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = nextLine().trim();
			}
			// System.err.println(Arrays.toString(s));
			int ans = 0;
			for (int i = 0; i < n; i++) {
				int id = -1;
				for (int j = i; j < n; j++) {
					if (s[j].lastIndexOf("1") <= i) {
						id = j;
						break;
					}
				}
				// System.err.println(id);
				for (int k = id; k > i; k--) {
					String ss = s[k];
					s[k] = s[k - 1];
					s[k - 1] = ss;
					++ans;
				}
			}
			out.println("Case #" + www + ": " + ans);
		}
	}

	public void run() {
		try {
			br = std ? new BufferedReader(new InputStreamReader(System.in))
					: new BufferedReader(new FileReader(new File(
							(in_out) ? INFILE : "input.txt")));
			out = std ? new PrintWriter(new OutputStreamWriter(System.out))
					: new PrintWriter(new File((in_out) ? OUTFILE
							: "output.txt"));
		} catch (Exception e) {
			System.exit(111);
		}
		solve();
		out.close();
	}
}