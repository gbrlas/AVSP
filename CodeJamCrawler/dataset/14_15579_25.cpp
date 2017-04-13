import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class magic {

	public static void main(String[] args) {
		// The name of the file to open.
		String fileName = "data.txt";

		// This will reference one line at a time
		String line = null;
		int numCases;

		try {
			// FileReader reads text files in the default encoding.
			FileReader fileReader = new FileReader(fileName);

			// Always wrap FileReader in BufferedReader.
			BufferedReader bufferedReader = new BufferedReader(fileReader);

			numCases = Integer.parseInt(bufferedReader.readLine());

			// indl cases
			for (int i = 0; i < numCases; i++) {
				int choice1 = Integer.parseInt(bufferedReader.readLine());
				String line1 = null;
				for (int j = 0; j < 4; j++) {
					line = bufferedReader.readLine();
					if (j == (choice1 - 1))
						line1 = line;
				}

				int choice2 = Integer.parseInt(bufferedReader.readLine());
				String line2 = null;
				for (int j = 0; j < 4; j++) {
					line = bufferedReader.readLine();
					if (j == (choice2 - 1))
						line2 = line;
				}

				int res = check(line1, line2);
				if (res == -2) {
					System.out.println("Case #" + (i + 1) + ": "
							+ "Volunteer cheated!");
				} else if (res == -1) {
					System.out.println("Case #" + (i + 1) + ": "
							+ "Bad magician!");
				} else {
					System.out.println("Case #" + (i + 1) + ": " + res);
				}

			}

			// Always close files.
			bufferedReader.close();
		} catch (FileNotFoundException ex) {
			System.out.println("Unable to open file '" + fileName + "'");
		} catch (IOException ex) {
			System.out.println("Error reading file '" + fileName + "'");
			// Or we could just do this:
			// ex.printStackTrace();
		}

	}

	private static int check(String line1, String line2) {
		String[] arr1 = line1.split(" ");
		String[] arr2 = line2.split(" ");
		int found = 0;
		int num = -10;
		for (int i = 0; i < arr1.length; i++) {
			for (int j = 0; j < arr2.length; j++) {
				if (Integer.parseInt(arr1[i]) == Integer.parseInt(arr2[j])) {
					found++;
					num = Integer.parseInt(arr1[i]);
				}
			}
		}
		if (found == 0)
			return -2;
		else if (found > 1)
			return -1;
		else
			return num;
	}
}
