import java.util.Scanner;
import java.util.TreeSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Alien {

	private static TreeSet<String> dict;
	private static int count;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int length = scn.nextInt();
		int dictLength = scn.nextInt();
		int wordsLength = scn.nextInt();
		
		dict = new TreeSet<String>();
		scn.nextLine();
		
		for( int i = 0; i < dictLength; i++ ) {
			dict.add(scn.nextLine().trim());
		}
		
		for( int w = 0; w < wordsLength; w++ ) {
			String word = scn.nextLine().trim().replaceAll("\\(", "[").replaceAll("\\)", "]");
			Pattern p = Pattern.compile(word);
			count = 0;
			for( String s : dict ) {
				Matcher m = p.matcher(s);
				while(m.find()) {
					count++;
				}
			}
			StringBuilder builder = new StringBuilder();
			builder.append("Case #");
			builder.append(w+1);
			builder.append(": ");
			builder.append(count);
			System.out.println(builder.toString());
			
		}
	}

}
