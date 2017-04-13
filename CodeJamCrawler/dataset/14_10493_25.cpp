
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class GoogleCodeJam_MagicTrick {

	private static final BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
	private static final PrintWriter printWriter = new PrintWriter(System.out);
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int testCount = Integer.parseInt(bufferedReader.readLine());
		
		for(int currentCase = 1; currentCase <= testCount; currentCase++) {
			int q1Answer = Integer.parseInt(bufferedReader.readLine());
			int[][] arrangement1 = new int[4][4];
			String[] input;
			for(int i = 0; i < 4; i++) {
				input = bufferedReader.readLine().split(" ");
				for(int j = 0; j < 4; j++) {
					arrangement1[i][j] = Integer.parseInt(input[j]);
				}
			}
			int q2Answer = Integer.parseInt(bufferedReader.readLine());
			int[][] arrangement2 = new int[4][4];
			for(int i = 0; i < 4; i++) {
				input = bufferedReader.readLine().split(" ");
				for(int j = 0; j < 4; j++) {
					arrangement2[i][j] = Integer.parseInt(input[j]);
				}
			}
			
			printWriter.print("Case #" + currentCase + ": ");
			int outcome = checkMagicTrick(q1Answer, arrangement1, q2Answer, arrangement2);
			if(outcome >= 0) {
				printWriter.println(outcome);
			} else if(outcome == -1) {
				printWriter.println("Bad magician!");
			} else {
				printWriter.println("Volunteer cheated!");
			}
		}
		printWriter.flush();
	}

	private static int checkMagicTrick(int q1Answer, int[][] arrangement1, int q2Answer, int[][] arrangement2) {
		int magicNumber = 0, integrityNumber = 0;
		
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				//System.out.println(q1Answer + " "  + i + " " + q2Answer + " " + j);
				if(arrangement1[q1Answer - 1][i] == arrangement2[q2Answer - 1][j]) {
					//System.out.println(q1Answer + " "  + i + " " + q2Answer + " " + j);
					integrityNumber++;
					magicNumber = arrangement1[q1Answer - 1][i];
				}
			}
		}
		
		if(integrityNumber == 1) {
			return magicNumber;
		} else if(integrityNumber == 0) {
			return -2;
		} else {
			return -1;
		}
	}
}
