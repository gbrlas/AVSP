package google.code.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class SpeakingInTongues {

	final static int maxInputLength = 100;
	final static String alphabet = "abcdefghijklmnopqrstuvwxyz ";
	final static String substitution = "ynficwlbkuomxsevzpdrjgthaq ";
	final static String fileNameIn = "A-small-attempt0.in";
	final static String fileNameOut = "A-small-attempt0.out";

	private static String decrypt(String input) {
		String cipherText = input.trim();
		StringBuffer plainText = new StringBuffer();
		int size = Math.min(maxInputLength, cipherText.length());
		for (int i = 0; i < size; i++) {
			Character ch = cipherText.charAt(i);
			int substitutionIndex = substitution.indexOf(ch);
			if (substitutionIndex >= 0
					&& substitutionIndex <= alphabet.length() - 1) {
				plainText.append(alphabet.charAt(substitutionIndex));
			}
		}
		return plainText.toString();
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(fileNameIn));
		BufferedWriter out = new BufferedWriter(new FileWriter(fileNameOut));
		int testCases = Integer.parseInt(in.readLine());
		for (int i = 0; i < testCases; i++) {
			out.write(String.format("Case #%s: %s\n", i + 1, decrypt(in.readLine())));
		}
		in.close();
		out.close();
	}

}
