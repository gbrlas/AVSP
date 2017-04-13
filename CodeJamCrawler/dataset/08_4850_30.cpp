import java.util.Scanner;


public class CropTriangles {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		
		for (int i = 1; i <= N; i++) {
			System.out.print("Case #" + i + ": ");
			
			int n = s.nextInt();
			long A = s.nextLong();
			long B = s.nextLong();
			long C = s.nextLong();
			long D = s.nextLong();
			
			long[] x = new long[n];
			long[] y = new long[n];
			x[0] = s.nextLong();
			y[0] = s.nextLong();
			long M = s.nextLong();
			for (int j = 1; j < n; j++) {
				x[j] = (A * x[j - 1] + B) % M;
				y[j] = (C * y[j - 1] + D) % M;
			}
			
			long count = 0;
			for (int a = 0; a < n - 2; a++) {
				for (int b = a + 1; b < n - 1; b++) {
					for (int c = b + 1; c < n; c++) {
						if ((x[a] + x[b] + x[c]) % 3 == 0 
								&& (y[a] + y[b] + y[c]) % 3 == 0) {
							count++;
						}
					}
				}
			}
			
			System.out.println(count);
		}

	}

}
