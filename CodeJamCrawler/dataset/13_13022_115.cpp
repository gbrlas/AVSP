import java.util.*;
import java.io.*;

public class ProblemA {

	private static final String IN_FILE = "A-large.in";
	private static final String OUT_FILE = "output_a.txt";
	
	private static char[][] grid = new char[4][4];
	
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter out = null;

		try {
			sc = new Scanner(new File(IN_FILE));
			out = new BufferedWriter(new FileWriter(OUT_FILE));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		int numTests = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < numTests; i++) {
			try {
				handleTest(sc, out, i+1);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		try {
			sc.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws Exception {
		int tr = -1;
		int tc = -1;
		boolean gameOver = true;
		
		for (int i = 0; i < 4; i++) {
			String nextRow = sc.nextLine();
			for (int j = 0; j < 4; j++) {
				grid[i][j] = nextRow.charAt(j);
				if (grid[i][j] == 'T') {
					tr = i;
					tc = j;
				} else if (grid[i][j] == '.') {
					gameOver = false;
				}
			}
		}
		sc.nextLine();
		
		if (tr >= 0) 
			grid[tr][tc] = 'X';
		if (isWinner('X')) {
			out.write("Case #" + caseNum + ": X won\n");
			return;
		}
		
		if (tr >= 0) 
			grid[tr][tc] = 'O';
		if (isWinner('O')) {
			out.write("Case #" + caseNum + ": O won\n");
			return;
		}
		
		if (gameOver) {
			out.write("Case #" + caseNum + ": Draw\n");
		} else {
			out.write("Case #" + caseNum + ": Game has not completed\n");
		}
	}

	private static boolean isWinner(char ch) {
		for (int i = 0; i < 4; i++) {
			boolean goodRow = true;
			boolean goodCol = true;
			for (int j = 0; j < 4; j++) {
				if (grid[i][j] != ch) {
					goodRow = false;
				}
				if (grid[j][i] != ch) {
					goodCol = false;
				}
			}
			
			if (goodRow || goodCol)
				return true;
		}
		
		boolean leftDiag = true;
		boolean rightDiag = true;
		for (int i = 0; i < 4; i++) {
			if (grid[i][i] != ch)
				leftDiag = false;
			if (grid[i][3-i] != ch)
				rightDiag = false;
		}
		if (leftDiag || rightDiag)
			return true;
		
		return false;
	}
}
