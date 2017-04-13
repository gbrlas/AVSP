import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class b {

	public static void main(String[] args) throws IOException {

		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamR1B/src/B-small-attempt1.in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamR1B/src/test.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(
				System.in));
		System.setOut(new PrintStream(fileOut));

		String line;
		int testCase = 1;
		int i = 1;

		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue;
			}
			calculate(Integer.parseInt(input[0]), Integer.parseInt(input[1]), Integer.parseInt(input[2]), testCase);
			testCase++;
		}

	}

	private static void calculate(int a, int b, int k, int testCase) {
		long total = 0;
		Set<Integer> setK = new HashSet<>();
		for (int i = 0; i < k; i++) {
			setK.add(i);
		}
		
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (setK.contains(i & j)) {
					total++;
				}
			}
		}
		
		System.out.println("Case #" + testCase + ": " + total);
	}

}
