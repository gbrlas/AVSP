import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;


public class C {
	String inFile = "C.in";
	String outFile = "C.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	boolean[] visited;
	boolean[][] adj;
	int n, m;
	Vector<String> codes;
	int[] parents;
	
	String applySchedule(int crtNode, boolean[] schedule, int pos) {
		if (crtNode == -1) {
			if (pos == 2*n-1) {
				return "";
			}
			else {
				return null;
			}
		}
		
		visited[crtNode] = true;
		
		if (!schedule[pos]) {
			return applySchedule(parents[crtNode], schedule, pos+1);
		}
		// go to the best not visited neighbor
		String bestString = null;
		int bestNode = -1;
		for (int i=0; i<n; i++) {
			if (adj[crtNode][i] && !visited[i]) {
				if (bestString == null || codes.get(i).compareTo(bestString) < 0) {
					bestString = codes.get(i);
					bestNode = i;
				}
			}
		}
		
		if (bestNode == -1) {
			return null;	// invalid schedule
		}
		
		parents[bestNode] = crtNode;
		String sRest = applySchedule(bestNode, schedule, pos+1);
		if (sRest == null) return null;
		return bestString + sRest;
	}
	
	void solve(int test) {
		System.out.println(test);
		n = sc.nextInt();
		m = sc.nextInt();
		codes = new Vector<String>();
		sc.nextLine();
		
		for (int i=0; i<n; i++) {
			codes.add(sc.nextLine());
		}
		System.out.println(codes);
		
		adj = new boolean[n][n];
		for (int i=0; i<m; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			adj[a][b] = true;
			adj[b][a] = true;
		}
		
		boolean[] schedule = new boolean[2*(n-1) + 1];
		visited = new boolean[n];
		System.out.println(n + "!!");
		
		int firstNode = 0;
		for (int i=0; i<n; i++) {
			if (codes.get(i).compareTo(codes.get(firstNode)) < 0) {
				firstNode = i;
			}
		}
		
		String bestS = null;
		for (int i=0; i<1<<(2*(n-1) + 1); i++) {
			
			for (int j=0; j<2*(n-1); j++) {
				schedule[j] = ((i & (1 << j)) != 0);
			}
			for (int j=0; j<n; j++) {
				visited[j] = false;
			}
			
			parents = new int[n];
			for (int k=0; k<n; k++) {
				parents[k] = -2;
			}
			parents[firstNode] = -1;
			
			String s = applySchedule(firstNode, schedule, 0);
			if (s != null && (bestS == null || s.compareTo(bestS) < 0)) {
				bestS = s;
			}
			
		}
		bestS = codes.get(firstNode) + bestS;
		pw.print(String.format("Case #%d: ", test));
		pw.println(bestS);
	}
	
	
	void run() throws FileNotFoundException {
		init();
		
		int T = sc.nextInt();
		for (int test=1; test<=T; test++) {
			solve(test);
		}
		pw.close();
		sc.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		C t = new C();
		t.run();
	}
}
