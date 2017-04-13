import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class TicTacToeTomek {
	
	static final int WIDTH = 4;
	static final int HEIGHT = 4;
	
	static void judge(Scanner scanner, int time) {
		boolean isDone = false;
		boolean isCompleted = true;
		Set<Integer> xSet = new HashSet<Integer>();
		Set<Integer> oSet = new HashSet<Integer>();
		char[][] board = new char[HEIGHT][WIDTH];
		for (int i = 0; i < HEIGHT; i++) {
			String line = scanner.nextLine();
			if (!isDone) {
				for (int j = 0; j < WIDTH; j++) {
					if (!isDone) {
						board[i][j] = line.charAt(j);
						switch (board[i][j]) {
							case 'T':
								xSet.add(i * WIDTH + j);
								oSet.add(i * WIDTH + j);
								if (j == 3) {
									if (xSet.contains(i * WIDTH) && xSet.contains(i * WIDTH + 1) && xSet.contains(i * WIDTH + 2)) {
										System.out.println("Case #" + time + ": X won");
										isDone = true;
										break;
									} else if (oSet.contains(i * WIDTH) && oSet.contains(i * WIDTH + 1) && oSet.contains(i * WIDTH + 2)) {
										System.out.println("Case #" + time + ": O won");
										isDone = true;
										break;
									}
									if (i == 3) {
										if (xSet.contains(0) && xSet.contains(5) && xSet.contains(10)) {
											System.out.println("Case #" + time + ": X won");
											isDone = true;
											break;
										} else if (oSet.contains(0) && oSet.contains(5) && oSet.contains(10)) {
											System.out.println("Case #" + time + ": O won");
											isDone = true;
											break;
										}
									}
								}
								if (i == 3) {
									if (xSet.contains(j) && xSet.contains(WIDTH + j) && xSet.contains(2 * WIDTH + j)) {
										System.out.println("Case #" + time + ": X won");
										isDone = true;
										break;
									} else if (oSet.contains(j) && oSet.contains(WIDTH + j) && oSet.contains(2 * WIDTH + j)) {
										System.out.println("Case #" + time + ": O won");
										isDone = true;
										break;
									} 
									if (j == 0) {
										if (xSet.contains(3) && xSet.contains(6) && xSet.contains(9)) {
											System.out.println("Case #" + time + ": X won");
											isDone = true;
											break;
										} else if (oSet.contains(3) && oSet.contains(6) && oSet.contains(9)) {
											System.out.println("Case #" + time + ": O won");
											isDone = true;
											break;
										}
									}
								}
								break;
							case 'X':
								xSet.add(i * WIDTH + j);
								if (j == 3) {
									if (xSet.contains(i * WIDTH) && xSet.contains(i * WIDTH + 1) && xSet.contains(i * WIDTH + 2)) {
										System.out.println("Case #" + time + ": X won");
										isDone = true;
										break;
									}
									if (i == 3) {
										if (xSet.contains(0) && xSet.contains(5) && xSet.contains(10)) {
											System.out.println("Case #" + time + ": X won");
											isDone = true;
											break;
										}
									}
								}
								if (i == 3) {
									if (xSet.contains(j) && xSet.contains(WIDTH + j) && xSet.contains(2 * WIDTH + j)) {
										System.out.println("Case #" + time + ": X won");
										isDone = true;
										break;
									}
									if (j == 0) {
										if (xSet.contains(3) && xSet.contains(6) && xSet.contains(9)) {
											System.out.println("Case #" + time + ": X won");
											isDone = true;
											break;
										}
									}
								}
								break;
							case 'O':
								oSet.add(i * WIDTH + j);
								if (j == 3) {
									if (oSet.contains(i * WIDTH) && oSet.contains(i * WIDTH + 1) && oSet.contains(i * WIDTH + 2)) {
										System.out.println("Case #" + time + ": O won");
										isDone = true;
										break;
									}
									if (i == 3) {
										if (oSet.contains(0) && oSet.contains(5) && oSet.contains(10)) {
											System.out.println("Case #" + time + ": O won");
											isDone = true;
											break;
										}
									}
								}
								if (i == 3) {
									if (oSet.contains(j) && oSet.contains(WIDTH + j) && oSet.contains(2 * WIDTH + j)) {
										System.out.println("Case #" + time + ": O won");
										isDone = true;
										break;
									} 
									if (j == 0) {
										if (oSet.contains(3) && oSet.contains(6) && oSet.contains(9)) {
											System.out.println("Case #" + time + ": O won");
											isDone = true;
											break;
										}
									}
								}
								break;
							default:
								isCompleted = false;
								break;
						}
					}
					
				}
			}
		}
		if (!isDone) {
			System.out.println("Case #" + time + ": " + (isCompleted ? "Draw" : "Game has not completed"));
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new File("C:\\Users\\Xing\\A-large.in"));
		int num = Integer.parseInt(scanner.nextLine());
		for (int i = 0; i < num; i++) {
			judge(scanner, i + 1);
			scanner.nextLine();
		}
		scanner.close();
	}
}
