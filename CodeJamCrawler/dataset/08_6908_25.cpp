import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws Exception {
		new ProblemB();
	}

	public ProblemB() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-b.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-b.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int n = scan.nextInt();
			int m = scan.nextInt();
			long A = scan.nextLong();
			long xa = 0;
			long yb = 0;
			long xb = 0, xc = 0, ya = 0, yc = 0;
			boolean done = false;
			String blah = "";
			for ( xb = 0; xb <= n && !done; xb++)
				for ( xc = 0; xc <= n && !done; xc++)
					for ( ya = 0; ya <= m && !done; ya++)
						for ( yc = 0; yc <= m && !done; yc++)
						{
							long z = xb*yc-xb*ya+xc*ya;
							if ( z == A || z == -A ) done = true;
							blah = xa + " " + ya + " " + xb+ " " + yb + " " + xc + " " + yc +"\n";
							/*
							long z = A +xb*ya-xc*ya;
							if ( z % xb == 0 	) {
								yc = z/ xb;
								done = true;
							}
							*/
						}
			String answer = String.format("Case #%d: ", test +1);
			if ( !done ) answer += "IMPOSSIBLE\n";
			else answer += blah;
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
}
