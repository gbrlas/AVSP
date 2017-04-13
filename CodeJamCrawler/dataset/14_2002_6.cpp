import java.util.Scanner;
public class MagicTrick {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int numProbs = input.nextInt();
		for (int i = 1; i <= numProbs; i++) {
			int first = input.nextInt();
			int[][] firstCards = new int[4][4];
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					firstCards[j][k] = input.nextInt();
				}
			}
			int second = input.nextInt();
			int[][] secondCards = new int[4][4];
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					secondCards[j][k] = input.nextInt();
				}
			}
			int possibleAnswers = 0;
			int currentAnswer = 0;
			for (int j = 0; j < 4; j++) {
				int currentFirst = firstCards[first - 1][j];
				for (int k = 0; k < 4; k++) {
					int currentSecond = secondCards[second - 1][k];
						if (currentSecond == currentFirst) {
						currentAnswer = currentSecond;
						possibleAnswers ++;
					}
				}
			}
			System.out.print("Case #" + i  + ": ");
			if (possibleAnswers == 1) {
				System.out.println(currentAnswer);
			} else if (possibleAnswers > 1) {
				System.out.println("Bad magician!");
			} else if (possibleAnswers == 0) {
				System.out.println("Volunteer cheated!");
			}
		}
		input.close();
	}
}