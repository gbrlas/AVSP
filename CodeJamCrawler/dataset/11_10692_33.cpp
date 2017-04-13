import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  String solve(String s) {

    int n = s.length();
    int v = 0;

    for(int i=0; i<n; ++i) {
      if( s.charAt(i) == '?' ) { ++v; }
    }

    int max = 1 << v;

    for(int i=0; i<max; ++i) {

      int p = 0;
      long cur = 0;
      long base = 1;

      for(int j=n-1; j>=0; --j) {
        char c = s.charAt(j);
        if( c == '?' ) {
          if( (i & (1 << p)) != 0 ) { cur += base; }
          ++p;
        }
        else if( c == '1' ) { cur += base; }
        base *= 2;
      }

      p = 0;

      long x = (long)(Math.sqrt(cur));
      for(int k=-2; k<=2; ++k) {
        String ret = "";
        if( (x + k) * (x + k) == cur ) {
          for(int j=n-1; j>=0; --j) {
            char c = s.charAt(j);
            if( c == '?' ) {
              if( (i & (1 << p)) != 0 ) { ret = '1' + ret; }
              else { ret = '0' + ret; }
              ++p;
            }
            else { ret = c + ret; }
          }
          return ret;
        }
      }

    }

    return null;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int c=1; c<=t; ++c) {

      String s = cin.next();
      System.out.println("Case #" + c + ": " + solve(s));

    }

  }

}
