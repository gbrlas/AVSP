import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("c.in"));
		PrintWriter out = new PrintWriter("c.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ":");
			solve(in, out);
			System.err.println("Test #" + i);
		}
		out.close();
	}

	static final Random rand = new Random(123123L);

	static void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int[] best = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			best[i] = in.nextInt() - 1;
		}
		int q = 50000000;
		all: while (true) {
			if (--q < 0) {
				out.println(" Impossible");
				return;
			}
			long[] x = new long[n];
			for (int i = 0; i < n; i++) {
				x[i] = rand.nextInt(100);
			}
			int[] z = new int[n - 1];
			for (int i = 0; i < n - 1; i++) {
				z[i] = i + 1;
				for (int j = i + 2; j < n; j++) {
					if ((x[j] - x[i]) * (z[i] - i) > (x[z[i]] - x[i]) * (j - i)) {
						z[i] = j;
					}
				}
				if (z[i] != best[i]) {
					continue all;
				}
			}
			for (int i = 0; i < n; i++) {
				out.print(" " + x[i]);
			}
			out.println();
			return;
		}
	}
}
