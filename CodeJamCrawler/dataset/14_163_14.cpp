import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.math.RoundingMode;


public class CookieClicker {

static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) {
		int testCases = Integer.parseInt(readInput());
		String finalOutput = new String();
		for( int i=1; i <= testCases; i++ ) {
			finalOutput += doCookieCalculations(i) + "\n";
		}    
		System.out.print(finalOutput);
	}
	
	public static String doCookieCalculations(int testCase) {
		String output = "Case #" + String.valueOf(testCase) + ": ";
		String[] input = readInput().split(" ");
		BigDecimal C,F,X, rate;
		C = new BigDecimal(input[0]);
		F = new BigDecimal(input[1]);
		X = new BigDecimal(input[2]);
		
		rate = new BigDecimal("2");
		
		if(C.compareTo(X) == 1) {
			output += X.divide(rate, 10, RoundingMode.HALF_UP).toString();
		} else {
			output += doCalcultations(C, F, X, rate, new BigDecimal("0")).toString();
		}
		return output;
	}
	
	public static BigDecimal doCalcultations(BigDecimal C, BigDecimal F, BigDecimal X, BigDecimal rate, BigDecimal timeSpent) {
		BigDecimal time = C.divide(rate, 10, RoundingMode.HALF_UP);
		
		BigDecimal withoutBuyingTime = (X.subtract(C)).divide(rate, 10, RoundingMode.HALF_UP); //  (X-C)/rate;
		BigDecimal newRate = rate.add(F);
		
		if (withoutBuyingTime.compareTo(X.divide(newRate,10, RoundingMode.HALF_UP))!=1)
			return timeSpent.add(withoutBuyingTime).add(time);
		
		return doCalcultations(C, F, X, newRate, timeSpent.add(time));
	}
	
	public static String readInput() {
		String input = new String();
	    // assuming input is always correct 
	    try {
	    	input =  br.readLine();
	    	
	    } catch (IOException e) {
	        System.err.println("Wrong input!");
	    }
	    return input;
	}
}
