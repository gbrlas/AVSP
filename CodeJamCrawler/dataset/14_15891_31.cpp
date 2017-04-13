import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	String inFile = "B.in";
	String outFile = "Bsmall.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	
	int[] p;
	int best;
	void bkt(int pos, int n) {
		if (pos == n) {
//			for (int i=0; i<n; i++) System.out.print(p[i] + " ");
//			System.out.println();
			
			boolean ok = true;
			boolean stdesc = false;
			for (int i=1; i<n; i++) {
				if (v[p[i]] < v[p[i-1]]) {
					stdesc = true;
				}
				if (stdesc && v[p[i]] > v[p[i-1]]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				int nr = 0;
				for (int i=0; i<n; i++) {
					for (int j=i+1; j<n; j++) {
						if (p[i] > p[j]) {
							nr++;
						}
					}
				}
				if (nr < best) {
					best = nr;
				}
			}
			return;
		}
		
		for (int val=0; val<n; val++) {
			boolean ok = true;
			for (int i=0; i<pos; i++) {
				if (p[i] == val) {
					ok = false;
					break;
				}
			}
			if (ok) {
				p[pos] = val;
				bkt(pos+1, n);
			}
		}
	}
	
	int[] v;
	void solve(int test) {
		best = Integer.MAX_VALUE;
		int n = sc.nextInt();
		v = new int[n];
		p = new int[n];
		
		for (int i=0; i<n; i++) {
			v[i] = sc.nextInt();
		}
		
		System.out.println("--" + test + " " + n);
		bkt(0, n);
		
		pw.print(String.format("Case #%d: ", test));
		pw.println(best);
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
		B t = new B();
		t.run();
	}
}
