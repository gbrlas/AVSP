import java.util.*;

public class A {

	public static void main(String[] args) {
		new A().run();
	}

	void run() {
		// Calculate goals for 1<= n <= 30
		int goalsArray[][] = new int[30][];
		for (int i = 0; i <= 29; i++) {
			goalsArray[i] = new int[2];
			if (i == 0) {
				goalsArray[i][0] = 2;
				goalsArray[i][1] = 1;
			} else {
				goalsArray[i][0] = goalsArray[i - 1][0] * 2;
				goalsArray[i][1] = goalsArray[i][0] - 1;
			}
		}
		int n = 0;
		int k = 0;
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			n = sc.nextInt();
			k = sc.nextInt();
			System.out.print("Case #" + i + ": ");
			if (k % goalsArray[n - 1][0] == goalsArray[n - 1][1]) {
				System.out.println("ON");
			} else {
				System.out.println("OFF");
			}
		}
	}
}
