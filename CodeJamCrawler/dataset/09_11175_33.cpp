import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Watersheds {
	static final Coordinate SINK = new Coordinate(-1, -1);
	static Scanner inputScanner;

	public static void main(String[] args) throws FileNotFoundException {
		File inputFile = new File(args[0]);
		inputScanner = new Scanner(inputFile);
		readMaps();
	}

	private static void readMaps() {
		int mapCount = getNextInt();
		for (int mapNumber = 1; mapNumber <= mapCount; mapNumber++) {
			char[][] basinMap = processMap();
			display(mapNumber, basinMap);
		}
	}

	private static char[][] processMap() {
		int[][] map = readMap();
		Coordinate[][] neighbourhood = calculateNeighbourhood(map);
		char[][] basinMap = calculateBasinMap(neighbourhood);
		return basinMap;
	}

	private static char[][] calculateBasinMap(Coordinate[][] neighbourhood) {
		int height = neighbourhood.length;
		int width = neighbourhood[0].length;
		char[][] basinMap = new char[height][];
		for (int row = 0; row < height; row++) {
			basinMap[row] = new char[width];
		}
		char currentBasinCode = 'a';
		basinMap[0][0] = currentBasinCode;
		do {
			locateCurrentBasin(basinMap, currentBasinCode, neighbourhood);
		} while (markNextBasin(basinMap, ++currentBasinCode, neighbourhood));
		return basinMap;
	}

	private static void locateCurrentBasin(char[][] basinMap,
			char currentBasinCode, Coordinate[][] neighbourhood) {
		int height = basinMap.length;
		int width = basinMap[0].length;
		boolean madeProgress;
		do {
			madeProgress = false;
			for (int row = 0; row < height; row++) {
				for (int column = 0; column < width; column++) {
					// is the cell in the basin, flowing to an unknown cell?
					if (basinMap[row][column] == currentBasinCode) {
						Coordinate neighbour = neighbourhood[row][column];
						if (neighbour != SINK && basinMap[neighbour.row][neighbour.column] == 0) {
							basinMap[neighbour.row][neighbour.column] = currentBasinCode;
							madeProgress = true;
						}
					}
					// water flows to a known basin from here?
					if (basinMap[row][column] == 0) {
						Coordinate neighbour = neighbourhood[row][column];
						if (neighbour != SINK && basinMap[neighbour.row][neighbour.column] == currentBasinCode) {
							basinMap[row][column] = currentBasinCode;
							madeProgress = true;
						}
					}
				}
			}
		} while (madeProgress);
	}

	private static boolean markNextBasin(char[][] basinMap, char basinCode,
			Coordinate[][] neighbourhood) {
		int height = basinMap.length;
		int width = basinMap[0].length;
		for (int row = 0; row < height; row++) {
			for (int column = 0; column < width; column++) {
				if (basinMap[row][column] == 0) {
					basinMap[row][column] = basinCode;
					return true;
				}
			}
		}
		return false;
	}

	private static Coordinate[][] calculateNeighbourhood(int[][] map) {
		int height = map.length;
		int width = map[0].length;
		Coordinate[][] neighbourhood = new Coordinate[height][];
		for (int row = 0; row < height; row++) {
			neighbourhood[row] = new Coordinate[width];
			for (int column = 0; column < width; column++) {
				neighbourhood[row][column] = calculateNeighbour(row, column,
						map);
			}
		}
		return neighbourhood;
	}

	private static Coordinate calculateNeighbour(int row, int column,
			int[][] map) {
		int height = map.length;
		int width = map[0].length;
		int elevation = map[row][column];
		Coordinate neighbour = SINK;
		if (row > 0) {
			if (map[row - 1][column] < elevation) {
				elevation = map[row - 1][column];
				neighbour = new Coordinate(row - 1, column);
			}
		}
		if (column > 0) {
			if (map[row][column - 1] < elevation) {
				elevation = map[row][column - 1];
				neighbour = new Coordinate(row, column - 1);
			}
		}
		if (column + 1 < width) {
			if (map[row][column + 1] < elevation) {
				elevation = map[row][column + 1];
				neighbour = new Coordinate(row, column + 1);
			}
		}
		if (row + 1 < height) {
			if (map[row + 1][column] < elevation) {
				elevation = map[row + 1][column];
				neighbour = new Coordinate(row + 1, column);
			}
		}
		return neighbour;
	}

	private static int[][] readMap() {
		int height = getNextInt();
		int width = getNextInt();
		int[][] map = new int[height][];
		for (int row = 0; row < height; row++) {
			map[row] = new int[width];
			for (int column = 0; column < width; column++) {
				map[row][column] = getNextInt();
			}
		}
		return map;
	}

	private static void display(int mapNumber, char[][] basinMap) {
		System.out.println("Case #" + mapNumber + ":");
		int height = basinMap.length;
		int width = basinMap[0].length;
		for (int row = 0; row < height; row++) {
			for (int column = 0; column < width; column++) {
				if (column > 0) {
					System.out.print(" ");
				}
				System.out.print(basinMap[row][column]);
			}
			System.out.println();
		}
	}

	static int getNextInt() {
		return inputScanner.nextInt();
	}

	static class Coordinate {
		Coordinate(int row, int column) {
			this.row = row;
			this.column = column;
		}

		int row;
		int column;

		@Override
		public String toString() {
			return "[" + row + ", " + column + "]";
		}
	}
}
