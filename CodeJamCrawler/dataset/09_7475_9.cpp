import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;

import static java.lang.String.format;
import static java.lang.Math.*;


public class ProblemB {
//	final static String testType = "test";
		final static String testType = "small";
	//	final static String testType = "large";
	static BufferedReader infile;
	static PrintWriter outfile;

	public static void main(String[] args) throws Exception {
		String inFileName = "input_" + testType + "_ProblemB.txt";
		String outFileName = "output_" + testType + "_ProblemB.txt";
		infile = new BufferedReader(new FileReader(inFileName));
		outfile = new PrintWriter(new BufferedWriter(
				new FileWriter(outFileName)));
		new ProblemB();
	}

	public void log(String s) {
		System.out.print(s);
		outfile.print(s);
	}
	
	int[] dr = { 0,0, 1, 1};
	int[] dc = { -1, 1,-1,1};

	public ProblemB() throws Exception {
		Scanner scan = new Scanner(infile);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			int height = scan.nextInt();
			int width = scan.nextInt();
			int fall = scan.nextInt();
			char[][] orgmap = new char[height][width];
			for (int i = 0; i < height; i++) {
				orgmap[i] = scan.next().toCharArray(); 
			}
//			for ( int r = 0; r < height; r++) {
//				String s = "";
//				for (char c: orgmap[r]) s+= c;
//				System.out.println(s);
//			}

			HashSet<String> done = new HashSet<String>();

			LinkedList<State> list = new LinkedList<State>();
			State first = new State(0,0,0,orgmap);
			list.add(first);
			done.add(first.grrString());
			State answer = null;
			int counter = 0;
			while ( list.size() > 0 ) {
				State here = list.poll();
				if ( here.row == height-1 ) {
					answer = here;
					break;
				}
				counter++;
//				if ( counter > 20) break;
//				System.out.println("state = "+here.grrString());                               
				int r = here.row;
				int c = here.col;
				int d = here.dist;
				char[][] map = here.getMap(height, width);
				for ( int i = 0; i < 4; i++) {
					boolean dig = dr[i] > 0;
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nc < 0 || nc >= width) continue;
					if ( map[r][nc] == '#') continue;
					
					if ( dig && map[nr][nc] == '#') {
						char[][] newmap = new char[height][width];
						for (int a = 0; a < height; a++)
							for ( int b = 0; b < width; b++)
								newmap[a][b] = map[a][b];
						newmap[nr][nc] = '.';
						State next = new State(r,c, d+1, newmap);
						if ( !done.contains(next.grrString())) {
							list.addLast(next);
							done.add(next.grrString());
						}
					}
					if ( !dig ) {
						int fr = nr;
						while ( fr < height-1 && map[fr+1][nc] =='.') fr++;
						if ( fr - r > fall) continue;
						nr = fr;
						State next = new State(nr, nc, d, map);
						if ( !done.contains(next.grrString())) {
							list.addFirst(next);
							done.add(next.grrString());
						}
										
					}
					
				}
			}
			String result = (answer == null ? "No" : "Yes "+answer.dist);
			log(format("Case #%d: %s\n", test + 1, result));
		}
		outfile.close();
	}
	
	public class State  {
		int row;
		int col;
		int dist;
		String mapstring;
		char[][] map;

		public State(int row, int col, int dist, char[][] map ) {
			this.row = row;
			this.col = col;
			this.dist = dist;
			mapstring = "";
			for ( char[] a: map)
				for ( char b: a) mapstring += b;
		}
		public String toString() {
			return String.format("r = %d c = %d dist = %d", row, col, dist);
		}
		public String grrString() {
			return String.format("r = %d c = %d dist = %d %s", row, col, dist, mapstring);
		}
		public char[][] getMap(int height, int width) {
			char[][] result = new char[height][width];
			int index = 0;
			for ( int r = 0; r < height; r++) 
				for ( int c = 0; c < width; c++ ) {
					result[r][c] = mapstring.charAt(index);
					index++;
				}
			return result;
		}
		public boolean equals(Object o) {
			if ( !(o instanceof State)) return false;
			State other = (State)o;
			return col == other.col && row == other.row && mapstring.equals(other.mapstring);
			
		}
//		public int hashCode() {
//			
//		}

	}

	
}
