import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int solve(int rest[], int d, int i, int m, int n) {
    // current value * rest;
    int table[][] = new int[256][n+1];
    int inf = Integer.MAX_VALUE / 4;
    for(int l=0; l<256; ++l) {
      for(int j=1; j<=n; ++j) { table[l][j] = inf; }
    }

    for(int j=0; j<n; ++j) {
      for(int l=0; l<256; ++l) {
        if( table[l][j] == inf ) { continue; }
        // insert;
        if( m > 0 ) {
          int diff = m;
          int req = 0;
          while( Math.abs(rest[j] - l) > diff ) {
            diff += m;
            req += i;
          }
          table[rest[j]][j+1] = Math.min(table[rest[j]][j+1], table[l][j] + req);
        }
        // delete;
        {
          table[l][j+1] = Math.min(table[l][j+1], table[l][j] + d);
        }
        // move;
        for(int k=Math.max(l - m, 0); k<=Math.min(l + m, 255); ++k) {
          table[k][j+1] = Math.min(table[k][j+1], table[l][j] + Math.abs(rest[j] - k));
        }
      }
    }

    int ret = inf;
    for(int l=0; l<256; ++l) {
      ret = Math.min(ret, table[l][n]);
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();
    for(int c=1; c<=t; ++c) {
      int d = cin.nextInt();
      int i = cin.nextInt();
      int m = cin.nextInt();
      int n = cin.nextInt();
      int rest[] = new int[n];
      for(int j=0; j<n; ++j) { rest[j] = cin.nextInt(); }
      System.out.println("Case #" + c + ": " + solve(rest, d, i, m, n));
    }

  }

}
