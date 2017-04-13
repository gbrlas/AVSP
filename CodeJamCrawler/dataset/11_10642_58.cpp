import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  double solve(int x, double s, double r, double t, int n, int w[][]) {

    for(int i=0; i<n; ++i) {
      x -= w[i][1] - w[i][0];
    }

    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        if( w[i][2] > w[j][2] ) {
          int tmp[] = w[i];
          w[i] = w[j];
          w[j] = tmp;
        }
      }
    }

    double ret = 0;
    double run = check(x, r, t);
    ret += run + (x - r * run) / s;
    t -= run;

    for(int i=0; i<n; ++i) {
      int d = w[i][1] - w[i][0];
      double v = r + w[i][2];
      double u = s + w[i][2];
      run = check(d, v, t);
      ret += run + (d - v * run) / u;
      t -= run;
    }

    return ret;

  }

  double check(int d, double v, double max) {
    return Math.min(max, d / v);
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int c=1; c<=T; ++c) {

      int x = cin.nextInt();
      int s = cin.nextInt();
      int r = cin.nextInt();
      int t = cin.nextInt();
      int n = cin.nextInt();

      int w[][] = new int[n][3];
      for(int i=0; i<n; ++i) {
        for(int j=0; j<3; ++j) {
          w[i][j] = cin.nextInt();
        }
      }

      System.out.println("Case #" + c + ": " + solve(x, s, r, t, n, w));

    }

  }

}
