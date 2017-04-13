import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;


public class Water {
	private static int basins = 0;

	public static void main(String args[]) throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("E:/in.dat")));
		Integer maps = Integer.parseInt(reader.readLine());
		for(int i = 1; i <= maps; i++) {
			String s[] = reader.readLine().split(" ");
			int h = Integer.parseInt(s[0]);
			int w = Integer.parseInt(s[1]);
			int altMap[][] = new int[w][h];
			basins = 0;
			for(int y = 0; y < h; y++) {
				s = reader.readLine().split(" ");
				for(int x = 0; x < w; x++) {
					altMap[x][y] = Integer.parseInt(s[x]);
				}
			}
			System.out.println("Case #" + i + ":");
			solve(w, h, altMap);
			System.out.println();
		}
	}
	
	private static void solve(int w, int h, int[][] altMap) {
		char basinMap[][] = new char[w][h];
		for(int i = 0; i < w; i++) Arrays.fill(basinMap[i], ' ');

		// Fill in the rest.
		for(int j = 0; j < h; j++) {
			for(int i = 0; i < w; i++) {
				findBasin(i, j, w, h, altMap, basinMap);
			}
		}
		
		// Print the answer.
		for(int j = 0; j < h; j++) {
			for(int i = 0; i < w; i++) {
				System.out.print(basinMap[i][j]);
				if(i != w - 1) System.out.print(" ");
			}
			System.out.println();
		}
	}

	private static char findBasin(int x, int y, int w, int h, int[][] altMap, char[][] basinMap) {
		if(basinMap[x][y] != ' ') return basinMap[x][y];
		
		int lowest = altMap[x][y];
		int lowestX = -1;
		int lowestY = -1;
		
		// North
		if(isValid(x, y - 1, w, h) && altMap[x][y - 1] < lowest) {
			lowest = altMap[x][y - 1];
			lowestX = x;
			lowestY = y - 1;
		}
		
		// West
		if(isValid(x - 1, y, w, h) && altMap[x - 1][y] < lowest) {
			lowest = altMap[x - 1][y];
			lowestX = x - 1;
			lowestY = y;
		}
		
		// East
		if(isValid(x + 1, y, w, h) && altMap[x + 1][y] < lowest) {
			lowest = altMap[x + 1][y];
			lowestX = x + 1;
			lowestY = y;
		}
		
		// South
		if(isValid(x, y + 1, w, h) && altMap[x][y + 1] < lowest) {
			lowest = altMap[x][y + 1];
			lowestX = x;
			lowestY = y + 1;
		}
		
		if(lowestX == -1) {
			return basinMap[x][y] = (char)('a' + basins++);
		} else {
			return basinMap[x][y] = findBasin(lowestX, lowestY, w, h, altMap, basinMap);
		}
	}

	private static boolean isValid(int x, int y, int w, int h) {
		return x >= 0 && x < w && y >= 0 && y < h;
	}
}
