import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void check(int t, Scanner cin) {

    int n = cin.nextInt();
    String s = "";
    for(int i=0; i<n; ++i) { s += (i + 1); }
    int table[] = new int[n];
    for(int i=0; i<n; ++i) {
      table[i] = 0;
      String v = cin.next();
      for(int j=0; j<n; ++j) {
        if( v.charAt(j) == '1' ) { table[i] = j; }
      }
    }

    int ret = 0;
  MAIN:
    for(int i=0; i<n; ++i) {
      if( table[i] > i ) {
        for(int j=i+1; j<n; ++j) {
          if( table[j] <= i ) {
            ret += j - i;
            for(int k=j; k>i; --k) {
              table[k] = table[k-1];
            }
            continue MAIN;
          }
        }
      }
    }

    System.out.println("Case #" + t + ": " + ret);

  }

  boolean ok(String s, int table[], int n) {
    for(int i=0; i<n; ++i) {
      int id = s.charAt(i) - '1';
      if( table[id] - 1 <= i ) { continue; }
      return false;
    }
    return true;
  }

  String swap(String s, int i, int j) {
    return s.substring(0, i) + s.charAt(j) + s.charAt(i) + s.substring(j + 1);
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {
      check(i + 1, cin);
    }

  }

}
