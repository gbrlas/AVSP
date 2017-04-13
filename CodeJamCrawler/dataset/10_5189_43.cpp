import java.util.Scanner;


class ProblemA {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int v[] = new int[31];
		v[1] = 1;
		for (int i = 2; i < 31; i++) {
			v[i] = v[i - 1] * 2 + 1;
		}
		for (int tt = 1; tt <= t; tt++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			boolean res = false;
			int nro = v[n];
			while (nro < k) {
				nro += v[n] + 1;
			}
			if (nro == k) {
				res = true;
			}
			System.out.println("Case #" + tt + ": " + (res ? "ON" : "OFF"));
		}
	}

}
