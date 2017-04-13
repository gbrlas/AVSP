import java.util.*;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  private static final int size = 1000006;
  boolean see[] = new boolean[size];
  ArrayList<Integer> primes;

  void init() {
    primes = new ArrayList<Integer>();
    for(int i=2; i<size; ++i) {
      if( see[i] ) { continue; }
      primes.add(i);
      for(int j=i; j<size; j+=i) { see[j] = true; }
    }
  }

  long solve(long n) {

    long ret = 0;
    if( n > 1 ) { ret += 1; }

    for(int p : primes) {
      long v = n;
      int c = 0;
      while( v >= p ) {
        v /= p;
        ++c;
      }
      if( c > 1 ) { ret += c - 1; }
    }

    return ret;

  }

  void exec() {

    init();

    Scanner cin = new Scanner(System.in);
    int T = cin.nextInt();

    for(int c=1; c<=T; ++c) {

      long n = cin.nextLong();

      System.out.println("Case #" + c + ": " + solve(n));

    }

  }

}
