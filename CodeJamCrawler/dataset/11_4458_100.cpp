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
	
	boolean[][] destroy;
	char[][] combine;
	char[] cast = new char[10000000];
	int[] counter = new int[256];
	int pointer;
	
	void invoke(char ch) {
		counter[ch]++;
		cast[pointer++] = ch;
	}
	
	void checkCombination() {
		if (pointer > 1) {
			char a = cast[pointer - 2];
			char b = cast[pointer - 1];
			if (combine[a][b] != 0) {
				counter[a]--;
				counter[b]--;
				pointer -= 2;
				char ch = combine[a][b];
				counter[ch]++;
				cast[pointer++] = ch;
			}
		}
	}
	
	char[] baseChars = {'Q', 'W', 'E', 'R', 'A', 'S', 'D', 'F'};
	
	void checkDestruction() {
		if (pointer > 1) {
			char a = cast[pointer - 1];
			
			for (int i = 0; i < baseChars.length; i++) {
				char b = baseChars[i];
				if (counter[b] > 0 && destroy[a][b]) {
					pointer = 0;
					for (char ch = 'A'; ch <= 'Z'; ch++) {
						counter[ch] = 0;
					}
					return;
				}
			}
		}
	}
	
	void run() {
		//Place your code here
		int T = ni();
		for (int t = 0; t < T; t++) {
			pointer = 0;
			Arrays.fill(counter, 0);
			combine = new char[256][256];
			
			int C = ni();
			for (int i = 0; i < C; i++) {
				char[] chars = ns().toCharArray();
				combine[chars[0]][chars[1]] = combine[chars[1]][chars[0]] = chars[2];
			}
			
			destroy = new boolean[256][256];
			int D = ni();
			for (int i = 0; i < D; i++) {
				char[] chars = ns().toCharArray();
				destroy[chars[0]][chars[1]] = destroy[chars[1]][chars[0]] = true;
			}
			ni();
			char[] str = ns().toCharArray();
			for (int i = 0; i < str.length; i++) {
				invoke(str[i]);
				checkCombination();
				checkDestruction();
			}
			
			out.print("Case #" + (t + 1) + ": ");
			out.print('[');
			for (int i = 0; i < pointer; i++) {
				if (i > 0) {
					out.print(", ");
					
				}
				out.print(cast[i]);
			}
			out.println("]");
		}
	}
}