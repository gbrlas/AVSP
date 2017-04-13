import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class Problem3 {
	private static final String INPUT = "d:/input.txt";
	
	private static final String OUTPUT = "d:/output.txt";
	
	private static PrintWriter output;
	
	private static Scanner input;
	
	private static void set(int[][] b, int x, int y, int value) {
		if (x >= 0 && y >= 0) {
			b[x][y] = Math.min(b[x][y], value);
		}
	}
	
	private static void exec() throws Exception {
		int m = input.nextInt();
		int n = input.nextInt();
		input.nextLine();
		int[][] a = new int[m][n];
		int tot = 0;
		for (int i = 0; i < m; i++) {
			String line = input.nextLine();
			assert(line.length() * 4 == n);
			char[] c = line.toCharArray();
			for (int j = 0; j < c.length; j++) {
				int v = Integer.parseInt("" + c[j], 16);
				a[i][j * 4] = v / 8;
				a[i][j * 4 + 1] = v / 4 % 2;
				a[i][j * 4 + 2] = v / 2 % 2;
				a[i][j * 4 + 3] = v % 2;
			}
		}
		int[][] b = new int[m][n];
		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				b[i][j] = 1;
				if (i < m - 1 && j < n - 1) {
					if (a[i][j] == a[i + 1][j + 1] && 
						a[i + 1][j] == a[i][j + 1] &&
						a[i][j] != a[i + 1][j]) {
						b[i][j] = Math.min(Math.min(b[i + 1][j + 1], b[i][j + 1]), b[i + 1][j]) + 1; 
					}
				}
			}
		}
/*		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(b[i][j] + " ");
			}
			System.out.println();
		}
*/		
		int w = Math.min(m, n);
		int[] r = new int[w + 1];
		tot = 0;
		while (true) {
			int x = -1;
			int y = -1;
			int max = 0;
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++) {
					if (b[i][j] != -1 && max < b[i][j]) {
						max = b[i][j];
						x = i;
						y = j;
					}
				}
			if (max == 0)
				break;
			if (max == 1) {
				
				int ttt = 0;
				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++) {
						if (b[i][j] != -1) {
							ttt++;
						}
					}
				r[1] = ttt;
				break;
			}
			tot += max * max;
			r[max]++;
			System.out.println(max + " " + tot);
//			System.out.println("Get " + max + " at [" + x + "," + y + "]");
			for (int i = x; i < x + max; i++) {
				for (int j = y; j < y + max; j++) {
					b[i][j] = -1;
				}
			}
			for (int s = 1; s < max; s++) {
				int xx = x - s;
				int yy = y - s;
				for (int j = yy; j < y + max; j++) {
					set(b, xx, j, s);
				}
				for (int i = xx; i < x + max; i++) {
					set(b, i, yy, s);
				}
			}
		}
		int count = 0;
		for (int t = w; t >= 1; t--) {
			if (r[t] > 0) {
				count++;
			}
		}
		output.print(count);
		for (int t = w; t >= 1; t --) {
			if (r[t] > 0) {
				output.println();
				output.print(t + " " + r[t]);
			}
		}
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
