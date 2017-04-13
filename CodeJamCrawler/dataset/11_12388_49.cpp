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
			if (n==1) {
				pw.println(0);
				continue;
			}
			// max
			int max = 1;
			boolean call;
			HashMap<Integer, Integer> h = new HashMap();
			for (int i=2; i<=n; i++) {
				int ci = i;
				call = false;
				for (int j=2; j<=i; j++) {
					int pow = 0;
					while (ci % j == 0) {
						ci /= j;
						pow++;
					}
					if (pow>0) {
						Integer ep = h.get(j);
						if (ep==null) ep = 0;
						
//						System.out.println(i + " " + j + " " + pow);
						if (pow > ep) {
							call = true;
							h.put(j, pow);
						}
					}
				}
				if (call) {
//					System.out.println("max " + i );
					max++;
				}
			}
			
			int min = h.keySet().size();
			
/*			
			// min
			int min = 0;
			h = new HashMap();
			for (int i=n; i>=2; i--) {
				int ci = i;
				call = false;
				for (int j=2; j<=i; j++) {
					int pow = 0;
					while (ci % j == 0) {
						ci /= j;
						pow++;
					}
					if (pow>0) {
						Integer ep = h.get(j);
						if (ep==null) ep = 0;
						
						if (pow > ep) {
							call = true;
							h.put(j, pow);
						}
					}
				}
				if (call) {
//					System.out.println("min " + i );
					min++;
				}
			}
*/			
			
			pw.println(max - min);
		}
		pw.close();
	}
}
