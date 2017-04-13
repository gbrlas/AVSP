import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class GCJ2012A2 {
	static int[] s = new int[200];
	static PrintWriter pw = new PrintWriter(System.out);
	static ArrayList<Integer> a = new ArrayList<Integer>();

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(r.readLine());
		StringTokenizer st;
		int n, x;
		for (int i = 1; i <= t; i++) {
			st = new StringTokenizer(r.readLine());
			n = Integer.parseInt(st.nextToken());
			x = 0;
			for (int j = 0; j < n; j++) {
				s[j] = Integer.parseInt(st.nextToken());
				x += s[j];
			}
			pw.print("Case #" + i + ":");
			solve(n, x);
			pw.println();
		}
		pw.flush();
	}

	private static void solve(int n, int x) {
		double result;
		double low, high, b, middle, sum;
		for (int i = 0; i < n; i++) {
			a.clear();
			for (int j = 0; j < n; j++) {
				if (j != i) {
					a.add(s[j]);
				}
			}
			low = 0;
			high = 100;
			while (high - low > 0.0000001) {
				middle = (low + high) / 2;
				b = s[i] + x * middle / 100;
				sum = 0;
				for (int k : a) {
					if (k < b) {
						sum += b - k;
					}
				}
				if (sum > x * (100 - middle) / 100) {
					high = middle;
				} else {
					low = middle;
				}
			}
			result = high;
			pw.format(" %1.6f", result);
		}
	}

}
