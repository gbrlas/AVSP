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
		for (int test=1; test<=T; test++) {
			pw.print("Case #"+test+": ");
			
			long l = sc.nextLong();
			long t = sc.nextLong();
			long n = sc.nextLong();
			long c = sc.nextLong();
			
			long[] a = new long[(int)c];
			for (int i=0; i<c; i++) {
				a[i] = sc.nextInt();
			}
			
			long[] d = new long[(int)n];
			for (int i=0; i<n; i++) {
				d[i] = a[(int)((i)%c)];
			}
			
			double tmin = Long.MAX_VALUE;
			if (l==0) {
				tmin = 0;
				for (int i=0; i<n; i++) {
					tmin += 2*d[i];
				}
			}
			else if (l==1) {
				for (int p=0; p<n; p++) {
					double tcrt = 0;
					
					for (int pos=0; pos<n; pos++) {
						if (pos == p) {
							if (tcrt >= t) {
								tcrt += d[pos];
							}
							else if (tcrt+2*d[pos] <= t) {
								tcrt += 2*d[pos];
							}
							else {
								double dist = (t - tcrt) / 2;
								double distLeft = d[pos] - dist;
								tcrt += 2*dist + distLeft;
							}
						}
						else {
							tcrt += 2*d[pos];
						}
					}
					if (tcrt < tmin) {
						tmin = tcrt;
					}
				}
			}
			else if (l==2) {
				for (int p1=0; p1<n; p1++)
				for (int p2=p1+1; p2<n; p2++) {
					double tcrt = 0;
					
					for (int pos=0; pos<n; pos++) {
						if (pos == p1 || pos == p2) {
							if (tcrt >= t) {
								tcrt += d[pos];
							}
							else if (tcrt+2*d[pos] <= t) {
								tcrt += 2*d[pos];
							}
							else {
								double dist = (t - tcrt) / 2;
								double distLeft = d[pos] - dist;
								tcrt += 2*dist + distLeft;
							}
						}
						else {
							tcrt += 2*d[pos];
						}
					}
					if (tcrt < tmin) tmin = tcrt;
				}
			}
			
			if ((long)tmin == Long.MAX_VALUE) {
				System.out.println(test);
				System.exit(0);
			}
			pw.println((long)tmin);
			System.out.println(test);
		}
		pw.close();
	}
}
