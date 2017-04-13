import java.util.*;
import java.io.*;

public class ProblemB {

	private static final String IN_DIR = "inputs";
	private static final String OUT_DIR = "outputs";

	private static final String IN_FILE = "B-small-attempt0.in";
	private static final String OUT_FILE = "output_b.txt";
	
	private static int[][] grid = new int[100][100];
	private static int[] rowMaxes = new int[100];
	private static int[] colMaxes = new int[100];
	
	public static void main(String[] args) {
		Scanner sc = null;
		BufferedWriter out = null;

		try {
			sc = new Scanner(new File(IN_DIR + "/" + IN_FILE));
			out = new BufferedWriter(new FileWriter(OUT_DIR + "/" + OUT_FILE));
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		int numTests = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < numTests; i++) {
			try {
				handleTest(sc, out, i+1);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		
		try {
			sc.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void handleTest(Scanner sc, BufferedWriter out, int caseNum) throws IOException {
		int nrows = sc.nextInt();
		int ncols = sc.nextInt();
		for (int row = 0; row < nrows; row++) {
			for (int col = 0; col < ncols; col++) {
				grid[row][col] = sc.nextInt();
			}
		}
		
		for (int row = 0; row < nrows; row++) {
			rowMaxes[row] = -1;
			for (int col = 0; col < ncols; col++) {
				rowMaxes[row] = Math.max(rowMaxes[row], grid[row][col]);
			}
		}
		
		for (int col = 0; col < ncols; col++) {
			colMaxes[col] = -1;
			for (int row = 0; row < nrows; row++) {
				colMaxes[col] = Math.max(colMaxes[col], grid[row][col]);
			}
		}
		
		for (int row = 0; row < nrows; row++) {
			for (int col = 0; col < ncols; col++) {
				if (grid[row][col] < rowMaxes[row] && grid[row][col] < colMaxes[col]) {
					out.write("Case #" + caseNum + ": NO\n");
					return;
				}
			}
		}
		
		out.write("Case #" + caseNum + ": YES\n");
	}
}
