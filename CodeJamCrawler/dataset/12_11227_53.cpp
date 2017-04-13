import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.*;


public class A {
	Scanner sc;
	PrintStream ps;

	public void solve() {
		int a = sc.nextInt();
		int b = sc.nextInt();
		double[] v = new double[a];
		
		for (int i=0; i<a; i++) {
			v[i] = sc.nextDouble();
		}
		double e;
		
		// keep
		double[] allOk = new double[a+1]; //1.0;
		double min;
		
		allOk[0] = 1.0;
		for (int i=0; i<a; i++) {
			allOk[i+1] = allOk[i] * v[i];
		}
		e = allOk[a] * (b-a+1) + (1-allOk[a]) * (1+b-a + b+1);
//		System.out.println("1~" + e);
		min = e;
		// delete to i
		for (int i=1; i<a; i++) {
			e = allOk[i] * ((a-i) + (b-i) + 1) + (1-allOk[i]) * ((a-i) + (b-i) + 1 + b+1);
			if (e<min) min = e;
//			System.out.println("2~" + i + " " + e);
		}
		
		// enter
		e = 1 + b+1;
//		System.out.println("3~" + e + "! " + min);
		if (e<min) {
			min = e;
		}
		ps.println(min);
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
