import java.util.Scanner;

public class A {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		final int t = sc.nextInt();

		for (int tt = 1; tt <= t; ++tt) {

			final int n = sc.nextInt();

			int[] rows = new int[n + 1];
			for (int row = 1; row <= n; ++row) {
				rows[row] = readRow(n, sc);
			}

			int changes = 0;
			for (int row = 1; row < n; ++row) {
				if (rows[row] > row) {
					for (int rowb = row + 1; rowb <= n; ++rowb) {
						if (rows[rowb] <= row) {
							while (rowb > row) {
								int tmp = rows[rowb - 1];
								rows[rowb - 1] = rows[rowb];
								rows[rowb] = tmp;
								++changes;
								--rowb;
							}
							break;
						}
					}
				}
			}
			
			System.out.println("Case #" + tt + ": " + changes);
		}

	}

	static int readRow(final int n, Scanner sc) {

		int result = 0;
		String row = sc.next();
		for (int i = 1; i <= n; ++i) {
			if (row.charAt(i-1) == '1')
				result = i;
		}
		return result;
	}
}
