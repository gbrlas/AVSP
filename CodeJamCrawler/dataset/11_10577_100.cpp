import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int solve(int n, String p[], int v[]) {

    int o = 1;
    int b = 1;

    int to = 0;
    int tb = 0;

    for(int i=0; i<n; ++i) {
      if( p[i].equals("O") ) {
        int req = Math.abs(v[i] - o) + 1;
        o = v[i];
        to = Math.max(to + req, tb + 1);
      }
      else {
        int req = Math.abs(v[i] - b) + 1;
        b = v[i];
        tb = Math.max(tb + req, to + 1);
      }
    }

    return Math.max(to, tb);

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {

      int n = cin.nextInt();
      String p[] = new String[n];
      int v[] = new int[n];
      for(int j=0; j<n; ++j) {
        p[j] = cin.next();
        v[j] = cin.nextInt();
      }

      System.out.println("Case #" + (i + 1) + ": " + solve(n, p, v));

    }

  }

}
