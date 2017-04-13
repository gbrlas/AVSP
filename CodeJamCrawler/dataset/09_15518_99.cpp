import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Alien {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int L = scanner.nextInt();
		int D = scanner.nextInt();
		int N = scanner.nextInt();

		List<String> words = new ArrayList<String>();
		List<String> patterns = new ArrayList<String>();
		char[][] wordCharArray = new char[D][L];

		for (int i = 0; i < D; i++) {
			String temp = scanner.next();
			words.add(temp);
			wordCharArray[i] = temp.toCharArray();

		}

		for (int i = 0; i < N; i++) {
			patterns.add(scanner.next());
		}

		int index = 1;
		StringBuffer sb = new StringBuffer();

		for (String pattern : patterns) {
			List<Integer> matched = new ArrayList<Integer>();
			for (int i = 0; i < D; i++) {
				matched.add(i);
			}
			int i = 0;
			while (pattern.length() > 0) {
				char[] chars;
				if (pattern.charAt(0) == '(') {
					int right = pattern.indexOf(')');
					chars = pattern.substring(1, right).toCharArray();
					pattern = pattern.substring(right + 1);
				} else {
					chars = new char[] { pattern.charAt(0) };
					pattern = pattern.substring(1);
				}
				List<Integer> tempL = new ArrayList<Integer>();
				for (int mi : matched) {
					boolean isMatch = false;
					for (char c : chars) {
						if (wordCharArray[mi][i] == c) {
							isMatch = true;
							continue;
						}
					}
					if (!isMatch) {
						tempL.add(mi);
					}
				}
				matched.removeAll(tempL);

				i++;
			}

			sb.append("Case #").append(index++).append(": ").append(
					matched.size()).append("\n");
		}
		System.out.println(sb.toString());
	}

}
