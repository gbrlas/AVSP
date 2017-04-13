import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

public class WelcomeToCodeJam{
	
	public static void main(String args[]) throws IOException{
		
		String inputFileName = "";
		String output = "";
		String phrase = "welcome to code jam";
		int numTest;
		
		if(args.length != 1){
			System.out.println("Please specify input file name as 1st argument.");
		}else{
			inputFileName = args[0];
		}
		
		FileReader fr = new FileReader(inputFileName);
		BufferedReader br = new BufferedReader(fr);
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		
		numTest = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < numTest; i++){
			line = br.readLine();
			long count = countSubSequence(phrase, line, 0, 0);
			String result = count + "";
			if(result.length() > 4){
				result.substring(result.length() - 4, result.length());
			}else{
				for(int j = result.length(); j < 4; j++){
					result = "0" + result;
				}
			}
			output += "Case #" + (i+1) + ": " + result + "\n";
		}
		
		br.close();
		
		st = new StringTokenizer(inputFileName, ".");
		String outFileName = st.nextToken() + ".out";
		FileWriter fstream = new FileWriter(outFileName);
		BufferedWriter out = new BufferedWriter(fstream);
		
		//System.out.println(output);
		out.write(output);
		out.close();
		
	}
	
	private static long countSubSequence(String phrase, String seq, int pos, long count){
		char c = phrase.charAt(pos);
		int stopIndex = seq.length() - (phrase.length() - pos) + 1;
		if(pos < phrase.length() - 1){
			for(int i = 0; i < stopIndex; i++){
				if(seq.charAt(i) == c){
					count = countSubSequence(phrase, seq.subSequence(i + 1, seq.length()).toString(), pos+1, count);
				}
			}
		}else{
			for(int i = 0; i < stopIndex; i++){
				if(seq.charAt(i) == c){
					count++;
				}
			}
		}
		
		return count;
	}
	
}