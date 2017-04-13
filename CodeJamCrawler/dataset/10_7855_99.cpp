import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class SnapperChain {
	String PROBLEM_ID = "snapperchain";
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
		new SnapperChain();
	}
	
	public SnapperChain() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int k = scan.nextInt();
			k %= (1 << n);
			
			String resultStr = String.format("Case #%d: ", test+1);
			resultStr += k + 1 == 1<<n ? "ON" : "OFF";
						
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
	}
}
