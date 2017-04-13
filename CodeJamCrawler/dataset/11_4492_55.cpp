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
	
	void run() {
		//Place your code here
		int T = ni();
		for (int t = 1; t <= T; t++) {
			int n = ni();
			int[][] map = new int[n][n];
			for (int[] temp : map) {
				Arrays.fill(temp, -1);
			}
			for (int r = 0; r < n; r++) {
				String s = ns();
				for (int c = 0; c < n; c++) {
					if (s.charAt(c) != '.') {
						map[r][c] = s.charAt(c) - '0';
					}
				}
			}
			
			double[] wp = new double[n];
			for (int i = 0; i < n; i++) {
				int cnt = 0;
				int wcnt = 0;
				for (int j = 0; j < n; j++) {
					if (map[i][j] != -1) {
						cnt++;
						wcnt += map[i][j];
					}
				}
				wp[i] = (double)wcnt / cnt;
			}
			
			double[] owp = new double[n];
			for (int i = 0; i < n; i++) {
				double sum = 0;
				int ecnt = 0;
				for (int j = 0; j < n; j++) {
					if (map[i][j] == -1) {
						continue;
					}
					ecnt++;
					int cnt = 0;
					int wcnt = 0;
					for (int k = 0; k < n; k++) {
						if (k != i) {
							if (map[j][k] != -1) {
								cnt++;
								wcnt += map[j][k];
							}
						}
					}
					sum += (double) wcnt / cnt;
				}
				owp[i] = sum / ecnt; //!!!
			}
			
			double[] oowp = new double[n];
			for (int i = 0; i < n; i++) {
				double sum = 0;
				int cnt = 0;
				for (int j = 0; j < n; j++) {
					if (map[i][j] != -1) {
						cnt++;
						sum += owp[j];
					}
				}
				oowp[i] = sum / cnt;
			}
			
			out.println("Case #" + t + ":");
			for (int i = 0; i < n; i++) {
				out.println(0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
			}
			
		}
	}
}