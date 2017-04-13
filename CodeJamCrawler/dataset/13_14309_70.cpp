import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class P2 {
	
	public void solve(Scanner sc, PrintWriter pw, int test) {
		pw.print("Case #" + test + ": ");
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		int[][] h = new int[n][m];
		int[][] crt = new int[n][m];
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				h[i][j] = sc.nextInt();
				crt[i][j] = 100;
			}
		}
		
		int[] maxl = new int[n];
		int[] maxc = new int[m];

		for (int i=0; i<n; i++) maxl[i] = 0;
		for (int j=0; j<m; j++) maxc[j] = 0;
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (h[i][j] > maxl[i]) maxl[i] = h[i][j];
				if (h[i][j] > maxc[j]) maxc[j] = h[i][j];
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (crt[i][j] > maxl[i]) crt[i][j] = maxl[i];
				if (crt[i][j] > maxc[j]) crt[i][j] = maxc[j];
			}
		}
		
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (crt[i][j] != h[i][j]) {
					pw.println("NO");
					return;
				}
			}
		}
		pw.println("YES");

	}
	
	public void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("P2.in"));
		PrintWriter pw = new PrintWriter("P2.txt");
		
		int numTests = sc.nextInt();
		
		for (int test = 1; test <= numTests; test++) {
			solve(sc, pw, test);
		}
		pw.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new P2().run();
	}
}
