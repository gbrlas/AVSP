import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Prob3 {
	int K = 0, N = 0;
	final int One = 1;
	FileWriter out; // = new FileWriter(new File("pro1.out"));
	private boolean RTrue = false;
	private boolean BTrue = false;

	public Prob3() {
		try {
			run();
		} catch (Exception e) {
			// System.err.println();
			e.printStackTrace();
		}
	}

	private void run() throws IOException {

		Scanner scan = new Scanner(new File("test.in"));
		out = new FileWriter(new File("pro1.out"));
		int numberOfTestCases = scan.nextInt();

		String temp;
		short[][] board;
		short[] index;
		for (int i = 0; i < numberOfTestCases; i++) {
			N = scan.nextInt();
			K = scan.nextInt();

			index = new short[N];
			board = new short[N][N];
			RTrue = false;
			BTrue = false;
			for (int j = 0; j < N; j++) {
				index[j] = 0;
				for (int j2 = 0; j2 < N; j2++) {
					board[j][j2] = 0;
				}
			}
			
			for (int p = 0; p < N; p++) {
				temp = scan.next();
				
				for (int j = (N - 1); j >= 0; j--) {
					
					char input = temp.charAt(j);
					switch (input) {

					case 'R':
						board[N - 1 - index[N-1 -p]][N-1 -p] = 1;
						index[N-1 -p]++;
						break;
					case 'B':
						board[N - 1 - index[N-1 -p]][N-1 -p] = -1;
						index[N-1 -p]++;
						break;

					default:
						break;

					}
				}
			}

			for (int j = 0; j < N; j++) {
				for (int j2 = 0; j2 < N; j2++) {
					checkCell(board, j, j2);
				}
			}

			if (BTrue && RTrue) {
				out.write("Case #"+(i+1)+": Both\n");
			} else if (BTrue) {
				out.write("Case #"+(i+1)+": Blue\n");
			} else if (RTrue) {
				out.write("Case #"+(i+1)+": Red\n");
			} else {
				out.write("Case #"+(i+1)+": Neither\n");
			}

		}

		out.close();
		scan.close();
	}

	private int checkCell(short[][] board, int j, int j2) {
		if (board[j][j2] != 0) {
			for (int i = 0; i < 8; i++) {
				short sum = 0;
				switch (i) {
				case 0:
					// Test the line 0
					if (j + (K - 1) <= N - 1) {
						for (int e = 0; e < K; e++) {
							sum += board[j + e][j2];
							if (board[j + e][j2] == 0)
								break;
						}
					}
					break;
				case 1:
					if (j - (K - 1) >= 0) {
						for (int e = 0; e < K; e++) {
							sum += board[j - e][j2];
							if (board[j - e][j2] == 0)
								break;
						}
					}
					break;
				case 2:
					if (j2 + (K - 1) <= N - 1) {
						for (int e = 0; e < K; e++) {
							sum += board[j][j2 + e];
							if (board[j][j2 + e] == 0)
								break;
						}
					}
					break;
				case 3:
					if (j2 - (K - 1) >= 0) {
						for (int e = 0; e < K; e++) {
							sum += board[j][j2 - e];
							if (board[j][j2 - e] == 0)
								break;
						}
					}
					break;
				case 4:
					if (j + (K - 1) <= N - 1 && (j2 + (K - 1)) <= N - 1) {
						for (int e = 0; e < K; e++) {
							sum += board[j + e][j2 + e];
							if (board[j + e][j2 + e] == 0)
								break;
						}
					}
					break;
				case 5:
					if (j - (K - 1) >= 0 && (j2 + (K - 1)) <= N - 1) {
						for (int e = 0; e < K; e++) {
							sum += board[j - e][j2 + e];
							if (board[j - e][j2 + e] == 0)
								break;
						}
					}
					break;
				case 6:
					if (j2 - (K - 1) >= 0 && (j + (K - 1)) <= N - 1) {
						for (int e = 0; e < K; e++) {
							sum += board[j + e][j2 - e];
							if (board[j + e][j2 - e] == 0)
								break;
						}
					}
					break;
				case 7:
					if (j - (K - 1) >= 0 && j2 - (K - 1) >= 0) {
						for (int e = 0; e < K; e++) {
							sum += board[j - e][j2 - e];
							if (board[j - e][j2 - e] == 0)
								break;
						}
					}
					break;

				default:
					break;
				}
				if (sum == K) {
					RTrue = true;
				} else if (sum == -K) {
					BTrue = true;
				}
			}
		}
		return 0;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Prob3();
	}

}
