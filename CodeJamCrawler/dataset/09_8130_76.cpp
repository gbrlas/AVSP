import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Watersheds {

	public static void main(String[] args) throws IOException {
		BufferedReader infile = new BufferedReader(new FileReader("watersheds.in"));
		BufferedWriter outfile = new BufferedWriter(new FileWriter("watersheds.out"));
		
		int T = Integer.parseInt(infile.readLine());
		
		ArrayList<Map> maps = new ArrayList<Map>();
		for (int i=0; i<T; i++) {
			outfile.write("Case #"+(i+1)+":\n");
			maps.add(new Map(infile, outfile));
		}
		outfile.close();
	}

}

class Map {
	int H, W;
	int alt[][];
	int clr[][];
	
	public Map(BufferedReader infile, BufferedWriter outfile) throws IOException {
		StringTokenizer st = new StringTokenizer(infile.readLine());
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		
		alt = new int[W][H]; // x then y
		clr = new int[W][H];
		
		for (int i=0; i<H; i++) {
			st = new StringTokenizer(infile.readLine());
			for (int j=0; j<W; j++)
				alt[j][i] = Integer.parseInt(st.nextToken());
		}
		/*
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				System.out.print(alt[j][i] + " ");
			}
			System.out.println();
		}
		System.out.println();
		*/

		int curColor = 1;
		for (int i=0; i<W; i++) {
			for (int j=0; j<H; j++) {
				if (clr[i][j] == 0)
					fill(i,j,curColor++);
			}
		}
		HashMap<Integer, Character> ltr = new HashMap<Integer, Character>();
		char nextLtr = 'a';
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if (!ltr.containsKey(clr[j][i]))
					ltr.put(clr[j][i], nextLtr++);
				if (j>0) outfile.write(" ");
				outfile.write(ltr.get(clr[j][i]));
			}
			outfile.write("\n");
			//System.out.println();
		}
		//System.out.println();
		//System.out.println();
	}
	
	public void fill(int x, int y, int curColor) {
		if (clr[x][y] != 0) {
			merge(curColor, clr[x][y]);
		} else {
			// pick next
			clr[x][y] = curColor;
			int lowest = alt[x][y];
			int lowestx = x;
			int lowesty = y;

			// NORTH
			if (y>0 && lowest > alt[x][y-1]) {
				lowest = alt[x][y-1];
				lowestx = x;
				lowesty = y-1;
			}
			// WEST
			if (x>0 && lowest > alt[x-1][y]) {
				lowest = alt[x-1][y];
				lowestx = x-1;
				lowesty = y;
			}
			// EAST
			if (x<W-1 && lowest > alt[x+1][y]) {
				lowest = alt[x+1][y];
				lowestx = x+1;
				lowesty = y;
			}
			// SOUTH
			if (y<H-1 && lowest > alt[x][y+1]) {
				lowest = alt[x][y+1];
				lowestx = x;
				lowesty = y+1;
			}
			
			if (lowestx != x || lowesty != y) {
				fill(lowestx, lowesty, curColor);
			}
		}
	}
	
	public void merge(int clrFrom, int clrTo) {
		if (clrFrom == clrTo) return;
		for (int i=0; i<W; i++) {
			for (int j=0; j<H; j++) {
				if (clr[i][j] == clrFrom) clr[i][j] = clrTo;
			}
		}
	}
}