import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Qualification{

	public static void main(String args[]) throws IOException{
		
		String inputFileName = "";
		int wordLength, numWords, numTests;
		Map<String, State> dictionary = new HashMap<String, State>();
		
		if(args.length != 1){
			System.out.println("Please specify input file name as 1st argument.");
		}else{
			inputFileName = args[0];
		}
		
		FileReader fr = new FileReader(inputFileName);
		BufferedReader br = new BufferedReader(fr);
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		
		wordLength = Integer.parseInt(st.nextToken());
		numWords = Integer.parseInt(st.nextToken());
		numTests = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < numWords; i++){
			line = br.readLine();
			State cs = null;
			State ns = null;
			String c = line.charAt(0) + "";
			if(dictionary.containsKey(c)){
				cs = dictionary.get(c);
			}else{
				cs = new State(c);
				dictionary.put(c, cs);
			}
			for(int j = 1; j < wordLength; j++){
				c = line.charAt(j) + "";
				ns = cs.hasNextState(c);
				if(ns != null){
					cs = ns;
				}else{
					cs = cs.addNextState(c);
				}
			}
		}
		
		int[] counts = new int[numTests];
		
		for(int i = 0; i < numTests; i++){
			line = br.readLine();
			counts[i] = getNumMatches(null, 0, line + "", 0, dictionary);
		}
		
		br.close();
		
		st = new StringTokenizer(inputFileName, ".");
		String outFileName = st.nextToken() + ".out";
		FileWriter fstream = new FileWriter(outFileName);
		BufferedWriter out = new BufferedWriter(fstream);
		String output = "";
		for(int i = 0; i < counts.length; i++){
			output += "Case #" + (i+1) + ": " + counts[i] + "\n";
		}
		System.out.println(output);
		out.write(output);
		out.close();
		
	}
	
	private static int getNumMatches(State cur, int sum, String exp, int pos, Map<String, State> dic){

		if((cur != null) || (pos == 0)){
			
			String c = exp.charAt(pos) + "";
			if(c.equals("(")){
				String tmp = "";
				int j = pos + 1;
				c = exp.charAt(j) + "";
				while(!c.equals(")")){
					tmp += c;
					j++;
					c = exp.charAt(j) + "";
				}
				j++;
				if(j < exp.length() - 1){
					for(int i = 0; i < tmp.length(); i++){
						c = tmp.charAt(i) + "";
						if((pos == 0)){
							if(dic.containsKey(c)){
								sum = getNumMatches(dic.get(c), sum, exp, j, dic);
							}	
						}else{
							sum = getNumMatches(cur.hasNextState(c), sum, exp, j, dic);
						}
					}
				}else{
					for(int i = 0; i < tmp.length(); i++){
						c = tmp.charAt(i) + "";
						if((pos == 0)){
							if(dic.containsKey(c)){
								sum++;
							}	
						}else{
							if(cur.hasNextState(c) != null){
								sum++;
							}
						}
					}
				}
			}else{
				if(pos < exp.length() - 1){
					if(pos == 0){
						if(dic.containsKey(c)){

							sum = getNumMatches(dic.get(c), sum, exp, pos+1, dic);
						}	
					}else{
						sum = getNumMatches(cur.hasNextState(c), sum, exp, pos+1, dic);
					}
				}else{
					if(pos == 0){
						if(dic.containsKey(c)){
							cur = dic.get(c);
						}
					}else{
						cur = cur.hasNextState(c);
					}
					if(cur != null){
						sum++;
					}
				}
			}
		}	
		return sum;
	}
	
}

/*
 
Problem:

After years of study, scientists at Google Labs have discovered an alien language transmitted from a faraway planet. The alien language is very unique in that every word consists of exactly L lowercase letters. Also, there are exactly D words in this language.

Once the dictionary of all the words in the alien language was built, the next breakthrough was to discover that the aliens have been transmitting messages to Earth for the past decade. Unfortunately, these signals are weakened due to the distance between our two planets and some of the words may be misinterpreted. In order to help them decipher these messages, the scientists have asked you to devise an algorithm that will determine the number of possible interpretations for a given pattern.

A pattern consists of exactly L tokens. Each token is either a single lowercase letter (the scientists are very sure that this is the letter) or a group of unique lowercase letters surrounded by parenthesis ( and ). For example: (ab)d(dc) means the first letter is either a or b, the second letter is definitely d and the last letter is either d or c. Therefore, the pattern (ab)d(dc) can stand for either one of these 4 possibilities: add, adc, bdd, bdc.

Input:

The first line of input contains 3 integers, L, D and N separated by a space. D lines follow, each containing one word of length L. These are the words that are known to exist in the alien language. N test cases then follow, each on its own line and each consisting of a pattern as described above. You may assume that all known words provided are unique.

Output:

For each test case, output

Case #X: K

where X is the test case number, starting from 1, and K indicates how many words in the alien language match the pattern.

Limits:

Small dataset

1 ² L ² 10
1 ² D ² 25
1 ² N ² 10

Large dataset

1 ² L ² 15
1 ² D ² 5000
1 ² N ² 500

*/