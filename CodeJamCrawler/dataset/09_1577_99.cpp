package com.baskok.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class WelcomeToTheCodejam {

	public class PosCount {
		public int pos;
		public int count;
		public PosCount(int pos, int count) {
			this.pos=pos;
			this.count=count;
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("src/com/baskok/codejam/C-small-attempt0.in"));
		// unneeded, but need to parse anyway
		int numberOfTestCases = in.nextInt();
		in.nextLine();
		// read words
		for (int i = 1; i <= numberOfTestCases; i++) {
			WelcomeToTheCodejam problem = new WelcomeToTheCodejam();
			System.out.println("Case #" + i + ": " + problem.solve(in.nextLine()));
		}
	}

	String solve(String input) {
		String target = "welcome to code jam";
		// initial run
		
		int[] prev = new int[500];
		// manually setting the w's first
		for (int i=0; i<input.length(); i++) {
			if (input.charAt(i) == 'w') {
				prev[i] = 1;
			}
		}
		int[] next;
		for (int i = 1; i < target.length(); i++) {
			next = new int[500];
			char currentChar = target.charAt(i);
			for (int j = 0; j < input.length(); j++) {
				if (input.charAt(j) == currentChar) {
					for (int k = 0; k < j; k++) {
						next[j] += prev[k];
						next[j] %= 10000;
					}
				}
			}
			prev = next;
		}

		// aggregate the counts of the m's
		int total = 0;
		for (int i=0; i<input.length(); i++) {
			total += prev[i];
			total %= 10000;
		}
		
		return String.format("%04d", total);
	}

}
