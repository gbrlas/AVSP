import java.util.Scanner;


public class TicTacToeTomek {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.nextLine());
		for (int t = 1; t <= T; t++) {
			char v[][] = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String s = sc.nextLine();
				for (int j = 0; j < 4; j++) {
					v[i][j] = s.charAt(j);
				}
			}
			sc.nextLine();
			String r = checkRows(v);
			String c = checkCols(v);
			String d = checkDiag(v);
			if (r != null || c != null || d != null) {
				r = r != null ? r : (c != null ? c : d);
				System.out.println("Case #" + t + ": " + r + " won");
			} else if (full(v)) {
				System.out.println("Case #" + t + ": Draw");
			} else {
				System.out.println("Case #" + t + ": Game has not completed");
			}
		}
	}

	private static boolean full(char[][] v) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (v[i][j] == '.') {
					return false;
				}
			}
		}
		return true;
	}

	private static String checkDiag(char[][] v) {
		if (isX(v[0][0]) && isX(v[1][1]) && isX(v[2][2]) && isX(v[3][3])) {
			return "X";
		} else if (isO(v[0][0]) && isO(v[1][1]) && isO(v[2][2]) && isO(v[3][3])) {
			return "O";
		}
		if (isX(v[3][0]) && isX(v[2][1]) && isX(v[1][2]) && isX(v[0][3])) {
			return "X";
		} else if (isO(v[3][0]) && isO(v[2][1]) && isO(v[1][2]) && isO(v[0][3])) {
			return "O";
		}
		return null;
	}

	private static String checkCols(char[][] v) {
		for (int i = 0; i < 4; i++) {
			if (isX(v[i][0]) && isX(v[i][1]) && isX(v[i][2]) && isX(v[i][3])) {
				return "X";
			} else if (isO(v[i][0]) && isO(v[i][1]) && isO(v[i][2]) && isO(v[i][3])) {
				return "O";
			}
		}
		return null;
	}

	private static String checkRows(char[][] v) {
		for (int i = 0; i < 4; i++) {
			if (isX(v[0][i]) && isX(v[1][i]) && isX(v[2][i]) && isX(v[3][i])) {
				return "X";
			} else if (isO(v[0][i]) && isO(v[1][i]) && isO(v[2][i]) && isO(v[3][i])) {
				return "O";
			}
		}
		return null;
	}

	private static boolean isX(char c) {
		if (c == 'X' || c == 'T') {
			return true;
		}
		return false;
	}

	private static boolean isO(char c) {
		if (c == 'O' || c == 'T') {
			return true;
		}
		return false;
	}

}
