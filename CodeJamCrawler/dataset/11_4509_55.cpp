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
	
	int f(int u, int v, int i) {
		if (u < v) {
			if (i < u || i > v) {
				return Integer.MAX_VALUE;
			}
			return v - i;
		} else {
			if (i > v && i < u) {
				return Integer.MAX_VALUE;
			}
			return i > u
				? v + (N - 1) - i + 1
				: v - i;
		}
	}
	
	class Cmp implements Comparator<int[]> {

		@Override
		public int compare(int[] arg0, int[] arg1) {
			if (arg0.length < arg1.length) {
				return -1;
			}
			if (arg0.length > arg1.length) {
				return 1;
			}
			for (int i = 0; i < arg0.length; i++) {
				int a = arg0[i];
				int b = arg1[i];
				if (a < b) {
					return -1;
				}
				if (a > b) {
					return 1;
				}
			}
			return 0;
		}
		
	}
	
	int[] ans;
	int ansC;
	
	int[] colors;
	int[][] arrays;
	int N;
	
	boolean[] used;
	
	boolean validate() {
		int C = 0;
		for (int i = 0; i < N; i++) {
			if (colors[i] > C) {
				C = colors[i];
			}
		}
		
		if (C <= ansC) {
			return false;
		}
		
		for (int i = 1; i <= C; i++) {
			used[i] = false;
		}
		
		for (int i = 0; i < N; i++) {
			used[colors[i]] = true;
		}
		
		for (int i = 1; i <= C; i++) {
			if (!used[i]) {
				return false;
			}
		}
		
		for (int i = 0; i < arrays.length; i++) {
			int[] arr = arrays[i];
			for (int j = 1; j <= C; j++) {
				used[j] = false;
			}
			for (int j = 0; j < arr.length; j++) {
				used[colors[arr[j]]] = true;
			}
			for (int j = 1; j <= C; j++) {
				if (!used[j]) {
					return false;
				}
			}
		}
		
		ansC = C;
		ans = colors.clone();
		return true;
	}
	
	void fx(int pos) {
		if (pos == N) {
			validate();
		} else {
			for (int c = 1; c <= N; c++) {
				
				
				colors[pos] = c;
				fx(pos + 1);
				if (pos == 0) {
					return;
				}
			}
		}
	}
	
	void run() {
		//Place your code here
		//Place your code here
		int T = ni();
		for (int t = 1; t <= T; t++) {
			ans = null;
			ansC = 0;
			
			N = ni();
			used = new boolean[N + 1];
			int M = ni();
			
			ArrayList<Integer>[] edges = new ArrayList[N];
			
			int[][] inpEdges = new int[M][2];
			
			for (int i = 0; i < N; i++) {
				edges[i] = new ArrayList<Integer>();
				edges[i].add((i - 1 + N) % N);
				edges[i].add((i + 1) %  N);
			}
			
			for (int i = 0; i < M; i++) {
				inpEdges[i][0] = ni() - 1;
			}
			
			for (int i = 0; i < M; i++) {
				inpEdges[i][1] = ni() - 1;
			}
			
			for (int i = 0; i < M; i++) {
				int a = inpEdges[i][0];
				int b = inpEdges[i][1];
				edges[a].add(b);
				edges[b].add(a);
			}
			
			TreeSet<int[]> set = new TreeSet<int[]>(new Cmp());
			
			for (int[] edge : inpEdges) {
				for (int dir = 0; dir < 2; dir++) {
					int a = dir *  edge[0] + (1 - dir) * edge[1];
					int b = (1 - dir) * edge[0] + dir * edge[1];
					
					ArrayList<Integer> list = new ArrayList<Integer>();
					list.add(a);
					int pos = a;
					while (pos != b) {
						int bestId = -1;
						int bestDist = Integer.MAX_VALUE;
						for (int e : edges[pos]) {
							if (e == b && list.size() == 1) {
								continue;
							}
							if(e == a) {
								continue;
							}
							int curDist = f(a, b, e);
							if (curDist < bestDist) {
								bestDist = curDist;
								bestId = e;
							}
						}
						pos = bestId;
						list.add(pos);
					}
					
					int[] arr = new int[list.size()];
					for (int i = 0; i < list.size(); i++) {
						arr[i] = list.get(i);
					}
					Arrays.sort(arr);
					set.add(arr);
				}
			}
			
			arrays = new int[set.size()][];
			int ptr = 0;
			for (int[] arr : set) {
				arrays[ptr++] = arr;
			}
			
			colors = new int[]{ 1, 2, 3, 2, 1, 5, 4, 5 };
			validate();
			
			
			colors = new int[N];
			fx(0);
			
			out.println("Case #" + t + ": " + ansC);
			for (int i = 0; i < N; i++) {
				out.print(ans[i]);
				if (i + 1 < N) {
					out.print(" ");
				}
			}
			out.println();
		}		
	}
}