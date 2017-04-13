import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;


public class Alarge {
	String inFile = "A.in";
	String outFile = "Alarge.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	void solve(int test) {
		System.out.println("-- " + test);
		int n = sc.nextInt();
		int s = sc.nextInt();
		int[] v = new int[n];
		
		for (int i=0; i<n; i++) {
			v[i] = sc.nextInt();
		}
		Arrays.sort(v);
		
		
		boolean[] picked = new boolean[n];
		int[] next = new int[n];
		for (int i=0; i<n; i++) next[i] = -2;
		int best=0;
		int crt=-1;
		int nr=0;
		for (int i=n-1; i>=0; i--) {
			while(true) {
				if (best <= i && (v[i] + v[best] <= s)) {
					best++;
				}
				else {
					break;
				}
			}
			if (picked[i]) continue;
			nr++;
			System.out.print(v[i] + " ");
			picked[i] = true;
			if (best == 0) {
				System.out.println();
				continue;
			}
			if (next[best-1] < -1) {
				next[best-1] = best-1;
			}
			
			crt = next[best-1];
			if (crt >= 0) {
				while (true) {
					if (!picked[crt]) {
						next[best-1] = crt;
						break;
					}
					crt--;
					if (crt < 0) {
						next[best-1] = -1;
						break;
					}
				}
			}
			if (next[best-1] >= 0) {
				crt = next[best-1];
				picked[crt] = true;
				System.out.print(v[crt]);
				next[best-1] = crt-1;
			}
			System.out.println();
		}
		System.out.println("=>"+nr);
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
		Alarge t = new Alarge();
		t.run();
	}
}
