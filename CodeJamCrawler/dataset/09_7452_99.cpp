import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class qualify2009C {
	public static void main(String[] args) throws Exception {
		new qualify2009C();
	}

	public qualify2009C() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_c.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"outC.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		scan.nextLine();
		n = welcome.length();
		for (int test = 0; test < tests; test++) {
			line = scan.nextLine();
			memo = new int[line.length()][n];
			for ( int[] a: memo) Arrays.fill(a, -1);
			int result = go(0,0);
			String answer = ""+ result;
			while ( answer.length() < 4) answer = "0"+answer;
			out.printf("Case #%d: %s\n", test + 1, answer);
			System.out.printf("Case #%d: %s\n", test + 1, answer);
		}
		out.close();
	}
	
	public int go(int pos, int k) {
		if ( k >= n	) return 1;
		if ( pos >= line.length()) return 0;
		if ( memo[pos][k] >= 0) return memo[pos][k];
		int sum = go(pos+1, k);
		if ( welcome.charAt(k) == line.charAt(pos)) sum += go(pos+1, k+1);
		sum %= MOD;
		memo[pos][k] = sum;
		return sum;
	}
	
	String line;
	int n;
	int MOD = 10000;
	String welcome = "welcome to code jam";
	int[][] memo;
}
