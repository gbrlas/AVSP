import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	String inFile = "B.in";
	String outFile = "B.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	void solve(int test) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		int nr = 0;
		for (int i=0; i<a; i++) {
			for (int j=0; j<b; j++) {
				if ((i & j) < k) {
					nr++;
				}
			}
		}
		
		pw.print(String.format("Case #%d: ", test));
		pw.println(nr);
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
