import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;

public class C {
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C.in"));
		PrintWriter pw = new PrintWriter("C.out");
		int T = sc.nextInt();
		for (int test=1; test<=T; test++) {
			pw.print("Case #"+test+": ");
			
			int n = sc.nextInt();
			int l = sc.nextInt();
			int h = sc.nextInt();
			
			int[] f = new int[n];
			for (int i=0; i<n; i++) {
				f[i] = sc.nextInt(); 
			}
			
			int note = -1;
			for (int i=l; i<=h; i++) {
				boolean ok = true;
				for (int j: f) {
					if (!( (j%i==0) || (i%j==0))) {
						ok = false;
						break;
					}
				}
				if (ok) {
					note = i;
					break;
				}
			}
			if (note != -1)
				pw.println(note);
			else
				pw.println("NO");
		}
		pw.close();
	}
}
