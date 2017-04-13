import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.*;

public class ProblemB {
	
	String PROBLEM_ID = "problemB";
	enum TestType { EXAMPLE, SMALL, LARGE }
//	TestType TYPE = TestType.EXAMPLE;
	TestType TYPE = TestType.SMALL;
//	TestType TYPE = TestType.LARGE;
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
			int rows = scan.nextInt();
			int cols = scan.nextInt();
			int D = scan.nextInt();
			int[][] value = new int[rows][cols];
			for ( int r = 0; r < rows; r++	) {
				String s = scan.next();
				for ( int c = 0; c < cols; c++) {
					value[r][c] = (s.charAt(c) - '0') + D; 
				}
			}
//			for ( int[] v: value ) System.out.println(Arrays.toString(v));
			int maxK = -1;
			for ( int r = 0; r < rows; r++)
				for ( int c = 0; c < cols; c++) {
					for ( int k = 3; k <= 10; k++ ) {
						if ( k % 2 == 0) {
							int count = 0;
							long sumX = 0;
							long sumY = 0;
							for ( int nr = max(0, r - k/2); nr < min(rows, r + k/2); nr++) {
								for ( int nc = max(0, c - k/2); nc < min(cols, c + k/2); nc++) {
									if ( (nr == r-k/2 || nr == r + k/2-1) && (nc == c-k/2 || nc == c+k/2-1)) continue;
									count++;
									int w = value[nr][nc];
									sumX += (2*nc+1 - 2*c)*w;
									sumY += (2*nr+1 - 2*r)*w;
								}
							}
							if ( count == k*k - 4 && sumX == 0 && sumY == 0 ) maxK = max(k, maxK);
						} else {
							int count = 0;
							long sumX = 0;
							long sumY = 0;
							for ( int nr = max(0, r - k/2); nr <= min(rows-1, r + k/2); nr++) {
								for ( int nc = max(0, c - k/2); nc <= min(cols-1, c + k/2); nc++) {
									if ( (nr == r-k/2 || nr == r + k/2) && (nc == c-k/2 || nc == c+k/2)) continue;
									count++;
									int w = value[nr][nc];
									sumX += (2*nc - 2*c)*w;
									sumY += (2*nr - 2*r)*w;
								}
							}
							if ( count == k*k - 4 && sumX == 0 && sumY == 0 ) maxK = max(k, maxK);
						}
					}
				}
			
			
			String resultStr = String.format("Case #%d: ", test+1);
			// add answer here
			resultStr += maxK < 3 ? "IMPOSSIBLE" : maxK;
			
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
}
