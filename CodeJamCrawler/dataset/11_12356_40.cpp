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
			pw.println("Case #"+test+": ");
			
			int R = sc.nextInt();
			int C = sc.nextInt();
			
			StringBuilder[] s = new StringBuilder[R];
			for (int i=0; i<R; i++) {
				s[i] = new StringBuilder(sc.next());
			}
			
			boolean ok = true;
			for (int i=0; i<R-1; i++) {
				for (int j=0; j<C-1; j++) {
					if (s[i].charAt(j)=='#') {
						if (s[i].charAt(j) == '.' || s[i].charAt(j+1) == '.' || s[i+1].charAt(j) == '.' || s[i+1].charAt(j+1) == '.') {
							ok = false;
						}
							
						s[i].setCharAt(j, '/');
						s[i].setCharAt(j+1, '\\');
						s[i+1].setCharAt(j, '\\');
						s[i+1].setCharAt(j+1, '/');
					}
				}
			}
			for (int i=0; i<R; i++) {
				for (int j=0; j<C; j++) {
					if (s[i].charAt(j) == '#') {
						ok = false;
					}
				}
			}
			
			if (!ok) {
				pw.println("Impossible");
			}
			else {
				for (int i=0; i<R; i++) {
					pw.println(s[i]);
				}
			}
			
		}
		pw.close();
	}
}
