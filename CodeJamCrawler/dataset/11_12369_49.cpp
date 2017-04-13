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
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("A.in"));
		PrintWriter pw = new PrintWriter("A.out");
		int T = sc.nextInt();
		for (int test=1; test<=T; test++) {
			pw.print("Case #"+test+": ");
			
			
			int x = sc.nextInt();
			int s = sc.nextInt();
			int r = sc.nextInt();
			int t = sc.nextInt();
			int n = sc.nextInt();
			
			int dif = r - s;
			
			Vector<Integer> vect = new Vector<Integer>();
			for (int i=0; i<x; i++) {
				vect.add(s);
			}
			
			for (int i=0; i<n; i++) {
				int b = sc.nextInt();
				int e = sc.nextInt();
				int w = sc.nextInt();
				
				for (int j=b; j<e; j++) {
					vect.set(j, w+s);
				}
			}
			
			Collections.sort(vect);
			
			double t1 = 0;	// used
			double tt = 0;	// total
			for (int i=0; i<x; i++) {
				int v = vect.get(i);
				if (t1 < t) {
					double tmax = t - t1;
					double t0 = 1 / (double)(v+dif);
					if (t0 < tmax) {
						t1 += t0;
						tt += t0;
					}
					else {
						t1 = t;
						
						double d1 = tmax * (v+dif);
						tt+=tmax;
						
						double d2 = 1 - d1;
						tt += d2 / (double)v;
					}
					
				}
				else {
					tt += 1 / (double)v;
				}
			}
			
			pw.println(tt);
		}
		pw.close();
	}
}
