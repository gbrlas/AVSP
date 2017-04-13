import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Problem1 {

	public static void main(String[] args) throws IOException {

		System.setOut(new PrintStream(".\\Problem1Output.txt"));

		FileInputStream inputStream = new FileInputStream(".\\B-small-attempt0(2).in");
		BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

		String firstLine = reader.readLine();

		if (firstLine != null) {

			int numberOfTestCases = Integer.parseInt(firstLine);

			for (int i = 0; i < numberOfTestCases; i++) {

				long firstNumber = Long.parseLong(reader.readLine());

				String numberStr = String.valueOf(firstNumber);

				char[] chars = numberStr.toCharArray();
				List<Integer> digitsList = new ArrayList<Integer>();

				for (int j = 0; j < chars.length; j++) {
					if (chars[j] != '0') {
						digitsList.add(Integer.parseInt(String.valueOf(chars[j])));
					}
				}

				Collections.sort(digitsList);

				boolean found = false;

				while (true) {
					firstNumber++;

					numberStr = String.valueOf(firstNumber);
					chars = numberStr.toCharArray();
					List<Integer> digitsList1 = new ArrayList<Integer>();

					for (int j = 0; j < chars.length; j++) {
						if (chars[j] != '0') {
							digitsList1.add(Integer.parseInt(String.valueOf(chars[j])));
						}
					}

					Collections.sort(digitsList1);

					if (digitsList.size() == digitsList1.size() && digitsList.equals(digitsList1)) {
						found = true;
						break;
					}
				}
				
				int caseCount = i + 1;
				if (found) {
					System.out.println("Case #" + caseCount + ": " + firstNumber);
				}
			}
		}
	}
}
