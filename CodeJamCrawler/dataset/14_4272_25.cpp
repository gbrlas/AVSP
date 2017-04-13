import java.io.BufferedReader;
import java.io.FileReader;


public class MainProgram {

	static BufferedReader in = null;
	static double C, F, X;
	static double currentCookies = 0;
	static double timeSpent = 0;
	static double rateOfProduction = 2.0;
	
	public static void main(String[] args) throws Exception {
		in = new BufferedReader(new FileReader("/Users/himanshugupta/workspace/practice/CookieGenerator/B-large.in")); 
		int T = Integer.parseInt(in.readLine());
		for (int i=0; i<T; i++){
			readInput();
			currentCookies = 0;
			timeSpent = 0;
			rateOfProduction = 2.0;
			System.out.println("Case #"+(i+1)+": "+getOutput());
		}
		in.close();
	}

	private static double getOutput() {
		while (currentCookies < X){
			double time1 = timeSpent + ((X - currentCookies) / rateOfProduction);
			double time2 = timeSpent + ((C - currentCookies) / rateOfProduction) + (X / (rateOfProduction + F));
			if (time1 < time2){
				time1 = Math.round(time1 * 10000000.0);
				time1 /= 10000000.0;
				return time1;
			}
			else{
				timeSpent += ((C - currentCookies) / rateOfProduction);
				currentCookies = 0;
				rateOfProduction += F;
			}
		}
		return 0.0;
	}

	
	
	private static void readInput() throws Exception {
		String str = in.readLine();
		String[] strArray = str.split(" ");
		C = Double.parseDouble(strArray[0]);
		F = Double.parseDouble(strArray[1]);
		X = Double.parseDouble(strArray[2]);
	}

}
