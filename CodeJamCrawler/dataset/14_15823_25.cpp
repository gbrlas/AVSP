import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;

public class CookieClicker {

	public static void main(String args[]) throws IOException {
		Input input = new Input(
				"D:/GoogleCodeJam/ActualCodeJam/B-large.in");

		ArrayList<String> testCases = input.getTestcases();
		
		
		  BufferedWriter writer = new BufferedWriter(new FileWriter
		  ("D:/GoogleCodeJam/ActualCodeJam/output1.txt"));
		 

		for (int i = 0; i < testCases.size(); i++) {
			double time = findTime1(testCases.get(i));
			
			DecimalFormat df = new DecimalFormat("#.0000000");

			System.out.println("Case #" + (i + 1) + ": " + df.format(time) + "\n");
			
			writer.write("Case #" + (i + 1) + ": " + df.format(time) + "\n");
		}
		
		writer.close();
	}

	private static double findTime1(String cookieParameters) {
		String[] values = cookieParameters.split(" ");

		double costOfCookieFarm = Double.parseDouble(values[0]);

		double framCookieProduce = Double.parseDouble(values[1]);

		double numberOfCookiesRequired = Double.parseDouble(values[2]);

		System.out.println(costOfCookieFarm+" "+framCookieProduce+" "+numberOfCookiesRequired);
		
		double rateOfCookieEarning = 2;

		double time = 0.0;

		double total_time = 0.0;

		double timeWithoutBuyingCookieFarm;

		double timeafterBuyingCookieFarm;

		do {
			timeWithoutBuyingCookieFarm = total_time
					+ (numberOfCookiesRequired / rateOfCookieEarning);

			time = costOfCookieFarm / rateOfCookieEarning;

			total_time = total_time + time;

			rateOfCookieEarning = rateOfCookieEarning + framCookieProduce;

			timeafterBuyingCookieFarm = total_time
					+ (numberOfCookiesRequired / rateOfCookieEarning);

		} while (timeafterBuyingCookieFarm < timeWithoutBuyingCookieFarm);

		return timeWithoutBuyingCookieFarm;
	}
}