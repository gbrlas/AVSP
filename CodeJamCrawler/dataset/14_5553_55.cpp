import java.io.InputStreamReader;
import java.io.IOException;
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
		CookieClickerAlpha solver = new CookieClickerAlpha();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class CookieClickerAlpha {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        double c = in.nextDouble();
        double f = in.nextDouble();
        double x = in.nextDouble();
        double rate = 2;
        double time = 0;

        double best = Double.MAX_VALUE;
        while (true) {
            double winTime = time + x / rate;
            if (DoubleUtils.less(winTime, best)) {
                best = winTime;
            }

            time += c / rate;
            rate += f;
            if (DoubleUtils.great(time, best)) {
                break;
            }
        }

        out.println(ContestUtil.gcjTestNumber(testNumber) + String.format("%.7f", best));
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

    public double nextDouble() {
        return Double.parseDouble(nextToken());
    }

}

class DoubleUtils {
    static private double EPS = 1e-9;

    static public boolean equal(double a, double b) {
        return Math.abs(b - a) < EPS;
    }

    static public boolean less(double a, double b) {
        return a < b && !equal(a, b);
    }

    static public boolean great(double a, double b) {
        return a > b && !equal(a, b);
    }

}

class ContestUtil {
    static public String gcjTestNumber(int test) {
        return "Case #" + test + ": ";
    }
}

