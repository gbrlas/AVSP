package qualification.a;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 * 
 * Problem

We have come up with the best possible language here at Google, called Googlerese. To translate text into Googlerese, we take any message and replace each English letter with another English letter. This mapping is one-to-one and onto, which means that the same input letter always gets replaced with the same output letter, and different input letters always get replaced with different output letters. A letter may be replaced by itself. Spaces are left as-is.
For example (and here is a hint!), our awesome translation algorithm includes the following three mappings: 'a' -> 'y', 'o' -> 'e', and 'z' -> 'q'. This means that "a zoo" will become "y qee".
Googlerese is based on the best possible replacement mapping, and we will never change it. It will always be the same. In every test case. We will not tell you the rest of our mapping because that would make the problem too easy, but there are a few examples below that may help.
Given some text in Googlerese, can you translate it to back to normal text?

Solving this problem
Usually, Google Code Jam problems have 1 Small input and 1 Large input. This problem has only 1 Small input. Once you have solved the Small input, you have finished solving this problem.

Input
The first line of the input gives the number of test cases, T. T test cases follow, one per line.
Each line consists of a string G in Googlerese, made up of one or more words containing the letters 'a' - 'z'. There will be exactly one space (' ') character between consecutive words and no spaces at the beginning or at the end of any line.

Output
For each test case, output one line containing "Case #X: S" where X is the case number and S is the string that becomes G in Googlerese.

Limits
1 ≤ T ≤ 30.
G contains at most 100 characters.
None of the text is guaranteed to be valid English.
Sample

Input
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv

Output
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up


 * 2012.04.15. 01:41 - 
 * @author Chei
 */
public class SpeakingInTongues {
	Scanner scanner;
	public static void main(String[] args) throws FileNotFoundException {
		new SpeakingInTongues().solve();
	}
	
	void solve() throws FileNotFoundException {
		scanner = new Scanner(new File("resources/A-small-attempt0.in"));
		int numberOfTestCases = scanner.nextInt();
		String text = scanner.nextLine();
		for (int testCaseIndex = 1; testCaseIndex <= numberOfTestCases; testCaseIndex++) {
			String result = solveTestCase();
			System.out.format("Case #%d: %s%n", testCaseIndex, result);
		}
	}

	String solveTestCase() {
		String text = scanner.nextLine();
		StringBuilder result = new StringBuilder();
		for (char c: text.toCharArray()) {
			char translatedChar = 0;
			switch (c) {
			case 'a': translatedChar = 'y'; break;
			case 'b': translatedChar = 'h'; break;
			case 'c': translatedChar = 'e'; break;
			case 'd': translatedChar = 's'; break;
			case 'e': translatedChar = 'o'; break;
			case 'f': translatedChar = 'c'; break;
			case 'g': translatedChar = 'v'; break;
			case 'h': translatedChar = 'x'; break;
			case 'i': translatedChar = 'd'; break;
			case 'j': translatedChar = 'u'; break;
			case 'k': translatedChar = 'i'; break;
			case 'l': translatedChar = 'g'; break;
			case 'm': translatedChar = 'l'; break;
			case 'n': translatedChar = 'b'; break;
			case 'o': translatedChar = 'k'; break;
			case 'p': translatedChar = 'r'; break;
			case 'q': translatedChar = 'z'; break;
			case 'r': translatedChar = 't'; break;
			case 's': translatedChar = 'n'; break;
			case 't': translatedChar = 'w'; break;
			case 'u': translatedChar = 'j'; break;
			case 'v': translatedChar = 'p'; break;
			case 'w': translatedChar = 'f'; break;
			case 'x': translatedChar = 'm'; break;
			case 'y': translatedChar = 'a'; break;
			case 'z': translatedChar = 'q'; break;
			case ' ': translatedChar = ' '; break;
			default:
				break;
			}
			result.append(translatedChar);
		}
		return result.toString();
	}
}
