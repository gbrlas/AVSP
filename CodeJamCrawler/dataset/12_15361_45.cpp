import java.io.FileReader;
import java.io.FileWriter;
import java.io.LineNumberReader;
import java.io.PrintStream;
import java.util.Map;
import java.util.TreeMap;


public class Googlerese {
	
	private Map<Character, Character> langMap = new TreeMap<Character, Character>();
	
	public Googlerese() {
		for(char i='a'; i<='z'; i++) {
			langMap.put(i, '-');
		}
		langMap.put('y', 'a');
		langMap.put('e', 'o');
		langMap.put('q', 'z');
		langMap.put('z', 'q');
		
	}
	
	public void addCase2Language(String input, String output) {
		for(int i=0; i<input.length(); i++) {
			if(langMap.containsKey(input.charAt(i))) {
				if(!langMap.get(input.charAt(i)).equals(output.charAt(i)) && !langMap.get(input.charAt(i)).equals('-'))
					System.out.println("Discrepance: "+input.charAt(i)+","+output.charAt(i));
				else
					langMap.put(input.charAt(i), output.charAt(i));
			}
		}
	}
	
	public void findMisses() {
		for(char i='a'; i<='z'; i++) {
			if(!langMap.containsValue(new Character(i)))
				System.out.println(i+" is missing");
		}
	}
	
	public void init(String input, String output) throws Exception {
		LineNumberReader in = new LineNumberReader(new FileReader(input));
		LineNumberReader out = new LineNumberReader(new FileReader(output));
		String line = null;
		line = in.readLine();
		if(line==null||line.length()==0)
			return;
		int T = 0;
		T = Integer.parseInt(line);
		for(int i=1; i<=T; i++){
			String inputS = in.readLine();
			String outputS = out.readLine();
			addCase2Language(inputS,outputS);
		}
		in.close();
		out.close();
		langMap.put(' ', ' ');
		System.out.println(langMap);
	}
	
	public String translate(String s) {
		StringBuffer out = new StringBuffer();
		for(int i=0; i<s.length(); i++) {
			out.append(langMap.get(s.charAt(i)));
		}
		return out.toString();
	}
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		Googlerese trad = new Googlerese();
		trad.init(args[1],args[2]);
		trad.findMisses();
		LineNumberReader in = new LineNumberReader(new FileReader("A-small-attempt2.in"));
		String line = null;
		line = in.readLine();
		if(line==null||line.length()==0)
			return;
		int T = 0;
		T = Integer.parseInt(line);
		PrintStream out = new PrintStream("A-small-attempt2.out");
		for(int i=1; i<=T; i++){
			line = in.readLine();
			StringBuffer buf = new StringBuffer();
			buf.append("Case #");
			buf.append(i);
			buf.append(": ");
			buf.append(trad.translate(line));
			out.println(buf.toString());
			System.out.println(buf.toString());
		}
		in.close();
		out.close();

	}

}
