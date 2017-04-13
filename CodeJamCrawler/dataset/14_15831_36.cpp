import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class A {
	String inFile = "A.in";
	String outFile = "A.out";
	Scanner sc;
	PrintWriter pw;
	
	void init() throws FileNotFoundException {
		sc = new Scanner(new File(inFile));
		pw = new PrintWriter(new File(outFile));
	}
	
	HashSet<Integer> getCandidates() {
		int r = sc.nextInt();
		HashSet<Integer> candidates = new HashSet<Integer>();
		for (int i=1; i<=4; i++) {
			for (int j=1; j<=4; j++) {
				int c = sc.nextInt();
				if (i == r) {
					candidates.add(c);
				}
			}
		}
		return candidates;
	}
	
	void solve(int test) {
		HashSet<Integer> set1 = getCandidates();
		HashSet<Integer> set2 = getCandidates();
		HashSet<Integer> set = new HashSet<Integer>();
		
		for (int number: set1) {
			if (set2.contains(number)) {
				set.add(number);
			}
		}

		pw.print(String.format("Case #%d: ", test));
		if (set.size() == 0) {
			pw.println("Volunteer cheated!");
		}
		else if (set.size() == 1) {
			pw.println(set.iterator().next());
		}
		else {
			pw.println("Bad magician!");
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
