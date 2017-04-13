import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

import javax.swing.text.StyledEditorKit.ForegroundAction;


public class Main {

	public static void main(String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		Scanner in = new Scanner(new File("A-small-attempt0.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("small-A.txt"));
		int amountOfTasks = in.nextInt();
		for (int task = 0; task < amountOfTasks; task++) {
			System.out.println("Task: " + (task+1));
			int sizeAmrin = in.nextInt();
			int amountOfOthers = in.nextInt();
			int[] motes = new int[amountOfOthers];
			for (int i = 0; i < amountOfOthers; i++) {
				motes[i] = in.nextInt();
			}
			
			Arrays.sort(motes);
			
			int amountOfMoves = solve(motes, sizeAmrin, 0, amountOfOthers);
			
			out.write("Case #" + (task+1) + ": " + amountOfMoves);
			out.newLine();
		}
		in.close();
		out.close();
	} 
	
	private int solve(int[] motes, int size, int index, int maxIndex) {
		if (index == maxIndex) return 0;
		if (size == 1) return maxIndex;
		int moteSize = size;
		int amountOfMoves = 0;
		if (motes[index] < moteSize) {
			moteSize += motes[index];
			amountOfMoves += solve(motes, moteSize, index+1, maxIndex);
		} else {
			int amount1 = solve(motes, 2*moteSize - 1, index, maxIndex);
			int amount2 = solve(motes, moteSize, index + 1, maxIndex);
			amountOfMoves += (Math.min(amount1, amount2) + 1);
		}	
		return amountOfMoves;
	}
}
