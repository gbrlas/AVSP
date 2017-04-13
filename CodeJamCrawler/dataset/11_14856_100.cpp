import java.io.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int testsNumber = sc.nextInt();
		for (int test = 0; test < testsNumber; test++) {
			System.err.println("Test #" + test);
			int n = sc.nextInt();
			boolean[] first = new boolean[n];
			int[] b = new int[n];
			for (int i = 0; i < n; i++) {
				first[i] = sc.next().equals("O");
				b[i] = sc.nextInt();
			}
			out.println("Case #" + (test + 1) + ": " + solve(first, b));
		}
		out.close();
	}

	private static int solve(boolean[] isfirst, int[] b) {
		int n = b.length;
		ArrayList<Integer> first = new ArrayList<Integer>();
		ArrayList<Integer> second = new ArrayList<Integer>();
		first.add(1);
		second.add(1);
		for (int i = 0; i < n; i++) {
			if (isfirst[i]) {
				first.add(b[i]);
			} else {
				second.add(b[i]);
			}
		}
		int[] t1 = new int[first.size()];
		int[] t2 = new int[second.size()];
		for (int i = 0, j = 0, k = 0; i < n; i++) {
			if (isfirst[i]) {
				j++;
				t1[j] = Math.max(
						t1[j - 1] + Math.abs(first.get(j) - first.get(j - 1))
								+ 1, t2[k] + 1);
			} else {
				k++;
				t2[k] = Math.max(
						t2[k - 1] + Math.abs(second.get(k) - second.get(k - 1))
								+ 1, t1[j] + 1);
			}
		}
		return Math.max(t1[t1.length - 1], t2[t2.length - 1]);
	}
}
