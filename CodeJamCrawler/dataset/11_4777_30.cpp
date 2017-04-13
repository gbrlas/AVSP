import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
//		String f = "test";
//		System.setIn(A.class.getResourceAsStream(f+".in"));
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i<=T; i++) {
			Map<String, Character> combine = new HashMap<String, Character>();
			int C = in.nextInt();
			for(int j=1; j<=C; j++) {
				String s = in.next();
				combine.put(s.substring(0, 2), s.charAt(2));
				s = new StringBuffer(s).reverse().toString();
				combine.put(s.substring(1), s.charAt(0));
			}
			Map<Character, Character> opposed = new HashMap<Character, Character>();
			int D = in.nextInt();
			for(int j=1; j<=D; j++) {
				String s = in.next();
				opposed.put(s.charAt(0),s.charAt(1));
				opposed.put(s.charAt(1),s.charAt(0));
			}
			int N = in.nextInt();
			String s = in.next();
			List<Character> l = new ArrayList<Character>();
			for(char ch : s.toCharArray()) {
				if(l.isEmpty()) {
					l.add(ch);
					continue;
				}
				String op = new StringBuffer().append(l.get(l.size()-1)).append(ch).toString();
				if(combine.containsKey(op)) {
					l.set(l.size()-1, combine.get(op));
					continue;
				}
				if(opposed.containsKey(ch)) {
					if (l.contains(opposed.get(ch))) {
						l.clear();
						continue;
					}
				} 
				l.add(ch);
			}
			System.out.println("Case #"+i+": "+l);
		}
	}
}
