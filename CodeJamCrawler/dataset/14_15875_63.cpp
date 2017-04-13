import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;


public class Clarge {
	String inFile = "C.in";
	String outFile = "Clarge.out";
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
	
	
	boolean[] accessible;
	
	boolean getAccessible(int i) {
		boolean update = false;
		
		accessible[i] = true;
		
		for (int j=0; j<n; j++) {
			if ((!visited[j]) && adj[i][j] && (!accessible[j])) {
				update = true;
				getAccessible(j);
			}
		}
		
		return update;
	}
	
	// get ancestors with the same list of accessible nodes
	Vector<Integer> getOkParents(int i) {
//		System.out.println(i + "!");
		if (i == -1) {
			accessible = new boolean[n];
			return new Vector<Integer>();
		}
		
		Vector<Integer> v = getOkParents(parents[i]);
		boolean update = getAccessible(i);
		if (update) {
			v = new Vector<Integer>();
		}
		v.add(i);
		
		return v;
	}
	
	String schedule(int crtNode) {
		visited[crtNode] = true;
//		System.out.println(crtNode);
		Vector<Integer> v = getOkParents(crtNode);
		// find best node directly accessible from one (lowest possible) in the 'ok' set.
		int bestNode = -1;
		int bestParent = -1;
		for (int idx=v.size()-1; idx>=0; idx--) {
			int i = v.get(idx);
			for (int j=0; j<n; j++) {
				if (!visited[j]) {
					if (adj[i][j]) {
						if ((bestNode == -1) || (codes.get(j).compareTo(codes.get(bestNode)) < 0)) {
							bestParent = i;
							bestNode = j;
						}
					}
				}
			}
		}
		
		if (bestNode == -1) {
			// done
			System.out.println("DONE");
			return codes.get(crtNode);
		}
		else {
			parents[bestNode] = bestParent;
			return codes.get(crtNode) + schedule(bestNode);
		}
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
		
		visited = new boolean[n];
		
		int firstNode = 0;
		for (int i=0; i<n; i++) {
			if (codes.get(i).compareTo(codes.get(firstNode)) < 0) {
				firstNode = i;
			}
		}
		
		String bestS = null;
		for (int j=0; j<n; j++) {
			visited[j] = false;
		}
			
		parents = new int[n];
		for (int k=0; k<n; k++) {
			parents[k] = -2;
		}
		parents[firstNode] = -1;
		
		
		
		bestS = schedule(firstNode);
		
		
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
		Clarge t = new Clarge();
		t.run();
	}
}
