import java.util.*;

public class B {

  public static void main(String args[]) {
    (new B()).start();
  }

  void start() {
    Scanner cin = new Scanner(System.in);
    int n = Integer.parseInt(cin.nextLine());
    for(int i=0; i<n; ++i) { solve(cin, i + 1); }
  }

  int toInt(String time) {
    String tmp[] = time.split(":");
    return (Integer.parseInt(tmp[0]) * 60 + Integer.parseInt(tmp[1]));
  }

  void solve(Scanner cin, int cnum) {

    int turn = Integer.parseInt(cin.nextLine());
    String tmp[] = cin.nextLine().split(" +");
    int na = Integer.parseInt(tmp[0]);
    int nb = Integer.parseInt(tmp[1]);

    int time[][] = new int[na + nb][2];
    for(int i=0; i<na + nb; ++i) {
      tmp = cin.nextLine().split(" +");
      for(int j=0; j<2; ++j) {
        time[i][j] = toInt(tmp[j]);
      }
    }

    int ns = na + nb + 2;
    int anum = na - maxflow(bigraph(time, turn, na, nb, 0, na), new int[ns][ns], na + nb, na + nb + 1);
    int bnum = nb - maxflow(bigraph(time, turn, 0, na, na, nb), new int[ns][ns], na + nb, na + nb + 1);

    System.out.println("Case #" + cnum + ": " + anum + " " + bnum);

  }

  int maxflow(int arr[][], int used[][], int s, int t) {
    int count = 0;
    while( dfs(arr, used, s, t) ) { ++count; }
    return count;
  }

  boolean dfs(int arr[][], int used[][], int s, int t) {
    ArrayList<Integer> queue = new ArrayList<Integer>();
    // points to queue(index)
    ArrayList<Integer> prev = new ArrayList<Integer>();
    queue.add(s);
    prev.add(-1);
    boolean checked[] = new boolean[s+2];
    checked[s] = true;
    for(int q=0; q<queue.size(); ++q) {
      int cur = queue.get(q);
      // !end
      if( arr[cur][t] > used[cur][t] ) {
        used[cur][t] = 1;
        while( prev.get(q) >= 0 ) {
          int me = queue.get(q);
          int back = queue.get(prev.get(q));
          if( arr[back][me] > used[back][me] ) { used[back][me] = 1; }
          if( used[me][back] == 1 ) { used[me][back] = 0; }
          q = prev.get(q);
        }
        return true;
      }
      for(int i=0; i<s; ++i) {
        if( checked[i] ) { continue; }
        if( arr[cur][i] > used[cur][i] ) {
          queue.add(i);
          prev.add(q);
          checked[i] = true;
        }
        if( used[i][cur] == 1 ) {
          queue.add(i);
          prev.add(q);
          checked[i] = true;
        }
      }
    }
    return false;
  }

  int[][] bigraph(int time[][], int turn, int ao, int as, int bo, int bs) {

    int s = as + bs;
    int t = s + 1;

    int ret[][] = new int[s+2][s+2];

    for(int i=0; i<as; ++i) {
      ret[s][ao+i] = 1;
    }

    for(int i=0; i<bs; ++i) {
      ret[bo+i][t] = 1;
    }

    for(int i=0; i<as; ++i) {
      for(int j=0; j<bs; ++j) {
        ret[ao+i][bo+j] = (time[ao + i][1] + turn <= time[bo + j][0]) ? 1 : 0;
      }
    }

    return ret;

  }

}
