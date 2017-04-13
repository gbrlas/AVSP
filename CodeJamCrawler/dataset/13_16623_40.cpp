import java.util.Scanner;
import java.io.FileWriter;
import java.io.File;
import java.io.BufferedWriter;
import java.io.IOException;

public class TicTacToemek {
	private static char[][] grid = new char[4][4];
	private static char[][] coor = { {'A', 'B', 'C', 'D'},
									 {'E', 'F', 'G', 'H'}, 
									 {'I', 'J', 'K', 'L'},
									 {'M', 'N', 'O', 'P'} };
	private static String[] sol = {".*A.*B.*C.*D.*",
							 ".*E.*F.*G.*H.*",
							 ".*I.*J.*K.*L.*",
							 ".*M.*N.*O.*P.*",
							 ".*A.*E.*I.*M.*",
							 ".*B.*F.*J.*N.*",
							 ".*C.*G.*K.*O.*",
							 ".*D.*H.*L.*P.*",
							 ".*A.*F.*K.*P.*",
							 ".*D.*G.*J.*M.*"};
	
	public static void main(String[] args) throws IOException {
		File in = new File("A-large.in");
		Scanner s = new Scanner(in);
		int n = s.nextInt();
		File out = new File("output.txt");
		FileWriter f = new FileWriter(out);
		BufferedWriter o = new BufferedWriter(f);
		System.out.println();
		
		for (int i = 0; i < n; i++) {
			String next = s.nextLine();
			if(next.length() == 0) next = s.nextLine();
			
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					grid[j][k] = next.charAt(k);
				}
				if (s.hasNext())
					next = s.nextLine();
			}
			
			for (int row = 0; row < 4; row++) {
				for (int col = 0; col < 4; col++) {
					System.out.print(grid[row][col]);
				}
				System.out.println();
			}
			
			o.write("Case #" + (i + 1) + ": " + (getResult()));
			o.newLine();
		}
		
		o.close();
	}
	
	public static String getResult() {
		boolean resultFound = false;
		int gridMoveCount = 0;
		String x, o;
		x = o = "";
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid.length; j++) {
				if(grid[i][j] != '.') gridMoveCount++;
			}
		}
		
		for(int i = 0; i < grid.length; i++) {
			for(int j = 0; j < grid.length; j++) {
				if (grid[i][j] == 'X') x += coor[i][j];
				else if (grid[i][j] == 'O') o += coor[i][j];
				else if (grid[i][j] == 'T') {
					o += coor[i][j];
					x += coor[i][j];
				}
			}
		}
		
		String returnS = "";
		for (int i = 0; i < sol.length; i++) {
			if (x.matches(sol[i])) {
				returnS = "X won";
				resultFound = true;
				break;
			} else if (o.matches(sol[i])) {
				returnS = "O won";
				resultFound = true;
				break;
			}
		}

		
		if (!resultFound) {
			if (gridMoveCount == 16) return "Draw";
		} else {
			return returnS;
		}
		
		return "Game has not completed";
	}
}
