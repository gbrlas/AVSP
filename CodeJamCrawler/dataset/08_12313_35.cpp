import java.io.FileReader;
import java.util.Scanner;

public class R2B {
	static Scanner s;
	static void suan() throws Exception {
		long n = s.nextLong();
		long m = s.nextLong();
		long a = s.nextLong();
		if (a > m * n) {
			System.out.println("IMPOSSIBLE");
			return;
		}
		System.out.println("0 0 "+n+" "+1+" "+(a % n == 0 ? 0 : n - a % n)+" "+((a - 1) / n + 1));
	}
	public static void main(String[] args) throws Exception {
		s = new Scanner(new FileReader("B-small-attempt1.in.txt"));
		int c = s.nextInt();
		for (int i = 1; i <= c; ++i) {
			System.out.print("Case #" + i + ": ");
			suan();
		}
	}
}
