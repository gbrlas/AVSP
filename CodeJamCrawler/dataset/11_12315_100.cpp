import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Vector;


public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("B.in"));
		PrintWriter pw = new PrintWriter("B.out");
		int t = s.nextInt();
		for (int test=1; test<=t; test++) {
			pw.print("Case #"+test+": ");
			
			HashMap<String, Character> h1 = new HashMap<String, Character>();
			HashSet<String> h2 = new HashSet<String>();
			
			int c = s.nextInt();
			for (int i=0; i<c; i++) {
				String str = s.next();
				h1.put("" + str.charAt(0) + str.charAt(1), str.charAt(2));
				h1.put("" + str.charAt(1) + str.charAt(0), str.charAt(2));
			}
			
			int d = s.nextInt();
			for (int i=0; i<d; i++) {
				String str = s.next();
				h2.add("" + str.charAt(0) + str.charAt(1));
				h2.add("" + str.charAt(1) + str.charAt(0));
			}
			
			int n = s.nextInt();
			String str = s.next();
			char prev = '_';
			
			Vector<Character> v = new Vector<Character>();
			for (int i=0; i<n; i++) {
				char ch = str.charAt(i);
				String l2 = ""+prev+ch;
				
				if (h1.containsKey(l2)) {
					v.remove(v.size()-1);
					v.add(h1.get(l2));
					prev = h1.get(l2);
				}
				else {
					boolean r = false;
					for (int j=0; j<v.size(); j++) {
						String g = "" + v.get(j) + ch;
						if (h2.contains(g)) {
							r = true;
							break;
						}
					}
					if (r) {
						v = new Vector<Character>();
						prev = '_';
					}				
					else {
						v.add(ch);
						prev = ch;
					}
				}
			}
			pw.println(v);
		}
		pw.close();
	}
}
