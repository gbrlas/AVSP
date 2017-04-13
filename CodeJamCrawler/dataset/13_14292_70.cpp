import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class P1 {
	
	boolean check(char ch, char[][] b) {
		// line
		for (int i=0; i<4; i++) {
			boolean win = true;
			for (int j=0; j<4; j++) {
				if (b[i][j] != ch && b[i][j] != 'T') {
					win = false;
				}
			}
			if (win) return true;
		}
		// column
		for (int i=0; i<4; i++) {
			boolean win = true;
			for (int j=0; j<4; j++) {
				if (b[j][i] != ch && b[j][i] != 'T') {
					win = false;
				}
			}
			if (win) return true;
		}
		// diagonals
		{
			boolean win = true;
			for (int i=0; i<4; i++) {
				if (b[i][i] != ch && b[i][i] != 'T') {
					win = false;
				}
			}
			if (win) return true;
		}		
		{
			boolean win = true;
			for (int i=0; i<4; i++) {
				if (b[i][3-i] != ch && b[i][3-i] != 'T') {
					win = false;
				}
			}
			if (win) return true;
		}
		
		return false;
	}
	public void solve(Scanner sc, PrintWriter pw, int test) {
		pw.print("Case #" + test + ": ");
		sc.nextLine();
		char[][] b = new char[4][4];
		for (int i=0; i<4; i++) {
			b[i] = sc.nextLine().toUpperCase().toCharArray();
		}
		
		boolean completed = true;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (b[i][j] == '.') completed = false;
			}
		}
		
		if (check('X', b) && check('O', b)) {
			throw new AssertionError("Both won - test #" + test);
		}
		
		// check X won;
		if (check('X', b)) {
			pw.println("X won");
			return;
		}
		// check O won;
		if (check('O', b)) {
			pw.println("O won");
			return;
		}
		
		if (completed) {
			pw.println("Draw");
		}
		else {
			pw.println("Game has not completed");
		}
	}
	
	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("P1.in"));
		PrintWriter pw = new PrintWriter("P1.out");
		
		int numTests = sc.nextInt();
		
		for (int test = 1; test <= numTests; test++) {
			solve(sc, pw, test);
		}
		pw.close();

	}
	public static void main(String[] args) throws FileNotFoundException {
		new P1().run();
	}
}
