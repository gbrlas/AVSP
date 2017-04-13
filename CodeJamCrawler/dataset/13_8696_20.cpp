import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.sort;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class TicTacToeTomek {

	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer tok;
	static int test;

	static void solve() throws Exception {
		// System.err.println();
		// System.err.println("TEST " + test);

		char[][] board = new char[4][4];
		for (int i = 0; i < 4; i++) {
			String line = next();
			for (int j = 0; j < 4; j++) {
				board[i][j] = line.charAt(j);
			}
		}

		// Emtpy line at the end.
		next();

		printCase();

		// Solve.
		int[][] adjustXcountH = new int[4][4];
		int[][] adjustXcountV = new int[4][4];
		int adjustXcountD1 = 0;
		int adjustXcountD2 = 0;
		int[][] adjustOcountH = new int[4][4];
		int[][] adjustOcountV = new int[4][4];
		int adjustOcountD1 = 0;
		int adjustOcountD2 = 0;

		boolean isEmpty = false;
		boolean isXwon = false;
		boolean isOwon = false;

		// Diagonal

		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				if ('T' == board[0][0]) {
					adjustXcountD1 = 1;
					adjustOcountD1 = 1;
				} else if ('T' == board[0][3]) {
					adjustXcountD2 = 1;
					adjustOcountD2 = 1;
				} 
				if ('X' == board[0][0]) {
					adjustXcountD1 = 1;
					adjustOcountD1 = 0;
				}
				if ('X' == board[0][3]) {
					adjustXcountD2 = 1;
					adjustOcountD2 = 0;
				}
				if ('O' == board[0][0]) {
					adjustXcountD1 = 0;
					adjustOcountD1 = 1;
				}
				if ('O' == board[0][3]) {
					adjustXcountD2 = 0;
					adjustOcountD2 = 1;
				}
				if ('.' == board[0][0]) {
					adjustXcountD1 = 0;
					adjustOcountD1 = 0;
				}
				if ('.' == board[0][3]) {
					adjustXcountD2 = 0;
					adjustOcountD2 = 0;
				}
			} else {
				if ('T' == board[i][i]) {
					adjustXcountD1++;
					adjustOcountD1++;
				} else {
					if ('T' == board[i - 1][i - 1]) {
						adjustXcountD1++;
						adjustOcountD1++;
					}
				}
				if ('T' == board[i][3 - i]) {
					adjustXcountD2++;
					adjustOcountD2++;
				} else {
					if ('T' == board[i - 1][3 - i + 1]) {
						adjustXcountD2++;
						adjustOcountD2++;
					}
				}

				if ('.' == board[i][i]) {
					// Cancels everything above.
					adjustXcountD1 = 0;
					adjustOcountD1 = 0;
					isEmpty = true;
				} else if (board[i][i] == board[i - 1][i - 1]) {
					if (board[i][i] == 'X') {
						adjustXcountD1++;
						adjustOcountD1 = 0;
					} else {
						adjustXcountD1 = 0;
						adjustOcountD1++;
					}
				}

				if ('.' == board[i][3 - i]) {
					// Cancels everything above.
					adjustXcountD2 = 0;
					adjustOcountD2 = 0;
					isEmpty = true;
				} else if (board[i][3 - i] == board[i - 1][3 - i + 1]) {
					if (board[i][3 - i] == 'X') {
						adjustXcountD2++;
						adjustOcountD2 = 0;
					} else {
						adjustXcountD2 = 0;
						adjustOcountD2++;
					}
				}
			}
		}
		if ((adjustXcountD1 == 4) || (adjustXcountD2 == 4)) {
			isXwon = true;
		} else if ((adjustOcountD1 == 4) || (adjustOcountD2 == 4)) {
			isOwon = true;
		}

		if (isXwon) {
			out.println("X won");
			return;
		} else if (isOwon) {
			out.println("O won");
			return;
		}

		// Horizontal & Vertical
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == 0) {
					if ('T' == board[i][j]) {
						adjustXcountV[i][j] = 1;
						adjustOcountV[i][j] = 1;
					} else if ('X' == board[i][j]) {
						adjustXcountV[i][j] = 1;
						adjustOcountV[i][j] = 0;
					} else if ('O' == board[i][j]) {
						adjustXcountV[i][j] = 0;
						adjustOcountV[i][j] = 1;
					} else
					// ('.' == board[i][j])
					{
						adjustXcountV[i][j] = 0;
						adjustOcountV[i][j] = 0;
						isEmpty = true;
					}
				} else {
					if ('T' == board[i][j]) {
						adjustXcountV[i][j] = adjustXcountV[i - 1][j] + 1;
						adjustOcountV[i][j] = adjustOcountV[i - 1][j] + 1;
					} else {
						if ('T' == board[i - 1][j]) {
							adjustXcountV[i][j] = adjustXcountV[i - 1][j] + 1;
							adjustOcountV[i][j] = adjustOcountV[i - 1][j] + 1;
						} 
					}

					if ('.' == board[i][j]) {
						// Cancels everything above.
						adjustXcountV[i][j] = 0;
						adjustOcountV[i][j] = 0;
						isEmpty = true;
					} else {
						if (board[i][j] == board[i - 1][j]) {
							if (board[i][j] == 'X') {
								adjustXcountV[i][j] = adjustXcountV[i - 1][j] + 1;
								adjustOcountV[i][j] = 0;
							} else {
								adjustOcountV[i][j] = adjustOcountV[i - 1][j] + 1;
								adjustXcountV[i][j] = 0;
							}
						}						
					}
				}
								
				if (j == 0) {
					if ('T' == board[i][j]) {
						adjustXcountH[i][j] = 1;
						adjustOcountH[i][j] = 1;
					} else if ('X' == board[i][j]) {
						adjustXcountH[i][j] = 1;
						adjustOcountH[i][j] = 0;
					} else if ('O' == board[i][j]) {
						adjustXcountH[i][j] = 0;
						adjustOcountH[i][j] = 1;
					} else
					// if ('.' == board[i][j])
					{
						adjustXcountH[i][j] = 0;
						adjustOcountH[i][j] = 0;
						isEmpty = true;
					}
				} else {
					if ('T' == board[i][j]) {
						adjustXcountH[i][j] = adjustXcountH[i][j - 1] + 1;
						adjustOcountH[i][j] = adjustOcountH[i][j - 1] + 1;
					} else {
						if ('T' == board[i][j - 1]) {
							adjustXcountH[i][j] = adjustXcountH[i][j - 1] + 1;
							adjustOcountH[i][j] = adjustOcountH[i][j - 1] + 1;
						}
					}

					if ('.' == board[i][j]) {
						// Cancels everything above.
						adjustXcountH[i][j] = 0;
						adjustOcountH[i][j] = 0;
						isEmpty = true;
					} else {
						if (board[i][j] == board[i][j - 1]) {
							if (board[i][j] == 'X') {
								adjustXcountH[i][j] = adjustXcountH[i][j - 1] + 1;
								adjustOcountH[i][j] = 0;
							} else {
								adjustOcountH[i][j] = adjustOcountH[i][j - 1] + 1;
								adjustXcountH[i][j] = 0;
							}
						}
					}
				}
				if (adjustOcountH[i][j] == 4) {
					isOwon = true;
					break;
				} else if (adjustOcountV[i][j] == 4) {
					isOwon = true;
					break;
				} else if (adjustXcountH[i][j] == 4) {
					isXwon = true;
					break;
				}
				if (adjustXcountV[i][j] == 4) {
					isXwon = true;
					break;
				}
			}
		}

		if (isXwon) {
			out.println("X won");
		} else if (isOwon) {
			out.println("O won");
		} else if (isEmpty) {
			out.println("Game has not completed");
		} else {
			out.println("Draw");
		}

		// System.err.print("FOOD");
		// System.err.println();

		// printCase();
		// out.println(days.longValue());
	}

	static void printCase() {
		out.print("Case #" + test + ": ");
	}

	static void printlnCase() {
		out.println("Case #" + test + ":");
	}

	static int nextInt() throws IOException {
		return parseInt(next());
	}

	static long nextLong() throws IOException {
		return parseLong(next());
	}

	static double nextDouble() throws IOException {
		return parseDouble(next());
	}

	static String next() throws IOException {
		while (tok == null || !tok.hasMoreTokens()) {
			// Handle the empty line.
			String line = in.readLine();
			if ((line == null) || line.isEmpty()) {
				return "";
			}
			tok = new StringTokenizer(line);
		}
		return tok.nextToken();
	}

	public static void main(String[] args) {
		try {
			// in = new BufferedReader(new InputStreamReader(System.in));
			in = new BufferedReader(
					new FileReader(
							"D:\\Workspaces\\eclipse_workspace\\codejam\\CodeJam\\src\\A-small-attempt0.in"));
			// out = new PrintWriter(new OutputStreamWriter(System.out));
			out = new PrintWriter(
					new FileWriter(
							"D:\\Workspaces\\eclipse_workspace\\codejam\\CodeJam\\src\\A-small-attempt0.out"));
			int tests = nextInt();
			for (test = 1; test <= tests; test++) {
				solve();
			}
			in.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			exit(1);
		}
	}
}
