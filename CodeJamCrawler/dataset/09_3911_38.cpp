import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Vector;


public class round1a {

	
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader file = new BufferedReader(new FileReader(new File("input.txt")));
		String line = "";
		int l = 0;
		int base = 0;
		
		char[] characters = new char[36];
		characters[0] = 49;
		characters[1] = 48;
		for(char i = 50; i < 59; ++i)
			characters[i - 48] = i;
		
		for(char i = 97; i < 123; ++i)
			characters[i - 87] = i;
		
		
		//for(int i = 0; i < 36; ++i)
		//	System.out.println(characters[i]);
		
		Vector<String> words = new Vector<String>();
		HashMap<Character, Character> map = new HashMap<Character, Character>();
		String number = "";
		
		line = file.readLine();
		l = Integer.valueOf(line);
		int caseno = 0;
		
		
		for(int i = 0; i < l; ++i) {
			words.add(file.readLine());
		}
		
		int count = 1;
		
		for(String s: words) {
			
			
			map.clear();
			number = "";
			
			caseno++;
		
			count = 0;
			for(Character c: s.toCharArray()) {
				
				if(!map.containsKey(c)) {
					map.put(c, characters[count]);
					count++;
				}
			}
			
			base = map.size();
			
			for(Character c: s.toCharArray()) {
				number += map.get(c);
			}
			if(base == 1) base = 2;
			System.out.println("Case #" + caseno + ": " +  Integer.parseInt(number, base));
			
		}
		
	}
}
