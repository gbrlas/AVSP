import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class A {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(A.class.getName() + ".in"));
			out.add(new PrintStream(A.class.getName() + ".out"));
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			li();
			pf("Case #%d: %s\n", i + 1, solve());
		}
		System.out.println("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		boolean x = false;
		boolean o = false;
		boolean full = true;
		char[][] board = new char[4][4];
		for (int i = 0; i < 4; i++) {
			String line = li();
			board[i] = line.toCharArray();
		}
		List<char[]> lines = new ArrayList<char[]>();
		for (int i = 0; i < 4; i++) {
			lines.add(board[i]);
		}
		for (int i = 0; i < 4; i++) {
			lines.add(new char[]{board[0][i], board[1][i], board[2][i], board[3][i]});
		}
		lines.add(new char[]{board[0][0], board[1][1], board[2][2], board[3][3]});
		lines.add(new char[]{board[0][3], board[1][2], board[2][1], board[3][0]});
		for (char[] line : lines) {
			switch (win(line)) {
			case 1:
				x = true;
				break;
			case 2:
				o = true;
				break;
			case 3:
				full = false;
				break;
			}
		}
		if (x) {
			return "X won";
		}
		if (o) {
			return "O won";
		}
		if (full) {
			return "Draw";
		}
		return "Game has not completed";
	}

	// 0 for none, 1 for x, 2 for o, 3 for not full
	static int win(char[] row) {
		int x = 0;
		int o = 0;
		int t = 0;
		for (char c : row) {
			switch(c) {
				case '.':
					return 3;
				case 'X':
					x++;
					break;
				case 'O':
					o++;
					break;
				case 'T':
					t++;
					break;
			}
		}
		if (x + t == 4) {
			return 1;
		} else if (o + t == 4) {
			return 2;
		}
		return 0;
	}

	static void p(String x) {
		for (PrintStream ps : out) {
			ps.print(x);
		}
	}

	static void pl(String x) {
		for (PrintStream ps : out) {
			ps.println(x);
		}
	}

	static void pf(String format, Object... args) {
		for (PrintStream ps : out) {
			ps.printf(format, args);
		}
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}