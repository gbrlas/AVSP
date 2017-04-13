import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class B {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B.in"));
		PrintWriter pw = new PrintWriter("B.out");
		int T = sc.nextInt();
		tests:

		for (int test=1; test<=T; test++) {
			pw.print("Case #"+test+": ");
			
			int r = sc.nextInt();
			int c = sc.nextInt();
			int d = sc.nextInt();
			int[][] m = new int[r][c];
			
			sc.nextLine();
			for (int i=0; i<r; i++) {
				String line = sc.nextLine();
				for (int j=0; j<c; j++) {
					m[i][j] = d + (line.charAt(j)-'0');
				}
			}
			
			for (int k=Math.min(r, c); k>=3; k--) {
				
				for (int i=0; i<=r-k; i++) {
					for (int j=0; j<=c-k; j++) {
						
						int si = 0;
						int sj = 0;
						int ti = 0, tj = 0;
						
						for (int i1=i; i1<i+k; i1++) {
							for (int j1=j; j1<j+k; j1++) {
								si += i1 * m[i1][j1];
								sj += j1 * m[i1][j1];
								ti += m[i1][j1];
								tj += m[i1][j1];
							}
						}
						
						si -= i * m[i][j];
						si -= (i+k-1) * m[i+k-1][j];
						si -= i * m[i][j+k-1];
						si -= (i+k-1) * m[i+k-1][j+k-1];
						
						ti -= m[i][j];
						ti -= m[i+k-1][j];
						ti -= m[i][j+k-1];
						ti -= m[i+k-1][j+k-1];
						
						sj -= j * m[i][j];
						sj -= j * m[i+k-1][j];
						sj -= (j+k-1) * m[i][j+k-1];
						sj -= (j+k-1) * m[i+k-1][j+k-1];
						tj -= m[i][j];
						tj -= m[i+k-1][j];
						tj -= m[i][j+k-1];
						tj -= m[i+k-1][j+k-1];
						
						double ci = ((double)si) / ti;
						double cj = ((double)sj) / tj;
						
						if (ci == ((double)(i + i+k-1))/2 ) {
							if (cj == ((double)(j + j+k-1))/2 ) {
								pw.println(k);
								continue tests;
							}
						}
					}
				}
			}
			pw.println("IMPOSSIBLE");
			
		}
		pw.close();
	}
}
