import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class AlienLanguage {

	public static void main(String[] args) throws IOException {

		System.setOut(new PrintStream(".\\AlienLanguageOutput.txt"));
		
		FileInputStream inputStream = new FileInputStream(".\\A-large.in");
		BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));

		int numberOfLetters = 0;
		int numberOfWords = 0;
		int numberOfPatterns = 0;
		int[] integers = new int[3];
		List<String> wordsList = new ArrayList<String>();
		List<String> patternList = new ArrayList<String>();

		String firstLine = reader.readLine();

		if (firstLine != null) {
			firstLine = firstLine.trim();
			StringTokenizer tokenizer = new StringTokenizer(firstLine, " ");

			int i = 0;
			while (tokenizer.hasMoreTokens()) {
				integers[i] = Integer.parseInt(tokenizer.nextToken());
				i++;
			}

			if (integers.length == 3) {
				numberOfLetters = integers[0];
				numberOfWords = integers[1];
				numberOfPatterns = integers[2];
			}
		}

		if (numberOfLetters > 0 && numberOfPatterns > 0 && numberOfWords > 0) {

			int i = 0;
			String word = null;
			while (i < numberOfWords) {
				word = reader.readLine();
				if (word != null) {
					wordsList.add(word.trim());
				}
				i++;
			}

			int j = 0;
			String pattern = null;
			while (j < numberOfPatterns) {
				pattern = reader.readLine();
				if (pattern != null) {
					patternList.add(pattern.trim().replace('(', '[').replace(')', ']'));
				}
				j++;
			}

			int caseCount = 0;
			int validWordCount = 0;

			for (String patternStr : patternList) {
				if (patternStr != null) {
					caseCount++;
					validWordCount = 0;
					boolean skip = false;
					char[] charachers = patternStr.toCharArray();

					if (charachers != null) {
						for (int l = 0; l < charachers.length; l++) {
							if (charachers[l] != '[' && charachers[l] != ']'
									&& !(String.valueOf(charachers[l]).matches("[a-z]"))) {
								skip = true;
								break;
							}
						}
					} else {
						skip = true;
					}

					if (!skip) {
						for (String wordStr : wordsList) {
							if (wordStr != null && wordStr.matches(patternStr)) {
								validWordCount++;
							}
						}
					}

					System.out.println("Case #" + caseCount + ": " + validWordCount);
				}
			}
		}
	}
}
