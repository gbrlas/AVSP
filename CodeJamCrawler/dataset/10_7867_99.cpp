import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class FairWarning {
	String PROBLEM_ID = "fairwarning";
	enum TestType { EXAMPLE, SMALL, LARGE }
	TestType TYPE = TestType.LARGE;
	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch ( TYPE ) {
		case EXAMPLE: result += "example"; break;
		case SMALL:   result += "small"; break;
		case LARGE:   result += "large"; break;
		}
		return result;
	}
	public String getInFileName() { return getFileName() + ".in"; }
	public String getOutFileName() { return getFileName() + ".out"; }
	
	public static void main(String[] args) throws Exception {
		new FairWarning();
	}
	
	public FairWarning() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			BigInteger[] list = new BigInteger[n];
			for ( int i = 0; i < n; i++ ) {
				String ggg = scan.next();
				list[i] = new BigInteger(ggg);	
			}
			BigInteger gcd = null;
			for ( int i = 0; i < n; i++) {
				for ( int j = i + 1; j < n; j++) {
					BigInteger delta = list[i].subtract(list[j]).abs();
					if ( gcd == null ) { gcd = delta; }
					else {
						gcd = gcd.gcd(delta);
					}
				}
			}
//			System.out.println("gcd = " + gcd);
			BigInteger y = list[0].negate().mod(gcd);
//			System.out.println("answer  = "+y);
			String resultStr = String.format("Case #%d: ", test+1);
			// add answer here
			resultStr += y;
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	
	
	
}
