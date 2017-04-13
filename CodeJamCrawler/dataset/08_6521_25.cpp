import java.util.*;

public class A {

  public static void main(String args[]) {
    (new A()).exec();
  }

  int check(int n, int v, int g[], int c[], int x[]) {
    for(int i=(n-1)/2-1; i>=0; --i) {
      int l = i * 2 + 1;
      int r = i * 2 + 2;
      x[i] = (x[l] + x[r] - g[i]) > 0 ? 1 : 0;
    }
    return check(0, n, v, g, c, x);
  }

  int check(int cur, int n, int v, int g[], int c[], int x[]) {
    if( x[cur] == v ) { return 0; }
    int l = cur * 2 + 1;
    int r = cur * 2 + 2;
    if( l >= n ) { return -1; }
    if( v == 1 ) {
      if( (x[l] == 1 || x[r] == 1) ) {
        if( c[cur] == 1 ) { return 1; }
        int vl = check(l, n, v, g, c, x);
        int vr = check(r, n, v, g, c, x);
        if( vl == -1 || vr == -1 ) { return -1; }
        return vl + vr;
      }
      else {
        int vl = check(l, n, v, g, c, x);
        int vr = check(r, n, v, g, c, x);
        if( c[cur] == 1 ) {
          if( g[cur] == 1 ) {
            if( vl == -1 && vr == -1 ) { return -1; }
            if( vl == -1 ) { return vr + 1; }
            if( vr == -1 ) { return vl + 1; }
            return Math.min(vr, vl) + 1;
          }
          if( vl == -1 && vr == -1 ) { return -1; }
          if( vl == -1 ) { return vr; }
          if( vr == -1 ) { return vl; }
          return Math.min(vr, vl);
        }
        else {
          if( vl == -1 && vr == -1 ) { return -1; }
          if( g[cur] == 0 ) {
            if( vl == -1 ) { return vr; }
            if( vr == -1 ) { return vl; }
            return Math.min(vr, vl);
          }
          if( vl == -1 || vr == -1 ) { return -1; }
          return vr + vl;
        }
      }
    }
    else {
      if( x[l] == 0 || x[r] == 0 ) {
        if( c[cur] == 1 ) { return 1; }
        int vl = check(l, n, v, g, c, x);
        int vr = check(r, n, v, g, c, x);
        if( vl == -1 || vr == -1 ) { return -1; }
        return vl + vr;
      }
      else {
        int vl = check(l, n, v, g, c, x);
        int vr = check(r, n, v, g, c, x);
        if( c[cur] == 1 ) {
          if( g[cur] == 0 ) {
            if( vl == -1 && vr == -1 ) { return -1; }
            if( vl == -1 ) { return vr + 1; }
            if( vr == -1 ) { return vl + 1; }
            return Math.min(vr, vl) + 1;
          }
          if( vl == -1 && vr == -1 ) { return -1; }
          if( vl == -1 ) { return vr; }
          if( vr == -1 ) { return vl; }
          return Math.min(vr, vl);
        }
        else {
          if( vl == -1 && vr == -1 ) { return -1; }
          if( g[cur] == 1 ) {
            if( vl == -1 ) { return vr; }
            if( vr == -1 ) { return vl; }
            return Math.min(vr, vl);
          }
          if( vl == -1 || vr == -1 ) { return -1; }
          return vr + vl;
        }
      }
    }
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int time = cin.nextInt();

    for(int count=0; count<time; ++count) {

      int n = cin.nextInt();
      int v = cin.nextInt();

      int g[] = new int[(n-1)/2];
      int c[] = new int[(n-1)/2];
      int x[] = new int[n];
      for(int i=0; i<(n-1)/2; ++i) {
        g[i] = cin.nextInt();
        c[i] = cin.nextInt();
      }

      for(int i=(n-1)/2; i<n; ++i) {
        x[i] = cin.nextInt();
      }

      int ans = check(n, v, g, c, x);
      System.out.println("Case #" + (count + 1) + ": " + (ans == -1 ? "IMPOSSIBLE" : ans));

    }

  }

}
