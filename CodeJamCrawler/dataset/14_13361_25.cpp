import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CookieClicker {

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader reader = new BufferedReader(new FileReader(
				"B-small-attempt1.in"));
		int caseNumber = Integer.parseInt(reader.readLine());

		BufferedWriter writer = new BufferedWriter(new FileWriter(
				"CookieClicker.out"));

		final int cookieRatePerSecond = 2;

		for (int i = 1; i <= caseNumber; i++) {

			String line = reader.readLine();
			String[] conditions = line.split(" ");

			double cookieFarmCost = Double.parseDouble(conditions[0].trim());
			double cookieFarmOffset = Double.parseDouble(conditions[1].trim());
			double targetCookieNumber = Double
					.parseDouble(conditions[2].trim());

			double minimumTime = getMinimumTimeForTargetCookie(cookieFarmCost,
					cookieFarmOffset, targetCookieNumber, cookieRatePerSecond);

			writer.write(String.format("Case #%d: %.7f\n", i, minimumTime));
		}

		reader.close();
		writer.flush();
		writer.close();
	}

	private static double getMinimumTimeForTargetCookie(double cookieFarmCost,
			double cookieFarmOffset, double targetCookieNumber,
			double cookieRatePerSecond) {

		double total = 0;

		do {
			double timeAttemptedToBuyFarm = cookieFarmCost
					/ cookieRatePerSecond;

			double timeWithoutBuyFarm = total
					+ (targetCookieNumber / cookieRatePerSecond);

			double timeAfterBuyFarm = total
					+ timeAttemptedToBuyFarm
					+ (targetCookieNumber / (cookieRatePerSecond + cookieFarmOffset));

			if (timeWithoutBuyFarm < timeAfterBuyFarm) {
				total = timeWithoutBuyFarm;
				break;

			} else {
				cookieRatePerSecond += cookieFarmOffset;
				total += timeAttemptedToBuyFarm;
			}

		} while (true);

		return total;
	}

}
