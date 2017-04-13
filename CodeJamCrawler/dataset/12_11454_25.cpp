
import java.io.*;
import java.util.*;

public class Googlerese {
	
	Map<Character,Character> mapping=new HashMap<Character,Character>();

	int nCases;
	StringBuffer teststring=new StringBuffer();
	
	String converted;
	ArrayList<Character> ab=new ArrayList<Character>();
	String output="";
	
	public void converter() {
		
		try{
		
		FileReader in = new FileReader("E:/A-small-attempt0.in");
		BufferedReader buff = new BufferedReader(in);
        mapping.put('y','a');
        mapping.put('n','b');
        mapping.put('f','c');
        mapping.put('i','d');
        mapping.put('c','e');
        mapping.put('w','f');
        mapping.put('l','g');
        mapping.put('b','h');
        mapping.put('k','i');
        mapping.put('u','j');
        mapping.put('o','k');
        mapping.put('m','l');
        mapping.put('x','m');
        mapping.put('s','n');
        mapping.put('e','o');
        mapping.put('v','p');
        mapping.put('z','q');
        mapping.put('p','r');
        mapping.put('d','s');
        mapping.put('r','t');
        mapping.put('j','u');
        mapping.put('g','v');
        mapping.put('t','w');
		mapping.put('h','x');
	    mapping.put('a','y');
	    mapping.put('q','z');	
	    mapping.put(' ',' ');	
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"E:/A-small-attempt0.out")));
		
			 nCases= Integer.parseInt(buff.readLine());
			 System.out.println(nCases);
			 for (int i = 0; i < nCases; i++) {
			 converted=buff.readLine();
		
		
		    for(int k=0;k<converted.length();k++){
		    	
		    	ab.add(k,converted.charAt(k));
		    }
		    
		
			
		
			for(int j=0;j<converted.length();j++){
	
	
		
			ab.set(j,mapping.get(ab.get(j)));

			}
			
			     for(Character s:ab){
			     	output += Character.toString(s);
			     }
				out.println("Case #" + (i + 1) + ": "
					+ output);
					output="";
			ab.clear();

	}
	
		in.close();
		out.close();
		}
		catch(Exception e){
			System.out.println(e);
		}
		
	
	}
	
	public static void main(String arg[]){
		
		Googlerese ob=new Googlerese();
		ob.converter();
		
	}
}