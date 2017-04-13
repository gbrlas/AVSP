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
      table[i] = 1;
      String v = cin.next();
      for(int j=0; j<n; ++j) {
        if( v.charAt(j) == '1' ) { table[i] = j + 1; }
      }
    }

    HashSet<String> hist = new HashSet<String>();
    ArrayList<String> queue = new ArrayList<String>();
    ArrayList<Integer> score = new ArrayList<Integer>();

    hist.add(s);
    queue.add(s);
    score.add(0);

    for(int i=0; i<queue.size(); ++i) {
      String cur = queue.get(i);
      if( ok(cur, table, n) ) {
        System.out.println("Case #" + t + ": " + score.get(i));
        return;
      }
      for(int j=1; j<n; ++j) {
        String next = swap(cur, j - 1, j);
        if( hist.contains(next) ) { continue; }
        hist.add(next);
        queue.add(next);
        score.add(score.get(i) + 1);
      }
    }

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
