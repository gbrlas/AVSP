package cs224n.gcj;

import java.io.IOException;
import java.util.Hashtable;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.FileInputStream;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.File;

public class ProbA {

		
	static Hashtable<String, String> charMap = new Hashtable<String, String>();
	
	static String mapGToN(String gs){
		
		String ns = "";
		
		int len = gs.length();
		for(int i = 0; i < len; i++){
			if(gs.charAt(i) == ' '){
				ns += " ";
				continue;
			}
			if( charMap.containsKey(gs.substring(i, i+1)) )
				ns += charMap.get(gs.substring(i, i+1));
			if( !charMap.containsKey(gs.substring(i, i+1)) )
				ns += "***"+gs.substring(i, i+1)+"***";
		}
		
		return ns;
	}
	
	public static void main(String[] args) throws IOException{
		
		File inFile = new File(args[0]);
		File outFile = new File(args[1]);
		
		if(!inFile.exists())
			System.out.println("File Does Not Exist!");
		
		
		String[] gs = new String[3];
		gs[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		gs[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		gs[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

		String[] ns = new String[3];
		ns[0] = "our language is impossible to understand";
		ns[1] = "there are twenty six factorial possibilities";
		ns[2] = "so it is okay if you want to just give up";
		
		for(int i = 0; i<3; i++){
			
			int len = gs[i].length();
			for(int j = 0; j < len; j++){
				if( gs[i].charAt(j) != ' ' ){
					charMap.put(gs[i].substring(j, j+1), ns[i].substring(j,j+1));					
				}				
			}				
		}

		//gs: q,z
		//ns: q,z
		charMap.put("q", "z");
		charMap.put("z", "q");
		
		System.out.println(charMap.toString());
		
		BufferedReader in = new BufferedReader( new InputStreamReader( new FileInputStream(inFile) ) );
		PrintWriter out = new PrintWriter( new FileWriter(args[1]), true );
		
		String line;
		line = in.readLine();
		int T = Integer.parseInt(line);
		for(int i = 1; i <= T; i++){
			line = in.readLine();
			//Case #1: 
			out.print("Case #"+i+": ");
			out.println( mapGToN(line) );
			
		}
		
		
		in.close();
		out.close();
		
	}
	
}
