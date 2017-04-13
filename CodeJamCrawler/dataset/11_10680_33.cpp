import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  int solve(int n, int v[]) {

    if( n == 0 ) { return 0; }

    Arrays.sort(v);

    int min = Integer.MAX_VALUE;
    PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
    PriorityQueue<Integer> next = new PriorityQueue<Integer>();

    int p = -2;

    for(int i=0; i<n; ++i) {

      int c = v[i];

      // queue -> next;
      if( c > p ) {
        while( !queue.isEmpty() ) { min = Math.min(min, queue.poll()); }
        queue = next;
        next = new PriorityQueue<Integer>();
      }

      // insert;
      if( c == p + 1 || c == p ) {
        if( queue.isEmpty() ) { next.add(1); }
        else { next.add(queue.poll() + 1); }
      }

      else { next.add(1); }

      p = c;

    }

    while( !queue.isEmpty() ) { min = Math.min(min, queue.poll()); }
    while( !next.isEmpty() ) { min = Math.min(min, next.poll()); }

    return min;

  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();

    for(int c=1; c<=t; ++c) {

      int n = cin.nextInt();
      int v[] = new int[n];
      for(int i=0; i<n; ++i) { v[i] = cin.nextInt(); }

      System.out.println("Case #" + c + ": " + solve(n, v));

    }

  }

}
