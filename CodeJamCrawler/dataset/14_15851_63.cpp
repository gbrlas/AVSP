import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Vector;


public class A {
	String inFile = "A.in";
	String outFile = "A.out";
	Scanner sc;
	PrintWriter pw;
	
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	public String reduceString(String s) {
		String r = "" + s.charAt(0);
		for (int i=1; i<s.length(); i++) {
			if (s.charAt(i) != s.charAt(i-1)) {
				r += s.charAt(i);
			}
		}
		return r;
	}
	
	public Vector<Integer> getType(String s) {
		Vector<Integer> v = new Vector<Integer>();
		
		int nr = 1;
		for (int i=1; i<s.length(); i++) {
			if (s.charAt(i) != s.charAt(i-1)) {
				v.add(nr);
				nr = 0;
			}
			nr++;
		}
		v.add(nr);
		return v;
	}
	
	void solve(int test) {
		System.out.println(test);
		
		int n = sc.nextInt();
		sc.nextLine();
		Vector<Vector<Integer>> v = new Vector<Vector<Integer>>();
		
		String s1 = sc.nextLine();
		
		String t1 = reduceString(s1);
		Vector<Integer> n1 = getType(s1);
		v.add(n1);
		System.out.println(s1 + " " + t1 + " " + n1);
		
		boolean ok = true;
		for (int i=1; i<n; i++) {
			String s = sc.nextLine();
			String t = reduceString(s);
			Vector<Integer> v_crt = getType(s);
			v.add(v_crt);
			
			System.out.println(s + " " + t + " " + v_crt);
			
			if (!t.equals(t1)) {
				ok = false;
			}
		}
		
		pw.print(String.format("Case #%d: ", test));
		if (!ok) {
			pw.println("Fegla Won");
		}
		else {
			
			if (n != v.size()) throw new RuntimeException();
			
			int total = 0;
			for (int pos=0; pos<v.get(0).size(); pos++) {
				int minMoves = 1000;
				
				for (int candidate = 0; candidate < 110; candidate++) {
					int moves = 0;
					for (int i=0; i<n; i++) {
						moves += Math.abs(candidate - v.get(i).get(pos));
					}
					if (moves < minMoves) {
						minMoves = moves;
					}
				}
				total += minMoves;
			}
			
			pw.println(total);
		}
	}
	
	
	void run() throws FileNotFoundException {
		init();
		
		int T = sc.nextInt();
		for (int test=1; test<=T; test++) {
			solve(test);
		}
		pw.close();
		sc.close();	
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		A t = new A();
		t.run();
	}
}
