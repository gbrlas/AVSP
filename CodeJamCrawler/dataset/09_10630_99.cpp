import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class A {
	public static void main(String[] args) throws FileNotFoundException {
		FileInputStream file = new FileInputStream("input.txt");
		Scanner input = new Scanner(file);
		int l = input.nextInt(), d = input.nextInt(), n = input.nextInt();
		String dict[] = new String[d];
		for (int i = 0; i < d; ++ i) {
			dict[i] = input.next();
		}
		for (int i = 0; i < n; ++ i) {
			int answer = 0;
			StringBuilder regex = new StringBuilder(input.next());
			for (int j = 0, sz = regex.length(); j < sz; ++ j) {
				if (regex.charAt(j) == '(') {
					regex.setCharAt(j, '[');
				} else if (regex.charAt(j) == ')') {
					regex.setCharAt(j, ']');
				}
			}
			Pattern pat = Pattern.compile(regex.toString());
			for (int j = 0; j < d; ++ j) {
				Matcher matcher = pat.matcher(dict[j]);
				if (matcher.matches()) {
					answer ++;
				}
			}
			System.out.printf("Case #%d: %d\n", i + 1, answer);
		}
	}
}
