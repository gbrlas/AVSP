import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_a.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output_a.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			HashMap<String,Integer> engine = new HashMap<String,Integer>();
			int s = scan.nextInt();
			scan.nextLine();
			for ( int i = 0; i < s; i++ ) {
				engine.put(scan.nextLine().trim(), i);
			}
			int q = scan.nextInt();
			scan.nextLine();
			int[] x = new int[q];
			for ( int i = 0; i < q; i++) 
				x[i] = engine.get(scan.nextLine().trim());
			int[][] dp = new int[q][s];
			if ( q > 0)
				for ( int i = 0; i < s; i++) dp[0][i] = x[0] == i ? 10000: 0;
			for ( int i = 1; i < q; i++) {
				for ( int j = 0; j < s; j++) {
					if ( x[i] == j ) dp[i][j] = 10000;
					else {
						int best = 10000;
						int extra = 0;
						for ( int k = 0; k < s; k++) {
							extra = k == j ? 0 : 1;
							if ( extra + dp[i-1][k] < best )
								best = extra + dp[i-1][k];
						}
						dp[i][j] = best;
					}
				}
			}
			int answer = 10000;
			if ( q > 0 )
			{
				for ( int i = 0; i < s; i++) if ( dp[q-1][i] < answer ) answer = dp[q-1][i];
			}
			else answer = 0;
			System.out.printf("test case %d, antwoord %d \n", test+1, answer);
			out.printf("Case #%d: %d\n", test + 1, answer);
		}
		out.close();
	}
}
