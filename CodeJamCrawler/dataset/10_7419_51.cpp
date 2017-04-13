import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int dx[] = { 1, 0, 1, -1 };
  int dy[] = { 0, 1, 1, 1 };

  String solve(String table[], int n, int k) {
    char c[][] = new char[n][n];
    for(int i=0; i<n; ++i) {
      int p = 0;
      for(int j=n-1; j>=0; --j) {
        char d = table[i].charAt(j);
        if( d == '.' ) { continue; }
        c[i][p++] = d;
      }
    }
    boolean red = false;
    boolean blue = false;
  MAIN:
    for(int i=0; i<n; ++i) {
    SUB:
      for(int j=0; j<n; ++j) {
        if( c[i][j] == 0 ) { continue SUB; }
        if( c[i][j] == 'B' ) {
          if( blue ) { continue; }
          blue |= seek(c, i, j, n, k);
        }
        if( c[i][j] == 'R' ) {
          if( red ) { continue; }
          red |= seek(c, i, j, n, k);
        }
        if( blue && red ) { break MAIN; }
      }
    }
    if( blue && red ) { return "Both"; }
    if( blue ) { return "Blue"; }
    if( red ) { return "Red"; }
    return "Neither";
  }

  boolean seek(char c[][], int x, int y, int n, int k) {
    char d = c[x][y];
  MAIN:
    for(int j=0; j<4; ++j) {
      int nx = x;
      int ny = y;
      for(int i=1; i<k; ++i) {
        nx += dx[j];
        ny += dy[j];
        if( nx < 0 || ny < 0 || nx >= n || ny >= n || c[nx][ny] != d ) { continue MAIN; }
      }
      return true;
    }
    return false;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();
    for(int i=1; i<=t; ++i) {
      int n = cin.nextInt();
      int k = cin.nextInt();
      String table[] = new String[n];
      for(int j=0; j<n; ++j) { table[j] = cin.next(); }
      System.out.println("Case #" + i + ": " + solve(table, n, k));
    }

  }

}
