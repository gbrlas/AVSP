import java.util.Scanner;

public class TicTacToe {
	
	private static boolean matches(char toMatch, char c1, char c2, char c3, char c4) {
		int sumX = 0;
		int sumT = 0;
		
		if (c1 == toMatch) {
			sumX++;
		} else if (c1 == 'T') {
			sumT++;
		}
		if (c2 == toMatch) {
			sumX++;
		} else if (c2 == 'T') {
			sumT++;
		}
		if (c3 == toMatch) {
			sumX++;
		} else if (c3 == 'T') {
			sumT++;
		}
		if (c4 == toMatch) {
			sumX++;
		} else if (c4 == 'T') {
			sumT++;
		}
		return (sumX == 3 && sumT == 1) || (sumX == 4 && sumT == 0);
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		for (int t = 0; t < T; t++) {
			boolean x_wins = false;
			boolean y_wins = false;
			boolean done = true;
			char[][] board = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String line = in.nextLine();
				for (int j = 0; j < 4; j++) {
					board[i][j] = line.charAt(j);
					if (board[i][j] == '.') {
						done = false;
					}
				}
			}
			
			for (int i = 0; i < 4; i++) {
				x_wins = x_wins || matches('X', board[i][0], board[i][1], board[i][2], board[i][3]) || matches('X', board[0][i], board[1][i], board[2][i], board[3][i]);
				y_wins = y_wins || matches('O', board[i][0], board[i][1], board[i][2], board[i][3]) || matches('O', board[0][i], board[1][i], board[2][i], board[3][i]);;
			}
			x_wins = x_wins || matches('X', board[0][0], board[1][1], board[2][2], board[3][3]) || matches('X', board[0][3], board[1][2], board[2][1], board[3][0]);
			y_wins = y_wins || matches('O', board[0][0], board[1][1], board[2][2], board[3][3]) || matches('O', board[0][3], board[1][2], board[2][1], board[3][0]);
			String result = "";
			if (x_wins && !y_wins) {
				result = "X won";
			} else if (!x_wins && y_wins) {
				result = "O won";
			} else if (x_wins && y_wins || (!x_wins && !y_wins && done)) {
				result = "Draw";
			} else if (!x_wins && !y_wins && !done) {
				result = "Game has not completed";
			}
			System.out.printf("Case #%d: %s\n", (t+1), result);
			in.nextLine();
		}
	}
	
}
