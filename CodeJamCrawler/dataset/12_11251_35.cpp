import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;


public class A {
	Scanner sc;
	PrintStream ps;

	void pln(Object o) {System.out.println(o.toString());}	
	
	public void solve() {
		int n = sc.nextInt();
		
		long[] di = new long[n];
		long[] li = new long[n];
		long[] bst = new long[n];
		long d;
		
		for (int i=0; i<n; i++) {
			di[i] = sc.nextLong();
			li[i] = sc.nextLong();
			bst[i] = 0;
		}
		d = sc.nextLong();
		
		li[0] = di[0];
		bst[0] = di[0];
		
//		pln(bestNext + " !" + d);
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (di[j] - di[i] > bst[i]) {
					break;
				}
				
				long crtl2 = li[j];
				if (di[j] - di[i] < li[j]) {
					crtl2 = di[j] - di[i];
				}
				
				if (crtl2 > bst[j]) bst[j] = crtl2;
				
			}
		}
		
		for (int i=0; i<n; i++) {
			if (di[i] + bst[i] >= d) {
				ps.println("YES");
				return;
			}
		}
		
		ps.println("NO");
		
	}
	
	
	public void run(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File("A.in"));
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
		A a = new A();
		a.run(args);
	}
}
