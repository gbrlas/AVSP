import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

import com.sun.accessibility.internal.resources.accessibility;

public class Watersheds {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int round = scanner.nextInt();
		StringBuffer sb = new StringBuffer();
		String al = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < round; i++) {
			int rows = scanner.nextInt();
			int columns = scanner.nextInt();
			int[][] input = new int[rows][columns];
			int[][] direction = new int[rows][columns];
			char[][] charoutput = new char[rows][columns];
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < columns; k++) {
					input[j][k] = scanner.nextInt();
				}
			}
			int number = 0;
			int group = 0;
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < columns; k++) {
					int dir = 0;
					int max = 1;
					int middle = 0, left = 0, right = 0, up = 0, down = 0;
					middle = input[j][k];
					if (j < rows - 1) {
						down = middle - input[j + 1][k];
						if (down >= max) {
							max = down;
							dir = 4;
						}
					}

					if (k < columns - 1) {
						right = middle - input[j][k + 1];
						if (right >=max) {
							max = right;
							dir = 3;
						}
					}

					if (k > 0) {
						left = middle - input[j][k - 1];
						if (left >=max) {
							max = left;
							dir = 2;
						}
					}

					if (j > 0) {
						up = middle - input[j - 1][k];
						if (up >=max) {
							max = up;
							dir = 1;
						}
					}
					direction[j][k] = dir;
				}
			}
			while (number != rows * columns) {
				char c = al.charAt(group++);
				int minR = -1, minC = -1, min = 100000;
				for (int j = 0; j < rows; j++) {
					for (int k = 0; k < columns; k++) {
						if (input[j][k] < min && charoutput[j][k] == 0) {
							minR = j;
							minC = k;
							min = input[j][k];
						}
					}
				}

				Stack<int[]> stack = new Stack<int[]>();
				stack.push(new int[] { minR, minC });
				while (stack.size() > 0) {
					int[] temp = stack.pop();
					if(charoutput[temp[0]][temp[1]]!=0)
						continue;
					charoutput[temp[0]][temp[1]] = c;
					number++;
					if (temp[0] < rows - 1
							&& direction[temp[0] + 1][temp[1]] == 1) {
						stack.push(new int[] { temp[0] + 1, temp[1] });
					}
					if (temp[0] > 0 && direction[temp[0] - 1][temp[1]] == 4) {
						stack.push(new int[] { temp[0] - 1, temp[1] });
					}

					if (temp[1] < columns - 1
							&& direction[temp[0]][temp[1] + 1] == 2) {
						stack.push(new int[] { temp[0], temp[1] + 1 });
					}

					if (temp[1] > 0 && direction[temp[0]][temp[1] - 1] == 3) {
						stack.push(new int[] { temp[0], temp[1] - 1 });
					}

				}

			}

			sb.append("Case #").append(i + 1).append(":\n");
			int chIndex = 0;
			Map<Character, Character> map = new HashMap<Character, Character>();
			for (int j = 0; j < rows; j++) {
				for (int k = 0; k < columns; k++) {
					if (!map.containsKey(charoutput[j][k]))
						map.put(charoutput[j][k], al.charAt(chIndex++));
					sb.append(map.get(charoutput[j][k])).append(" ");

				}
				sb.append("\n");
			}

		}
		System.out.println(sb.toString());

	}
}
