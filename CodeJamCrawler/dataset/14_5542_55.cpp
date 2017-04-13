import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
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
		MagicTrick solver = new MagicTrick();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class MagicTrick {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int n = in.nextInt() - 1;
        int[][] a = new int[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                a[i][j] = in.nextInt() - 1;
            }
        }

        int m = in.nextInt() - 1;
        int[] pos = new int[16];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                pos[in.nextInt() - 1] = i;
            }
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            int c = a[n][i];
            if (pos[c] == m) {
                ans.add(c + 1);
            }
        }

        if (ans.size() == 0) {
            out.println(ContestUtil.gcjTestNumber(testNumber) + "Volunteer cheated!");
        } else if (ans.size() > 1) {
            out.println(ContestUtil.gcjTestNumber(testNumber) + "Bad magician!");
        } else {
            out.println(ContestUtil.gcjTestNumber(testNumber) + ans.get(0));
        }
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

}

class ContestUtil {
    static public String gcjTestNumber(int test) {
        return "Case #" + test + ": ";
    }
}

