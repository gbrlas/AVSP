import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class Problem1 {
	
	private static final String INPUT = "d:/input.txt";
	
	private static final String OUTPUT = "d:/output.txt";
	
	private static PrintWriter output;
	
	private static Scanner input;
	
	private static void exec() throws Exception {
		int n = input.nextInt();
		int[] a = new int[n];
		int[] b = new int[n]; 
		for (int i = 0; i < n; i++) {
			a[i] = input.nextInt();
			b[i] = input.nextInt();
		}
		new Test();
		HashSet<String> result = new HashSet<String>();
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int tmp = (a[i] - a[j]) * (b[i] - b[j]);
				if (tmp < 0) { // cross
					double x1 = a[i];
					double x2 = a[j];
					double y1 = b[i];
					double y2 = b[j];
					if (a[i] < a[j]) {
						x1 = a[j]; x2 = a[i]; y1 = b[j]; y2 = b[i];
					}
					
					double left = x1 - x2;
					assert(left > 0);
					double right = y2 - y1;
					assert(right > 0);
					
					double xxx = left / (left + right);
					double yyy = 0;
					new Test();
					if (x1 == y1) {
						yyy = x1;
					} else if (x1 > y1) {
						yyy = y1 + (x1 - y1) * right / (left + right);
					} else {
						yyy = x1 + (y1 - x1) * left / (left + right);
					}
					xxx = xxx * 1e12;
					yyy = yyy * 1e8;
					long xx = Math.round(xxx);
					long yy = Math.round(yyy);
					String r = xx + " " + yy;
					//System.out.println(r);
					result.add(r);
				}
			}
		}
		output.print(result.size());
	}
	
	public static class Test {
		int a;
		int b;
		
	}
	
	public static void main(String[] args) throws Exception {
		input = new Scanner(new File(INPUT));
		output = new PrintWriter(new OutputStreamWriter(new FileOutputStream(OUTPUT)));
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			System.out.println(i);	
			output.print("Case #" + (i + 1) + ": ");
			exec();
			output.println();
		}
		output.close();
		input.close();
	}
	

}
