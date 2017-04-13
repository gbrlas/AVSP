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
	String phrase = "welcome to code jam";
	int M = 10000;
	
	boolean[][] done;
	int[][] memo;
	
	String line;
	
	int get(int i, int k) {
		if (k == phrase.length())
			return 1;
		if (i == line.length())
			return 0;
		if (!done[i][k]) {
			
			for (int j = i; j < line.length(); j++)
				if (line.charAt(j) == phrase.charAt(k)) {
					memo[i][k] += get(j + 1, k + 1);
					memo[i][k] %= M;
				}
			
			done[i][k] = true;
		}
		return memo[i][k];
	}
	
	void run() {
		//Place your code here
		int T = ni();
		for (int t = 1; t <= T; t++) {
			line = nline();
			int n = line.length();
			int m = phrase.length();
			done = new boolean[n + 1][m + 1];
			memo = new int[n + 1][m + 1];
			
			int ans = get(0, 0);
			String s = Integer.toString(ans);
			while (s.length() < 4)
				s = "0" + s;
			out.println("Case #" + t + ": " + s);
			
		}
	}
}