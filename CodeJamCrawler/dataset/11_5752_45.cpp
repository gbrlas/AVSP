package gcj2011.qualificationround;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Magicka {

	public static void main(String[] args) throws Exception {
		
		final char[] baseElements = {'Q', 'W', 'E', 'R', 'A', 'S', 'D', 'F'};
		
		Scanner s = new Scanner(new File("data/gcj2011/qualificationround/B-small-attempt0.in"));
		int T = s.nextInt();
		for (int t=1; t<=T; t++) {
			
			Map<String, Character> combine = new HashMap<String, Character>();
			
			Map<Character, Set<Character>> opposed = new HashMap<Character, Set<Character>>();
			for (char e : baseElements) {
				opposed.put(e, new HashSet<Character>());
			}
			
			int C = s.nextInt();
			for (int c=1; c<=C; c++) {
				char[] elems = s.next().toCharArray();
				combine.put(String.format("%c%c", elems[0], elems[1]), elems[2]);
				combine.put(String.format("%c%c", elems[1], elems[0]), elems[2]);
			}
//			System.out.println(combine);
			
			int D = s.nextInt();
			for (int d=1; d<=D; d++) {
				char[] elems = s.next().toCharArray();
				opposed.get(elems[0]).add(elems[1]);
				opposed.get(elems[1]).add(elems[0]);
			}
//			System.out.println(opposed);
			
			List<Character> elemlist = new ArrayList<Character>();
			
			int N = s.nextInt();
			char[] elems = s.next().toCharArray();
			for (char e : elems) {
				
				// invoke element
				elemlist.add(e);
//				System.out.printf("invoke %c; now have %s%n", e, elemlist);
				
				// >= 2 elements in list, so could combine
				if (elemlist.size() >= 2) {
					
					int numelems = elemlist.size();
					String lastTwo = String.format("%c%c", elemlist.get(numelems-1), elemlist.get(numelems-2));
//					System.out.printf("last two: %s%n", lastTwo);
					if (combine.containsKey(lastTwo)) {
						elemlist.remove(numelems-1);
						elemlist.remove(numelems-2);
						elemlist.add(combine.get(lastTwo));
//						System.out.printf("  %s combined; now have %s%n", lastTwo, elemlist);
					}
					
					else {
						Set<Character> opposedTo = new HashSet<Character>(opposed.get(e));
						opposedTo.retainAll(elemlist);
						if (!opposedTo.isEmpty()) {
							elemlist.clear();
						}
//						System.out.printf("elems in list opposed: %s %s%n", opposed.get(e), opposedTo);
					}
				}
			}
			System.out.printf("Case #%d: %s%n", t, elemlist);
		}
	}

}
