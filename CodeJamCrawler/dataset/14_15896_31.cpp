import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Blarge {
	String inFile = "B.in";
	String outFile = "Blarge.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	
	void solve(int test) {
		int n = sc.nextInt();
		int[] v = new int[n];
		for (int i=0; i<n; i++) {
			v[i] = sc.nextInt();
		}
		
		int[] l1 = new int[n];
		int[] l2 = new int[n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<i; j++)
				if (v[j] > v[i])
					l1[i]++;
			for (int j=i+1; j<n; j++)
				if (v[j] > v[i])
					l2[i]++;
		}
		
		int nr = 0;
		for (int i=0; i<n; i++)
			
			nr += Math.min(l1[i], l2[i]);
		
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
		Blarge t = new Blarge();
		t.run();
	}
}
