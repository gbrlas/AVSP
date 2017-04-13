import java.io.PrintWriter;
import java.util.Scanner;

public class A2 {
	static int[][] a = new int[100][100];
	static int n;
	static PrintWriter pw = new PrintWriter(System.out);

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		String s;
		char c;
		for (int i = 0; i < t; i++) {
			n = sc.nextInt();
			for (int j = 0; j < n; j++) {
				s = sc.next();
				for (int k = 0; k < n; k++) {
					c = s.charAt(k);
					switch (c) {
					case '0':
						a[j][k] = 0;
						break;
					case '1':
						a[j][k] = 1;
						break;
					case '.':
						a[j][k] = -1;
					}
				}
			}
			pw.println("Case #" + (i + 1) + ":");
			solve();
		}
		pw.flush();
	}

	private static void solve() {
		double[] rpi = new double[n];
		double[] wp = new double[n];
		double[] owp = new double[n];
		double[] oowp = new double[n];
		int count, owpCount;
		double sum, sum1;
		for (int i = 0; i < n; i++) {
			count = 0;
			sum = 0.0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 0) {
					count++;
				}
				if (a[i][j] == 1) {
					count++;
					sum += 1.0;
				}
			}
			wp[i] = sum / count;
			owpCount = count;
			sum = 0.0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] != -1) {
					sum1 = 0;
					count = 0;
					for (int k = 0; k < n; k++) {
						if (k != i) {
							if (a[j][k] == 0) {
								count++;
							}
							if (a[j][k] == 1) {
								count++;
								sum1 += 1.0;
							}
						}
					}
					sum1 /= count;
					sum += sum1;
				}
			}
			owp[i] = sum / owpCount;
		}
		for (int i = 0; i < n; i++) {
			oowp[i] = 0.0;
			count = 0;
			for (int j = 0; j < n; j++) {
				if (a[i][j] != -1) {
					count++;
					oowp[i] += owp[j];
				}
			}
			oowp[i] /= count;
			rpi[i] = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
			pw.println(rpi[i]);
		}
	}
}
