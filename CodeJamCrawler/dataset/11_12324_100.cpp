import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("C.in"));
		PrintWriter pw = new PrintWriter("C.out");
		int t = s.nextInt();
		for (int test=1; test<=t; test++) {
			pw.print("Case #"+test+": ");
			
			int n = s.nextInt();
			int totalX = 0;
			int totalR = 0;
			int min = Integer.MAX_VALUE;
			
			for (int i=0; i<n; i++) {
				int v = s.nextInt();
				totalX ^= v;
				totalR += v;
				if (v<min) min=v;
			}
			
			if (totalX == 0)
				pw.println(totalR - min);
			else
				pw.println("NO");
		}
		pw.close();
	}
}
