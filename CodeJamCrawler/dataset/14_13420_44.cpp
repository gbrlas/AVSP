import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemB {
	public static void main(String[] args) {
	    try {
	    	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	        int inputLines = Integer.parseInt(in.readLine());
	        
	        for (int i = 1, length = inputLines; i <= length; i++) {
	        	String line = in.readLine();
	        	double[] vars = new double[4];
	        	String[] var = line.split(" ");
	        	for(int j = 0; j < var.length; j++) {
	        		vars[j] = Double.parseDouble(var[j]);
	        	}
	        	vars[3] = 2;
	        	
	        	System.out.print("Case #" + i + ": ");
	        	lengthToMakeCookies(0,vars);
	        	System.out.println();
	        }
	    }
	    catch (IOException e) {
	    	
	    }
	}
	
	public static void lengthToMakeCookies(double curTotal, double[] vars) {
		double howManySecs = vars[0] / vars[3];
		vars[3] += vars[1];
		double howManyNextSecs = vars[0] / vars[3];
		
		double howLongItWouldTake = curTotal + (howManySecs * (vars[2] / vars[0]));
		double howLongItWouldTakeIfNext = curTotal + howManySecs + (howManyNextSecs * (vars[2] / vars[0]));
		
		if (howLongItWouldTakeIfNext >= howLongItWouldTake) {
			System.out.printf("%.7f", howLongItWouldTake);
		} else {
			lengthToMakeCookies(curTotal + howManySecs, vars);
		}
	}
}
