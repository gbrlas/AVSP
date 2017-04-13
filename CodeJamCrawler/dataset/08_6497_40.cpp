import java.util.*;

public class A {

  public static void main(String args[]) {
    (new A()).exec();
  }

  int ans(Scanner cin) {
    int n = cin.nextInt();
    int A = cin.nextInt();
    int B = cin.nextInt();
    int C = cin.nextInt();
    int D = cin.nextInt();
    long x[] = new long[n];
    long y[] = new long[n];
    x[0] = cin.nextInt();
    y[0] = cin.nextInt();
    int M = cin.nextInt();
    for(int i=1; i<n; ++i) {
      x[i] = (A * x[i-1] + B) % M;
      y[i] = (C * y[i-1] + D) % M;
    }
    int ret = 0;
    for(int i=0; i<n; ++i) {
      for(int j=i+1; j<n; ++j) {
        for(int k=j+1; k<n; ++k) {
          if( (x[i] + x[j] + x[k]) % 3 == 0 && (y[i] + y[j] + y[k]) % 3 == 0 ) { ++ret; }
        }
      }
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);

    int t = cin.nextInt();
    for(int z=0; z<t; ++z) {
      System.out.println("Case #" + (z + 1) + ": " + ans(cin));
    }

  }

}
