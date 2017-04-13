import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;


public class WelcomeToCodeJam {
	
	public static final String searchStr = "welcome to code jam";

	public static void main(String[] args) throws IOException {
		BufferedReader infile = new BufferedReader(new FileReader("codejam.in"));
		PrintStream outfile = new PrintStream("codejam.out");
		
		int N = Integer.parseInt(infile.readLine());
		
		for (int i=0; i<N; i++) {
			String str = infile.readLine();
			outfile.printf("Case #%d: %04d\n", i+1, search(str, -1, 0));
		}
		
		outfile.close();
	}
	
	public static int search(String str, int strIndex, int searchIndex) {
		int tot = 0;
		while ((strIndex = str.indexOf(searchStr.charAt(searchIndex), strIndex+1)) >= 0) {
			if (searchIndex+1 == searchStr.length()) tot++;
			else tot += search(str, strIndex, searchIndex+1);
		}
		return tot;
	}

}
