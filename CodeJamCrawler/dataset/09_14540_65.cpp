import java.util.Locale;
import java.util.Scanner;

public class Fireflies {
	public static double sumX = 0.0, sumY = 0.0, sumZ = 0.0, sumVX = 0.0,
			sumVY = 0.0, sumVZ = 0.0;

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(System.in);
		int tst = in.nextInt();
		for (int z = 0; z < tst; ++z) {
			int n = in.nextInt();
			sumX = 0.0;
			sumY = 0.0;
			sumZ = 0.0;
			sumVX = 0.0;
			sumVY = 0.0;
			sumVZ = 0.0;
			for (int i = 0; i < n; ++i) {
				sumX += in.nextInt();
				sumY += in.nextInt();
				sumZ += in.nextInt();
				sumVX += in.nextInt();
				sumVY += in.nextInt();
				sumVZ += in.nextInt();
			}
			sumX /= n;
			sumY /= n;
			sumZ /= n;
			sumVX /= n;
			sumVY /= n;
			sumVZ /= n;

			// System.out.printf("%f %f %f", sumX, sumY, sumZ);
			double t = bins(0.0, 1e8);
			System.out.printf("Case #%d: %.8f %.8f\n", (z + 1), f(t), t);
		}

	}

	private static double bins(double left, double right) {
		double leftThird = (left * 2 + right) / 3;
		double rightThird = (left + right * 2) / 3;
		if (Math.abs(left - right) < 1e-8)
			return (left + right) / 2;
		if (f(leftThird) > f(rightThird))
			return bins(leftThird, right);
		else
			return bins(left, rightThird);
	}

	static double f(double mid) {
		return Math.sqrt(Math.pow(sumX + sumVX * mid, 2)
				+ Math.pow(sumY + sumVY * mid, 2)
				+ Math.pow(sumZ + sumVZ * mid, 2));
	}
}
