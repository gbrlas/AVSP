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
    int n, m, found_i, found_j, ch_x, ch_y;
    int[][] lev;
    boolean[][] was;
    char cur;
    char[][] basin;
    int[] dx = {-1, 0, 0, 1};
    int[] dy = {0, -1, 1, 0};
    private void check(int xx, int yy) {
        int fff = lev[xx][yy], idx = -1, idy = -1;
        for (int dir = 0; dir < 4; dir++) {
            int x = xx + dx[dir], y = yy + dy[dir];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (fff > lev[x][y]) {
                fff = lev[x][y];
                idx = x;
                idy = y;
            }
        }
        ch_x = idx;
        ch_y = idy;
    }
    private void dfs(int x, int y) {
        was[x][y] = true;
        basin[x][y] = cur;
        for (int dir = 0; dir < 4; dir++) {
            int xx = dx[dir] + x, yy = dy[dir] + y;
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
            if (lev[xx][yy] > lev[x][y]) {
                check(xx, yy);
                if (ch_x == x && ch_y == y) {
                    dfs(xx, yy);
                }
            }
        }
    }
    private void find_fall(int xx, int yy) {
        while (true) {
            check(xx, yy);
            if (ch_x == -1) break;
            xx = ch_x;
            yy = ch_y;
        }
        found_i = xx;
        found_j = yy;
    }
    private void solve() {
        int T = nextInt();
        for (int www = 1; www <= T; ++www) {
            n = nextInt(); m = nextInt();
            lev = new int[n][m];
            was = new boolean[n][m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) lev[i][j] = nextInt();
            cur = 'a';
            basin = new char[n][m];
            for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) if (!was[i][j]){
                find_fall(i, j);
                int ii = found_i, jj = found_j;
                dfs(ii, jj);
                cur++;
            }
            StringBuilder sb = new StringBuilder();
            sb.append("Case #" + www + ":\n");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (j != 0) sb.append(" ");
                    sb.append(basin[i][j] + "");
                }
                sb.append("\n");
            }
            out.print(sb.toString());
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
