import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int solve(int table[][], int m, int n) {
    int inf = Integer.MAX_VALUE / 3;
    // pos.x * pos.y
    int max_ok[][] = new int[m+1][n];
    int max = n;
    for(int i=0; i<n; ++i) {
      max_ok[0][i] = table[0][i];
    }
    for(int i=1; i<=m; ++i) {
      max /= 2;
      for(int j=0; j<max; ++j) {
        max_ok[i][j] = Math.min(max_ok[i-1][j*2], max_ok[i-1][j*2+1]);
      }
    }
    // life * pos.x * pos.y
    int dp[][][] = new int[m+1][m+1][n];
    for(int i=1; i<=m; ++i) {
      for(int j=0; j<n; ++j) {
        for(int k=0; k<=m; ++k) { dp[k][i][j] = inf; }
      }
    }
    max = n;
    int ret = inf;
    for(int i=1; i<=m; ++i) {
      max /= 2;
      for(int j=0; j<max; ++j) {
        for(int k=0; k<=max_ok[i][j]; ++k) {
          for(int x=k; x<=max_ok[i-1][j*2]; ++x) {
            for(int y=k; y<=max_ok[i-1][j*2+1]; ++y) {
              // must buy;
              if( x == k || y == k ) {
                dp[k][i][j] = Math.min(dp[k][i][j], dp[x][i-1][j*2] + dp[y][i-1][j*2+1] + table[i][j]);
              }
              // skip;
              else {
                dp[k][i][j] = Math.min(dp[k][i][j], dp[x][i-1][j*2] + dp[y][i-1][j*2+1]);
              }
            }
          }
          if( i == m ) { ret = Math.min(ret, dp[k][i][j]); }
        }
      }
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int c=1; c<=t; ++c) {
      int m = cin.nextInt();
      int n = 1;
      for(int i=0; i<m; ++i) { n *= 2; }
      int table[][] = new int[m+1][n];
      int max = n;
      for(int i=0; i<=m; ++i) {
        for(int j=0; j<max; ++j) {
          table[i][j] = cin.nextInt();
        }
        max /= 2;
      }
      System.out.println("Case #" + c + ": " + solve(table, m, n));
    }

  }

}
