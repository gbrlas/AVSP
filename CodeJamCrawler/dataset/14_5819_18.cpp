package com.round1B;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class TheRepeater {

	public static void main(String[] args) throws IOException {
		int T;
		int caseNum;
		int N, L;
		int ans;
		int i;
		FileReader file = new FileReader("repeater_input.txt");
		File outFile = new File("repeater_output.txt");
		FastScannerSlow fScanner = new FastScannerSlow(file);
		PrintWriter out = new PrintWriter(outFile);
		PrintWriter outConsole = new PrintWriter(System.out);
		String str[];

		T = fScanner.nextInt();

		for (caseNum = 1; caseNum <= T; caseNum++) {

			N = fScanner.nextInt();
			str = new String[N];

			for (i = 0; i < N; i++)
				str[i] = fScanner.next();

			ans = Integer.MAX_VALUE;

			for (i = 0; i < N; i++) {
				ans = Math.min(ans, solve(str, str[i]));
			}

			if (ans == Integer.MAX_VALUE) {
				out.println("Case #" + caseNum + ": Fegla Won");
				outConsole.println("Case #" + caseNum + ": Fegla Won");
			} else {
				out.println("Case #" + caseNum + ": " + ans);
				outConsole.println("Case #" + caseNum + ": " + ans);
			}
		}

		out.flush();
		outConsole.flush();
		out.close();
		outConsole.close();
	}

	public static int solve(String[] str, String pattern) {

		int i;
		int N;
		int changes = 0;
		int c;

		N = str.length;

		for (i = 0; i < N; i++) {
			c = minChange(str[i], pattern);
			if (c == Integer.MAX_VALUE)
				return Integer.MAX_VALUE;
			changes += c;
		}

		return changes;
	}

	public static int minChange(String a, String b) {

		int i, j;
		char c;
		int change = 0;
		int n;
		ArrayList<Sequence> seqA = new ArrayList<>();
		ArrayList<Sequence> seqB = new ArrayList<>();

		if (a.equals(b))
			return 0;

		for (i = 0; i < a.length(); i += n) {
			j = i + 1;
			while (j < a.length() && a.charAt(j) == a.charAt(i))
				j++;
			n = j - i;
			seqA.add(new Sequence(a.charAt(i), n));
		}

		for (i = 0; i < b.length(); i += n) {
			j = i + 1;
			while (j < b.length() && b.charAt(j) == b.charAt(i))
				j++;
			n = j - i;
			seqB.add(new Sequence(b.charAt(i), n));
		}

		if (seqA.size() != seqB.size())
			return Integer.MAX_VALUE;

		for (i = 0; i < seqA.size(); i++) {
			if (seqA.get(i).c != seqB.get(i).c)
				return Integer.MAX_VALUE;
			change += Math.abs(seqA.get(i).n - seqB.get(i).n);
		}

		return change;
	}

	private static class Sequence {
		public int n;
		public char c;

		public Sequence(char c, int n) {
			this.c = c;
			this.n = n;
		}
	}

}
