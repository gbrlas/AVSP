import java.util.*;

public class A {

  public static void main(String args[]) {
    (new A()).start();
  }

  void start() {

    Scanner cin = new Scanner(System.in);

    int n = Integer.parseInt(cin.nextLine());

    for(int z=0; z<n; ++z) {

      int s = Integer.parseInt(cin.nextLine());
      String sn[] = new String[s];
      for(int i=0; i<s; ++i) {
        sn[i] = cin.nextLine();
      }

      boolean used[] = new boolean[s];
      int us = 0;
      int ret = 0;
      int q = Integer.parseInt(cin.nextLine());
      for(int i=0; i<q; ++i) {
        String query = cin.nextLine();
        int index = indexOf(sn, query);
        if( index < 0 ) { continue; }
        if( !used[index] ) {
          used[index] = true;
          ++us;
          if( us == s ) {
            used = new boolean[s];
            used[index] = true;
            us = 1;
            ++ret;
          }
        }
      }

      System.out.println("Case #" + (z + 1) + ": " + ret);

    }

  }

  int indexOf(String arr[], String s) {
    for(int i=0; i<arr.length; ++i) {
      if( arr[i].equals(s) ) { return i; }
    }
    return -1;
  }

}
