import java.util.*;
import java.io.*;

public class B {
	public static boolean[][] good_board = null;
	public static int good_r = 0;
	public static int good_c = 0;

	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(in.readLine());

		for(int cas = 1; cas <= cases; cas++) {
			String[] parts = in.readLine().split(" ");
			int r = Integer.parseInt(parts[0]);
			int c = Integer.parseInt(parts[1]);
			int m = Integer.parseInt(parts[2]);

			if(r * c - m <= 1) {
				good_board = new boolean[r][c];
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) {
						if(i == 0 && j == 0 && r * c - m == 1) good_board[i][j] = false;
						else good_board[i][j] = true;
					}
				}
				good_r = 0;
				good_c = 0;
			} else {
				boolean[][] board = new boolean[r][c];
				good_board = null;
				recurse(board, 0, 0, m);
			}


			if(good_board == null) System.out.println("Case #" + cas + ":\nImpossible");
			else {
				System.out.println("Case #" + cas + ":");
				print(good_board);
			}
		}
	}

	public static void print(boolean[][] board) {
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j < board[i].length; j++) {
				if(i == good_r && j == good_c) System.out.print("c");
				else System.out.print(board[i][j] ? "*" : ".");
			}
			System.out.println();
		}
	}

	public static boolean valid(boolean[][] board, int r, int c) {
		if(r >= 0 && r < board.length && c >= 0 && c < board[0].length) {
			return true;
		} else {
			return false;
		}
	}

	public static boolean bomb(boolean[][] board, int r, int c) {
		if(valid(board, r, c)) {
			return board[r][c];
		} else {
			return false; //okay
		}
	}

	public static boolean check(boolean[][] board, int i, int j) {
		return !bomb(board, i - 1, j) && !bomb(board, i, j) && !bomb(board, i + 1, j) && !bomb(board, i - 1, j - 1) && !bomb(board, i, j - 1) && !bomb(board, i + 1, j - 1) && !bomb(board, i - 1, j + 1) && !bomb(board, i, j + 1) && !bomb(board, i + 1, j + 1);
	}

	public static void dig(boolean[][] board, boolean[][] dug, int r, int c) {
		if(valid(board, r, c) && !dug[r][c] && !bomb(board, r, c)) {
			dug[r][c] = true;
			if(check(board, r, c)) {
				dig(board, dug, r + 1, c);
				dig(board, dug, r - 1, c);
				dig(board, dug, r, c + 1);
				dig(board, dug, r + 1, c + 1);
				dig(board, dug, r - 1, c + 1);
				dig(board, dug, r, c - 1);
				dig(board, dug, r + 1, c - 1);
				dig(board, dug, r - 1, c - 1);
			}
		}
	}

	public static void recurse(boolean[][] board, int idx, int cm, int m) {
		if(good_board != null || cm > m || board.length * board[0].length - idx + cm < m) {
			return;
		}

		if(idx == board.length * board[0].length) {
			//find starting point, which should have area to clean
			int r_start = -1;
			int c_start = -1;
			for(int i = 0; i < board.length; i++) {
				for(int j = 0; j < board[i].length; j++) {
					if(check(board, i, j)) {
						r_start = i;
						c_start = j;
						break;
					}
				}
			}

			if(r_start == -1) return;

			boolean[][] dug = new boolean[board.length][board[0].length];
			for(int i = 0; i < board.length; i++) {
				for(int j = 0; j < board[i].length; j++) {
					dug[i][j] = false;
				}
			}

			//try to clean
			dig(board, dug, r_start, c_start);

			boolean fail = false;
			for(int i = 0; i < board.length; i++) {
				for(int j = 0; j < board[i].length; j++) {
					if(!dug[i][j] && !board[i][j]) {
						fail = true;
						break;
					}
				}
			}

			if(!fail) {
				good_board = new boolean[board.length][board[0].length];
				for(int i = 0; i < board.length; i++) {
					for(int j = 0; j < board[i].length; j++) {
						good_board[i][j] = board[i][j];
					}
				}
				good_r = r_start;
				good_c = c_start;
			}

			return;
		}

		int r = idx / board[0].length;
		int c = idx % board[0].length;
		board[r][c] = true;
		recurse(board, idx + 1, cm + 1, m);
		board[r][c] = false;
		recurse(board, idx + 1, cm, m);
	}
}
