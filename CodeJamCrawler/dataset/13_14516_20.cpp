import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TaskA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			File file = new File("A-small-attempt0.in");
			Scanner scanner = new Scanner(file);
			String[] input = null;
			int n = scanner.nextInt();
			for (int i = 0; i < n; i++) {
				input = new String[4];
				for (int j = 0; j < 4; j++) {
					input[j] = scanner.next();
				}
				check(i + 1, input);
			}
			scanner.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void check(int num, String[] input) {
		String answer = "", line;
		int not_completed = 0, x, o, dot, dx = 0, idx = 0, d = 0, id = 0;
		for (int i = 0; i < 4; i++) {
			line = input[i];
			if (line.indexOf('.') > -1) {
				not_completed++;
			}
			if (line.indexOf('O') > -1 && line.indexOf('.') == -1
					&& line.indexOf('X') == -1) {
				answer = "O won";
			}
			if (line.indexOf('X') > -1 && line.indexOf('.') == -1
					&& line.indexOf('O') == -1) {
				answer = "X won";
			}
			x = 0;
			o = 0;
			dot = 0;
			for (int j = 0; j < 4; j++) {
				if (input[j].charAt(i) == 'O')
					o++;
				if (input[j].charAt(i) == 'X')
					x++;
				if (input[j].charAt(i) == '.') {
					dot++;
					break;
				}
			}
			if (dot == 0 && x != 0 && o == 0)
				answer = "X won";
			if (dot == 0 && x == 0 && o != 0)
				answer = "O won";
			switch (input[i].charAt(i)) {
			case 'X':
				dx++;
				break;
			case 'O':
				d++;
				break;
			case '.':
				dx = 0;
				d = 0;
			}
			switch (input[3 - i].charAt(i)) {
			case 'X':
				idx++;
				break;
			case 'O':
				id++;
				break;
			case '.':
				idx = 0;
				id = 0;
			}

			if (!answer.isEmpty())
				break;
		}
		if (answer.isEmpty()) {
			if (id >= 3 || idx >= 3) {
				if (id > 0 && idx == 0)
					answer = "O won";
				else if (id == 0 && idx > 0)
					answer = "X won";
			} else if (d >= 3 || dx >= 3) {
				if (d > 0 && dx == 0)
					answer = "O won";
				else if (d == 0 && dx > 0)
					answer = "X won";
			}
		}
			if (not_completed == 0&&answer.isEmpty())
				answer = "Draw";
			if (answer.isEmpty())
				answer = "Game has not completed";

		System.out.println("Case #" + num + ": " + answer);
	}
}
