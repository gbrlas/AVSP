import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


/**
 * @author fabrizio
 * 
 */
public class Rotate {

	int n;

	public String getWin(String[] m, int k) {
		n = m.length;
		char[][] r = new char[n][n];
		for (char[] cs : r) {
			Arrays.fill(cs, '.');
		}
		for (int col = n - 1; col >= 0; col--) {
			for (int row = 0; row < n; row++) {
				char c = m[row].charAt(col);
				if (c=='.') continue;
				int ncol = n - 1 - row;
				for (int nrow = n-1; nrow >=0; nrow--) {
					if (r[nrow][ncol] == '.') {
						r[nrow][ncol] = c;
						break;
					}
				}
			}
		}
		
		/*for (int i = 0; i < r.length; i++) {
			System.out.println();
			for (int j = 0; j < r.length; j++) {
				System.out.print(m[i].charAt(j)+" ");
			}
		}
		
		System.out.println();
		
		for (int i = 0; i < r.length; i++) {
			System.out.println();
			for (int j = 0; j < r.length; j++) {
				System.out.print(r[i][j]+" ");
			}
		}
		
		System.out.println();*/

		boolean red = isRow(r, 'R', k);
		boolean blue = isRow(r, 'B', k);
		if (red && blue)
			return "Both";
		if (!red && !blue)
			return "Neither";
		if (red)
			return "Red";
		return "Blue";

	}

	boolean isRow(char[][] r, char c, int k) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int s = 0;
				for (int u = i; u < n; u++) {
					if (r[u][j] != c) {
						break;
					}
					s++;
				}

				if (s >= k) {
					return true;
				}

				s = 0;
				for (int u = j; u < n; u++) {
					if (r[i][u] != c) {
						break;
					}
					s++;
				}

				if (s >= k) {
					return true;
				}

				s = 0;
				for (int u = i, l = j; u < n && l < n; u++, l++) {
					if (r[u][l] != c) {
						break;
					}
					s++;
				}

				if (s >= k) {
					return true;
				}

				s = 0;
				for (int u = i, l = j; u < n && l >= 0; u++, l--) {
					if (r[u][l] != c) {
						break;
					}
					s++;
				}

				if (s >= k) {
					return true;
				}

			}
		}
		return false;

	}

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("A-large.in"));
		PrintWriter p = new PrintWriter("out-large.txt");
		int cases = sc.nextInt();
		for (int c = 1; c <= cases; c++) {
			int n = sc.nextInt();
			int k = sc.nextInt();
			sc.nextLine();
			String[] m = new String[n];
			for (int i = 0; i < m.length; i++) {
				m[i] = sc.nextLine();
			}
			p.println("Case #" + c + ": " + new Rotate().getWin(m, k));
		}
		p.close();
	}

}
