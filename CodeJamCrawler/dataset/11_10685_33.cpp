import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int mod = 1000003;

  // | - / \;
  int solve(int h, int w, String map[]) {

    int max = 1 << (h * w);

    int ret = 0;

  MAIN:
    for(int i=0; i<max; ++i) {
      boolean used[][] = new boolean[h][w];
      for(int j=0; j<h; ++j) {
        for(int k=0; k<w; ++k) {
          boolean b = (i & (1 << (j * w + k))) == 0;
          int nx = k;
          int ny = j;
          switch( map[j].charAt(k) ) {
          case '|':
            ny += b ? 1 : (h - 1);
            break;
          case '-':
            nx += b ? 1 : (w - 1);
            break;
          case '/':
            nx += b ? 1 : (w - 1);
            ny += b ? (h - 1) : 1;
            break;
          case '\\':
            nx += b ? 1 : (w - 1);
            ny += b ? 1 : (h - 1);
            break;
          }
          if( used[ny % h][nx % w] ) { continue MAIN; }
          used[ny % h][nx % w] = true;
        }
      }
      ++ret;
    }

    return ret % mod;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int c=1; c<=t; ++c) {

      int h = cin.nextInt();
      int w = cin.nextInt();

      String map[] = new String[h];

      for(int i=0; i<h; ++i) {
        map[i] = cin.next();
      }

      System.out.println("Case #" + c + ": " + solve(h, w, map));

    }

  }

}
