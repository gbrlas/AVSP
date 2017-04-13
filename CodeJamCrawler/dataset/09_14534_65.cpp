import java.math.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i = 0; i < n; ++i) {
			String s = in.next();
			TreeSet<Character> ss = new TreeSet<Character>();
			for (int j = 0; j < s.length(); ++j)
				ss.add(s.charAt(j));
			int base = ss.size();
			char[] ans = new char[s.length()];
			Arrays.fill(ans, '_');
			int k = 0;
			if (i == 10) {
				// System.out.println("CRAP!!!");
			}
			for (int j = 0; j < s.length(); ++j)
				if (s.charAt(j) == s.charAt(k))
					ans[j] = '1';
			for (k = 0; k < base; ++k) {
				if (k == 1)
					continue;
				int j = 0;
				for (j = 0; j < ans.length; ++j)
					if (ans[j] == '_')
						break;
				if (j == ans.length)
					break;
				int kk = j;
				for (j = 0; j < ans.length; ++j)
					if (s.charAt(j) == s.charAt(kk))
						ans[j] = (char) ((k >= 10) ? ('a' + k - 10) : ('0' + k));
			}
			StringBuilder sb = new StringBuilder();
			for (char c : ans)
				sb.append(c);
			// System.out.println(sb.toString() + "\t" + base);
			base = Math.max(base, 2);
			BigInteger ret = new BigInteger(sb.toString(), base);
			System.out.println("Case #" + (i + 1) + ": " + ret.toString());
		}

	}
}
