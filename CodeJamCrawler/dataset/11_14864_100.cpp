import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new File("B.out"));
		int testsNumber = sc.nextInt();
		for (int test = 0; test < testsNumber; test++) {
			System.err.println("Test #" + test);
			int c = sc.nextInt();
			Pair[] combine = new Pair[c];
			for (int i = 0; i < c; i++) {
				combine[i] = new Pair(sc.next());
			}
			int d = sc.nextInt();
			Pair[] oppose = new Pair[d];
			for (int i = 0; i < d; i++) {
				oppose[i] = new Pair(sc.next());
			}
			sc.next();
			String toInvoke = sc.next();
			out.println("Case #" + (test + 1) + ": "
					+ solve(combine, oppose, toInvoke));
		}
		out.close();
	}

	static final int ALPHABET = 26;

	private static String solve(Pair[] combine, Pair[] oppose, String toInvoke) {
		Map<Pair, Character> good = new HashMap<Pair, Character>();
		for (Pair p : combine) {
			good.put(p, p.c0);
		}
		Set<Pair> bad = new HashSet<Pair>(Arrays.asList(oppose));
		ArrayList<Character> list = new ArrayList<Character>();
		int[] was = new int[ALPHABET];
		Deque<Character> q = new ArrayDeque<Character>();
		for (char c : toInvoke.toCharArray()) {
			q.addLast(c);
		}
		all: while (!q.isEmpty()) {
			char c = q.pollFirst();
			if (!list.isEmpty()) {
				char d = list.get(list.size() - 1);
				if (good.containsKey(new Pair(c, d))) {
					was[d - 'A']--;
					list.remove(list.size() - 1);
					Character e = good.get(new Pair(c, d));
					q.addFirst(e);					
					continue all;
				}
			}
			for (char d = 'A'; d <= 'Z'; d++) {
				if (was[d - 'A'] == 0) {
					continue;
				}
				if (bad.contains(new Pair(c, d))) {
					Arrays.fill(was, 0);
					list.clear();
					continue all;
				}
			}
			list.add(c);
			was[c - 'A']++;
		}
		return list.toString();
	}

	static class Pair {
		char c1;
		char c2;
		char c0;

		public Pair(String s) {
			this(s.charAt(0), s.charAt(1), s.substring(2).toCharArray());
		}

		public Pair(char c1, char c2, char... c0) {
			super();
			if (c1 > c2) {
				char t = c1;
				c1 = c2;
				c2 = t;
			}
			this.c1 = c1;
			this.c2 = c2;
			this.c0 = c0.length == 0 ? 0 : c0[0];
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + c1;
			result = prime * result + c2;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (c1 != other.c1)
				return false;
			if (c2 != other.c2)
				return false;
			return true;
		}

	}

}
