import java.math.BigDecimal;
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

			List<BigDecimal[]> posNumList = new ArrayList<BigDecimal[]>();
			posNumList.add(new BigDecimal[] { new BigDecimal(-1),
					new BigDecimal(1) });
			for (int j = 0; j < 19; j++) {
				char c = jam.charAt(j);
				List<Integer> posList = position.get(c);
				List<BigDecimal[]> temp = new ArrayList<BigDecimal[]>();
				int posNumIndex = 0;
				BigDecimal tempTotal = new BigDecimal(0);
				for (int p : posList) {
					while (posNumIndex < posNumList.size()) {
						if (posNumList.get(posNumIndex)[0].intValue() < p)
							tempTotal = tempTotal.add(posNumList
									.get(posNumIndex++)[1]);
						else
							break;
					}
					temp.add(new BigDecimal[] { new BigDecimal(p), tempTotal });
				}
				posNumList = temp;
			}
			BigDecimal total = new BigDecimal(0);
			for (BigDecimal[] posNum : posNumList) {
				total = total.add(posNum[1]);
			}
			String totalString = total.toString() + "";
			if (totalString.length() >= 4)
				totalString=totalString.substring(totalString.length() - 4);
			else {
				while (totalString.length() < 4) {
					totalString = "0" + totalString;
				}
			}
			sb.append("Case #").append(i + 1).append(": ").append(totalString)
					.append("\n");
		}
		System.out.println(sb.toString());
	}

}
