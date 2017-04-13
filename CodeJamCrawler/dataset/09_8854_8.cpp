import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class AllYourBase{
	
	public static void main(String args[]) throws IOException{
		
		String inputFileName = "";
		int numTests;
		
		if(args.length != 1){
			System.out.println("Please specify input file name as 1st argument.");
		}else{
			inputFileName = args[0];
		}
		
		FileReader fr = new FileReader(inputFileName);
		BufferedReader br = new BufferedReader(fr);
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		
		numTests = Integer.parseInt(st.nextToken());
		String[] cases = new String[numTests];
		int[] results = new int[numTests];
		
		for(int i = 0; i < numTests; i++){
			st = new StringTokenizer(br.readLine());
			cases[i] = st.nextToken();
			results[i] = 0;
		}
		
		for(int i = 0; i < numTests; i++){
			Map<Character, Character> chars = new HashMap<Character, Character>();
			Map<Character, Integer> charsToDig = new HashMap<Character, Integer>();
			String c = cases[i];
			for(int j = 0; j < c.length(); j++){
				chars.put(c.charAt(j), 'n');
			}
			int base = 2;
			if(chars.size() > 2){
				base = chars.size();
			}
			int num = 0;
			int curNum = 0;
			charsToDig.put(c.charAt(0), 1);
			results[i] += (Math.pow(base, c.length() - 1));

			for(int j = 1; j < c.length(); j++){
				if(charsToDig.containsKey(c.charAt(j))){
					num = charsToDig.get(c.charAt(j));
				}else{
					num = curNum;
					charsToDig.put(c.charAt(j), curNum);
					curNum++;
					if(curNum == 1){
						curNum = 2;
					}
				}
				results[i] += (Math.pow(base, c.length() - j - 1) * num);
			}
		}
		

		st = new StringTokenizer(inputFileName, ".");
		String outFileName = st.nextToken() + ".out";
		FileWriter fstream = new FileWriter(outFileName);
		BufferedWriter out = new BufferedWriter(fstream);
		String output = "";
		for(int i = 0; i < numTests; i++){
			output += "Case #" + (i+1) + ": " + results[i] + "\n";
		}
		//System.out.println(output);
		out.write(output);
		out.close();
		br.close();
	}	
}