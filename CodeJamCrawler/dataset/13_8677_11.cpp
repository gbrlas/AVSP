import java.util.Scanner;


public class Bullseye {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int c = 1; c <= T; c++) {
			long r = sc.nextLong();
			long t = sc.nextLong();
			long cc = 0;
			r++;
			while (t >= 0) {
				t -= (2 * r - 1);
				r += 2;
				cc++;
			}
			cc--;
			System.out.println("Case #" + c + ": " + cc);
		}
	}

}
