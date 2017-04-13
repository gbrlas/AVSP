import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemA {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for (int i = 1; i <= T; i++) {
			int ans1 = scan.nextInt();
			int[] row1 = getGrid(scan)[ans1 - 1];
			/*
			 * for (int j = 0; j < row1.length; j++) { System.out.print(row1[j]
			 * + " "); } System.out.println();
			 */
			int ans2 = scan.nextInt();
			int[] row2 = getGrid(scan)[ans2 - 1];
			/*
			 * for (int j = 0; j < row2.length; j++) { System.out.print(row2[j]
			 * + " "); } System.out.println();
			 */
			String res = solve(row1, row2);
			System.out.println("Case #" + i + ": " + res);
		}

		scan.close();
	}

	public static int[][] getGrid(Scanner sc) {
		int[][] res = new int[4][4];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				res[i][j] = sc.nextInt();
			}
		}

		return res;
	}

	public static String solve(int[] r1, int[] r2) {

		Set<Integer> s1 = new HashSet<Integer>(), s2 = new HashSet<Integer>();

		for (int i = 0; i < 4; i++) {
			s1.add(r1[i]);
			s2.add(r2[i]);
		}

		s1.retainAll(s2);

		if (s1.size() == 0) {
			return "Volunteer cheated!";
		} else if (s1.size() > 1) {
			return "Bad magician!";
		} else {
			return s1.iterator().next().toString();
		}

	}
}
