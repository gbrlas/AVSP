import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;


public class B {
	Scanner sc;
	PrintStream ps;

	public void solve() {
		int n = sc.nextInt();
		
		boolean[] d1 = new boolean[n];
		boolean[] d2 = new boolean[n];
		int[] c1 = new int[n];
		int[] c2 = new int[n];
		
		for (int i=0; i<n; i++) {
			c1[i] = sc.nextInt();
			c2[i] = sc.nextInt();
		}
		
		int s = 0;
		int nr = 0;
		int rest = n;
		
		for (int it=0; it<2*n; it++) {
			
			boolean done = false;
			for (int i=0; i<n; i++) {
				if (c2[i] <= s && !d2[i] && !d1[i]) {
					s += 2;
					d2[i] = true;
					done = true;
					rest--;
					break;
				}
			}

			if (!done) {
				for (int i=0; i<n; i++) {
					if (c2[i] <= s && !d2[i] && d1[i]) {
						s += 1;
						d2[i] = true;
						done = true;
						rest--;
						break;
					}
				}
			}
			
			if (!done) {
				int idx = -1;
				int max2 = -1;
				for (int i=0; i<n; i++) {
					if (c1[i] <= s && !d1[i] && !d2[i]) {
						if (c2[i] > max2) {
							idx = i;
							max2 = c2[i];
						}
					}
				}
				if (idx != -1) {
					s += 1;
					d1[idx] = true;
					done = true;
				}
			}
			nr++;
			if (rest == 0) {
				ps.println(nr);
				return;
			}
			
			if (!done) {
				ps.println("Too Bad");
				return;
			}
		}
		ps.println("Too Bad");
		ps.println();
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
