package com.google.codejam.clue.welcome;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Runner {
	public static void main(String[] args) throws Exception{
		BufferedReader r = new BufferedReader(new FileReader("A-large.in"));
		String params = r.readLine();
		int firstSpaceIdx = params.indexOf(" ");
		int secondSpaceIdx = params.indexOf(" ", firstSpaceIdx+1);
		int wordLength = Integer.parseInt(params.substring(0, firstSpaceIdx));
		int dictionaryLength = Integer.parseInt(params.substring(firstSpaceIdx+1, secondSpaceIdx));
		int casesNumber = Integer.parseInt(params.substring(secondSpaceIdx+1));
		
		char[][] dictionary = new char[dictionaryLength][];
		for (int i=0; i<dictionaryLength; i++){
			String wordStr = r.readLine();
			dictionary[i] = wordStr.toCharArray();
		}
		
		
		CompiledPattern[] compiledPatterns = new CompiledPattern[casesNumber];
		for (int i=0; i<casesNumber; i++) {
			String pattern = r.readLine();
			
			int currCharNum = 0;
			CompiledPattern currentPattern  = new CompiledPattern(wordLength);
			int cursorPos = 0;
			boolean orMode = false;
			
			while (cursorPos < pattern.length()) {
				char currChar = pattern.charAt(cursorPos);
				if (currChar == '(') {					
					orMode = true;
					
				} else if (currChar == ')') {
					orMode = false;
					currCharNum++;
					
				} else {
					currentPattern.addCharVariation(currCharNum, currChar);
					if (!orMode) {						
						currCharNum++;						
					}					
				}
				
				cursorPos++;
			}
			
			compiledPatterns[i] = currentPattern;
		}
		
		r.close();
		
		int[] results = new int[casesNumber];
		for (int dictPos=0; dictPos<dictionaryLength; dictPos++) {
			char[] word = dictionary[dictPos];
			for (int patternPos=0; patternPos<casesNumber; patternPos++) {
				if (compiledPatterns[patternPos].wordMatches(word)) {
					results[patternPos]++;
				}
			}
		}
		
		PrintWriter wr = new PrintWriter(new FileWriter("C-small-attempt0.out"));
		for (int i=0; i<casesNumber; i++) {
			wr.println("Case #"+(i+1)+": "+results[i]);
		}
		wr.close();
	}
}
