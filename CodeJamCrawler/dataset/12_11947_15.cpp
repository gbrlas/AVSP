package codejam.qualification.question;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

import org.apache.commons.collections.BidiMap;
import org.apache.commons.collections.bidimap.DualHashBidiMap;

public class QuestionA {

	Map<String, String> dictionary = new HashMap<String, String>(); 
	char[] dictionaryKeys;
	char[] dictionaryValues;
	
	private List<List<String>> inputList = new ArrayList<List<String>>();
	private List<String> lineList; 
	
	private String inFile = "/home/erenay/Downloads/A-small-attempt1.in";
	private String outFile = "/home/erenay/Documents/code/codejam2012/out/qual/QuestionA.txt";
	
	public static void main(String[] args) throws IOException {
		
		QuestionA main = new QuestionA();
		main.solve();
		
	}

	
		
	protected void solve() throws IOException{
			
		BidiMap dictionary = new DualHashBidiMap() {{
			   put('a', 'y'); put('b', 'n'); put('c', 'f'); put('d', 'i');
			   put('e', 'c'); put('f', 'w'); put('g', 'l'); put('h', 'b');
			   put('i', 'k'); put('j', 'u'); put('k', 'o'); put('l', 'm');
			   put('m', 'x'); put('n', 's'); put('o', 'e'); put('p', 'v');
			   put('q', 'z'); put('r', 'p'); put('s', 'd'); put('t', 'r');
			   put('u', 'j'); put('v', 'g'); put('w', 't'); put('x', 'h');
			   put('y', 'a'); put('z', 'q'); 
			}};
			
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new	FileWriter(outFile)));
		
			int numOfEntries = Integer.valueOf(br.readLine());
			int r;
			int currentCase = 1;
			pw.print("Case #"+currentCase+": ");
	        while ((r = br.read()) != -1) {
	            char ch = (char) r;
	            if (dictionary.containsKey(ch)) {
	            	pw.print(dictionary.getKey(ch));
	            }
	            else {
	            	pw.print(ch);
	            	if (ch == '\n' && currentCase < numOfEntries) {
	            		currentCase++;
	            		pw.print("Case #"+currentCase+": ");
	            	}
	            }
	        }

	        br.close();
			pw.close();
			System.out.println("Completed.");
	}
		
	protected void readInput() throws IOException{
		BufferedReader br = new BufferedReader(new FileReader(inFile));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new	FileWriter(outFile)));
		String line = null;
		int nEntry = Integer.valueOf(br.readLine());
		if (!(nEntry > 0)){
			throw new RuntimeException("Unexpected input value.");
		}
		while ((line = br.readLine()) != null){
			lineList = new ArrayList<String>();
			StringTokenizer st = new StringTokenizer(line, "\r\n\t\f ");
			while(st.hasMoreTokens()) {
				String word = st.nextToken();
				lineList.add(word);
		
			}
			inputList.add(lineList);
		}
	}
		
		
	
		
}
		


