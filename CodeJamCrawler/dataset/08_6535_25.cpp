import java.util.*;

public class B {

  public static void main(String args[]) {
    (new B()).exec();
  }

  int[] check(int a, int x, int y) {
    for(int i=0; i<=x; ++i) {
      for(int j=0; j<=y; ++j) {
        for(int k=0; k<=x; ++k) {
          for(int l=0; l<=y; ++l) {
            if( i * l - j * k == a ) { return new int[] { 0, 0, i, j, k, l}; }
          }
        }
      }
    }
    return new int[0];
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int time = cin.nextInt();

    for(int count=0; count<time; ++count) {

      int x = cin.nextInt();
      int y = cin.nextInt();
      int a = cin.nextInt();
      int ans[] = check(a, x, y);

      String ret = "";
      if( ans.length == 0 ) { ret = "IMPOSSIBLE"; }
      else {
        for(int v : ans) { ret += v + " "; }
        ret = ret.trim();
      }

      System.out.println("Case #" + (count + 1) + ": " + ret);

    }

  }

}
