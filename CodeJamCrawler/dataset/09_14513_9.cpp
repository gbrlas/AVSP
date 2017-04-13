import java.util.LinkedList;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	static boolean isHappy(int num, int base) {
		TreeSet<Integer> s = new TreeSet<Integer>();
		for (;;) {
			s.add(num);
			num = work(num, base);
			if (num == 1)
				return true;
			if (s.contains(num))
				return false;
		}
	}

	private static int work(int num, int base) {
		int ans = 0;
		while (num != 0) {
			int t = num % base;
			ans += t * t;
			num /= base;
		}
		return ans;
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tes = Integer.parseInt(in.nextLine());
		for (int i = 0; i < tes; ++i) {
			StringTokenizer st = new StringTokenizer(in.nextLine());
			LinkedList<Integer> ls = new LinkedList<Integer>();
			while (st.hasMoreTokens()) {
				ls.add(Integer.parseInt(st.nextToken()));
			}
			outer: for (int j = 2;; ++j) {
				for (int base : ls)
					if (!isHappy(j, base)) {
						continue outer;
					}
				System.out.println("Case #" + (i + 1) + ": " + j);
				break;
			}
		}
	}
}
