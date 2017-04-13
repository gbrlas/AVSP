import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.math.*;

public class ProblemA {
	void doMain() throws Exception {
		Scanner sc = new Scanner(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int L = sc.nextInt();
		int D = sc.nextInt();
		int N = sc.nextInt();
		
		HashSet<String> dict = new HashSet<String>(D);
		
		for(int i=0;i<D;i++){
			dict.add(sc.next());
		}
		
		String currString = "";
		Pattern pat;
		Iterator<String> iter;
		String dictWord="";
		int cnt = 0;
		Matcher m;
		for (int caseNum=1; caseNum <= N; caseNum++) {
			pw.print("Case #" + caseNum + ": ");
			currString = sc.next();
			currString = currString.replaceAll("\\)", "]");
			currString = currString.replaceAll("\\(","[");
			
			pat = Pattern.compile(currString);
			
			iter = dict.iterator();
			cnt = 0;
			while(iter.hasNext()){
				dictWord = iter.next();
				m = pat.matcher(dictWord);
				if(m.matches()&& dictWord.length() == L)
					cnt++;
			}
			
			pw.println(cnt);
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new ProblemA()).doMain();
	}
}
