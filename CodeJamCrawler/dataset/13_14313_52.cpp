import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


public class A {
	
	public void solve(Scanner sc, PrintWriter pw, int test) {
		pw.print("Case #" + test + ": ");
		int a = sc.nextInt();
		int n = sc.nextInt();
		Vector<Integer> v = new Vector<Integer>();
		for (int i=0; i<n; i++) v.add(sc.nextInt());
		
		Collections.sort(v);
		
		int numOps = 0;
		for (int i=0; i<n; i++) {
			int num1 = 0, ca = a;
			if (a == 1) {
				num1 = 2000000;
			}
			else {
				
				while (ca <= v.get(i)) {
					ca += ca-1;
					num1++;
				}
			}
			int num2 = n-i;
			if (num1 < num2) {
				a = ca;
				a += v.get(i);
				numOps += num1;
			}
			else {
				numOps += num2;
				break;
			}
		}
		pw.println(numOps);
	}
	
	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter pw = new PrintWriter("A.out");
		
		int numTests = sc.nextInt();
		
		for (int test = 1; test <= numTests; test++) {
			solve(sc, pw, test);
		}
		pw.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new A().run();
	}
}
