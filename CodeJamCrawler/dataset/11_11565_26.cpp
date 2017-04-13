import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.*;

public class ProblemA {
	String PROBLEM_ID = "problemA";
	enum TestType { EXAMPLE, SMALL, LARGE }
//	TestType TYPE = TestType.EXAMPLE;
//	TestType TYPE = TestType.SMALL;
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
		new ProblemA();
	}
	
	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int X = scan.nextInt();
			int S = scan.nextInt();
			int R = scan.nextInt();
			int time = scan.nextInt();
			int n = scan.nextInt();
			Interval[] list = new Interval[n+1];
			int total = 0;
			for (int i = 0; i < n; i++) {
				int b = scan.nextInt();
				int e = scan.nextInt();
				int w = scan.nextInt();
				list[i] = new Interval(w + S, e-b);
				total += e-b;
			}
			list[n] = new Interval(S, X - total);
			Arrays.sort(list);
			double timeLeft = time;
			double travelTime = 0;
			for ( Interval interval: list ) {
//				double timePerM = 1.0/interval.v;
//				double timeFastPerM = 1.0/(interval.v+(R-S));
				double fastTime = min(timeLeft, interval.length*1.0/(interval.v+(R-S)));
				double distLeft = interval.length - fastTime*(interval.v+(R-S));
				double slowTime = distLeft/interval.v;
				travelTime += fastTime + slowTime;
				timeLeft -= fastTime;
			}
			
			String resultStr = String.format("Case #%d: %.12f", test+1, travelTime);
			// add answer here
			
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	
	public class Interval implements Comparable<Interval> {
		int v;
		int length;

		public Interval(int v, int length ) {
			this.v = v;
			this.length = length;
		}

		public int compareTo( Interval other ) {
			if (v != other.v ) 
				return ( v < other.v ? -1 : 1 );
			if (length != other.length ) 
				return ( length < other.length ? -1 : 1 );
			return 0;
		}
	}


}
