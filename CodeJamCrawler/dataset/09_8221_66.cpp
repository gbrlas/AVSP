import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class WaterShedsProblem {

	public static List<String> algorithm(List<String> inputFileContent) {
		List<String> outputFileContent = new ArrayList<String>();

		long numberOfCases = Integer.parseInt(inputFileContent.get(0).trim());
		int lineCounter = 1;

		for (int index = 0; index < numberOfCases; index++) {
			String[] gridSize = inputFileContent.get(lineCounter).split(" ");
			int height = Integer.parseInt(gridSize[0]);
			int width = Integer.parseInt(gridSize[1]);
			lineCounter++;

			// input array
			int[][] grid = new int[height][width];

			for (int i = 0; i < height; i++) {
				String[] columnData = inputFileContent.get(lineCounter).split(" ");
				lineCounter++;
				for (int j = 0; j < columnData.length; j++) {
					grid[i][j] = Integer.parseInt(columnData[j]);
				}
			}

			// alphabetical array for output
			String[][] alphabets = new String[height][width];
			alphabets[0][0] = "a";
			char charac = 'a';
			for (int ht = 0; ht < height; ht++) {
				for (int wd = 0; wd < width; wd++) {
					boolean bool = true;
					int i = ht;
					int j = wd;

					int count = 0;
					while (bool) {
						count++;

						int currentValue = grid[i][j];
						String posn = "";
						if (i - 1 >= 0 && grid[i - 1][j] < currentValue) {
							currentValue = grid[i - 1][j];
							posn = "N";
						}
						if (j - 1 >= 0 && grid[i][j - 1] < currentValue) {
							currentValue = grid[i][j - 1];
							posn = "W";
						}
						if (j + 1 < width && grid[i][j + 1] < currentValue) {
							currentValue = grid[i][j + 1];
							posn = "E";
						}
						if (i + 1 < height && grid[i + 1][j] < currentValue) {
							currentValue = grid[i + 1][j];
							posn = "S";
						}
						if (posn.equalsIgnoreCase("N")) {
							if (alphabets[i - 1][j] == null || alphabets[i - 1][j].equals("")) {
								if (alphabets[i][j] == null || alphabets[i][j].equals("")) {
									charac = (char) ((int) charac + 1);
									alphabets[i][j] = new String("" + charac);
								}
								alphabets[i - 1][j] = alphabets[i][j];
							} else {
								alphabets[i][j] = alphabets[i - 1][j];
								// charac = (char) ((int) charac - 1);
							}
							i--;
						} else if (posn.equalsIgnoreCase("W")) {
							if (alphabets[i][j - 1] == null || alphabets[i][j - 1].equals("")) {
								if (alphabets[i][j] == null || alphabets[i][j].equals("")) {
									charac = (char) ((int) charac + 1);
									alphabets[i][j] = new String("" + charac);
								}
								alphabets[i][j - 1] = alphabets[i][j];
							} else {
								alphabets[i][j] = alphabets[i][j - 1];
								// charac = (char) ((int) charac - 1);
							}
							j--;
						} else if (posn.equalsIgnoreCase("E")) {
							if (alphabets[i][j + 1] == null || alphabets[i][j + 1].equals("")) {
								if (alphabets[i][j] == null || alphabets[i][j].equals("")) {
									charac = (char) ((int) charac + 1);
									alphabets[i][j] = new String("" + charac);
								}
								alphabets[i][j + 1] = alphabets[i][j];
							} else {
								alphabets[i][j] = alphabets[i][j + 1];
								// charac = (char) ((int) charac - 1);
							}
							j++;
						} else if (posn.equalsIgnoreCase("S")) {
							if (alphabets[i + 1][j] == null || alphabets[i + 1][j].equals("")) {
								if (alphabets[i][j] == null || alphabets[i][j].equals("")) {
									charac = (char) ((int) charac + 1);
									alphabets[i][j] = new String("" + charac);
								}
								alphabets[i + 1][j] = alphabets[i][j];
							} else {
								alphabets[i][j] = alphabets[i + 1][j];
								// charac = (char) ((int) charac - 1);
							}
							i++;
						} else {
							if (alphabets[i][j] == null || alphabets[i][j].equals("")) {
								charac = (char) ((int) charac + 1);
								alphabets[i][j] = new String("" + charac);
							}
							bool = false;
						}
					}
				}
			}
			for (int k = 0; k < 4; k++) {
				for (int ht = 0; ht < height; ht++) {
					for (int wd = 0; wd < width; wd++) {
						boolean bool = true;
						int i = ht;
						int j = wd;

						int count = 0;
						while (bool) {
							count++;

							int currentValue = grid[i][j];
							String posn = "";
							if (i - 1 >= 0 && grid[i - 1][j] < currentValue) {
								currentValue = grid[i - 1][j];
								posn = "N";
							}
							if (j - 1 >= 0 && grid[i][j - 1] < currentValue) {
								currentValue = grid[i][j - 1];
								posn = "W";
							}
							if (j + 1 < width && grid[i][j + 1] < currentValue) {
								currentValue = grid[i][j + 1];
								posn = "E";
							}
							if (i + 1 < height && grid[i + 1][j] < currentValue) {
								currentValue = grid[i + 1][j];
								posn = "S";
							}
							if (posn.equalsIgnoreCase("N")) {
								if (alphabets[i - 1][j] == null || alphabets[i - 1][j].equals("")) {
									alphabets[i - 1][j] = alphabets[i][j];
								} else {
									alphabets[i][j] = alphabets[i - 1][j];
								}
								i--;
							} else if (posn.equalsIgnoreCase("W")) {
								if (alphabets[i][j - 1] == null || alphabets[i][j - 1].equals("")) {
									alphabets[i][j - 1] = alphabets[i][j];
								} else {
									alphabets[i][j] = alphabets[i][j - 1];
								}
								j--;
							} else if (posn.equalsIgnoreCase("E")) {
								if (alphabets[i][j + 1] == null || alphabets[i][j + 1].equals("")) {
									alphabets[i][j + 1] = alphabets[i][j];
								} else {
									alphabets[i][j] = alphabets[i][j + 1];
								}
								j++;
							} else if (posn.equalsIgnoreCase("S")) {
								if (alphabets[i + 1][j] == null || alphabets[i + 1][j].equals("")) {
									alphabets[i + 1][j] = alphabets[i][j];
								} else {
									alphabets[i][j] = alphabets[i + 1][j];
								}
								i++;
							} else {
								bool = false;
							}
						}
					}
				}
			}

			List<String> allAlplabets = new ArrayList<String>();
			char cha = 'a';
			for (int k = 0; k < 26; k++) {
				allAlplabets.add(new String("" + cha));
				cha = (char) ((int) cha + 1);
			}
			List<String> chars = new ArrayList<String>();
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					if (!chars.contains(alphabets[i][j]))
						chars.add(alphabets[i][j]);
				}
			}
			Collections.sort(chars);
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					int ind = chars.indexOf(alphabets[i][j]);
					alphabets[i][j] = allAlplabets.get(ind);
				}
			}
			outputFileContent.add("Case #" + (index + 1) + ": ");
			for (int i = 0; i < height; i++) {
				String str = "";
				for (int j = 0; j < width; j++) {
					str = str + alphabets[i][j] + " ";

				}
				outputFileContent.add(str.trim());

			}
		}

		outputFileContent.add("");

		return outputFileContent;
	}

	public static void main(String[] args) throws FileNotFoundException, IOException {

		String inputFileLocation = ".\\B-small-attempt0.in";
		String outputFileLocation = ".\\WaterShedLargeOutput.txt";

		List<String> inputFileContent = getInputContents(inputFileLocation);
		List<String> outputFileContent = algorithm(inputFileContent);

		// Generate output file.
		writeOutputFile(outputFileContent, outputFileLocation);
	}

	/**
	 * Fetch the entire contents of a Input file, and return it in a List of
	 * String. This style of implementation does not throw Exceptions to the
	 * caller.
	 */
	static public List<String> getInputContents(String inputFileLocation) {

		File inputFile = new File(inputFileLocation);
		List<String> contents = new ArrayList<String>();
		try {
			BufferedReader input = new BufferedReader(new FileReader(inputFile));
			try {
				String line = null;
				while ((line = input.readLine()) != null) {
					contents.add(line);
				}
			} finally {
				input.close();
			}
		} catch (IOException ex) {
			ex.printStackTrace();
		}

		return contents;
	}

	/**
	 * Write the solution for Large or Small input to file named 'xxxOutput.txt' .
	 * 
	 * @param aContents -
	 *            Output written to the file.
	 * @throws FileNotFoundException
	 *             if the file does not exist.
	 * @throws IOException
	 *             if problem encountered during write.
	 */
	static public void writeOutputFile(List<String> outputFileContents, String outputFileLocation)
			throws FileNotFoundException, IOException {

		FileWriter fileWriter = new FileWriter(outputFileLocation);
		try {
			for (int index = 0; index < outputFileContents.size(); index++) {
				if (outputFileContents.get(index) != null) {
					fileWriter.write(outputFileContents.get(index).trim());
					fileWriter.write("\r\n");
				}
			}
		} finally {
			fileWriter.close();
		}
	}

}
