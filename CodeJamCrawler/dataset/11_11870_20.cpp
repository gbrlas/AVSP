import java.util.*;
import java.io.*;

public class BotTrust {

    public static int solve(ArrayList<Pos> positions) {
	Pos orangeHall = new Pos('O', 1, 0);
	Pos blueHall = new Pos('B', 1, 0);

	Bot orangeBot = new Bot(orangeHall);
	Bot blueBot = new Bot(blueHall);

	int steps = 0;

	boolean noOrangePos = true;
	boolean noBluePos = true;

	boolean orangeJustPressed = false;

	for (Pos p : positions) {
	    if (p.getColour() == 'O') {
		orangeBot.setNext(p);
		noOrangePos = false;
		break;
	    }
	}

	for (Pos p : positions) {
	    if (p.getColour() == 'B') {
		blueBot.setNext(p);
		noBluePos = false;
		break;
	    }
	}

	while(true) {
	    if (!noOrangePos) {
		if (orangeBot.getPos().getPos() < orangeBot.getNext().getPos()) {
		    //System.out.println("Orange FORWARD");
		    orangeBot.forward();
		} else if (orangeBot.getPos().getPos() > orangeBot.getNext().getPos()) {
		    //System.out.println("Orange BACKWARD");
		    orangeBot.backward();
		} else {
		    // at target, check if waiting for blue bot
		    if (noBluePos || (orangeBot.getNext()).compareTo(blueBot.getNext()) < 0) {
			// orange bot can press now
			//System.out.println("Orange PRESS");
			orangeJustPressed = true;
			noOrangePos = true;
			for (Pos p : positions) {
			    if (p.compareTo(orangeBot.getNext()) > 0 && p.getColour() == 'O') {
				orangeBot.setNext(p);
				noOrangePos = false;
				//System.out.println("Orange next: " + p);
				break;
			    }
			}
		    } else {
			// otherwise do nothing
			//System.out.println("Orange STUCK");
		    }
		}
	    }
	    if (!noBluePos) {
		if (blueBot.getPos().getPos() < blueBot.getNext().getPos()) {
		    //System.out.println("           Blue FORWARD");
		    blueBot.forward();
		} else if (blueBot.getPos().getPos() > blueBot.getNext().getPos()) {
		    //System.out.println("           Blue BACKWARD");
		    blueBot.backward();
		} else {
		    // at target, check if waiting for orange bot
		    if ((noOrangePos || (blueBot.getNext()).compareTo(orangeBot.getNext()) < 0) && !orangeJustPressed ) {
			// blue bot can press now
			//System.out.println("           Blue PRESS");
			noBluePos = true;
			for (Pos p : positions) {
			    if (p.compareTo(blueBot.getNext()) > 0 && p.getColour() == 'B') {
				blueBot.setNext(p);
				noBluePos = false;
				//System.out.println("Blue next: " + p);
				break;
			    }
			}
		    } else {
			// otherwise do nothing
			//System.out.println("           Blue STUCK");
		    }
		}
		orangeJustPressed = false;
	    }
	    steps++;
	    //System.out.println("At step " + steps + ", Blue Bot is at pos " + blueBot.getPos().getPos());
	    if (noBluePos && noOrangePos) {
		return steps;
	    }	    
	}
    }

    public static void main(String args[]) throws Exception {

	Scanner fileReader = new Scanner(new File("A-small-attempt0.in"));

	int totalCases = fileReader.nextInt();
	//System.out.println("Total: " + totalCases);

	fileReader.nextLine();

	for (int caseNum = 1; caseNum <= totalCases; caseNum++) {

	    int totalButtons = fileReader.nextInt();

	    String line = fileReader.nextLine();
	    //System.out.println("Line: " + line);

	    Scanner lineReader = new Scanner(line);

	    ArrayList<Pos> positions = new ArrayList<Pos>();

	    for (int i = 1; i <= totalButtons; i++) {
		positions.add(new Pos((lineReader.next()).charAt(0), lineReader.nextInt(), i));
	    }

	    System.out.println("Case #" + caseNum + ": " + solve(positions));

	}

    }

}
