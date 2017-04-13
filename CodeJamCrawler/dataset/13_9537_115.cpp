//package fairSquare;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FairSquare {

	public void solve(PrintWriter out, long a, long b) {
		long cnt = 0;
		
		System.out.println("a = " + a + ", b = " + b);
		for(long i = 1; (i*i) <=b; i++) {
			if( (i*i) >=a && isPalindrome(i) && isPalindrome(i*i)   ) {
				System.out.println("i = " + i + ", i*i = " + (i*i));
				cnt++;
			}
		}
		out.println(cnt);
	}

	private boolean isPalindrome(long a) {
		String s = String.valueOf(a);
		StringBuilder b = new StringBuilder(s).reverse();

		if (b.toString().equals(s))
			return true;
		return false;
	}

	public static void main(String[] args) throws IOException {
		String inFile = args[0];
		String outFile = args[1];

		Scanner in = new Scanner(new FileReader(inFile));
		PrintWriter out = new PrintWriter(outFile);

		int tests = in.nextInt();
		in.nextLine();

		for (int t = 1; t <= tests; t++) {
			out.printf("Case #%d: ", t);
			System.out.printf("Case #%d:\n ", t);
			long a = in.nextLong();
			long b = in.nextLong();
			new FairSquare().solve(out, a, b);
			if (t < tests)
				in.nextLine(); 
		}
		in.close();
		out.close();

	}

}
