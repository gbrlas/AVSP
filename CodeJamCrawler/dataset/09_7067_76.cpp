import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int L = cin.nextInt();
    int D = cin.nextInt();
    int N = cin.nextInt();

    String ds[] = new String[D];
    for(int i=0; i<D; ++i) { ds[i] = cin.next(); }

    for(int i=0; i<N; ++i) {
      String q = cin.next();
      q = q.replaceAll("\\(", "[");
      q = q.replaceAll("\\)", "]");
      int c = 0;
      for(int j=0; j<D; ++j) {
        if( ds[j].matches(q) ) { ++c; }
      }
      System.out.println("Case #" + (i + 1) + ": " + c);
    }

  }

}
