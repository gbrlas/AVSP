import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;




public class ProblemB {
	String PROBLEM_ID = "problemB";
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
		new ProblemB();
	}
	
	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int c = scan.nextInt();
			int d = scan.nextInt();
			int[] p = new int[c];
			int[] v = new int[c];
			ArrayList<Integer> list = new ArrayList<Integer>();
			for ( int i = 0; i < c; i++) {
				p[i] = scan.nextInt();
				v[i] = scan.nextInt();
				for ( int j = 0; j < v[i]; j++) list.add(p[i]);
			}
			int[] x = new int[list.size()];
			int index = 0;
			for (int a: list) x[index++] = a;
			double minTime = 1e12;
			for ( int i = 0; i < x.length; i++) {
				double[] startX = new double[d*2+1];
				for ( int k = 0; k < d*2+1; k++) startX[k] = x[i] - 0.5 *d + k*0.5;
				for ( double start: startX) {
					double lb = 0.0; 
					double ub = 10000;
					for ( int iter = 0; iter < 50; iter++ ) {
						double mid = (ub+lb)/2;
						boolean ok = Math.abs( x[i] - start ) <= mid +1e-12;
						double left = start - d;
						for ( int j = i-1; j >= 0; j--) {
							ok &= x[j] - mid <= left;
							double bestP = Math.min(left, x[j] + mid);
							left = bestP - d;
						}
						double right = start + d;
						for ( int j = i+1; j < x.length; j++) {
							ok &= x[j] + mid >= right;
							double bestP = Math.max(right, x[j] - mid);
							right = bestP + d;
						}
						if ( ok ) ub = mid; else lb = mid;
					}
					minTime = Math.min(minTime, ub);
					
				}
			}
		
			
			String resultStr = String.format("Case #%d: %.9f", test+1, minTime);
			// add answer here
			
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 

}
