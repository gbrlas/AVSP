package codejam2010.qualification;

import java.io.BufferedReader;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class ProblemB {

	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try {
			String fileName = "B-large";
			File folder = new File(new File("files", "codejam2010"), "qualification");
			File inputFile = new File(folder, fileName + ".in");
			File outputFile = new File(folder, fileName + ".out");
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new PrintWriter(new FileWriter(outputFile));
			int count = Integer.parseInt(reader.readLine());
			for (int i = 0; i < count; i++) {
				writer.printf("Case #%d: %s\n", i+1,
						solveIt(parseNumbers(reader.readLine())));
				writer.flush();
				System.out.println(i+1);
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			close(reader);
			close(writer);
		}
		System.out.println("Done.");
	}

	private static String solveIt(BigInteger[] t) {
		Arrays.sort(t);
		BigInteger[] diff = new BigInteger[t.length - 1];
		for (int i = 1; i < t.length; i++) {
			diff[i-1] = t[i].subtract(t[i-1]);
		}
		BigInteger T = mdc(diff);
		BigInteger y = mod(t[0], T);
		if (y.compareTo(BigInteger.ZERO) != 0) {
			y = T.subtract(y);
		}
		for (int i = 0; i < t.length; i++) {
			if (mod(t[i].add(y), T).compareTo(BigInteger.ZERO) != 0) {
				System.out.println("Oops!");
			}
		}
		return y.toString();
	}

	private static BigInteger mdc(BigInteger[] t) {
		BigInteger mdc = t[0];
		for (int i = 1; i < t.length; i++) {
			mdc = mdc(mdc, t[i]);
		}
		return mdc;
	}

	private static BigInteger mdc(BigInteger t1, BigInteger t2) {
		BigInteger mod = t1;
		do {
			t1 = mod;
			mod = mod(t2, t1);
			t2 = t1;
		} while (mod.compareTo(BigInteger.ZERO) != 0);
		return t1;
	}

	private static BigInteger mod(BigInteger t2, BigInteger t1) {
		if (t1.compareTo(BigInteger.ZERO) == 0) {
			return t2;
		}
		BigInteger[] divMod = t2.divideAndRemainder(t1);
		return divMod[1];
	}

	public static BigInteger[] parseNumbers(String line) {
		String[] strings = line.split("\\s");
		int n = Integer.parseInt(strings[0]);
		BigInteger[] numbers = new BigInteger[n];
		for (int i = 0; i < n; i++) {
			numbers[i] = new BigInteger(strings[i+1]);
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
