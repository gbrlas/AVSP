import java.io.*;
import java.util.*;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C.in"));
		PrintWriter out = new PrintWriter(new File("C.out"));
		int testsNumber = sc.nextInt();
		for (int test = 0; test < testsNumber; test++) {
			System.err.println("Test #" + test);
			int n = sc.nextInt();
			int[] a = new int[n];
			for (int i = 0; i < a.length; i++) {
				a[i] = sc.nextInt();
			}
			out.println("Case #" + (test + 1) + ": " + solve(a));
		}
		out.close();
	}

	private static String solve(int[] a) {
		int xor = 0;
		int sum = 0;
		Arrays.sort(a);
		for (int i = 0; i < a.length; i++) {
			sum += a[i];
			xor ^= a[i];
		}
		if (xor != 0) {
			return "NO";
		} else {
			return sum - a[0] + "";
		}
	}
}
