import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("A.in"));
		PrintWriter pw = new PrintWriter("A.out");
		int t = s.nextInt();
		for (int test=1; test<=t; test++) {
			pw.print("Case #"+test+": ");
			
			int total = 0;
			int[] tp = {0,0};
			int[] pp = {1,1};
			
			int n = s.nextInt();
			for (int i=0; i<n; i++) {
				String str = s.next();
				int p=0; 
				if (str.equals("B")) p = 1;
				int pos = s.nextInt();
				int time = Math.abs(pos - pp[p]);
				time = Math.max(1, time - tp[p] + 1);
				total += time;
				
				tp[p] = 0;
				tp[1-p] += time;
				
				pp[p] = pos;
			}
			pw.println(total);
		}
		pw.close();
	}
}
