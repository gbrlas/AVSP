import java.math.BigDecimal;
import java.util.Scanner;

public class D {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		final int t = sc.nextInt();

		for (int tt = 1; tt <= t; ++tt) {

			final int n = sc.nextInt();

			double result;
			if (n == 1) {
				sc.nextInt();
				sc.nextInt();
				result = sc.nextInt();
			} else if (n == 2) {
				sc.nextInt();
				sc.nextInt();
				result = sc.nextInt();
				sc.nextInt();
				sc.nextInt();
				result = Math.max(result, sc.nextInt());
			} else {
				final int x1 = sc.nextInt();
				final int y1 = sc.nextInt();
				final int r1 = sc.nextInt();
				final int x2 = sc.nextInt();
				final int y2 = sc.nextInt();
				final int r2 = sc.nextInt();
				final int x3 = sc.nextInt();
				final int y3 = sc.nextInt();
				final int r3 = sc.nextInt();

				double result1 = Math.max(dist(x1, y1, r1, x2, y2, r2), r3);
				double result2 = Math.max(dist(x1, y1, r1, x3, y3, r3), r2);
				double result3 = Math.max(dist(x2, y2, r2, x3, y3, r3), r1);
				result = Math.min(result1, Math.min(result2, result3));
			}

			System.out.println("Case #" + tt + ": " + new BigDecimal(result));
		}

	}

	static double dist(int x1, int y1, int r1, int x2, int y2, int r2) {

		int x = x1 - x2;
		int y = y1 - y2;
		double dist = Math.sqrt(x * x + y * y);
		return (dist + r1 + r2) / 2;
	}
}
