package com.baskok.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AlienLanguage {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("src/com/baskok/codejam/A-large.in"));
		// unneeded, but need to parse anyway
		int numberOfLetters = in.nextInt();
		int numberOfWords = in.nextInt();
		int numberOfTestCases = in.nextInt();
		AlienLanguage problem = new AlienLanguage();
		// read words
		for (int i = 0; i < numberOfWords; i++) {
			String word = in.next();
			problem.addWord(word);			
		}
		// handle problems
		for (int i = 1; i <= numberOfTestCases; i++) {
			String testCase = in.next();
			System.out.println("Case #" + i + ": " + problem.solve(testCase));
		}
	}

	private List<String> words = new ArrayList<String>();
	
	public void addWord(String word) {
		words.add(word);
	}

	public int solve(String testCase) {
		int matching = 0;
		testCase = testCase.replaceAll("\\(", "[");
		testCase = testCase.replaceAll("\\)", "]");
		for (String word : words) {
			if (word.matches(testCase)) {
				matching++;
			}
		}
		return matching;
	}

}
