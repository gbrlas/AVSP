import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;


public class A {
	Scanner sc;
	PrintStream ps;

	public void run(String[] args) throws FileNotFoundException {
		sc = new Scanner(new File("A.in"));
		ps = System.out; // new PrintWriter("A.out");
		
		String s1 = "yeq ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String s2 = "aoz our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		
		boolean[] existsK = new boolean[256];
		boolean[] existsV = new boolean[256];

		HashMap<Character, Character> h = new HashMap<Character, Character>();
		for (int i=0; i<s1.length(); i++) {
			h.put(s1.charAt(i), s2.charAt(i));
		}
		for (char c='a'; c<='z'; c++) {
			if (h.get(c) != null) {
				existsK[(int)c] = true;
				existsV[(int)h.get(c)] = true;
			}
		}
		char ck='0', cv='0';
		for (char c='a'; c<='z'; c++) {
			if (!existsK[(int)c]) ck = c;
			if (!existsV[(int)c]) cv = c;
		}
		h.put(ck, cv);
		
		int num_tests = sc.nextInt();
		sc.nextLine();
		
		for (int test=1; test<=num_tests; test++) {
			ps.print("Case #"+test+": ");
			String l = sc.nextLine();
			char[] r = new char[l.length()];
			for (int i=0; i<l.length(); i++) {
				r[i] = h.get(l.charAt(i));
			}
			ps.println(new String(r));
		}
		ps.close();
		
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		A a = new A();
		a.run(args);
	}
}
