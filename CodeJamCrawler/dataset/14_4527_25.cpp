import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.Reader;
import java.io.Writer;
import java.util.HashSet;

public class ProblemA {

	static int[][] cardMatrixFirst = new int[4][4];
	static int[][] cardMatrixSecond = new int[4][4];

	public static void solve(BufferedReader reader, PrintStream writer)
			throws NumberFormatException, IOException {
		int testCaseCount = Integer.valueOf(reader.readLine());
		int globalCount = 1;

		for (int i = 0; i < testCaseCount; i++) {
			int guessLineFirst = Integer.valueOf(reader.readLine());

			for (int j = 0; j < 4; j++) {
				String line = reader.readLine();
				String[] numsLineFirst = line.split(" ");

				for (int k = 0; k < numsLineFirst.length; k++) {
					cardMatrixFirst[j][k] = Integer.valueOf(numsLineFirst[k]);
				}
			}

			int guessLineSecond = Integer.valueOf(reader.readLine());

			for (int j = 0; j < 4; j++) {
				String line = reader.readLine();
				String[] numsLineSecond = line.split(" ");

				for (int k = 0; k < numsLineSecond.length; k++) {
					cardMatrixSecond[j][k] = Integer.valueOf(numsLineSecond[k]);
				}
			}

			HashSet<Integer> hashSet = new HashSet<>();

			// add round one to hash set
			for (int j = 0; j < 4; j++) {
				hashSet.add(cardMatrixFirst[guessLineFirst - 1][j]);
			}

			// compare round two to round one
			int count = 0;
			int lastMatch = 0;
			for (int j = 0; j < 4; j++) {
				if (hashSet.contains(cardMatrixSecond[guessLineSecond - 1][j])) {
					count++;
					lastMatch = cardMatrixSecond[guessLineSecond - 1][j];
				}
			}

			if (1 == count) {
				writer.println("Case #" + globalCount++ + ": " + lastMatch);
			} else if (0 == count) {
				writer.println("Case #" + globalCount++
						+ ": Volunteer cheated!");
			} else if (1 < count) {
				writer.println("Case #" + globalCount++ + ": Bad magician!");
			}
		}
	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		if (1 != args.length) {
			System.exit(0);
		}

		String filename = args[0];

		BufferedReader reader = new BufferedReader(new FileReader(filename));
		PrintStream writer = new PrintStream(args[0] + ".output");

		solve(reader, writer);

		reader.close();
		writer.close();
	}

}
