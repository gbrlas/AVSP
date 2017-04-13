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
			int C = ni();
			int D = ni();
			int[] Ps = new int[C];
			int[] Vs = new int[C];
			for (int i = 0; i < C; i++) {
				Ps[i] = ni();
				Vs[i] = ni();
			}
			
			double low = 0;
			double high = 1E20;
			double bestAns = Double.POSITIVE_INFINITY;
			
			for (int it = 0; it < 200; it++) {
				double time = (low + high) / 2;
				
				double lm = Double.NEGATIVE_INFINITY;
				
				boolean can = true;
				
				for (int i = 0; i < C; i++) {
					lm = max(lm, Ps[i] - time);
					double r = lm + (Vs[i] - 1) * D;
					if (r > Ps[i] + time) {
						can = false;
						break;
					}
					lm = r + D;
				}
				
				if (can) {
					bestAns = min(bestAns, time);
					high = time;
				} else {
					low = time;
				}
				
				
				
			}
			
			out.println("Case #" + t + ": " + bestAns);

			
		}

	}
}