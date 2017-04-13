import java.util.*;
import java.io.*;
import java.math.*;
import static java.lang.Math.*;
import static java.math.BigInteger.*;

public class Task {
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader("input.txt"));
		out = new PrintWriter("output.txt");
		
		new Task().run();
		out.close();
	}
	
	static BufferedReader br;
	static PrintWriter out;
	StringTokenizer st;
	static String taskName = "";
	
	String nline() {
		try {
			return br.readLine();
		} catch (Exception exc) {
			return  null;
		}
	}
	
	String ns() {
		try {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(nline());
			}
			return st.nextToken();
		} catch (Exception exc) {
			return null;
		}
	}
	
	int ni() {
		return Integer.valueOf(ns());
	}

	double nd() {
		return Double.valueOf(ns());
	}
	
	void pf(String format, Object ... obj) {
		out.printf(format, obj);
	}
	
	void pln() {
		out.println();
	}
	
	void pt(Object obj) {
		out.print(obj);
	}
	
	int R, C;
	
	int[][] map;
	
	int[][] dirs = new int[][] {
			{-1, 0}, 
			{0, -1},
			{0, 1},
			{1, 0}
	};
	
	boolean ok(int r, int c) {
		return r >=0 && r < R && c >= 0 && c < C;
	}
	
	char[][] memo;
	char curChar;
	
	char get(int r, int c) {
		if (memo[r][c] == 0) {
			int bestDir = -1;
			int bestH = Integer.MAX_VALUE;
			for (int d = 0; d < 4; d++) {
				int nr = r + dirs[d][0];
				int nc = c + dirs[d][1];
				
				if (!ok(nr, nc))
					continue;
				
				if (map[nr][nc] < bestH) {
					bestDir = d;
					bestH = map[nr][nc];
				}
			}
			if (bestH >= map[r][c]) {
				memo[r][c] = curChar++;
			} else {
				int nr = r + dirs[bestDir][0];
				int nc = c + dirs[bestDir][1];
				memo[r][c] = get(nr, nc);
			}
		}
		return memo[r][c];
	}
	
	void run() {
		//Place your code here
		int T = ni();
		for (int t = 1; t <= T; t++) {
			R = ni();
			C = ni();
			map = new int[R][C];
			for (int r = 0; r < R; r++)
				for (int c = 0; c < C; c++)
					map[r][c] = ni();
			curChar = 'a';
			memo = new char[R][C];
			for (int r = 0; r < R; r++)
				for (int c = 0; c < C; c++) {
					get(r, c);
				}
			
			out.println("Case #" + t + ": ");
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					out.print(memo[r][c]);
					if (c + 1 < C)
						out.print(' ');
				}
				out.println();
			}
			
		}
	}
}