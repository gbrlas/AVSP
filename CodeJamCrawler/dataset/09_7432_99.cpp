import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class qualify2009B {
	public static void main(String[] args) throws Exception {
		new qualify2009B();
	}

	public qualify2009B() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_b.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-B.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			height = scan.nextInt();
			width = scan.nextInt();
			alt = new int[height][width];
			for ( int r = 0; r < height; r++)
				for ( int c = 0; c < width; c++) 
					alt[r][c] = scan.nextInt();
			sink = new int[height][width];
			for ( int[] a: sink) Arrays.fill(a, -1);
			for ( int r = 0; r < height; r++)
				for ( int c = 0; c < width; c++) {
					if ( sink[r][c] == -1 ) go(r,c);
				}
			int index = 0;
			char[] sinkcode = new char[height*width];
			Arrays.fill(sinkcode, '.');
			out.printf("Case #%d:\n", test + 1);
			System.out.printf("Case #%d:\n", test + 1);
			for ( int r = 0; r < height; r++) {
				for ( int c = 0; c < width; c++) {
					char z = sinkcode[sink[r][c]];
					if ( z == '.') {
						sinkcode[sink[r][c]] = (char)('a'+index);
						index++;
						z = sinkcode[sink[r][c]];
					}
					out.print(z);
					System.out.print(z);
					if ( c < width -1) {
						out.print(' ');
						System.out.print(' ');
					}
				}
				out.print('\n');
				System.out.print('\n');
			}
			
			System.out.println("test case " + test);
		}
		out.close();
	}
	
	public int go(int r, int c) {
		if ( sink[r][c] >= 0 ) return sink[r][c];
		int best = alt[r][c];
		int bestIndex = -1;
		for ( int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= height || nc < 0 || nc >= width)
				continue;
			if ( alt[nr][nc] < best) {
				best = alt[nr][nc];
				bestIndex = i;
			}
		}
		if ( bestIndex == -1) {
			sink[r][c] = width*r + c;
		} else {
			sink[r][c] = go(r+dr[bestIndex], c+dc[bestIndex]);
		}
		return sink[r][c];
	}
	
	int[] dc = {0,-1,1,0};
	int[] dr = {-1,0,0,1};
	
	int height, width;
	int[][] alt;
	int[][] sink;
}
