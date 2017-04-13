package gcj2011.qualificationround;

import java.io.File;
import java.util.ArrayList;
import java.util.EnumMap;
import java.util.List;
import java.util.Scanner;

public class BotTrust {

	private static boolean DEBUG = false;
	
	enum Robot {
		BLUE,
		ORANGE
	}
	
	static class ButtonPress {
		public Robot robot;
		public int button;
		public boolean done = false;
		
		public ButtonPress(Robot robot, int button) {
			this.robot = robot;
			this.button = button;
		}
		
		@Override
		public String toString() {
			return String.format("%s %d", robot, button);
		}
	}
	
	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("data/gcj2011/qualificationround/A-small-attempt0.in"));
		int T = s.nextInt();
		for (int t=1; t<=T; t++) {
			
			List<ButtonPress> sequence = new ArrayList<ButtonPress>();
			
			int N = s.nextInt();
			for (int n=1; n<=N; n++) {
				String R = s.next();
				int P = s.nextInt();
				Robot robot = (R.equals("B")) ? Robot.BLUE : Robot.ORANGE;
				ButtonPress press = new ButtonPress(robot, P);
				sequence.add(press);
			}
			
			if (DEBUG) {
				System.out.println();
				System.out.println(sequence);
			}
			
			EnumMap<Robot, Integer> positions = new EnumMap<Robot, Integer>(Robot.class);
			positions.put(Robot.BLUE, 1);
			positions.put(Robot.ORANGE, 1);
			
			EnumMap<Robot, Integer> robotNextMove = new EnumMap<Robot, Integer>(Robot.class);
			robotNextMove.put(Robot.BLUE, -1);
			robotNextMove.put(Robot.ORANGE, -1);
			moveToNextButtonPress(Robot.BLUE, sequence, robotNextMove);
			moveToNextButtonPress(Robot.ORANGE, sequence, robotNextMove);
			
			int globalNextMove = 0;
			
			int overallElapsedTime = 0;
			
			while (globalNextMove < sequence.size()) {
				ButtonPress nextPress = sequence.get(globalNextMove);
				
				if (DEBUG) {
					System.out.printf("Elapsed=%d, globalNextMove=%d (%s), positions=%s, robotNextMove=%s%n", overallElapsedTime, globalNextMove, nextPress, positions, robotNextMove);
				}
				
				int elapsed = 0;
				
				// Deal first with the next required button press.
				// First part: move robot to required position
				if (nextPress.button != positions.get(nextPress.robot)) {
					int distance = Math.abs(nextPress.button - positions.get(nextPress.robot));
					positions.put(nextPress.robot, nextPress.button);
					if (DEBUG) {
						System.out.printf("  time %d-%d: %s moves %d step(s) to %d%n", overallElapsedTime+1, overallElapsedTime+distance, nextPress.robot, distance, nextPress.button);
					}
					elapsed += distance;
					overallElapsedTime += distance;
				}
				
				// Second part: make robot push the button
				if (nextPress.button == positions.get(nextPress.robot) && !nextPress.done) {
					nextPress.done = true;
					if (DEBUG) {
						System.out.printf("  time %d: %s presses button %d%n", overallElapsedTime+1, nextPress.robot, nextPress.button);
					}
					elapsed += 1;
					overallElapsedTime += 1;
					moveToNextButtonPress(nextPress.robot, sequence, robotNextMove);
					if (DEBUG) {
						if (robotNextMove.get(nextPress.robot) == sequence.size()) {
							System.out.printf("   - %s has finished%n", nextPress.robot);
						} else {
							System.out.printf("   - next press for %s will be #%d%n", nextPress.robot, robotNextMove.get(nextPress.robot));
						}
					}
					globalNextMove++;
				}
				
				// Could the other robot have moved during the elapsed time
				// (while the first robot was moving/pressing) ?
				Robot otherRobot = (nextPress.robot == Robot.BLUE) ? Robot.ORANGE : Robot.BLUE;
				if (robotNextMove.get(otherRobot) < sequence.size()) {
					if (DEBUG) {
						System.out.printf("  %s still has button(s) to press so could move for press #%d%n", otherRobot, robotNextMove.get(otherRobot));
					}
					ButtonPress otherPress = sequence.get(robotNextMove.get(otherRobot));
					int pos = positions.get(otherRobot);
					int distance = Math.abs(pos - otherPress.button);
					int moved = Math.min(distance, elapsed);
					if (DEBUG) {
						System.out.printf("  %s is at %d, needs to move towards %d%n", otherRobot, pos, otherPress.button);
					}
					if (pos < otherPress.button) {
						pos += moved;
					} else if (pos > otherPress.button) {
						pos -= moved;
					}
					positions.put(otherRobot, pos);
				}
			}
			System.out.printf("Case #%d: %d%n", t, overallElapsedTime);
		}
	}
	
	static void moveToNextButtonPress(Robot robot, List<ButtonPress> sequence, EnumMap<Robot, Integer> next) {
		int index = next.get(robot);
		index++;
		while (index < sequence.size() && sequence.get(index).robot != robot) {
			index++;
		}
		next.put(robot, index);
	}

}
