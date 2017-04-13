import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  long solve(int left, int cap, int gs[], int n) {
    int next[] = new int[n];
    int score[] = new int[n];
    int pturn[] = new int[n];
    for(int i=0; i<n; ++i) { pturn[i] = -1; }
    long pscore[] = new long[n];
    int sum = 0;
    int end = 0;
    for(int i=0; i<n; ++i) {
      do {
        if( sum + gs[end] > cap ) { break; }
        sum += gs[end];
        end = (end + 1) % n;
      } while( end != i );
      next[i] = end;
      score[i] = sum;
      sum -= gs[i];
    }
    int turn = 0;
    long ret = 0;
    int cur = 0;
    boolean fast = false;
    while( turn < left ) {
      if( !fast && pturn[cur] >= 0 ) {
        int step = (turn - pturn[cur]);
        long part = ret - pscore[cur];
        int times = (left - turn) / step;
        ret += times * part;
        turn += times * step;
        fast = true;
      }
      else {
        pturn[cur] = turn;
        pscore[cur] = ret;
        ++turn;
        ret += score[cur];
        cur = next[cur];
      }
    }
    return ret;
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();
    for(int i=1; i<=t; ++i) {
      int left = cin.nextInt();
      int cap = cin.nextInt();
      int n = cin.nextInt();
      int gs[] = new int[n];
      for(int j=0; j<n; ++j) { gs[j] = cin.nextInt(); }
      System.out.println("Case #" + i + ": " + solve(left, cap, gs, n));
    }

  }

}
