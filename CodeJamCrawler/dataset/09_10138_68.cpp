import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.regex.Pattern;

public class B implements Runnable {

    private class TestCaseSolver {

        private BigInteger solve(String s, String min) {
            BigInteger n = new BigInteger(min);

            char[] c = s.toCharArray();

            BigInteger result = null;
            for (int i = 0; i < c.length; i++) {
                for (int j = 0; j < c.length; j++) {
                    char x;
                    
                    x = c[i]; c[i] = c[j]; c[j] = x;

                    BigInteger cur = new BigInteger(new String(c));
                    if (cur.compareTo(n) > 0) {
                        if (result == null || cur.compareTo(result) < 0) {
                            result = cur;
                        }
                    }

                    x = c[i]; c[i] = c[j]; c[j] = x;
                }
            }

            return result;
        }

        private void solve() {
            String s = nextToken();

            BigInteger result = stupid(s, s);
            if (result == null) {
                result = stupid(s + "0", s);
            }

            out.print(" " + result);
        }

        char[] c, cClone;
        int[] digits;
        BigInteger result, n;

        private BigInteger stupid(String s, String min) {
            c = s.toCharArray();
            cClone = new char[c.length];

            digits = new int[10];
            for (char x : c) {
                digits[x - '0']++;
            }

            n = new BigInteger(min);
            rec(0);

            return result;
        }

        private void rec(int pos) {
            if (pos >= cClone.length) {
                BigInteger cur = new BigInteger(new String(cClone));
                if ((cur.compareTo(n) > 0) && (result == null || cur.compareTo(result) < 0)) {
                    result = cur;
                }
                return;
            }

            for (int d = 0; d < 10; d++)
                if (digits[d] > 0) {
                    cClone[pos] = (char) ('0' + d);
                    digits[d]--;

                    rec(pos + 1);

                    digits[d]++;
                }
        }

    }

    private BufferedReader in;
    private PrintWriter out;

    private StringTokenizer tokenizer = new StringTokenizer("");

    private String nextToken() {
        while (!tokenizer.hasMoreTokens()) {
            String line;
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new IllegalStateException(e);
            }
            if (line == null) {
                return null;
            }
            tokenizer = new StringTokenizer(line);
        }
        return tokenizer.nextToken();
    }

    private String nextLine() {
        try {
            return in.readLine();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    private int nextInt() {
        return Integer.parseInt(nextToken());
    }

    private int estimatedTimeLeft(int tc, int tCount, long timeStart) {
        long time = System.currentTimeMillis();
        double timePerTest = (1.0 * (time - timeStart)) / tc;
        return (int) (timePerTest * (tCount - tc) / 1000.0);
    }

    private void solve(File inFile) {
        long timeStart = System.currentTimeMillis();

        try {
            in = new BufferedReader(new FileReader(inFile));
            out = new PrintWriter(new FileWriter(inFile.getName() + ".out"));
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }

        int tCount = nextInt();
        for (int tc = 0; tc < tCount; tc++) {
            System.out.print("Solving test case #" + (tc + 1) + "/" + tCount);
            if (tc > 0) {
                System.out.print(", estimated time left: " + estimatedTimeLeft(tc, tCount, timeStart) + " sec");
            }
            System.out.println();

            out.print("Case #" + (tc + 1) + ":");
            new TestCaseSolver().solve();
            out.println();
        }

        try {
            in.close();
            out.close();
        } catch (IOException e) {
            throw new IllegalStateException(e);
        }
    }

    public void run() {
        final Pattern inPattern = Pattern.compile("^" + Pattern.quote(getClass().getSimpleName()) + "\\-.*\\.in$", Pattern.CASE_INSENSITIVE);
        final File[] inFiles = new File(".").listFiles(
            new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return inPattern.matcher(name).matches();
                }
            }
        );
        for (File inFile : inFiles) {
            System.out.println("Solving [" + inFile.getName() + ']');
            solve(inFile);
        }
    }

    public static void main(String[] args) {
        new Thread(new B()).start();
    }
}