import java.util.*;

public class ProblemA {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int l = in.nextInt();
		int d = in.nextInt();
		int n = in.nextInt();
		String[] a = new String[d];
		for (int i = 0; i < d; ++i)
			a[i] = in.next();
		for (int i = 0; i < n; ++i) {
			System.out.println("Case #" + (i + 1) + ": " + solve(a, in.next()));
		}
	}

	private static int solve(String[] a, String pat) {
		pat = pat.replaceAll("\\(", "\\[").replaceAll("\\)", "\\]");
		// System.out.println(Arrays.toString(a) + "\t" + pat);
		int ans = 0;
		for (String s : a)
			if (s.matches(pat))
				++ans;
		return ans;
	}

}
