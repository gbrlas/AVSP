import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class ProblemC {
	String PROBLEM_ID = "problemC";
	enum TestType { EXAMPLE, SMALL, LARGE }
//	TestType TYPE = TestType.EXAMPLE;
	TestType TYPE = TestType.SMALL;
	public String getFileName() {
		String result = PROBLEM_ID + "_";
		switch ( TYPE ) {
		case EXAMPLE: result += "example"; break;
		case SMALL:   result += "small"; break;
		case LARGE:   result += "large"; break;
		}
		return result;
	}
	public String getInFileName() { return getFileName() + ".in"; }
	public String getOutFileName() { return getFileName() + ".out"; }
	
	public static void main(String[] args) throws Exception {
		new ProblemC();
	}
	
	public ProblemC() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(getInFileName()));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(getOutFileName())));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			n = scan.nextInt();
			int m = scan.nextInt();
			int[] u = new int[m];
			for ( int i =0; i < m; i++) u[i] = scan.nextInt();
			int[] v = new int[m];
			for ( int i = 0; i < m; i++) v[i] = scan.nextInt();
			Polygon all = new Polygon(n);
			list = new ArrayList<Polygon>();
			list.add(all);
			for ( int i =0; i < m; i++) {
				ArrayList<Polygon> next = new ArrayList<Polygon>();
				for (Polygon p: list) {
					if (p.doesSplit(u[i], v[i])) {
						Polygon[] split = p.split(u[i], v[i]);
						next.add(split[0]);
						next.add(split[1]);
					} else next.add(p);
				}
				list = next;
			}
//			for (Polygon p: list) System.out.println(p);
			color = new int[n];
			okColor = new int[n];
			usedColor = new boolean[n+2];
			maxScore = 0;
			go(0, 0);
			
			String resultStr = String.format("Case #%d: ", test+1);
			// add answer here
			resultStr += maxScore + "\n";
			for ( int i = 0; i < n; i++) {
				resultStr += okColor[i];
				if ( i < n-1) resultStr += " ";
			}
			System.out.println(resultStr);
			out.println(resultStr);
		}
		out.close();
		System.out.println("*** in file =  " + getInFileName());
		System.out.println("*** out file = " + getOutFileName());
	} 
	
	int n;
	int[] color;
	int[] okColor;
	int maxScore = 0;
	boolean[] usedColor;
	ArrayList<Polygon> list;
	public void go(int index, int maxNr) {
		if ( index == n) {
			if ( maxNr <= maxScore) return;
			for ( Polygon p:list) {
				Arrays.fill(usedColor, false);
				for ( int a: p.elements) usedColor[color[a-1]] = true;
				boolean ok = true;
				for ( int i = 1; i <= maxNr; i++) ok &= usedColor[i];
				if ( !ok ) return;
			}
			maxScore = maxNr;
			for ( int i =0; i < n; i++) okColor[i] = color[i];
			
			// check
		} else {
			for ( int i = 1; i <= maxNr; i++) {
				color[index] = i;
				go(index+1, maxNr);
			}
			color[index] = maxNr+1;
			go(index + 1, maxNr+1);
		}
		
	}
	
	class Polygon {
		int[] elements;
		boolean[] hasElt;
		public Polygon(int size) {
			elements = new int[size];
			hasElt = new boolean[size+1];
			for ( int i = 0; i < size; i++) {
				elements[i] = i+1;
				hasElt[i+1] = true;
			}
		}
		public Polygon(int[] elts, int size) {
			elements = elts;
			hasElt = new boolean[size+1];
			for ( int e: elements) hasElt[e] = true;
		}
		public boolean doesSplit(int u, int v) {
			return hasElt[u] && hasElt[v];
		}
		
		public Polygon[] split(int u, int v) {
			Polygon[] result = new Polygon[2];
			result[0] = splitPart(u,v);
			result[1] = splitPart(v,u);
			return result;			
		}
		public String toString() { return Arrays.toString(elements); }
		
		Polygon splitPart(int u, int v) {
			ArrayList<Integer> newElts = new ArrayList<Integer>();
			int index = 0;
			int n = elements.length;
			while ( index < n && elements[index] != u) index ++;
			while ( elements[index] != v) {
				newElts.add(elements[index]);
				index = (index+1) % n;
			}
			newElts.add(v);
			int[] part = new int[newElts.size()];
			index = 0;
			for ( int a: newElts) part[index++] = a;
			return new Polygon(part, hasElt.length-1);
			
		}
	}

}
