import java.util.Scanner;

public class B {
	void solve() {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caseNum = 1; caseNum <= cases; caseNum++) {
			System.out.print("Case #" + caseNum + ": ");
			int C = sc.nextInt();
			int D = sc.nextInt();

			int[][] vendors = new int[C][2];
			for (int i = 0; i < C; i++) {
				int P = sc.nextInt();
				int V = sc.nextInt();
				vendors[i][0] = P;
				vendors[i][1] = V;
			}

			double maxTime = 0;

			for (int i = 1; i <= C; i++) {
				int numVendors = 0;
				for (int j = 0; j + i <= C; j++) {
					// numVendors = 0;
					if (j == 0) {
						for (int k = 0; k < i; k++) {
							numVendors += vendors[j + k][1];
							// System.out.println(vendors[j+k][1]+" at: "+(j+k));
						}
					} else {
						numVendors = numVendors - vendors[j - 1][1] + vendors[j + i - 1][1];
					}
					int distance = vendors[j + i - 1][0] - vendors[j][0];
					// System.out.println("--"+vendors[j+i-1][0]+"  "+vendors[j][0]);
					double time = ((double) (numVendors - 1) * (double) D - distance) / 2.0;

					if (time > maxTime) {
						// System.out.println(numVendors+" "+distance+" "+D+" "+i);
						maxTime = time;
					}
				}
			}

			System.out.print(maxTime + "\n");
		}
	}

	public static void main(String[] args) {
		new B().solve();
	}
}
