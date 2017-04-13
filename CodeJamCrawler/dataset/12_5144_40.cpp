package gcj2012.qualificationround;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class SpeakingInTongues {

	private static Map<Character, Character> googlereseToEnglish = new TreeMap<Character, Character>();
	
	public static void main(String[] args) throws Exception {
		build("a zoo", "y qee");
		build("our language is impossible to understand", "ejp mysljylc kd kxveddknmc re jsicpdrysi");
		build("there are twenty six factorial possibilities", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		build("so it is okay if you want to just give up", "de kr kd eoya kw aej tysr re ujdr lkgc jv");
		
		saveMapping('q', 'z');
		saveMapping(' ', ' ');
		
		solve(System.in, System.out);
	}
	
	private static void build(String english, String googlerese) {
		for (int i=0; i<english.length(); i++) {
			char englishChar = english.charAt(i);
			char googlereseChar = googlerese.charAt(i);
			if (englishChar != ' ') {
				saveMapping(englishChar, googlereseChar);
			}
		}
	}
	
	private static void saveMapping(char englishChar, char googlereseChar) {
		googlereseToEnglish.put(googlereseChar, englishChar);
	}
	
	private static void solve(InputStream in, PrintStream out) throws IOException {
		Scanner scanner = new Scanner(in);
		int T = scanner.nextInt();
		scanner.nextLine();
		for (int i=1; i<=T; i++) {
			String googlerese = scanner.nextLine();
			String english = translate(googlerese);
			out.printf("Case #%d: %s%n", i, english);
		}
		scanner.close();
	}
	
	private static String translate(String googlerese) {
		StringBuffer english =  new StringBuffer();
		for (char googlereseChar : googlerese.toCharArray()) {
			english.append(googlereseToEnglish.get(googlereseChar));
		}
		return english.toString();
	}
	
}
