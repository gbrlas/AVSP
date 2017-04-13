import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Point {
	private int i;
	private int j;

	public Point(int i, int j) {
		super();
		this.i = i;
		this.j = j;
	}

	public int getI() {
		return i;
	}

	public void setI(int i) {
		this.i = i;
	}

	public int getJ() {
		return j;
	}

	public void setJ(int j) {
		this.j = j;
	}
	
	public String toString() {
		return new String(i + " " + j);
	}

}

public class WaterSheds {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		System.out.println(Arrays.toString(args));
		String inputFileName = args[0];
		String outputFileName = args[1];

		Scanner scanner = new Scanner(new File(inputFileName));

		FileWriter fileWriter = new FileWriter(new File(outputFileName));
		BufferedWriter bufferedWriter = new BufferedWriter(fileWriter);
		PrintWriter printWriter = new PrintWriter(bufferedWriter);

		int nMaps = scanner.nextInt();
		//System.out.println("nMaps= " + nMaps);

		for (int k = 0; k < nMaps; k++) {
			int height = scanner.nextInt();
			int width = scanner.nextInt();
			//System.out.println("Map #" + k + " " + height + " " + width);

			int[][] map = new int[height][width];
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					map[i][j] = scanner.nextInt();
				}
				//System.out.println(Arrays.toString(map[i]));
			}
			char[][] basinMarks = fillMarkMap(map, width, height);
			
			//System.out.println("Case #" + (k+1) + ":");
			printWriter.println("Case #" + (k+1) + ":");
			
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					//System.out.print(basinMarks[i][j] + " ");
					printWriter.print(basinMarks[i][j] + " ");
				}
				//System.out.println();
				printWriter.println();
			}
		}
		
		printWriter.close();

	}

	private static char[][] fillMarkMap(int[][] map, int width, int height) {
		char[][] basinMarks = new char[height][width];
		List<Point> path = new ArrayList<Point>();
		Point actual = null;
		Point next = null;
		char markPointer = 'a' - 1;
		char mark = 0;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				actual = new Point(i, j);
				//System.out.println("Actual: " + actual);
				if (basinMarks[i][j] == 0) {
					//System.out.println("unmarked");
					path.add(actual);
					next = getNextDrainagePoint(actual, map, width, height);
					while (next != null && basinMarks[next.getI()][next.getJ()] == 0) {
						//System.out.println("Next: " + next);
						path.add(next);
						next = getNextDrainagePoint(next, map, width, height);
					}
					if (next == null) {
						mark = ++markPointer;
					} else {
						mark = basinMarks[next.getI()][next.getJ()];
					}
					
					//System.out.println("mark:" + mark);

					for (Point point : path) {
						basinMarks[point.getI()][point.getJ()] = mark;
					}
					
					path.clear();
				}
			}
		}

		return basinMarks;
	}

	private static Point getNextDrainagePoint(Point actual, int[][] map, int width, int height) {
		Point next = null;
		int ai = actual.getI();
		int aj = actual.getJ();
		int lowestAlt = map[ai][aj];

		// North
		if (ai > 0 && map[ai - 1][aj] < lowestAlt) {
			next = new Point(ai - 1, aj);
			lowestAlt = map[ai - 1][aj];
		}
		// West
		if (aj > 0 && map[ai][aj - 1] < lowestAlt) {
			next = new Point(ai, aj - 1);
			lowestAlt = map[ai][aj - 1];
		}
		// East
		if (aj < width-1 && map[ai][aj + 1] < lowestAlt) {
			next = new Point(ai, aj + 1);
			lowestAlt = map[ai][aj + 1];
		}
		// South
		if (ai < height-1 && map[ai + 1][aj] < lowestAlt) {
			next = new Point(ai + 1, aj);
			lowestAlt = map[ai + 1][aj];
		}

		return next;
	}

}
