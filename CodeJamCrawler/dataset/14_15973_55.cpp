import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.text.DecimalFormat;

public class CookieClicker {

	private static String inputDir = "C:\\CodeJam2014\\Input\\";
	private static String outputDir = "C:\\CodeJam2014\\Output\\";

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(inputDir + "B-small-attempt0.in")));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputDir + "CookieClickerOutput.txt")));
		int testCases = Integer.parseInt(in.readLine().trim());
		for (int i = 0; i < testCases; i++) {
			String[] inputValues = in.readLine().trim().split("\\s");
			double c = Double.parseDouble(inputValues[0]);
			double f = Double.parseDouble(inputValues[1]);
			double x = Double.parseDouble(inputValues[2]);
			double totalTime = 0, cookieRate = 2.0;
			while (canBuyFarm(c, cookieRate, f, x)) {
				totalTime += c / cookieRate;
				cookieRate += f;
			}
			totalTime += x / cookieRate;
			DecimalFormat format = new DecimalFormat("#.0000000");
			out.write("Case #" + (i + 1) + ": " + format.format(totalTime));
			if (i != testCases - 1) {
				out.newLine();
			}
		}
		in.close();
		out.close();
	}

	private static boolean canBuyFarm(double c, double cookieRate, double f, double x) {
		double maxTime = x / cookieRate;
		double minTime = (c / cookieRate) + (x / (cookieRate + f));
		return minTime < maxTime;
	}
}
