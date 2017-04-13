import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class ThemePark {
	String PROBLEM_ID = "themepark";
	enum TestType { EXAMPLE, SMALL, LARGE }
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
		new ThemePark();
	}
	
	public ThemePark() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int R = scan.nextInt(); // nr rides
			int k = scan.nextInt(); // capacity
			int n = scan.nextInt(); // number of groups
			int[] group = new int[n];
			for ( int i = 0; i < n; i++ ) group[i] = scan.nextInt();
			int[] next = new int[n];
			int[] size = new int[n];
			for ( int i = 0; i < n; i++ ) {
				int index = i;
				int count = 0;
				int sum = 0;
				while ( sum + group[index] <= k && count < n ) {
					count++;
					sum += group[index];
					index = (index + 1) % n;
				}
				size[i] = sum;
				next[i] = index;
			}
//			for ( int i = 0; i < n; i++ ) {
//				System.out.printf("index %d size %d next %d\n", i, size[i], next[i]	);
//			}
			int[] seen = new int[n];
			Arrays.fill(seen, -1);
			long[] income = new long[n];
			int ride = 0;
			int pos = 0;
			long answer = 0;
			while ( ride < R && seen[pos] < 0) {
				seen[pos] = ride++;
				income[pos] = answer;
				answer += size[pos];
//				System.out.printf("pos %d sum so far %d next %d\n", pos, answer, next[pos]);
				pos = next[pos];
			}
			if ( seen[pos] >= 0 ) {
				int cycleLength = ride - seen[pos];
				long cycleIncome = answer - income[pos];
				int cycles = (R-ride)/cycleLength;
				answer += cycles*cycleIncome;
				ride += cycles*cycleLength;
			}
			while ( ride < R ) {
				answer += size[pos];
				pos = next[pos];
				ride++;
			}
			String resultStr = String.format("Case #%d: ", test+1);
			// add answer here
			resultStr += answer;
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	
	
	
}
