import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class aEasy {

	public static void main(String[] args) throws IOException {

		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamR1B/src/A-small-attempt1.in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamR1B/src/test.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		System.setOut(new PrintStream(fileOut));

		String line;
		int testCase = 1;
		int nbWords = 0;
		int i = 1;
		int temp = 0;
		List<String> set = new ArrayList<>();

		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue;
			}
			switch (i) {
			case 1:
				nbWords = Integer.parseInt(input[0]);
				break;
			default:
				set.add(input[0]);
				temp++;
			}
			if (nbWords == temp) {
				temp = 0;
				calculate(nbWords, set, testCase);
				testCase++;
				set = new ArrayList<>();
				i = 0;
			}
			i++;
		}

	}

	private static void calculate(int nbWords, List<String> set, int testCase) {
		List<String> mySet = new ArrayList<>(set);

		boolean isOK = checkIfOk(mySet);

		if (!isOK) {
			System.out.println("Case #" + testCase + ": Fegla Won");
			return;
		}

		int total = 0;
		
		List<List<Integer>> list = new ArrayList<>();
		int k = 0;
		int temp = 0;
		for (String s : mySet) {
			list.add(new ArrayList<Integer>());
			char pred = '0';
			temp = 0;
			for (int j = 0; j < s.length(); j++) {
				if (j == 0) {
					temp++;
					pred = s.charAt(j);
					if (j == s.length() - 1) {
						list.get(k).add(temp);
					}
					continue;
				}
				if (s.charAt(j) != pred) {
					pred = s.charAt(j);
					list.get(k).add(temp);
					temp=1;
					if (j == s.length() - 1) {
						list.get(k).add(temp);
					}
					continue;
				}
				temp++;
				if (j == s.length() - 1) {
					list.get(k).add(temp);
				}
			}
			k++;
		}
		
		//uniquement 2 listes (easy)
		for (int i = 0; i < list.get(0).size(); i++) {
			int tempAv = (list.get(0).get(i) + list.get(1).get(i)) / 2;
			total += Math.abs(tempAv - list.get(0).get(i));
			total += Math.abs(tempAv - list.get(1).get(i));
		}

		System.out.println("Case #" + testCase + ": " + total);

	}

	private static String minWord(List<String> mySet) {
		for (String s : mySet) {
			return removeRedundance(s);
		}
		return null;
	}

	private static boolean checkIfOk(List<String> mySet) {
		String checker = "";
		int i = 0;
		for (String s : mySet) {
			if (!removeRedundance(s).equals(checker) && i != 0) {
				return false;
			}
			if (i == 0) {
				checker = removeRedundance(s);
			}

			i++;
		}
		return true;
	}

	private static String removeRedundance(String s) {
		String newWord = "";
		char pred = '0';
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != pred) {
				newWord += s.charAt(i);
			}
			pred = s.charAt(i);
		}
		return newWord;
	}

}
