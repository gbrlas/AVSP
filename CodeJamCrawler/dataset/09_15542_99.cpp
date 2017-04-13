import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Jam {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int round = scanner.nextInt();
		StringBuffer sb = new StringBuffer();
		String jam = "welcome to code jam";
		String anoter = "welcom tdja";
		int number = 12;
		scanner.nextLine();
		for (int i = 0; i < round; i++) {
			String input = scanner.nextLine();
			Map<Character, List<Integer>> position = new HashMap<Character, List<Integer>>();
			for (char c : anoter.toCharArray()) {
				position.put(c, new ArrayList<Integer>());
			}
			int index = 0;
			for (char c : input.toCharArray()) {
				switch (c) {
				case 'w':
					position.get('w').add(index++);
					break;
				case 'e':
					position.get('e').add(index++);
					break;
				case 'l':
					position.get('l').add(index++);
					break;
				case 'c':
					position.get('c').add(index++);
					break;
				case 'o':
					position.get('o').add(index++);
					break;
				case 'm':
					position.get('m').add(index++);
					break;
				case ' ':
					position.get(' ').add(index++);
					break;
				case 't':
					position.get('t').add(index++);
					break;
				case 'd':
					position.get('d').add(index++);
					break;
				case 'j':
					position.get('j').add(index++);
					break;
				case 'a':
					position.get('a').add(index++);
					break;
				}

			}

			List<int[]> posNumList = new ArrayList<int[]>();
			posNumList.add(new int[] { -1, 1 });
			for (int j = 0; j < 19; j++) {
				char c = jam.charAt(j);
				List<Integer> posList = position.get(c);
				List<int[]> temp = new ArrayList<int[]>();
				int posNumIndex = 0;
				int tempTotal = 0;
				for (int p : posList) {
					while (posNumIndex < posNumList.size()) {
						if (posNumList.get(posNumIndex)[0] < p)
							tempTotal += posNumList.get(posNumIndex++)[1];
						else
							break;
					}
					temp.add(new int[] { p, tempTotal });
				}
				posNumList = temp;
			}
			int total = 0;
			for (int[] posNum : posNumList) {
				total += posNum[1];
			}
			String totalString=total%10000+"";
			while(totalString.length()<4){
				totalString="0"+totalString;
			}
			sb.append("Case #").append(i + 1).append(": ").append(totalString).append("\n");
		}
		System.out.println(sb.toString());
	}

}
