import java.io.*;
import java.util.*;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("D.in"));
		PrintWriter out = new PrintWriter(new File("D.out"));
		int testsNumber = sc.nextInt();
		for (int test = 0; test < testsNumber; test++) {
			System.err.println("Test #" + test);
			int n = sc.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < n; i++) {
				a[i] = sc.nextInt() - 1;
			}
			out.println("Case #" + (test + 1) + ": "
					+ String.format(Locale.US, "%.6f", 1. * solve(a)));
		}
		out.close();
	}

	private static int solve(int[] a) {
		int n = a.length;
		int ans = 0;
		boolean[] was = new boolean[n];
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			int x = i;
			int count = 0;
			while (!was[x]) {
				was[x] = true;
				count++;
				x = a[x];
			}
			if (count > 1)
				ans += count;
		}
		return ans;
	}
}
