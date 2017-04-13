import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {
	public static void main(String[] args) throws Exception {
		new ProblemA();
	}

	public ProblemA() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_a.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
		"output-A.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			long A = scan.nextInt();
			long B = scan.nextInt();
			long C = scan.nextInt();
			long D = scan.nextInt();
			long[] x = new long[n];
			long[] y = new long[n];
			x[0] = scan.nextInt();
			y[0] = scan.nextInt();
			int M = scan.nextInt();
			for ( int i = 1; i < n; i++) {
				x[i] = (A * x[i-1] + B	) % M;
				y[i] = (C*y[i-1] + D) % M;
			}
			int count = 0;
			for ( int i = 0; i < n; i++)
				for ( int j = i+1; j < n; j++) 
					for ( int k = j+1; k < n; k++) {
						if ( (x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0 ) count++;
					}
			String answer = String.format("Case #%d: %d\n", test + 1, count);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
}
