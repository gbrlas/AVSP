//package ticTacToe;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class TicTacToe {
	private static String x_won = "X won";
	private static String o_won = "O won";
	private static String draw = "Draw";
	private static String nc = "Game has not completed";

	public void solve(PrintWriter out, char[][] board) {
		String winner = null;

		winner = checkHorizontally(board);

		if (winner == null)
			winner = checkVertically(board);

		if (winner == null)
			winner = checkDiagonally(board);

		if (winner == null)
			winner = CheckDraw(board);
		out.println(winner);

	}

	private String CheckDraw(char[][] board) {
		int dot_cnt = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (board[i][j] == '.')
					dot_cnt++;
			}
		}
		if (dot_cnt > 0) {
			return (nc);
		} else
			return (draw);

	}

	private String checkDiagonally(char[][] board) {
		int x_cnt = 0, o_cnt = 0;
		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {
				if (i == j) {
					switch (board[i][j]) {
					case 'X':
						x_cnt++;
						break;
					case 'O':
						o_cnt++;
						break;
					case 'T':
						x_cnt++;
						o_cnt++;
						break;
					}
				}
			}
			if (x_cnt == 4)
				return x_won;
			else if (o_cnt == 4)
				return o_won;

		}

		x_cnt = o_cnt = 0;

		for (int i = 0; i < 4; i++) {

			for (int j = 3; j >= 0; j--) {
				if (i + j == 3) {

					switch (board[i][j]) {
					case 'X':
						x_cnt++;
						break;
					case 'O':
						o_cnt++;
						break;
					case 'T':
						x_cnt++;
						o_cnt++;
						break;
					}
				}

			}

		}
		if (x_cnt == 4)
			return x_won;
		else if (o_cnt == 4)
			return (o_won);

		return null;

	}

	private String checkVertically(char[][] board) {
		int x_cnt = 0, o_cnt = 0;
		for (int i = 0; i < 4; i++) {
			x_cnt = o_cnt = 0;
			for (int j = 0; j < 4; j++) {
				switch (board[j][i]) {
				case 'X':
					x_cnt++;
					break;
				case 'O':
					o_cnt++;
					break;
				case 'T':
					x_cnt++;
					o_cnt++;
					break;
				}
			}
			if (x_cnt == 4)
				return x_won;
			else if (o_cnt == 4)
				return o_won;

		}
		return null;

	}

	private String checkHorizontally(char[][] board) {
		int x_cnt = 0;
		int o_cnt = 0;

		for (char[] s : board) {
			x_cnt = o_cnt = 0;

			for (int i = 0; i < 4; i++) {
				switch (s[i]) {
				case 'X':
					x_cnt++;
					break;
				case 'O':
					o_cnt++;
					break;
				case 'T':
					x_cnt++;
					o_cnt++;
					break;
				}
			}
			if (x_cnt == 4)
				return x_won;
			else if (o_cnt == 4)
				return o_won;

		}
		return null;
	}

	public static void main(String[] args) throws IOException {
		String inFile = args[0];
		String outFile = args[1];

		Scanner in = new Scanner(new FileReader(inFile));
		PrintWriter out = new PrintWriter(outFile);

		int tests = in.nextInt();
		in.nextLine();

		for (int t = 1; t <= tests; t++) {
			out.printf("Case #%d: ", t);
			char[][] board = new char[4][];
			for (int l = 0; l < 4; l++) {
				board[l] = in.nextLine().toCharArray();
			}
			new TicTacToe().solve(out, board);
			if (t < tests)
				in.nextLine();
		}

		in.close();

		out.close();

	}

}
