import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MagicTrick {

	private static String inputDir = "C:\\CodeJam2014\\Input\\";
	private static String outputDir = "C:\\CodeJam2014\\Output\\";

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream(inputDir + "A-small-attempt0.in")));
		BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputDir + "MagicTrickOutput.txt")));
		int testCases = Integer.parseInt(in.readLine().trim());
		for (int i = 0; i < testCases; i++) {
			int rowNumber = 0;
			Integer[][] cardNumbers = new Integer[4][4];
			MagicTrickTestCase testCase = new MagicTrickTestCase();
			testCase.setFirstAnswer(Integer.parseInt(in.readLine().trim()));
			while (rowNumber < 4) {
				String[] cards = in.readLine().trim().split("\\s");
				for (int j = 0; j < cards.length; j++) {
					cardNumbers[rowNumber][j] = Integer.parseInt(cards[j]);
				}
				rowNumber++;
			}
			testCase.setFirstArrangement(cardNumbers);
			rowNumber = 0;
			cardNumbers = new Integer[4][4];
			testCase.setSecondAnswer(Integer.parseInt(in.readLine().trim()));
			while (rowNumber < 4) {
				String[] cards = in.readLine().trim().split("\\s");
				for (int j = 0; j < cards.length; j++) {
					cardNumbers[rowNumber][j] = Integer.parseInt(cards[j]);
				}
				rowNumber++;
			}
			testCase.setSecondArrangement(cardNumbers);
			out.write("Case #" + (i + 1) + ": " + testCase.getResult());
			if (i != testCases - 1) {
				out.newLine();
			}
		}
		in.close();
		out.close();
	}

	private static class MagicTrickTestCase {
		private int firstAnswer;
		private int secondAnswer;
		private Integer firstArrangement[][];
		private Integer secondArrangement[][];

		public void setFirstAnswer(int firstAnswer) {
			this.firstAnswer = firstAnswer;
		}

		public void setSecondAnswer(int secondAnswer) {
			this.secondAnswer = secondAnswer;
		}

		public void setFirstArrangement(Integer[][] firstArrangement) {
			this.firstArrangement = firstArrangement;
		}

		public void setSecondArrangement(Integer[][] secondArrangement) {
			this.secondArrangement = secondArrangement;
		}

		public String getResult() {
			List<Integer> firstRow = new ArrayList<>(Arrays.asList(firstArrangement[firstAnswer - 1]));
			List<Integer> secondRow = new ArrayList<>(Arrays.asList(secondArrangement[secondAnswer - 1]));
			secondRow.retainAll(firstRow);
			return secondRow.size() == 0 ? "Volunteer cheated!" : (secondRow.size() > 1 ? "Bad magician!" : String.valueOf(secondRow.get(0)));
		}
	}
}
