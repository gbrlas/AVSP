import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void check(int t, Scanner cin) {

    int n = cin.nextInt();
    int p[][] = new int[n][3];
    for(int i=0; i<n; ++i) {
      p[i][0] = cin.nextInt();
      p[i][1] = cin.nextInt();
      p[i][2] = cin.nextInt();
    }

    double ans = Double.MAX_VALUE;

    if( n == 1 ) { ans = p[0][2]; }
    if( n == 2 ) { ans = Math.max(p[0][2], p[1][2]); }
    if( n == 3 ) {
      ans = Math.min(ans, Math.max(score(p[0], p[1]), p[2][2]));
      ans = Math.min(ans, Math.max(score(p[0], p[2]), p[1][2]));
      ans = Math.min(ans, Math.max(score(p[2], p[1]), p[0][2]));
    }

    System.out.println("Case #" + t + ": " + ans);

  }

  double score(int a[], int b[]) {
    double d = Math.sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    return (d + a[2] + b[2]) / 2;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      check(i + 1, cin);
    }

  }

}
