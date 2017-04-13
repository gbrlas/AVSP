import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.String.format;
import static java.lang.Math.*;


public class problemB {
//	final static String testType = "test";
		final static String testType = "small";
	//	final static String testType = "large";
	static BufferedReader infile;
	static PrintWriter outfile;

	public static void main(String[] args) throws Exception {
		String inFileName = "input_" + testType + "_problemB.txt";
		String outFileName = "output_" + testType + "_problemB.txt";
		infile = new BufferedReader(new FileReader(inFileName));
		outfile = new PrintWriter(new BufferedWriter(
				new FileWriter(outFileName)));
		new problemB();
	}

	public void log(String s) {
		System.out.print(s);
		outfile.print(s);
	}

	public problemB() throws Exception {
		Scanner scan = new Scanner(infile);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			String n = scan.next();
			int[] number = new int[n.length()];
			for ( int i = 0; i < n.length(); i++) number[i] = n.charAt(i)-'0';
			int[] digits = new int[10];
			Arrays.fill(digits, 0);
			for ( int d: number ) digits[d]++;
			String answer = "";
			boolean ok = nextPermutation(number);
			
			if ( !ok ) {
				// number needs more digits
				int first = 1;
				while ( first < 10 && digits[first] == 0) first++;
				answer += first;
				digits[first]--;
				digits[0]++;
				answer += smallest(digits);
			} else {
				for ( int x: number) answer += x;
			}
			log(format("Case #%d: %s\n", test + 1, answer));
		}
		outfile.close();
	}
	
	public String smallest(int[] digits) {
		String result = "";
		for ( int i = 0; i < digits.length; i++) {
			for ( int j = 0; j < digits[i]; j++) result += i;
		}
		return result;
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
