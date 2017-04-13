import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Mow {
	public static void main(String[] args) {
		if(args.length == 0) {
			System.out.println("Specify filename!");
			return;
		}
		
		Scanner s = null;
		try {
			s = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			System.out.println("File not found: "+args[0]);
			return;
		}
		
		int cases = s.nextInt();
		
		for(int casenr = 0; casenr < cases; casenr++) {
			new Case(s, casenr);
		}
	}
}

class Case {
	int w, h, lawn[][];
	int xmax[], xmin[];
	int ymax[], ymin[];
	int casenr;
	boolean res;
	
	Case(Scanner s, int casenr) {
		this.casenr = casenr;
		
		System.err.printf("Case %d:\n", casenr+1);
		
		w = s.nextInt();
		h = s.nextInt();
		System.err.printf("%dx%d\n", w, h);
		
		lawn = new int[w][h];
		
		xmax = new int[w];
		xmin = new int[w];
		
		ymax = new int[h];
		ymin = new int[h];
		
		for(int x = 0; x < w; x++) {
			xmin[x] = 100;
		}
		for(int y = 0; y < h; y++) {
			ymin[y] = 100;
		}
		
		for(int x = 0; x < w; x++) {
			for(int y = 0; y < h; y++) {
				lawn[x][y] = s.nextInt();
				checkBounds(x, y);
					
				System.err.printf("[%d]", lawn[x][y]);
			}
			System.err.printf(" %d -> %d", xmin[x], xmax[x]);
			System.err.println();
		}
		for(int x = 0; x < h; x++) {
			System.err.printf(" %d ", ymax[x]);
		}
		System.err.println();
		for(int x = 0; x < h; x++) {
			System.err.printf(" %d ", ymin[x]);
		}
		System.err.println();

		for(int x = 0; x < w; x++) {
			for(int y = 0; y < h; y++) {
				if(lawn[x][y] < xmax[x] && lawn[x][y] < ymax[y]) {
					resNo();
				}
			}
		}
/*		
		String min = "";
		String max = "";
		for(int x = 0; x < w; x++) {
			min += xmin[x] + " ";
			max += xmax[x] + " ";
		}
* /		
		// Simple cases
		if(w < 2 || h < 2) {
			resYes();
			return;
		}
*/		
		resYes();
	}

	private void checkBounds(int x, int y) {
		int lawn = this.lawn[x][y];
		int xmin = this.xmin[x];
		int xmax = this.xmax[x];
		int ymin = this.ymin[y];
		int ymax = this.ymax[y];
		
		if(lawn < xmin) {
			this.xmin[x] = lawn;
		}
		if(lawn > xmax) {
			this.xmax[x] = lawn;
		}
		
		if(lawn < ymin) {
			this.ymin[y] = lawn;
		}
		if(lawn > ymax) {
			this.ymax[y] = lawn;
		}
	}

	void resYes() {
		if(!res) {
			res = true;
			System.out.printf("Case #%d: YES\n", casenr+1);
		}
	}

	void resNo() {
		if(!res) {
			res = true;
			System.out.printf("Case #%d: NO\n", casenr+1);
		}
	}
}
