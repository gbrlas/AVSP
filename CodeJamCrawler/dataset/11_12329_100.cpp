import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class D {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("D.in"));
		PrintWriter pw = new PrintWriter("D.out");
		int t = s.nextInt();
		for (int test=1; test<=t; test++) {
			pw.print("Case #"+test+": ");
			int n = s.nextInt();
			int rez = 0;
			for (int i=0; i<n; i++)
				if (i != s.nextInt()-1) rez++; 
			
			pw.printf("%6.6f", (double)rez);
			pw.println();
		}
		pw.close();
	}
}
