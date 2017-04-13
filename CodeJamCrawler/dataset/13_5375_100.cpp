package com.wildhemp.codejam;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class TicTacToeTomek {

    private static final int ROWS = 4;
    private static final int COLS = 4;
    private static final int DIAG_RIGHT = ROWS + COLS;
    private static final int DIAG_LEFT = DIAG_RIGHT + 1;
    
    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
	BufferedReader dis = new BufferedReader(new InputStreamReader(
		new FileInputStream(args[0])));

	int testNum = Integer.parseInt(dis.readLine());
	for (int test = 0; test < testNum; test++) {
	    int[][] count = new int[2][ROWS + COLS + 2]; //4 lines + 4 cols + 2 for diagonal
	    boolean hasEmpty = false;
	    
	    for (int line = 0; line < 4; line++) {
		char[] str = dis.readLine().toCharArray();
		for (int pos = 0; pos < 4; pos ++) {
		    int incO = 0, incX = 0;
		    if (str[pos] == 'O') {
			incO = 1;
		    } else if (str[pos] == 'X') {
			incX = 1;
		    } else if (str[pos] == 'T') {
			incO = 1;
			incX = 1;
		    } else {
			hasEmpty = true;
		    }
		    
		    if (pos == line) {
			count[0][DIAG_RIGHT] += incO;
			count[1][DIAG_RIGHT] += incX;
		    }
		    if (3 - pos == line) {
			count[0][DIAG_LEFT] += incO;
			count[1][DIAG_LEFT] += incX;
		    }
		    
		    count[0][line] += incO;
		    count[1][line] += incX;
		    count[0][ROWS + pos] += incO;
		    count[1][ROWS + pos] += incX;
		}
	    }
	    dis.readLine();
	    
	    String result = (hasEmpty ? "Game has not completed" : "Draw");
	    String[] wons = new String[] {"O won", "X won"};
	    OUTER: for (int p = 0; p < count.length; p ++) {
		for (int line = 0; line < count[p].length; line ++) {
		    if (count[p][line] == 4) {
			result = wons[p];
			break OUTER;
		    }
		}
	    }
	    
	    System.out.println("Case #" + (test + 1) + ": " + result);
	}
    }

}
