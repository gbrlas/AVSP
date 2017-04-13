import java.util.*;
import java.util.concurrent.BlockingQueue;
import java.math.*;
import java.io.*;

public class Main implements Runnable{
    public static void main(String[] args) {
        new Thread(new Main()).start();
    }
    StringTokenizer st;
    PrintWriter out;
    BufferedReader br;
    boolean eof = false, in_out = false;
    private String nextToken() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (Exception e) {
                eof = true;
                return "0";
            }
        }
        return st.nextToken();
    }
    private String nextLine() {
        String ret = "";
        try {
            ret = br.readLine();
        } catch (Exception e) {
            ret = "";
        }
        if (ret == null) {
            eof = true;
            return "$";
        }
        return ret;
    }
    private String nextString() {
        return nextToken();
    }
    private int nextInt() {
        return Integer.parseInt(nextToken());
    }
    private long nextLong() {
        return Long.parseLong(nextToken());
    }
    private double nextDouble() {
        return Double.parseDouble(nextToken());
    }
    private BigInteger nextBigInteger() {
        return new BigInteger(nextToken());
    }
    private String to_precision(double x, int kol) {
        if (kol == 0) {
            return Long.toString((long)Math.floor(x));
        }
        String ret = Long.toString((long)Math.floor(x));
        x -= Math.floor(x);
        for (int i=0; i<kol; i++) {
            x *= 10;
        }
        ret += "." + Long.toString((long)Math.floor(x));
        if ((long)Math.floor(x) == 0) {
            ret += "0";
        }
        return ret;
    }
    private static double EPS = 1e-9;
    String INFILE = "bear.in", OUTFILE = "bear.out";
    private void solve() {
        int L = nextInt(), D = nextInt(), N = nextInt();
        String[] s = new String[D];
        for (int i = 0; i < D; i++) s[i] = nextLine().trim();
        for (int i = 0; i < N; i++) {
            String pat = nextLine().trim();
            String[] word = new String[L];
            int y = 0;
            for (int j = 0; j < pat.length();) {
                if (pat.charAt(j) != '(') {
                    word[y++] = pat.charAt(j) + "";
                    ++j;
                } else {
                    int id = pat.indexOf(")", j);
                    word[y++] = pat.substring(j + 1, id);
                    j = id + 1;
                }
            }
            int ans = 0;
            for (int j = 0; j < D; ++j) {
                boolean ok = true;
                for (int k = 0; k < L; k++) {
                    if (word[k].indexOf(s[j].charAt(k) + "") == -1) {
                        ok = false;
                        break;
                    }
                }
                if (ok) ++ans;
            }
            out.println("Case #" + (i + 1) + ": " + ans);
        }
    }
    public void run() {
        try {
            br = new BufferedReader(new FileReader(new File((in_out) ?  INFILE  : "input.txt")));
            out = new PrintWriter(new File((in_out) ? OUTFILE : "output.txt"));
            //br = new BufferedReader(new FileReader(new File("input.txt")));
            //out = new PrintWriter(new File("output.txt"));
        } catch (Exception e) {
            System.exit(111);
        }
        solve();
        out.close();
    }
}
