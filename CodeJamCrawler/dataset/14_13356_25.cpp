import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MargicTrick {

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		BufferedReader reader = new BufferedReader(new FileReader(
				"A-small-attempt4.in"));
		int caseNumber = Integer.parseInt(reader.readLine());

		BufferedWriter writer = new BufferedWriter(new FileWriter(
				"magicTrick.out"));

		ArrayList<Integer> firstArrangementAnswer = new ArrayList<Integer>();
		ArrayList<Integer> secondArrangementAnswer = new ArrayList<Integer>();

		if (1 <= caseNumber && caseNumber <= 100) {
			for (int i = 1; i <= caseNumber; i++) {

				firstArrangementAnswer.clear();
				secondArrangementAnswer.clear();

				int firstRowAnswer = Integer.parseInt(reader.readLine());
				arrangCard(reader, firstArrangementAnswer, firstRowAnswer);
				int secondRowAnswer = Integer.parseInt(reader.readLine());
				arrangCard(reader, secondArrangementAnswer, secondRowAnswer);

				if (secondArrangementAnswer.retainAll(firstArrangementAnswer)) {

					if (secondArrangementAnswer.size() == 1) {

						writer.write(String.format("Case #%d: %d\n", i,
								secondArrangementAnswer.get(0)));

					} else if (secondArrangementAnswer.size() > 1) {

						writer.write(String.format("Case #%d: Bad magician!\n",
								i));

					} else {
						writer.write(String.format(
								"Case #%d: Volunteer cheated!\n", i));
					}

				} else {
					writer.write(String.format("Case #%d: Bad magician!\n", i));
				}

			}
		}

		reader.close();
		writer.flush();
		writer.close();
	}

	private static void arrangCard(BufferedReader reader,
			ArrayList<Integer> pickedArrangement, int pickedRow)
			throws IOException {

		int rowNumnber = 0;
		while (rowNumnber < 4) {
			// pick only for picked row.
			if (rowNumnber == pickedRow - 1) {
				String line = reader.readLine();
				String[] listCardNumber = line.split(" ");
				for (String cardNumber : listCardNumber) {
					pickedArrangement.add(Integer.parseInt(cardNumber.trim()));
				}
			} else {
				// ignore
				reader.readLine();
			}
			rowNumnber++;
		}

	}

}
