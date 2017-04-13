import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class GCJ2012A3 {
	static PrintWriter pw = new PrintWriter(System.out);
	static HashMap<Integer, HashSet<Integer>> map = new HashMap<Integer, HashSet<Integer>>();
	static HashSet<Integer> set = new HashSet<Integer>();
	static LinkedList<Integer> queue = new LinkedList<Integer>();

	public static void main(String[] args) throws Exception {
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(r.readLine());
		StringTokenizer st;
		int n, m, p;
		for (int i = 1; i <= t; i++) {
			map.clear();
			n = Integer.parseInt(r.readLine());
			for (int j = 1; j <= n; j++) {
				st = new StringTokenizer(r.readLine());
				m = Integer.parseInt(st.nextToken());
				set = new HashSet<Integer>();
				for (int k = 0; k < m; k++) {
					p = Integer.parseInt(st.nextToken());
					set.add(p);
				}
				map.put(j, set);
			}
			pw.println("Case #" + i + ": " + solve(n));
		}
		pw.flush();
	}

	private static String solve(int n) {
		int k;
		for (int i = 1; i <= n; i++) {
			queue.clear();
			set = new HashSet<Integer>();
			queue.add(i);
			while (queue.size() > 0) {
				k = queue.pollFirst();
				if (set.contains(k)) {
					return "Yes";
				}
				set.add(k);
				for (int l : map.get(k)) {
					queue.add(l);
				}
			}
		}
		return "No";
	}
}
