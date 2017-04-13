import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemA {
	String PROBLEM_ID = "problemA";
	enum TestType { EXAMPLE, SMALL, LARGE }
//	TestType TYPE = TestType.EXAMPLE;
	TestType TYPE = TestType.SMALL;
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
		new ProblemA();
	}
	
	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			path = new HashSet<String>();
			path.add("");
			int n = scan.nextInt();
			int m = scan.nextInt();
			for ( int i = 0; i < n; i++) {
				String s = scan.next();
				addPath(s);
			}
			int oldSize = path.size();
			n = m;
			for ( int i = 0; i < n; i++) {
				String s = scan.next();
				addPath(s);
			}
			int newSize = path.size();
			
			String resultStr = String.format("Case #%d: ", test+1);
			// add answer here
			resultStr += (newSize - oldSize);
			
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	
	HashSet<String> path;
	public void addPath(String s) {
		if ( path.contains(s)) return;
		path.add(s);
		int k = s.lastIndexOf('/');
		addPath(s.substring(0,k));
	}
	
	
}
