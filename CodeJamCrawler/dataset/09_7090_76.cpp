import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    String s = cin.nextLine();
    int c = Integer.parseInt(s);

    for(int i=0; i<c; ++i) {
      check(i + 1, (new StringBuffer(cin.nextLine())).reverse().toString());
    }

  }

  String key = ((new StringBuffer("welcome to code jam")).reverse().toString());

  void check(int num, String s) {

    int L = s.length();
    int Z = key.length();

    int dp[][] = new int[L][Z];

    for(int i=0; i<Z; ++i) {
      for(int j=0; j<L; ++j) {
        if( s.charAt(j) == key.charAt(i) ) {
          if( i == 0 ) { dp[j][i] = 1; continue; }
          for(int k=0; k<j; ++k) {
            if( s.charAt(k) == key.charAt(i-1) ) {
              dp[j][i] += dp[k][i-1];
            }
          }
          dp[j][i] %= 10000;
        }
      }
    }

    int ans = 0;
    for(int j=0; j<L; ++j) { ans += dp[j][Z-1]; }
    ans %= 10000;

    System.out.printf("Case #%d: %04d\n", new Object[] { num, ans });

  }

}
