import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter writer = new PrintWriter(new File("output.txt"));

		int testCount = in.nextInt();
		int test = 0;
		while (test < testCount) {
			test++;

			ArrayList<String> comb = new ArrayList<String>();
			ArrayList<String> repl = new ArrayList<String>();

			int n = in.nextInt();
			for (int i = 0; i < n; i++) {
				String str = in.next();
				comb.add(str);
			}

			n = in.nextInt();
			for (int i = 0; i < n; i++) {
				String str = in.next();
				repl.add(str);
			}
			
			int len = in.nextInt();
			String moves = in.next();
			ArrayList<Character> result = new ArrayList<Character>();
			for (int i = 0; i < moves.length(); i++) {
				char currentChar = moves.charAt(i);
				boolean needadd = true;
				if (result.size() > 0) {
					char lastChar = result.get(result.size()-1);
					for (String str : comb) {
						if ((str.charAt(0) == lastChar && str.charAt(1) == currentChar)
								|| ((str.charAt(0) == currentChar && str.charAt(1) == lastChar))) {
							result.remove(result.size()-1);
							result.add(str.charAt(2));
							currentChar = str.charAt(2);
							needadd = false;
							break;
						}
					}
					for (String str : repl) {
						for (Character c : result)
						if ((str.charAt(0) == c && str.charAt(1) == currentChar)
								|| ((str.charAt(0) == currentChar && str.charAt(1) == c))) {
							result.clear();
							needadd = false;
							break;
						}
					}
				} 
				if (needadd) {
					result.add(currentChar);
				}
			}
			writer.print("Case #" + new Integer (test) + ": ["); 
			for (int i = 0; i < result.size() ; i++) {
				if (i != result.size()-1) writer.print(result.get(i) + ", ");
				else writer.print(result.get(i));
			}
							
			writer.println("]");
		}
		writer.close();
	}
}
