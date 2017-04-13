import java.util.Arrays;
import java.util.Scanner;


public class MinimumScalarProduct {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		
		for (int i = 1; i <= n; i++) {
			System.out.print("Case #" + i + ": ");
			
			int l = s.nextInt();
			long[] x = new long[l];
			for (int j = 0; j < l; j++) {
				x[j] = s.nextLong();
			}
			Arrays.sort(x);
			long[] y = new long[l];
			for (int j = 0; j < l; j++) {
				y[j] = s.nextLong();
			}
			Arrays.sort(y);
			
			long scalar = 0;
			for (int j = 0, k = l - 1; j < l; j++, k--) {
				scalar += x[j] * y[k];
			}
			
			System.out.println(scalar);
		}
		
	}

}
