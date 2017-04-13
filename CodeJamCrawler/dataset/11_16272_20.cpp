import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A1 {
	static int gcd(int a, int b) {
		int t;
		while (b != 0) {
			t = b;
			b = a % b;
			a = t;
		}
		return a;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(br.readLine());
		long n;
		int pd, pg;
		StringTokenizer st;
		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Long.parseLong(st.nextToken());
			pd = Integer.parseInt(st.nextToken());
			pg = Integer.parseInt(st.nextToken());
			pw.println("Case #" + (i + 1) + ": " + solve(n, pd, pg));
		}
		pw.flush();
	}

	private static String solve(long n, int pd, int pg) {
		if (pg == 100 && pd != 100) {
			return "Broken";
		}
		if (pg == 0 && pd != 0) {
			return "Broken";
		}
		int min = 100 / gcd(100, pd);
		if (min <= n) {
			return "Possible";
		} else {
			return "Broken";
		}
	}
}
