package com.wildhemp.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Lawnmower {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	BufferedReader dis = new BufferedReader(new InputStreamReader(
		new FileInputStream(args[0])));

	int testNum = Integer.parseInt(dis.readLine());
	for (int test = 0; test < testNum; test++) {
	    String[] temp = dis.readLine().split(" ");
	    int n = Integer.parseInt(temp[0]);
	    int m = Integer.parseInt(temp[1]);

	    int[][] desired = new int[n][m];
	    int[][] current = new int[n][m];

	    int[][] numsInRows = new int[n][m];
	    int[][] numsInCols = new int[m][n];

	    for (int line = 0; line < n; line++) {
		temp = dis.readLine().split(" ");
		for (int pos = 0; pos < m; pos++) {
		    desired[line][pos] = Integer.parseInt(temp[pos]);

		    numsInRows[line][pos] = desired[line][pos];
		    numsInCols[pos][line] = desired[line][pos];

		    current[line][pos] = 100;
		}
	    }
	    for (int idx = 0; idx < numsInRows.length; idx++) {
		Arrays.sort(numsInRows[idx]);
	    }
	    for (int idx = 0; idx < numsInCols.length; idx++) {
		Arrays.sort(numsInCols[idx]);
	    }

	    int nextRow = numsInRows[0].length;
	    int nextCol = numsInCols[0].length;
	    boolean didProcess = true;
	    while (didProcess) {
		nextRow--;
		nextCol--;
		didProcess = false;
		if (nextRow > -1) {
		    for (int row = 0; row < n; row++) {
			if (numsInRows[row][0] != -1
				&& processRow(desired, current, row,
					numsInRows[row][nextRow])) {
			    didProcess = true;
			} else {
			    numsInRows[row][0] = -1;
			}
		    }
		}

		if (nextCol > -1) {
		    for (int col = 0; col < m; col++) {
			if (numsInCols[col][0] != -1
				&& processColumn(desired, current, col,
					numsInCols[col][nextCol])) {
			    didProcess = true;
			} else {
			    numsInCols[col][0] = -1;
			}
		    }
		}
	    }

	    String result = "YES";
	    OUTER: for (int line = 0; line < n; line++) {
		for (int pos = 0; pos < m; pos++) {
		    if (desired[line][pos] != current[line][pos]) {
			result = "NO";
			break OUTER;
		    }
		}
	    }

	    System.out.println("Case #" + (test + 1) + ": " + result);
	}
    }

    private static boolean processRow(int[][] desired, int[][] current,
	    int row, int number) {
	for (int pos = 0; pos < desired[row].length; pos++) {
	    if (desired[row][pos] > number) {
		return false;
	    }
	}

	for (int pos = 0; pos < desired[row].length; pos++) {
	    current[row][pos] = Math.min(current[row][pos], number);
	}

	return true;
    }

    private static boolean processColumn(int[][] desired, int[][] current,
	    int col, int number) {
	for (int row = 0; row < desired.length; row++) {
	    if (desired[row][col] > number) {
		return false;
	    }
	}

	for (int row = 0; row < desired.length; row++) {
	    current[row][col] = Math.min(current[row][col], number);
	}

	return true;
    }

}
