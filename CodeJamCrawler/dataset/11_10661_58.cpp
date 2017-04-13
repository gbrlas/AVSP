import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  String solve(int n, boolean map[][]) {

    int d[] = new int[n];
    for(int i=1; i<n; ++i) { d[i] = -1; }

    ArrayList<Integer> queue = new ArrayList<Integer>();
    queue.add(0);

    for(int i=0; i<queue.size(); ++i) {
      int p = queue.get(i);
      int c = d[p];
      for(int j=0; j<n; ++j) {
        if( map[p][j] && d[j] == -1 ) {
          d[j] = c + 1;
          queue.add(j);
        }
      }
    }

    long v[][] = new long[n][3];

    for(int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        if( i != j && map[i][j] ) {
          v[i][d[j] - d[i] + 1] |= (1L << j);
        }
      }
    }

    int dp[][][] = new int[n+1][n][n];
    for(int i=0; i<=n; ++i) {
      for(int j=0; j<n; ++j) {
        for(int k=0; k<n; ++k) {
          dp[i][j][k] = -1;
        }
      }
    }

    for(int i=0; i<n; ++i) {
      if( i != 0 || d[i] != 0 ) { continue; }
      for(int j=0; j<n; ++j) {
        if( d[j] != 1 ) { continue; }
        if( j == 1 ) {
          int res = Long.bitCount(v[i][2]);
          return (d[j] - 1) + " " + res;
        }
        dp[1][j][i] = 0;
      }
    }

    int res = 0;

    for(int i=2; i<=n; ++i) {
      for(int j=0; j<n; ++j) {
        if( d[j] != i ) { continue; }
        for(int k=0; k<n; ++k) {
          if( !map[j][k] ) { continue; }
          for(int m=0; m<n; ++m) {
            if( dp[i-1][k][m] == -1 ) { continue; }
            if( j == 1 ) {
              res = Math.max(res, dp[i-1][k][m] + Long.bitCount(v[m][2] | v[k][1]) - 1 + Long.bitCount(v[k][2]));
            }
            else {
              dp[i][j][k] = Math.max(dp[i][j][k], dp[i-1][k][m] + Long.bitCount(v[m][2] | v[k][1] | v[j][0]) - 1);
            }
          }
        }
      }
    }

    return (d[1] - 1) + " " + res;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int C=1; C<=T; ++C) {

      int p = cin.nextInt();
      boolean map[][] = new boolean[p][p];

      int w = cin.nextInt();
      for(int i=0; i<w; ++i) {
        String s = cin.next();
        String tmp[] = s.split(",");
        int a = Integer.parseInt(tmp[0]);
        int b = Integer.parseInt(tmp[1]);
        map[a][b] = map[b][a] = true;
      }

      System.out.println("Case #" + C + ": " + solve(p, map));

    }

  }

}
