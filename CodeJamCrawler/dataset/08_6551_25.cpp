import java.util.*;

public class C {

  public static void main(String args[]) {
    (new C()).exec();
  }

  int check(int w, int h, String s[]) {

    int v[] = new int[h];
    for(int i=0; i<h; ++i) {
      for(int j=0; j<w; ++j) {
        v[i] |= (s[i].charAt(j) == 'x' ? 1 : 0) << j;
      }
    }

    int max = 1 << w;
    int dp[][] = new int[h+1][max];

    int ret = 0;
    for(int i=0; i<h; ++i) {
      // next
      for(int j=0; j<max; ++j) {
        if( ((j << 1) & j) != 0 ) { continue; }
        if( (j & v[i]) != 0 ) { continue; }
        int c = Integer.bitCount(j);
        int mask = see(j, w);
        // prev
        for(int k=0; k<max; ++k) {
          if( conflict(k, mask) ) { continue; }
          dp[i+1][j] = Math.max(dp[i+1][j], dp[i][k] + c);
        }
        ret = Math.max(ret, dp[i+1][j]);
      }
    }

    return ret;

  }

  int see(int s, int w) {
    int ret = 0;
    for(int i=0; i<w; ++i) {
      if( i > 0 ) {
        ret |= (s & (1 << i)) >> 1;
      }
      if( i < (w - 1) ) {
        ret |= (s & (1 << i)) << 1;
      }
    }
    return ret;
  }

  boolean conflict(int a, int b) {
    return (a & b) != 0;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int time = cin.nextInt();

    for(int count=0; count<time; ++count) {

      int h = cin.nextInt();
      int w = cin.nextInt();
      String s[] = new String[h];
      for(int i=0; i<h; ++i) { s[i] = cin.next(); }

      int ans = check(w, h, s);
      System.out.println("Case #" + (count + 1) + ": " + ans);

    }

  }

}
