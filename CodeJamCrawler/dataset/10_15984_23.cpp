package codejam2010.round1A;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemA {

	public enum Slot {
		EMPTY, RED, BLUE
	}

	private static final int MATCH_RED = 1;
	private static final int MATCH_BLUE = 2;
	private static final int MATCH_BOTH = MATCH_BLUE | MATCH_RED;

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "A-small-attempt0";
			File folder = new File(new File("files", "codejam2010"), "round1A");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				int[] params = parseIntegers(reader.readLine());
				int n = params[0];
				int k = params[1];
				Slot b[][] = new Slot[n][n];
				for (int j = 0; j < n; j++) {
					b[j] = parseSlots(reader.readLine());
				}
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(n, k, b));
				writer.flush();
				System.out.println(i+1);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static Object solveIt(int n, int k, Slot[][] b) {
		switch (checkTable(rotate(b), k)) {
		case 0:
			return "Neither";
		case MATCH_RED:
			return "Red";
		case MATCH_BLUE:
			return "Blue";
		case MATCH_BOTH:
			return "Both";
		default:
			throw new IllegalStateException("Oops!");
		}
	}

	private static Slot[][] rotate(Slot[][] b) {
		int n = b.length;
		Slot[][] r = new Slot[n][n];
		for (int i = 0; i < n; i++) {
			r[i] = new Slot[n];
			for (int j = 0; j < n; j++) {
				r[i][j] = b[n-1-j][i];
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = n-1; i >= 0; i--) {
				if (r[i][j] == Slot.EMPTY) {
					for (int x = i-1; x >= 0; x--) {
						if (r[x][j] != Slot.EMPTY) {
							r[i][j] = r[x][j];
							r[x][j] = Slot.EMPTY;
							break;
						}
					}
				}
			}
		}
		return r;
	}

	private static int checkTable(Slot[][] b, int k) {
		int matches = 0;
		for (int row = 0; row < b.length; row++) {
			matches |= checkRow(b, k, row);
			if (matches == MATCH_BOTH) {
				return matches;
			}
		}
		for (int col = 0; col < b.length; col++) {
			matches |= checkColumn(b, k, col);
			if (matches == MATCH_BOTH) {
				return matches;
			}
		}
		matches |= checkDiags1(b, k);
		if (matches == MATCH_BOTH) {
			return matches;
		}
		matches |= checkDiags2(b, k);
		if (matches == MATCH_BOTH) {
			return matches;
		}
		return matches;
	}

	private static int checkDiags1(Slot[][] b, int k) {
		int n = b.length;
		int matches = 0;
		for (int d = -n+1; d < n; d++) {
			int i = Math.max(d, 0);
			int j = Math.max(-d, 0);
			Slot slot = b[i][j];
			int count = 1;
			while (++i < n && ++j < n) {
				if (b[i][j] != Slot.EMPTY) {
					if (slot == b[i][j]) {
						count++;
					} else {
						slot = b[i][j];
						count = 1;
					}
				} else {
					slot = Slot.EMPTY;
					count = 0;
				}
				if (count >= k) {
					matches = resolveMatches(matches, slot);
					if (matches == MATCH_BOTH) {
						return matches;
					}
				}
			}
		}
		return matches;
	}

	private static int checkDiags2(Slot[][] b, int k) {
		int n = b.length;
		int matches = 0;
		for (int d = -n+1; d < n; d++) {
			int i = n-1 - Math.max(d, 0);
			int j = Math.max(-d, 0);
			Slot slot = b[i][j];
			int count = 1;
			while (--i >= 0 && ++j < n) {
				if (b[i][j] != Slot.EMPTY) {
					if (slot == b[i][j]) {
						count++;
					} else {
						slot = b[i][j];
						count = 1;
					}
				} else {
					slot = Slot.EMPTY;
					count = 0;
				}
				if (count >= k) {
					matches = resolveMatches(matches, slot);
					if (matches == MATCH_BOTH) {
						return matches;
					}
				}
			}
		}
		return matches;
	}

	private static int checkRow(Slot[][] b, int k, int row) {
		int matches = 0;
		Slot slot = b[row][0];
		int count = 1;
		for (int i = 1; i < b.length; i++) {
			if (b[row][i] != Slot.EMPTY) {
				if (slot == b[row][i]) {
					count++;
				} else {
					slot = b[row][i];
					count = 1;
				}
			} else {
				slot = Slot.EMPTY;
				count = 0;
			}
			if (count >= k) {
				matches = resolveMatches(matches, slot);
				if (matches == MATCH_BOTH) {
					return matches;
				}
			}
		}
		return matches;
	}

	private static int checkColumn(Slot[][] b, int k, int col) {
		int matches = 0;
		Slot slot = b[0][col];
		int count = 1;
		for (int i = 1; i < b.length; i++) {
			if (b[i][col] != Slot.EMPTY) {
				if (slot == b[i][col]) {
					count++;
				} else {
					slot = b[i][col];
					count = 1;
				}
			} else {
				slot = Slot.EMPTY;
				count = 0;
			}
			if (count >= k) {
				matches = resolveMatches(matches, slot);
				if (matches == MATCH_BOTH) {
					return matches;
				}
			}
		}
		return matches;
	}

	private static int resolveMatches(int matches, Slot slot) {
		switch(slot) {
		case RED:
			matches |= MATCH_RED;
			break;
		case BLUE:
			matches |= MATCH_BLUE;
			break;
		default:
			throw new IllegalStateException("Oops!");
		}
		return matches;
	}

	private static int[] parseIntegers(String line) {
		String[] strings = line.split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
	}

	private static Slot[] parseSlots(String line) {
		Slot[] slots = new Slot[line.length()];
		for (int i = 0; i < line.length(); i++) {
			switch (line.charAt(i)) {
			case '.':
				slots[i] = Slot.EMPTY;
				break;
			case 'R':
				slots[i] = Slot.RED;
				break;
			case 'B':
				slots[i] = Slot.BLUE;
				break;
			default:
				throw new IllegalArgumentException("Oops");
			}
		}
		return slots;
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
