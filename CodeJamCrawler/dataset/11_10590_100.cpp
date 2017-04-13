import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  String solve(String a[], String b[], String s) {

    ArrayList<Character> list = new ArrayList<Character>();

  MAIN:
    for(int i=0; i<s.length(); ++i) {
      char c = s.charAt(i);
      if( list.size() > 0 ) {
        char d = list.get(list.size() - 1);
        for(String t : a) {
          if( (t.charAt(0) == c && t.charAt(1) == d) ||
              (t.charAt(1) == c && t.charAt(0) == d) ) {
            list.set(list.size() - 1, t.charAt(2));
            continue MAIN;
          }
        }
      }
      for(int j=0; j<list.size(); ++j) {
        for(String t : b) {
          for(char d : list) {
            if( (t.charAt(0) == c && t.charAt(1) == d) ||
                (t.charAt(1) == c && t.charAt(0) == d) ) {
              list = new ArrayList<Character>();
              continue MAIN;
            }
          }
        }
      }
      list.add(c);
    }

    String glue = "";
    String ret = "";
    for(char c : list) {
      ret += glue + c;
      glue = ", ";
    }

    return "[" + ret + "]";

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int i=0; i<t; ++i) {

      int c = cin.nextInt();
      String a[] = new String[c];
      for(int j=0; j<c; ++j) { a[j] = cin.next(); }

      int d = cin.nextInt();
      String b[] = new String[d];
      for(int j=0; j<d; ++j) { b[j] = cin.next(); }

      cin.nextInt();
      String s = cin.next();

      System.out.println("Case #" + (i + 1) + ": " + solve(a, b, s));

    }

  }

}
