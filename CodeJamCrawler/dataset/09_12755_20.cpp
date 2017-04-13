import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class AlienLanguage {
	public static void main(String[] args) {
		final String question = "A-small-attempt0";
		BufferedReader br = null;
		BufferedWriter bw = null;
		int n = 0;
		int d = 0;
		int l = 0;
		int i = 0;
		String tempStr = null;
		String[] tempStrArray = null;
		
		try {
			br = new BufferedReader(new InputStreamReader(new FileInputStream(question + ".in"), "utf-8"));
			bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(question + ".out"), "utf-8"));
			tempStrArray = br.readLine().split(" ");
			l= Integer.parseInt(tempStrArray[0]);
			d = Integer.parseInt(tempStrArray[1]);
			n = Integer.parseInt(tempStrArray[2]);
			
			ArrayList<String> wordsList = new ArrayList<String>();
			ArrayList<String> matchList = new ArrayList<String>();
			while (i<d) {
				tempStr = br.readLine();
				wordsList.add(tempStr);
				System.out.println("Words : " + tempStr);
				i++;
			}
			
			Pattern letterPattern = Pattern.compile("(\\([a-z]+\\)|[a-z])");
			Matcher letterMatcher = null;
			
			i = 0;
			while (i<n) {
				tempStr = br.readLine();
				System.out.println("test case : " + tempStr);
				matchList.clear();
				matchList.addAll(wordsList);
				letterMatcher = letterPattern.matcher(tempStr);
				
				int k =0;
				String letters = null;
				while (letterMatcher.find()) {
					letters = letterMatcher.group(1);
					System.out.println("letters:" + letters);
					
					if (k >= l) {
						System.out.println((i + 1) + " more then l: " + l + " so clear match");
						matchList.clear();
					}
						
					for (Iterator<String> iter = matchList.iterator(); iter.hasNext();) {
						String words = iter.next();
						System.out.println("words:" + words + " char: " + words.charAt(k) + " " + letters.indexOf(words.charAt(k)) + " k: " + k);
						if (letters.indexOf(words.charAt(k)) == -1)
							iter.remove();
					}
					k++;
				}
				
				bw.write("Case #" + (i + 1) + ": " + matchList.size());
				bw.newLine();
				i++;
			}
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
			} catch (IOException ioe) {
				//Do Nothing
			}
			try {
				if (bw != null)
					bw.close();
			} catch (IOException ioe) {
				//Do Nothing
			}
		}
	}
}
