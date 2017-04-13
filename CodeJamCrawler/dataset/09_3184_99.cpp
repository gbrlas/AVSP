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
	
	boolean match(String a, String b) {
		int bPos = 0;
		for (int i = 0; i < a.length(); i++) {
			if (bPos >= b.length())
				return false;
			boolean ok = false;
			if (a.charAt(i) == '(') {
				while (i < a.length() && a.charAt(i) != ')') {
					ok |= a.charAt(i) == b.charAt(bPos);
					i++;
				}
			} else
				ok = a.charAt(i) == b.charAt(bPos);
			
			if (!ok)
				return false;
			bPos++;
		}
		return bPos == b.length();
	}
	
	void run() {
		//Place your code here
		int L = ni();
		int D = ni();
		int N = ni();
		String[] strs = new String[D];
		for (int i= 0; i < D; i++)
			strs[i] = ns();
		
		
		for (int t = 1; t <= N; t++) {
			String s = ns();
			int ans = 0;
			for (int i = 0; i < strs.length; i++) {
				if (match(s, strs[i])) {
					ans++;
				}
			}
			out.println("Case #" + t + ": "  + ans);
		}
		
	}
}