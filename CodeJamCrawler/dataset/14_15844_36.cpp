import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


public class D {
	String inFile = "D.in";
	String outFile = "D.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	int solveWar(Vector<Double> a, Vector<Double> b) {
		int n = a.size();
		int i=0, j=0, x=0, winB=0;
		
		while (i<n || j<n) {
			if (i!=n && (j==n || a.get(i) < b.get(j))) {
				i++;
				x++;
			}
			else {
				j++;
				if (x > 0) {
					x--;
					winB++;
				}
			}
		}
		return n-winB;
	}

	int solveWar2(Vector<Double> a, Vector<Double> b) {
		return a.size()-solveWar(b, a);
	}
	
	void solve(int test) {
		int n = sc.nextInt();
		Vector<Double> a = new Vector<Double>();
		Vector<Double> b = new Vector<Double>();
		
		for (int i=0; i<n; i++) {
			a.add(sc.nextDouble());
		}
		for (int i=0; i<n; i++) {
			b.add(sc.nextDouble());
		}
		Collections.sort(a);
		Collections.sort(b);
		
		int n1 = solveWar(a, b);
		int n2 = solveWar2(a, b);
		
		
		pw.println(String.format("Case #%d: %d %d", test, n2, n1));
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
		D t = new D();
		t.run();
	}
}
