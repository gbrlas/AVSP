package com.baskok.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Watersheds {

	private static final char START_CHAR = 'a';
	int[][] heights = new int[100][100];
	char[][] labelledMap = new char[100][100];
	char nextLabel = START_CHAR;
	private int width;
	private int height;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("src/com/baskok/codejam/B-large.in"));
		int numberOfMaps = in.nextInt();
		for (int i=1; i<= numberOfMaps; i++) {
			Watersheds problem = new Watersheds();
			System.out.println("Case #" + i + ":");
			System.out.print(problem.solve(in));
		}
	}
	
	String solve(Scanner in) {
		height = in.nextInt();
		width = in.nextInt();
		// read the map
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				heights[x][y] = in.nextInt();
			}
		}
		// traverse all nodes until a sink or a 'colored node'
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				dumpBucketOfWater(x, y);
			}
		}
		
		// output
		String result = "";
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				result += labelledMap[x][y];
				if (x != width-1) {
					result += " ";
				} else {
					result += "\n";
				}
			}
		}
		
		return result;
	}

	private char dumpBucketOfWater(int x, int y) {

		// check if this cell already has its label set
		if (labelledMap[x][y] >= START_CHAR) {
			return labelledMap[x][y];
		}
		
		// determine where to flow to
		boolean isSink = true;
		int currentLowest = heights[x][y];
		int xOfLowest = -1;
		int yOfLowest = -1;

		// north
		if (y>0 && heights[x][y-1] < currentLowest) {
			isSink = false;
			xOfLowest = x;
			yOfLowest = y-1;
			currentLowest = heights[x][y-1];
		}
		
		// west
		if (x>0 && heights[x-1][y] < currentLowest) {
			isSink = false;
			xOfLowest = x-1;
			yOfLowest = y;
			currentLowest = heights[x-1][y];
		}
		
		// east
		if (x<width-1 && heights[x+1][y] < currentLowest) {
			isSink = false;
			xOfLowest = x+1;
			yOfLowest = y;
			currentLowest = heights[x+1][y];
		}
		
		// south
		if (y<height-1 && heights[x][y+1] < currentLowest) {
			isSink = false;
			xOfLowest = x;
			yOfLowest = y+1;
			currentLowest = heights[x][y+1];
		}

		if (isSink) {
			labelledMap[x][y] = nextLabel;
			// make sure next sink uses the next label
			nextLabel++;
		} else {
			// continue search
			labelledMap[x][y] = dumpBucketOfWater(xOfLowest, yOfLowest);
		}
		return labelledMap[x][y];
	}
	
}
