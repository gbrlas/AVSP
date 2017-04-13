package codejam2010.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class ProblemC {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "C-small-attempt0";
			File folder = new File(new File("files", "codejam2010"), "qualification");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				int[] line1 = parseIntegers(reader.readLine());
				int[] line2 = parseIntegers(reader.readLine());
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(line1[0], line1[1], line1[2], line2));
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(int r, int k, int n, int[] g) {
		int y = 0;
		int ni = 0;
		for (int ri = 0; ri < r; ri++) {
			int no = ni;
			int ki = 0;
			while (true) {
				if (ki + g[ni] > k) {
					break;
				} else {
					ki += g[ni];
					ni++;
					if (ni >= n) {
						ni = 0;
					}
					if (no == ni) {
						break;
					}
				}
			}
			y += ki;
		}
		return String.valueOf(y);
	}

	public static int[] parseIntegers(String line) {
		String[] strings = line.split("\\s");
		int[] numbers = new int[strings.length];
		for (int i = 0; i < strings.length; i++) {
			numbers[i] = Integer.parseInt(strings[i]);
		}
		return numbers;
	}

	private static void close(Closeable file) {
		if (file != null) {
			try {
				file.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
