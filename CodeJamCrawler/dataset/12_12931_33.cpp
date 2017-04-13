import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("b.in"));
		PrintWriter out = new PrintWriter("b.out");
		int testCount = Integer.parseInt(in.nextLine().trim());
		for (int i = 0; i < testCount; i++) {
			out.print("Case #" + (i + 1) + ":");
			solve(in, out);
		}
		out.close();
	}

	static final Random rand = new Random(1231231L);

	static void solve(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int w = in.nextInt();
		int l = in.nextInt();
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			r[i] = in.nextInt();
		}
		all: while (true) {
			int[] p = new int[n];
			for (int i = 1; i < n; i++) {
				p[i] = i;
				int j = rand.nextInt(i + 1);
				int t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
			double[] x = new double[n];
			double[] y = new double[n];
			for (int i : p) {
				x[i] = rand.nextDouble() * w;
				y[i] = rand.nextDouble() * l;
				boolean ok = true;
				for (int j : p) {
					if (j == i) {
						break;
					}
					double dx = x[i] - x[j];
					double dy = y[i] - y[j];
					double dist = Math.sqrt(dx * dx + dy * dy);
					if (dist < r[i] + r[j] + 1e-8) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					continue all;
				}
			}
			for (int i = 0; i < n; i++) {
				out.print(" " + x[i] + " " + y[i]);
			}
			out.println();
			return;
		}
	}
}
