import java.io.PrintStream;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.Reader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("ticketswapping.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("ticketswapping.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TicketSwapping solver = new TicketSwapping();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TicketSwapping {

    static final int MOD = 1000002013;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        out.print("Case #" + testNumber + ": ");
        System.err.println("[" + testNumber + "]");
        int n = in.nextInt();
        int m = in.nextInt();
        final int[] start = new int[m];
        int[] finish = new int[m];
        int[] count = new int[m];
        for (int i = 0; i < m; i++) {
            start[i] = in.nextInt();
            finish[i] = in.nextInt();
            count[i] = in.nextInt();
        }
        long curAnswer = getAnswer(n, m, start, finish, count);
//        boolean changed = true;
//        while (changed) {
//            changed = false;
//            for (int i = 0; i < m; i++) {
//                for (int j = i + 1; j < m; j++) {
//                    long ans1 = getAnswer(n, Math.abs(start[i] - finish[i])) + getAnswer(n, Math.abs(start[i] - finish[i]));
//                    long ans2 = getAnswer(n, Math.abs(start[i] - finish[j])) + getAnswer(n, Math.abs(start[j] - finish[i]));
//                    if (ans2 < ans1) {
//                        int t = finish[i];
//                        finish[i] = finish[j];
//                        finish[j] = t;
//                    }
//                }
//            }
//        }
        Integer[] id = new Integer[m];
        for (int i = 0; i < m; i++) {
            id[i] = i;
        }
        Arrays.sort(id, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return start[o1] - start[o2];
            }
        });
        long bestAnswer = 0;
        for (int i = 0; i < m; ) {
            int end = finish[id[i]];
            int j = i;
            while (j < m && start[id[j]] <= end) {
                end = Math.max(end, finish[id[j]]);
                ++j;
            }
            int[] xs = new int[j - i + j - i];
            for (int k = i; k < j; k++) {
                xs[k - i] = start[id[k]];
                xs[k - i + j - i] = finish[id[k]];
            }
            xs = ArrayUtils.sortAndUnique(xs);
            int zn = xs.length;
            long[] cnt1 = new long[zn];
            long[] cnt2 = new long[zn];
            for (int k = i; k < j; k++) {
                cnt1[Arrays.binarySearch(xs, start[id[k]])] += count[id[k]];
                cnt2[Arrays.binarySearch(xs, finish[id[k]])] += count[id[k]];
            }
            for (int k = 0; k < zn; k++) {
                long z = Math.min(cnt1[k], cnt2[k]);
                cnt1[k] -= z;
                cnt2[k] -= z;
            }
            List<Integer> idz = new ArrayList<>();
            List<Long> avail = new ArrayList<>();
            for (int k = 0; k < zn; k++) {
                if (cnt1[k] > 0) {
                    idz.add(k);
                    avail.add(cnt1[k]);
                } else if (cnt2[k] > 0) {
                    while (cnt2[k] > 0) {
                        long got = Math.min(avail.get(avail.size() - 1), cnt2[k]);
                        bestAnswer = (bestAnswer + got % MOD * getAnswerMod(n, xs[k] - xs[idz.get(avail.size() - 1)])) % MOD;
                        avail.set(avail.size() - 1, avail.get(avail.size() - 1) - got);
                        cnt2[k] -= got;
                        while (!avail.isEmpty() && avail.get(avail.size() - 1) == 0) {
                            avail.remove(avail.size() - 1);
                            idz.remove(idz.size() - 1);
                        }
                    }
                }
            }
//            for (int k1 = 0, k2 = zn - 1; k1 < zn && k2 >= 0; ) {
//                while (k1 < zn && cnt1[k1] == 0) {
//                    k1++;
//                }
//                while (k2 >= 0 && cnt2[k2] == 0) {
//                    k2--;
//                }
//                if (k1 >= zn && k2 < 0) {
//                    break;
//                }
//                if (k1 >= zn || k2 < 0) {
//                    throw new AssertionError();
//                }
//                long z = Math.min(cnt1[k1], cnt2[k2]);
//                bestAnswer = (bestAnswer + z % MOD * getAnswerMod(n, Math.abs(xs[k1] - xs[k2]))) % MOD;
//                cnt1[k1] -= z;
//                cnt2[k2] -= z;
//            }
            i = j;
        }
        bestAnswer %= MOD;
        out.println((curAnswer - bestAnswer + MOD) % MOD);
    }

    private long getAnswer(int n, int m, int[] start, int[] finish, int[] count) {
        long curAnswer = 0;
        for (int i = 0; i < m; i++) {
            curAnswer = (curAnswer + count[i] * getAnswerMod(n, finish[i] - start[i])) % MOD;
        }
        curAnswer %= MOD;
        return curAnswer;
    }

    static long getAnswerMod(long n, long x) {
        return getAnswer(n, x) % MOD;
    }

    static long getAnswer(long n, long x) {
        return (f(n) - f(n - x));
    }

    static long f(long n) {
        return n * (n + 1) / 2;
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
                last = ret[i];
            }
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


    }

