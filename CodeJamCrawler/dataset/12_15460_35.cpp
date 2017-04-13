import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.TreeMap;


public class Googlerese {
	
	
	static TreeMap<Character,Character> alfabeto = new TreeMap<Character,Character>();
	
	public static void main(String[] args) {
		
		alfabeto.put('a', 'y');
		alfabeto.put('b', 'h');
		alfabeto.put('c', 'e');
		alfabeto.put('d', 's');
		alfabeto.put('e', 'o');
		alfabeto.put('f', 'c');
		alfabeto.put('g', 'v');
		alfabeto.put('h', 'x');
		alfabeto.put('i', 'd');
		alfabeto.put('j', 'u');
		alfabeto.put('k', 'i');
		alfabeto.put('l', 'g');
		alfabeto.put('m', 'l');
		alfabeto.put('n', 'b');
		alfabeto.put('o', 'k');
		alfabeto.put('p', 'r');
		alfabeto.put('q', 'z');
		alfabeto.put('r', 't');
		alfabeto.put('s', 'n');
		alfabeto.put('t', 'w');
		alfabeto.put('u', 'j');
		alfabeto.put('v', 'p');
		alfabeto.put('x', 'm');
		alfabeto.put('y', 'a');
		alfabeto.put('w', 'f');
		alfabeto.put('z', 'q');
		
		String text = "";
		String result;
		char space = ' ';
		int j = 0;		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try{
			int k = Integer.parseInt(br.readLine());		
			while ((text = br.readLine()) != null && j < k){			
				result = "";
				j++;
				for(int i = 0; i < text.length(); i++){
					if(text.charAt(i) == space){
						result += " ";
					} else { result += alfabeto.get(text.charAt(i)); }				
				}			
			System.out.println("Case #" + j + ": " + result);
			}
		} catch (Exception e) {e.printStackTrace();}			
	}
}
