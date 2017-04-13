import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int ok(int a, int b) {
    if( a > b ) { return ok(b, a); }
    if( a == b ) { return 0; }
    if( a + a <= b ) { return 1; }
    return 1 - ok(b - a, a);
  }

  int solve(int a1, int a2, int b1, int b2) {
    int ret = 0;
    for(int a=a1; a<=a2; ++a) {
      for(int b=b1; b<=b2; ++b) {
        ret += ok(a, b);
      }
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();
    for(int i=1; i<=t; ++i) {
      int a1 = cin.nextInt();
      int a2 = cin.nextInt();
      int b1 = cin.nextInt();
      int b2 = cin.nextInt();
      System.out.println("Case #" + i + ": " + solve(a1, a2, b1, b2));
    }

  }

}
