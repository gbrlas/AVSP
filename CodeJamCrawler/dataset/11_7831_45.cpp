import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class A {

	private static final int ORANGE = 0;
	private static final int BLUE = 1;
	private static Scanner in;

	/**
	 * @param args
	 * @throws IOException
	 * 
	 *             O = 79; B = 66;
	 */
	public static void main(String[] args) throws IOException {
		in = new Scanner(System.in);
		PrintWriter writer = new PrintWriter(new File("output.txt"));
		int testCount = getInt();
		int test = 0;
		while (testCount > 0) {
			test++;
			testCount--;
			int n = getInt();

			ArrayList<Integer> moves = new ArrayList<Integer>();
			ArrayList<Integer> orange = new ArrayList<Integer>();
			ArrayList<Integer> blue = new ArrayList<Integer>();

			for (int i = 0; i < n; i++) {
				int type = getInt();
				int cell = getInt();
				if (type == 0) { // O?
					moves.add(ORANGE);
					orange.add(cell);
				} else { // B - ?
					moves.add(BLUE);
					blue.add(cell);
				}
			}

			int time;
			int currentOrangePos = 1, currentBluePos = 1;
			for (time = 0;; time++) {
				boolean wasMade = false;
				if (moves.size() == 0)
					break;
				if (orange.size() > 0) {
					int x = orange.get(0);
					if (moves.get(0) == ORANGE && x == currentOrangePos) {
						moves.remove(0);
						orange.remove(0);
						wasMade = true;
					} else {
						if (currentOrangePos < x)
							currentOrangePos++;
						if (currentOrangePos > x)
							currentOrangePos--;
					}
				}
				if (blue.size() > 0) {
					int x = blue.get(0);
					if (moves.get(0) == BLUE && currentBluePos == x && !wasMade) {
						moves.remove(0);
						blue.remove(0);
					} else {
						if (currentBluePos < x)
							currentBluePos++;
						if (currentBluePos > x)
							currentBluePos--;
					}
				}
			}
			writer.println("Case #" + new Integer(test)+": " + time);
//			System.out.println(time);
		}
		writer.close();
	}

	private static int getInt() throws IOException {
		return in.nextInt();
	}

}
