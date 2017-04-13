import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class FairAndSquare {

	public static boolean isPal(long x) {
		String s = Long.toString(x);
		int len = s.length() / 2 + 1;
		for (int i = 0; i < len; i++) {
			if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		List<Long> list = new ArrayList<Long>();
		long lim = 100000000000000L;
		for (long i = 1; i <= lim; i++) {
			long sq = i * i;
			if (sq > lim) {
				break;
			}
			if (isPal(i) && isPal(sq)) {
				list.add(sq);
			}
		}
		for (int t = 1; t <= T; t++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			int c = 0;
			for (int i = 0; i < list.size(); i++) {
				long x = list.get(i);
				if (a <= x && x <= b) {
					c++;
				}
			}
			System.out.println("Case #" + t + ": " + c);
		}
	}

}
