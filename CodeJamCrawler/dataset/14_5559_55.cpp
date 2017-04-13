import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Zakhar Voit(zakharvoit@gmail.com)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		DeceitfulWar solver = new DeceitfulWar();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class DeceitfulWar {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt();
        double[] naomi = new double[n];
        double[] ken = new double[n];

        for (int i = 0; i < n; i++) {
            naomi[i] = in.nextDouble();
        }

        for (int i = 0; i < n; i++) {
            ken[i] = in.nextDouble();
        }

        Arrays.sort(naomi);
        Arrays.sort(ken);
        int l = 0;
        int r = n - 1;
        int ans = 0;
        for (double x: naomi) {
            if (x < ken[l]) {
                r--;
            } else {
                ans++;
                l++;
            }
        }

        boolean[] used = new boolean[n];
        int ans2 = 0;
        for (int i = 0; i < n; i++) {
            boolean ok = false;
            for (int j = 0; j < n; j++) {
                if (!used[j] && ken[j] > naomi[i]) {
                    used[j] = true;
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                for (int j = 0; j < n; j++) {
                    if (!used[j]) {
                        used[j] = true;
                        ans2++;
                        break;
                    }
                }
            }
        }

        out.println(ContestUtil.gcjTestNumber(testNumber) + ans + " " + ans2);
    }
}

class Scanner {
    BufferedReader in;
    StringTokenizer tok;

    public Scanner(InputStream in) {
        this.in = new BufferedReader(new InputStreamReader(in));
        tok = new StringTokenizer("");
    }

    public String nextToken() {
        while (!tok.hasMoreTokens()) {
            tok = new StringTokenizer(next());
        }

        return tok.nextToken();
    }

    private String tryReadNextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        String newLine = tryReadNextLine();
        if (newLine == null)
            throw new InputMismatchException();
        return newLine;
    }

    public int nextInt() {
        return Integer.parseInt(nextToken());
    }

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

}

class ContestUtil {
    static public String gcjTestNumber(int test) {
        return "Case #" + test + ": ";
    }
}

