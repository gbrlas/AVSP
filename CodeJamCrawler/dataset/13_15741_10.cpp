package codejam.r2;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;

public class ProblemA {
	PrintWriter out;
	BufferedReader buf;
	int[] ns;

	void run() throws IOException {
		// buf = new BufferedReader(new InputStreamReader(System.in));
		// out = new PrintWriter(new OutputStreamWriter(System.out));
		buf = new BufferedReader(new InputStreamReader(new FileInputStream(
				"/home/hex/Downloads/A-small-attempt11.in")));
		out = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
				"/home/hex/Downloads/A-small-attempt11.out")));
		solve();
		out.flush();
		out.close();
	}

	void solve() throws IOException {
		Integer t = Integer.valueOf(buf.readLine());
		for (int i = 1; i <= t; i++) {
			int res = doCase();
			out.println(String.format("Case #%d: %d", i, res));

		}
	}

	private int doCase() throws IOException {
		String[] an = buf.readLine().split(" ");
		int a = Integer.valueOf(an[0]);
		int n = Integer.valueOf(an[1]);
		String[] nss = buf.readLine().split(" ");
		ns = new int[n];
		for (int i = 0; i < nss.length; i++) {
			ns[i] = Integer.valueOf(nss[i]);
		}
		Arrays.sort(ns);

		int pas = rec(a, 0);

		return pas;
	}

	private int rec(int mim, int idx) {
		if (idx >= ns.length) {
			return 0;
		}

		if (mim > ns[idx]) {
			return rec(mim + ns[idx], idx + 1);
		} else {
			int rd = rec(mim, idx + 1) + 1;
			int ri;
			if (mim > 1) {
				ri = rec(mim + mim - 1, idx) + 1;
			} else {
				ri = Integer.MAX_VALUE;
			}
			return Math.min(rd, ri);
		}
	}

	public static void main(String[] args) throws IOException {
		new ProblemA().run();

	}

}
