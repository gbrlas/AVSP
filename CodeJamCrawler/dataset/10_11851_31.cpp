import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	private static final String INPUT = "d:/input.txt";

	private static final String OUTPUT = "d:/output.txt";
	
	private static PrintWriter output;
	
	private static Scanner input;
	
	public static void exec() {
		int R = input.nextInt();
		int n = 120;
		byte[][] a = new byte[n][n];
		byte[][] b = new byte[n][n];
		for (int i = 0; i < R; i++) {
			int x1 = input.nextInt();
			int y1 = input.nextInt();
			int x2 = input.nextInt();
			int y2 = input.nextInt();
			for (int x = x1; x <= x2; x++) {
				for (int y = y1; y <= y2; y++) {
					a[y][x] = 1;
				}
			}
		}
		
		int t = 0;
		int max = 0;
		while (true) {
			t++;

			boolean mark = true;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (a[i][j] > 0) {
						if (a[i - 1][j] == 0 && a[i][j - 1] == 0) {
							b[i][j] = 0;
						} else {
							b[i][j] = a[i][j];
						}
					} else if (i > 0 && j > 0 && a[i - 1][j] == 1 && a[i][j - 1] == 1) {
						b[i][j] = 1;
					} else {
						b[i][j] = 0;
					}
					
					if (b[i][j] > 0) {
						mark = false;
						if (i > max) {
							max = i;
						}
						if (j > max) {
							max = j;
						}
					}
				}
/*			System.out.println("After " + t);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(b[i][j]);
				}
				System.out.println();
			}*/
			if (mark)
				break;
			byte[][] temp = a;
			a = b;
			b = temp;
		}
		System.out.println(max);
		output.print("" + t);
	}

	public static void main(String[] args) throws Exception {
		input = new Scanner(new File(INPUT));
		output = new PrintWriter(new OutputStreamWriter(new FileOutputStream(
				OUTPUT)));
		int n = input.nextInt();
		for (int i = 0; i < n; i++) {
			//System.out.println("case" + i);
			output.print("Case #" + (i + 1) + ": ");
			exec();
			output.println();
		}
		output.close();
		input.close();
	}

}
