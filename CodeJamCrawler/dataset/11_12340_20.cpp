import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class A {
	class Pair<T, U> {T f; U s; Pair(T t, U u) {f=t;s=u;}}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter pw = new PrintWriter("A.out");
		int T = sc.nextInt();
		for (int test=1; test<=T; test++) {
			pw.println("Case #"+test+":");
			
			int n = sc.nextInt();
			double[] wp = new double[n];
			double[] owp = new double[n];
			double[] oowp = new double[n];
			
			
			
			String[] s = new String[n];
			for (int i=0; i<n; i++) {
				s[i] = sc.next();
			}
			
			// compute wp
			for (int i=0; i<n; i++) {
				int w = 0;
				int nr = 0;
				for (int j=0; j<n; j++) {
					if (s[i].charAt(j)=='1') {
						w++;
						nr++;
					}
					else if (s[i].charAt(j)=='0') {
						nr++;
					}
				}
				wp[i] = ((double)w)/nr; 
			}
			
			// compute owp
			for (int i=0; i<n; i++) {
				int nrT = 0;
				double sowp = 0;
				
				for (int j=0; j<n; j++) {
					int w = 0;
					int nr = 0;
					
					if ((s[i].charAt(j)!='.') && (i!=j)) {
						for (int k=0; k<n; k++) {
							if (k != i) {
								if (s[j].charAt(k)=='1') {
									w++;
									nr++;
								}
								else if (s[j].charAt(k)=='0') {
									nr++;
								}
							}
						}
						sowp += ((double)w)/nr;
						nrT++;
					}
				}
				owp[i] = ((double)sowp) / nrT;
				
			}
			
			// compute oowp
			for (int i=0; i<n; i++) {
				double sum = 0;
				double nrT = 0;
				for (int j=0; j<n; j++) {
					if (s[i].charAt(j)!='.') {
						sum += owp[j]; 
						nrT++;
					}
				}
				oowp[i] = ((double)sum) / nrT;
			}
			
			for (int i=0; i<n; i++) {
				double rpi = 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i];
//				pw.println(wp[i] + " " + owp[i] + " " + oowp[i] + " " + rpi);
				pw.printf("%.12f\n", rpi);
			}
		}
		pw.close();
	}
}
