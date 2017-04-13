import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemD {
	public static void main(String[] args) throws Exception {
		new ProblemD();
	}

	public ProblemD() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input-d.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-d.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int k = scan.nextInt();
			char[] word = scan.next().toCharArray();
			char[] code = new char[word.length];
			int[] perm = new int[k];
			for ( int i = 0; i < k; i++) perm[i] = i;
			int best = 1000000;
			do {
				for ( int i = 0; i < word.length/ k; i++) {
					for ( int j = 0; j < k; j++) code[i*k+j] = word[i*k+perm[j]];
				}
				int size = 0;
				char last = '1';
				for ( char c: code ) {
					if ( c != last ) {
						size++;
						last = c;
					}
				}
				if ( size < best ) best = size;				
			} while (nextPermutation(perm));
			
			String answer = String.format("Case #%d: %d\n", test + 1, best);
			System.out.print(answer);
			out.printf(answer);
		}
		out.close();
	}
	
	public boolean nextPermutation(int[] a) {
		if (a.length <= 1)
			return false;
		int k = a.length - 2;
		while (k >= 0 && a[k] >= a[k + 1])
			k--;
		int m = a.length - 1;
		if (k < 0) {
			reverse(a, 0, m);
			return false;
		}
		while (a[m] <= a[k])
			m--;
		swap(a, m, k);
		reverse(a, k + 1, a.length - 1);
		return true;
	}

	public void reverse(int[] a, int s, int t) {
		while (s < t)
			swap(a, s++, t--);
	}

	public void swap(int[] a, int s, int t) {
		int b = a[s];
		a[s] = a[t];
		a[t] = b;
	}
}
