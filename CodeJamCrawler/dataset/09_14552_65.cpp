import java.util.Arrays;
import java.util.Scanner;

public class Bribe {
	private static void swap(int[] p, int i, int j) {

		int t = p[i];
		p[i] = p[j];
		p[j] = t;
	}

	public static boolean nextPerm(int[] p) {

		int i;

		for (i = p.length - 1; i-- > 0 && p[i] > p[i + 1];)
			;

		if (i < 0)
			return false;

		int j;

		for (j = p.length; --j > i && p[j] < p[i];)
			;

		swap(p, i, j);

		for (j = p.length; --j > ++i; swap(p, i, j))
			;

		return true;
	}

	static int p;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tst = in.nextInt();
		for (int tt = 1; tt <= tst; ++tt) {
			p = in.nextInt();
			int q = in.nextInt();
			int[] pr = new int[q];
			for (int i = 0; i < pr.length; ++i)
				pr[i] = in.nextInt();
			Arrays.sort(pr);
			int ans = (int) 1e9;
			do {
				ans = Math.min(ans, count(pr));
				// System.out.println(Arrays.toString(pr));
			} while (nextPerm(pr));
			System.out.printf("Case #%d: %d\n", tt, ans);
		}
	}

	private static int count(int[] pr) {
		int ans = 0;
		boolean[] mask = new boolean[p + 1];
		Arrays.fill(mask, true);
		mask[0] = false;
		for (int rel : pr) {
			int t = 0;
			mask[rel] = false;
			for (int i = rel - 1; good(mask, i) && mask[i]; --i)
				++t;
			for (int i = rel + 1; good(mask, i) && mask[i]; ++i)
				++t;
//			System.out.print(t + " ");
			ans += t;
		}
//		System.out.println();
		return ans;
	}

	static boolean good(boolean[] pr, int x) {
		return x >= 0 && x < pr.length;
	}

}
