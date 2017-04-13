import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class QA {
	static int count;
	static int countBlue;
	static int countOrange;
	static int[] blueGoals = new int[100];
	static int[] orangeGoals = new int[100];
	static int[] goals = new int[100];
	static int nextGoal;
	static int nextBlueGoal;
	static int nextOrangeGoal;
	static int positionBlue;
	static int positionOrange;
	static int steps;
	static final int BLUE = 0;
	static final int ORANGE = 1;

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t = Integer.parseInt(r.readLine());
		String s;
		for (int i = 0; i < t; i++) {
			s = r.readLine();
			pw.println("Case #" + (i + 1) + ": " + solve(s));
		}
		pw.flush();
	}

	private static int solve(String s) {
		StringTokenizer st = new StringTokenizer(s, " ");
		int n = Integer.parseInt(st.nextToken());
		count = 0;
		countBlue = 0;
		countOrange = 0;
		String s1;
		int p;
		for (int i = 0; i < n; i++) {
			s1 = st.nextToken();
			p = Integer.parseInt(st.nextToken());
			if (s1.charAt(0) == 'B') {
				blueGoals[countBlue] = p;
				goals[count] = BLUE;
				countBlue++;
			} else {
				orangeGoals[countOrange] = p;
				goals[count] = ORANGE;
				countOrange++;
			}
			count++;
		}
		return calculate();
	}

	private static int calculate() {
		nextGoal = 0;
		positionBlue = 1;
		positionOrange = 1;
		nextBlueGoal = 0;
		nextOrangeGoal = 0;
		steps = 0;
		while (nextGoal < count) {
			simulate();
			steps++;
		}
		return steps;
	}

	private static void simulate() {
		if (goals[nextGoal] == BLUE) {
			moveOrange();
			if (blueGoals[nextBlueGoal] == positionBlue) {
				// next blue goal
				if (nextBlueGoal < countBlue - 1) {
					nextBlueGoal++;
				}
				// push button
				nextGoal++;
			} else {
				moveBlue();
			}
		} else {
			moveBlue();
			if (orangeGoals[nextOrangeGoal] == positionOrange) {
				// next orange goal
				if (nextOrangeGoal < countOrange - 1) {
					nextOrangeGoal++;
				}
				// push button
				nextGoal++;
			} else {
				moveOrange();
			}
		}
	}

	private static void moveBlue() {
		if (nextBlueGoal < countBlue) {
			if (blueGoals[nextBlueGoal] != positionBlue) {
				positionBlue = (blueGoals[nextBlueGoal]) < positionBlue ? positionBlue - 1
						: positionBlue + 1;
			}
		}
	}

	private static void moveOrange() {
		if (nextOrangeGoal < countOrange) {
			if (orangeGoals[nextOrangeGoal] != positionOrange) {
				positionOrange = (orangeGoals[nextOrangeGoal]) < positionOrange ? positionOrange - 1
						: positionOrange + 1;
			}
		}
	}
}
