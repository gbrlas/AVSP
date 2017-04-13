import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  String solve(int v[], int n) {

    int sum = -v[0];
    int xor = 0;

    for(int i=0; i<n; ++i) {
      sum += v[i];
      xor ^= v[i];
    }

    if( xor == 0 ) { return "" + sum; }
    return "NO";

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {

      int n = cin.nextInt();
      int v[] = new int[n];
      for(int j=0; j<n; ++j) { v[j] = cin.nextInt(); }
      Arrays.sort(v);

      System.out.println("Case #" + (i + 1) + ": " + solve(v, n));

    }

  }

}
