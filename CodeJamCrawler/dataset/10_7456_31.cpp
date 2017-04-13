import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  boolean safe(boolean table[][]) {
    for(int i=0; i<100; ++i) {
      for(int j=0; j<100; ++j) {
        if( table[i][j] ) { return true; }
      }
    }
    return false;
  }

  int solve(boolean table[][]) {

    int ret = 0;

    while( safe(table) ) {
      boolean next[][] = new boolean[100][100];
      for(int i=0; i<100; ++i) {
        for(int j=0; j<100; ++j) {
          boolean n = i > 0 ? table[i-1][j] : false;
          boolean m = j > 0 ? table[i][j-1] : false;
          if( n && m ) { next[i][j] = true; }
          if( table[i][j] && (n || m) )  { next[i][j] = true; }
        }
      }
      ++ret;
      table = next;
    }

    return ret;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int c=1; c<=t; ++c) {
      int r = cin.nextInt();
      boolean table[][] = new boolean[100][100];
      for(int a=0; a<r; ++a) {
        int x1 = cin.nextInt();
        int y1 = cin.nextInt();
        int x2 = cin.nextInt();
        int y2 = cin.nextInt();
        for(int i=x1; i<=x2; ++i) {
          for(int j=y1; j<=y2; ++j) {
            table[i-1][j-1] = true;
          }
        }
      }
      System.out.println("Case #" + c + ": " + solve(table));
    }

  }

}
