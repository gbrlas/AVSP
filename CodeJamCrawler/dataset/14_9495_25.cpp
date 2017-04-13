import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();

		for (int i = 1; i <= T; i++) {
			double C = scan.nextDouble();
			double F = scan.nextDouble();
			double X = scan.nextDouble();

			double res = solve(C, F, X);
			System.out.println(String.format("Case #%d: %.7f", i, res));
		}

		scan.close();
	}

	public static double solve(double c, double f, double x) {

		double[] farmTimes = new double[100000];

		double prevWinTime = Double.MAX_VALUE;

		farmTimes[0] = 0;

		for (int i = 1; i < farmTimes.length - 1; i++) {
			double rate = 2 + f * (i - 1);
			double farmTime = c / rate;
			double winTime = farmTimes[i - 1] + x / rate;

			farmTimes[i] = farmTimes[i - 1] + farmTime;
			if (winTime > prevWinTime) {
				return prevWinTime;
			}
			prevWinTime = winTime;
		}

		return 0;
	}
}
