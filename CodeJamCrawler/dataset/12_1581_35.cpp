import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Tongues {
	
	String[] samples = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", 
			"de kr kd eoya kw aej tysr re ujdr lkgc jv",
			"qz"};
	
	String[] translations ={"our language is impossible to understand",
			"there are twenty six factorial possibilities",
			"so it is okay if you want to just give up",
			"zq"};
	
	HashMap<Character, Character> rosetta;
	
	public Tongues(){
		this.rosetta = new HashMap<Character, Character>();
		this.rosetta.put(' ', ' ');
		for(int i = 0; i < samples.length; i++){
			for(int j = 0; j < samples[i].length(); j++){
				if(!this.rosetta.containsKey(samples[i].charAt(j))){
					this.rosetta.put(samples[i].charAt(j), translations[i].charAt(j));
				}
			}
		}
	}//Tongues.Tongues()
	
	public String translate(String S){
		String translation = "";
		for(int i = 0; i < S.length(); i++){
			translation += this.rosetta.get(S.charAt(i));
		}
		return translation;		
	}//Tongues.translate()


	public static void main(String[] args) throws IOException{

		String inputFile = args[0];
		String outputFile = args[1];
		File file = new File(inputFile);
		BufferedReader reader = new BufferedReader(new FileReader(file));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile));
		
		int numCases = Integer.parseInt(reader.readLine());
		
		Tongues t = new Tongues();
		
		for (int i = 1; i <= numCases; i++){
			int caseNumber = i;
			String text = reader.readLine();
			
			writer.write("Case #" + caseNumber + ": " + t.translate(text));
			writer.newLine();
		}
		reader.close();
		writer.close();
	}//Tongues.main()
}//Tongues
