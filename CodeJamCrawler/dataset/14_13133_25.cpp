import java.math.*;
import java.io.*;
import java.util.*;

public class CodeJam {
	
	public static void main(String[] args) throws IOException {
		Scanner s = null;
		PrintWriter w = null;
		try {
			System.out.println(args[0]);
			s = new Scanner(new BufferedReader(new FileReader(args[0])));
			w = new PrintWriter(args[0] + ".out");
			
			//total test cases
			int total = s.nextInt();

			//for each test case
			for(int i=1; i<=total; i++) {
				double c = s.nextDouble();
				double f = s.nextDouble();
				double x = s.nextDouble();
			
				double result = Double.POSITIVE_INFINITY;
				double newResult = x/2;
				double n = 1;
				double prevT = 0;
				double t = 0;
				while(newResult <= result) {
					result = newResult;
					t = prevT + (c/(2+((n-1)*f)));
					
					newResult = t + (x/(2+(n*f)));

					prevT = t;
					n++;
				}

				w.println("Case #"+i+": " + result);
			}

		} finally {
			if(s != null) {
				s.close();
			}

			if(w != null) {
				w.close();
			}
		}
	}
}
