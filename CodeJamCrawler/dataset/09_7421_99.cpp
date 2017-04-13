import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;


public class qualify2009A {
	public static void main(String[] args) throws Exception {
		new qualify2009A();
	}

	public qualify2009A() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("qual2009_input_a.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-A.txt")));
		Scanner scan = new Scanner(in);
		int L = scan.nextInt();
		int nrWords = scan.nextInt();
		int tests = scan.nextInt();
		String[] words = new String[nrWords];
		for ( int i = 0; i < nrWords; i++ ) {
			words[i] = scan.next();
		}
		for (int test = 0; test < tests; test++) {
			String s = scan.next();
			LinkedList<String> now = new LinkedList<String>();
			for ( String a: words) now.add(a);
			int pos = 0;
			boolean[] ok = new boolean[26];
			for ( int i = 0; i < L; i++) {
				Arrays.fill(ok, false);
				char c = s.charAt(pos);
				if ( c == '(') {
					pos++;
					c = s.charAt(pos);
					while ( c != ')' ) {
						ok[ c - 'a'] = true;
						pos++;
						c = s.charAt(pos);
					}
					pos++;
				} else {
					ok[c-'a'] = true;
					pos++;
				}
				
				LinkedList<String> next = new LinkedList<String>();
				// filter list
				for ( String a: now) {
					if ( ok[a.charAt(i) - 'a']) next.add(a);
				}
				now = next;
			}
			
//			System.out.println("test case " + test);
			System.out.printf("Case #%d: %d\n", test + 1, now.size());
			out.printf("Case #%d: %d\n", test + 1, now.size());
		}
		out.close();
	}
}
