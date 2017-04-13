import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  double solve(int n, int v[]) {

    int c[] = new int[n];
    for(int i=0; i<n; ++i) { c[i] = v[i]; }
    Arrays.sort(c);

    int ret = 0;

    for(int i=0; i<n; ++i) {
      if( c[i] != v[i] ) { ++ret; }
    }

    return ret;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {

      int n = cin.nextInt();
      int v[] = new int[n];

      for(int j=0; j<n; ++j) { v[j] = cin.nextInt(); }

      System.out.println("Case #" + (i + 1) + ": " + solve(n, v));

    }

  }

}
