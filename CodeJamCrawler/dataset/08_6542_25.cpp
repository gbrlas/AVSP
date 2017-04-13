import java.util.*;

public class D {

  public static void main(String args[]) {
    (new D()).exec();
  }

  int eval(int path[], int k, String s) {
    int ret = s.length();
    char prev = 0;
    for(int i=0; i<s.length(); i+=k) {
      for(int j=0; j<k; ++j) {
        char now = s.charAt(i + path[j]);
        if( now == prev ) { --ret; }
        prev = now;
      }
    }
    return ret;
  }

  int check(int cur, int path[], boolean used[], int k, String s) {
    if( cur == k ) {
      return eval(path, k, s);
    }
    int ret = s.length();
    for(int i=0; i<k; ++i) {
      if( used[i] ) { continue; }
      used[i] = true;
      path[cur] = i;
      ret = Math.min(ret, check(cur + 1, path, used, k, s));
      used[i] = false;
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int time = cin.nextInt();

    for(int count=0; count<time; ++count) {

      int k = cin.nextInt();
      String s = cin.next();
      int ans = check(0, new int[k], new boolean[k], k, s);

      System.out.println("Case #" + (count + 1) + ": " + ans);

    }

  }

}
