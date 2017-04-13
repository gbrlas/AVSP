import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;


public class B {
	Scanner sc;
	PrintStream ps;

	void pln(Object o) {System.out.println(o.toString());}	
	
	public void solve() {
		int n = sc.nextInt();
		long w = sc.nextLong();
		long h = sc.nextLong();
		
		long[] r = new long[n];
		int[] idx = new int[n];
		
		for (int i=0; i<n; i++) {
			r[i] = sc.nextLong();
			idx[i] = i;
		}
		
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (r[i] < r[j]) {
					long tmp = r[i];
					r[i] = r[j];
					r[j] = tmp;
					
					int tmp2 = idx[i];
					idx[i] = idx[j];
					idx[j] = tmp2;
				}
			}
		}
//		pln(r[0] + " " + r[1]);
		long[] x = new long[n];
		long[] y = new long[n];
		
		long wNxt = r[0];
		long hNxt = r[0];
		long crtx = 0;
		x[0] = 0;
		y[0] = 0;
//		pln(h + " " + w);
		for (int i=1; i<n; i++) {
			if (2 * r[i] + hNxt > h) {
				crtx = wNxt + r[i];
				wNxt += 2*r[i];
				hNxt = r[i];
				x[i] = crtx;
				y[i] = 0;
			}
			else {
				x[i] = crtx;
				y[i] = hNxt + r[i];
				hNxt += 2*r[i];
			}
			
		}

//		for (int i=0; i<n; i++) {
//			pln(y[i] + " " + x[i] + " [ " + r[i] + " ] ");
//		}
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (Math.abs(x[i] - x[j]) + Math.abs(y[i] - y[j]) < r[i] + r[j]) {
					System.out.println("intersect: " + i + " " + j + " ! " + " " + y[i] + " " + x[i] + " " + r[i] + "   -  " + y[j] + " " + x[j] + " " + r[j]);
				}
					
			}
		}
		
		String res = "";
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (idx[j] == i) {
					res += x[j] + " " + y[j] + " ";
//					if (x[j] > w) pln("!!!!!!!!!!!!!! OUT !!!!!!!!!!!!!!!!!!!!!");
				}
			}
		}
		System.out.println(res.substring(0, res.length()-1));
	}
	
	
	public void run(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File("B.in"));
		ps = System.out; // new PrintWriter("A.out");
		int num_tests = sc.nextInt();
		sc.nextLine();
		
		for (int test=1; test<=num_tests; test++) {
			ps.print("Case #"+test+": ");
			
			solve();
			
		}
		ps.close();
		
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		B a = new B();
		a.run(args);
	}
}
