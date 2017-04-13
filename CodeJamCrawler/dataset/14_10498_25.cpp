import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class GoogleCodeJam_CookieClickerAlpha {

	private static final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
	private static final PrintWriter printWriter = new PrintWriter(System.out);
	
	public static void main(String[] args) throws IOException {
		int testCount = Integer.parseInt(bufferedReader.readLine());
		String[] input;
		for(int currentCase = 1; currentCase <= testCount; currentCase++) {
			input = bufferedReader.readLine().split(" ");
			double c = Double.parseDouble(input[0]);
			double f = Double.parseDouble(input[1]);
			double x = Double.parseDouble(input[2]);
			printWriter.print("Case #" + currentCase + ": ");
			printWriter.format("%.7f\n", getMinimumTime(c, f, x));
			//printWriter.format("Case #%d: %.7lf\n", currentCase, getMinimumTime(c, f, x));
		}
		printWriter.flush();
	}

	private static double getMinimumTime(double c, double f, double x) {
		double currentBestTime = x / 2;
		double cumulativeBuyTime = 0.0;
		double currentRate = 2.0;
		
		while(true) {
			double buyTime = c / currentRate;
			cumulativeBuyTime += buyTime;
			currentRate += f;
			double candidateTime = cumulativeBuyTime + x / currentRate;
			//System.out.println(candidateTime + " " + currentBestTime);
			if(candidateTime < currentBestTime) {
				currentBestTime = candidateTime;
			} else {
				break;
			}
		}
		return currentBestTime;
	}
}
