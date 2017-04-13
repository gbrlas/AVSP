import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author Mark Devine
 * 
 */
public class B {
	static final boolean DEBUG = false;
	static Scanner in;
	static List<PrintStream> out;

	public static void main(String[] args) throws FileNotFoundException {
		out = new ArrayList<PrintStream>();
		out.add(System.out);
		if (DEBUG) {
			in = new Scanner(new File("t"));
		} else {
			in = new Scanner(new File(B.class.getName() + ".in"));
			out.add(new PrintStream(B.class.getName() + ".out"));
		}
		int T = i();
		for (int i = 0; i < T; i++) {
			pf("Case #%d: %s\n", i + 1, solve());
		}
		System.out.println("Done");
		in.close();
		for (PrintStream ps : out) {
			ps.close();
		}
	}

	static String solve() {
		int N = i();
		int M = i();
		int[][] lawn = new int[N][M];
		int[] NHeights = new int[N];
		int[] MHeights = new int[M];

		for (int i = 0; i < N; i++) {
			NHeights[i] = 0;
			for (int j = 0; j < M; j++) {
				lawn[i][j] = i();
				NHeights[i] = Math.max(lawn[i][j], NHeights[i]);
			}
		}
		for (int j = 0; j < M; j++) {
			MHeights[j] = 0;
			for (int i = 0; i < N; i++) {
				MHeights[j] = Math.max(lawn[i][j], MHeights[j]);
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (lawn[i][j] < Math.min(NHeights[i], MHeights[j])) {
					return "NO";
				}
			}
		}

		return "YES";
	}

	static void p(String x) {
		for (PrintStream ps : out) {
			ps.print(x);
		}
	}

	static void pl(String x) {
		for (PrintStream ps : out) {
			ps.println(x);
		}
	}

	static void pf(String format, Object... args) {
		for (PrintStream ps : out) {
			ps.printf(format, args);
		}
	}

	static String f(String format, Object... args) {
		return String.format(format, args);
	}

	static int i() {
		return in.nextInt();
	}

	static long l() {
		return in.nextLong();
	}

	static String s(String pattern) {
		return in.next(pattern);
	}

	static String li() {
		return in.nextLine();
	}
}