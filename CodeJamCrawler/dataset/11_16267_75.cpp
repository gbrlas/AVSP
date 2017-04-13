import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QD {

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(r.readLine());
		int n, k;
		StringTokenizer st;
		for (int i = 0; i < t; i++) {
			n = Integer.parseInt(r.readLine());
			// k is number of elements that are not sorted yet
			k = n;
			st = new StringTokenizer(r.readLine(), " ");
			for (int j = 0; j < n; j++) {
				if (Integer.parseInt(st.nextToken()) == j + 1) {
					k--;
				}
			}
			System.out.print("Case #" + (i + 1) + ": ");
			System.out.format("%1$.6f\n", (double) k);
		}
		pw.flush();
	}
}
