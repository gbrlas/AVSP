import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void check(int t, Scanner cin) {

    int n = cin.nextInt();
    int k = cin.nextInt();

    int table[][] = new int[n][k];
    for(int i=0; i<n; ++i) {
      for(int j=0; j<k; ++j) {
        table[i][j] = cin.nextInt();
      }
    }

    boolean cross[][] = new boolean[n][n];
    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        cross[i][j] = cross[j][i] = seek(table[i], table[j], k);
      }
    }

    int max = 1 << n;

    boolean grp[] = new boolean[max];
    boolean skip[] = new boolean[max];
  MAIN:
    for(int i=1; i<max; ++i) {
      if( Integer.bitCount(i) == 1 ) { grp[i] = true; }
      else {
        for(int j=0; j<n; ++j) {
          if( (i & (1 << j)) != 0 ) {
            int p = i - (1 << j);
            if( !grp[p] ) { continue; }
            if( grp[i] ) {
              skip[p] = false;
              continue;
            }
            for(int m=0; m<n; ++m) {
              if( (p & (1 << m)) != 0 ) {
                if( cross[j][m] ) { continue MAIN; }
              }
            }
            skip[p] = true;
            grp[i] = true;
          }
        }
      }
    }

System.err.println(t);
    int all[] = new int[max];
    int pp = 0;

    for(int i=1; i<max; ++i) {
      if( !skip[i] && grp[i] ) { all[pp++] = i; }
    }
System.err.println(pp);

    int dp[] = new int[max];
    for(int i=1; i<max; ++i) { dp[i] = n; }

    for(int i=0; i<max; ++i) {
      for(int j=0; j<pp; ++j) {
        dp[i | all[j]] = Math.min(dp[i | all[j]], dp[i] + 1);
      }
    }

    System.out.println("Case #" + t + ": " + dp[max-1]);

  }

  boolean seek(int a[], int b[], int k) {
    int d = 0;
    for(int i=0; i<k; ++i) {
      if( a[i] == b[i] ) { return true; }
      if( d == 0 ) {
        if( a[i] > b[i] ) { d = 1; }
        else { d = -1; }
      }
      else if( d == 1 ) {
        if( a[i] < b[i] ) { return true; }
      }
      else {
        if( a[i] > b[i] ) { return true; }
      }
    }
    return false;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      check(i + 1, cin);
    }

  }

}
