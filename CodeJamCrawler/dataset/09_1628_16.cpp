package com.baskok.codejam.round2_2009;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
//		File file = new File("src/com/baskok/codejam/round2_2009/A-example.in");
		File file = new File("src/com/baskok/codejam/round2_2009/A-small-attempt0.in");
//		File file = new File("src/com/baskok/codejam/round2_2009/A-small-attempt1.in");
//		File file = new File("src/com/baskok/codejam/round2_2009/A-large.in");
		Scanner in = new Scanner(file);
		int runs = in.nextInt();
		for (int run = 1; run <= runs; run++) {
			A problem = new A();
			// add arguments
			int result = problem.solve(in);
			System.out.println("Case #" + run + ": " + result);
		}
	}

	int[] rowmax;
	int n;
	
	private int solve(Scanner in) {
//		System.out.println("============");
		n = in.nextInt();
		rowmax = new int[n];
		for (int i = 0; i < n; i++) {
			String row = in.next();
			for (int j = 0; j < row.length(); j++) {
				if (row.charAt(j) == '1') {
					rowmax[i] = j;
				}
			}
		}
		debug();
		int swaps = 0;
		for (int i = 0; i < n; i++) {
			if (needsToMove(i)) {
				for (int j = i+1; j < n; j++) {
//					System.out.println("rowmax["+ j + "]: "+ rowmax[j] + " i:" + i);
					if (rowmax[j] <= i) {
//						System.out.println("swapping " + i + " to " + j);
//						for (int k = i; k < j; k++) {
						for (int k = j-1; k >= i; k--) {
							swaps++;
							swap(k);
							debug();
						}
						break;
					}
				}
			}
		}
		return swaps;
	}

	private void debug() {
		for (int i = 0; i < n; i++) {
//			System.out.println(rowmax[i]);
		}
//		System.out.println("---");
	}

	private void swap(int k) {
		int temp = rowmax[k+1];
		rowmax[k+1] = rowmax[k];
		rowmax[k] = temp;
	}

	private boolean needsToMove(int i) {
		return rowmax[i] > i;
	}
	
}
