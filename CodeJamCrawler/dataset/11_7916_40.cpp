import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class BotTrust {

	public static void main(String[] args) {
		int cases;
		Scanner sc = new Scanner(System.in);
		cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			Queue<String> next = new LinkedList<String>();
			Queue<Integer> orangeNext = new LinkedList<Integer>();
			Queue<Integer> blueNext = new LinkedList<Integer>();
			String nextColour;
			int nextButton;
			int combinations = sc.nextInt();
			// Read in instructions
			for (int j = 0; j < combinations; j++) {
				nextColour = sc.next("O|B");
				nextButton = sc.nextInt();
				next.add(nextColour);
				if (nextColour.equals("O")) {
					orangeNext.add(nextButton);
				} else {
					blueNext.add(nextButton);
				}
			}
			// run simulation
			int time = 0, moveTime, orangePosition = 1, bluePosition = 1;
			while (!next.isEmpty()) {
				nextColour = next.poll();
				if (nextColour.equals("O")) {
					nextButton = orangeNext.poll();
					// +1 for pressing button
					moveTime = Math.abs(nextButton - orangePosition) + 1;
					orangePosition = nextButton;
					//System.out.println("Move orange " + (moveTime - 1) + " to " + nextButton);
					// Move blue piece while orange is moving
					if (!blueNext.isEmpty()) {
						if (Math.abs(bluePosition - blueNext.peek()) <= moveTime) {
							//System.out.println("\tAnd blue goes to " + blueNext.peek());
							bluePosition = blueNext.peek();
						} else {
							//System.out.println("\tAnd blue goes " + moveTime + " towards " + blueNext.peek());
							bluePosition = blueNext.peek() - Math.abs(bluePosition - blueNext.peek()) + moveTime;
						}
					}
				} else {
					nextButton = blueNext.poll();
					// +1 for pressing button;
					moveTime = Math.abs(nextButton - bluePosition) + 1;
					bluePosition = nextButton;
					//System.out.println("Move blue " + (moveTime - 1) + " to " + nextButton);
					// Move orange piece while blue is moving
					if (!orangeNext.isEmpty()) {
						if (Math.abs(orangePosition - orangeNext.peek()) <= moveTime) {
							//System.out.println("\tAnd orange goes to " + orangeNext.peek());
							orangePosition = orangeNext.peek();
						} else {
							//System.out.println("\tAnd orange goes " + moveTime + " towards " + orangeNext.peek());
							orangePosition = orangeNext.peek() - Math.abs(orangePosition - orangeNext.peek()) + moveTime;
						}
					}
				}
				time += moveTime;
			}
			System.out.println("Case #" + i + ": " + time);
		}
	}
}
