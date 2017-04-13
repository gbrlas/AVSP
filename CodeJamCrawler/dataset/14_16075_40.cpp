import java.util.*;

public class D {
  static int nodes, ways, m, n;
  static String[] s;
  static int[] assign;
  static HashSet[] gg;
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int T = in.nextInt();
    for (int tc = 1; tc <= T; tc++) {
      nodes = 0;
      ways = 0;
      m = in.nextInt();
      n = in.nextInt();
      in.nextLine();
      s = new String[m];
      gg = new HashSet[n];
      for (int i = 0; i < n; i++) {
        gg[i] = new HashSet();
      }
      assign = new int[m];
      for (int i = 0; i < m; i++) {
        s[i] = in.nextLine();
      }
      go(0);
      System.out.println("Case #" + tc + ": " + nodes + " " + ways);
    }
  }
  
  static void go(int d) {
    if (d == m) {
      score();
    } else {
      for (int i = 0; i < n; i++) {
        assign[d] = i;
        go(d + 1);
      }
    }
  }
  
  static void score() {
    boolean[] used = new boolean[n];
    for (int i : assign) {
      used[i] = true;
    }
    for (boolean b : used) {
      if (!b) {
        return;
      }
    }
    for (int i = 0; i < n; i++) {
      gg[i].clear();
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j <= s[i].length(); j++) {
        gg[assign[i]].add(s[i].substring(0, j));
      }
    }
    int cnodes = 0;
    for (HashSet ggg : gg) {
      cnodes += ggg.size();
    }
    if (cnodes > nodes) {
      nodes = cnodes;
      ways = 1;
    } else if (cnodes == nodes) {
      ways++;
    }
  }
}