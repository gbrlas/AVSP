import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class B {
	
	private Scanner in;
	private PrintWriter out;
	
	// DATA
	double C;
	double F;
	double X;
	
	double currentTime = 0;
	double currentCookies = 0;
	double currentProduction = 2;
	
	private void readData() {
		C = in.nextDouble();
		F = in.nextDouble();
		X = in.nextDouble();
		
		currentTime = 0;
		currentCookies = 0;
		currentProduction = 2;
	}
	
	double timeToXNoC() {
		return X/currentProduction;
	}
	
	double timeToC() {
		return C/currentProduction;
	}
	
	double timeToXWithC() {
		return C/currentProduction  +  X/(currentProduction+F);
	}
	
	void buyC() {
		currentTime += timeToC();
		currentProduction += F;
	}
	
	
	
	private String solve() {
		while (timeToXWithC() < timeToXNoC()) {
			buyC();
		}
		return "" + (currentTime + timeToXNoC());
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		new B().execute();
	}

	public void execute() throws FileNotFoundException {
		in = new Scanner(new File("B-small-attempt0.in"));
		out = new PrintWriter("B-small-attempt0.out");
		
		int nrlines = in.nextInt();
		for (int i=0; i<nrlines; i++) {
			readData();
			String result = solve();
			out.println("Case #" + (i+1) + ": " + result);		
		}
			
		
        in.close();
        out.close();
	}

}