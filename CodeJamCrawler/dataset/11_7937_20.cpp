import java.util.*;
import java.io.*;

public class A {

	int minGames(int n) {
		if (n == 0) {
			return 0;
		}
		int minN = -1;

		for (int i = 1; i < 100; i++) {
			if (i * n % 100 == 0) {
				minN = i;
				break;
			}
		}
		if (minN > -1)
			return minN;

		return 100;
	}

	void solve() {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");

			int N = sc.nextInt();
			int PD = sc.nextInt();
			int PG = sc.nextInt();

			int minN = minGames(PD);

			if (minN == -1 || minN > N || (PD < 100 && PG == 100) || (PD > 0 && PG == 0)) {
				System.out.print("Broken");
			} else {
				System.out.print("Possible");
			}

			System.out.print("\n");
		}
	}

	public static void main(String[] args) {
		new A().solve();
	}
}
