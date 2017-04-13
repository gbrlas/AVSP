import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Vector;
import java.util.regex.Matcher;
import java.util.regex.Pattern;



public class main {

	
	
	public static void main(String[] args) throws Exception {
		
		BufferedReader file = new BufferedReader(new FileReader(new File("A-large.in")));
		String line = "";
		int l, d, n, count = 0;
		Vector<String> words = new Vector<String>();
		
		line = file.readLine();
		String[] tmp = line.split(" ");
		l = Integer.valueOf(tmp[0]);
		d = Integer.valueOf(tmp[1]);
		n = Integer.valueOf(tmp[2]);
		
		for(int i = 0; i < d; ++i) {
			words.add(file.readLine());
		}
		
		String regex = "";
		
		for(int i = 0; i < n; ++i) {
			regex = file.readLine();
			regex = regex.replaceAll("\\(", "[");
			regex = regex.replaceAll("\\)", "]");
			Pattern p = Pattern.compile(regex);
			
			for(String word: words) {
				Matcher m = p.matcher(word);
				if(m.find())
					count++;
				
			}
			System.out.println("Case #" + (i+1) + ": " + count);
			count = 0;
		}
	}
}
