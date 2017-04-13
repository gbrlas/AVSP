import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemB {
	String PROBLEM_ID = "ProblemB";
	enum TestType { EXAMPLE, SMALL, LARGE }
//	TestType TYPE = TestType.EXAMPLE;
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
		new ProblemB();
	}
	
	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			n = scan.nextInt();
			k = scan.nextInt();
			barn = scan.nextInt();
			time = scan.nextInt();
			x = new int[n];
			v = new int[n];
			for ( int i = 0; i < n; i++ ) x[i] = scan.nextInt();
			for ( int i = 0; i < n; i++ ) v[i] = scan.nextInt();
			memo = new int[n][k+1];
			for ( int[] a: memo) Arrays.fill(a, -1);
			int answer = go(n-1, k);
			String resultStr = String.format("Case #%d: ", test+1);
			// add answer here
			if ( answer == INF) resultStr += "IMPOSSIBLE";
			else resultStr += answer;
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	int barn;
	int time;
	int k;
	int n;
	int[] x;
	int[] v;
	int[][] memo;
	int INF = 10000000;
	
	public int go(int index, int need) {
		if ( index < 0) {
			return need == 0 ? 0 : INF;
		}
		if ( need <= 0) return 0;
		if ( memo[index][need] >= 0) return memo[index][need];
		if ( x[index] + time*v[index] >= barn ) {
			return memo[index][need] = go(index - 1, need - 1);
		} else {
			int z = go(index - 1, need);
			return memo[index][need] = Math.min(INF, z + need);
		}
	}
	
	
	
}
