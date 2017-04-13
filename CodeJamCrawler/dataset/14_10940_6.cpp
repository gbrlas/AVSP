package codejam._2014.magic_trick;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(br.readLine());

		for (int t = 0; t < T; t++) {
			int r1 = Integer.parseInt(br.readLine());
			String[] g1 = new String[4];
			for (int r = 0; r < 4; r++) {
				g1[r] = br.readLine();
			}
			int r2 = Integer.parseInt(br.readLine());
			String[] g2 = new String[4];
			for (int r = 0; r < 4; r++) {
				g2[r] = br.readLine();
			}

			solve(t + 1, r1 - 1, r2 - 1, g1, g2);
		}

	}

	private static void solve(int t, int r1, int r2, String[] g1, String[] g2) {

		Set<Integer> s1 = new HashSet<Integer>();

		String[] st = g1[r1].split(" ");
		for (int i = 0; i < st.length; i++) {
			s1.add(Integer.parseInt(st[i]));
		}

		Set<Integer> s2 = new HashSet<Integer>();
		st = g2[r2].split(" ");
		for (int i = 0; i < st.length; i++) {
			s2.add(Integer.parseInt(st[i]));
		}

		s1.retainAll(s2);
		if (s1.size() == 0) {
			System.out.printf("Case #%d: %s\n", t, "Volunteer cheated!");
		} else if (s1.size() > 1) {
			System.out.printf("Case #%d: %s\n", t, "Bad magician!");
		} else {
			Object[] res = s1.toArray();
			System.out.printf("Case #%d: %d\n", t, res[0]);
		}
	}
}
