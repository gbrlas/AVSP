import java.util.*;
import java.math.BigInteger;

public class Main {

  public static void main(String args[]) {
    (new Main()).exec();
  }

  BigInteger gcd(BigInteger a, BigInteger b) {
    if( a.compareTo(BigInteger.ZERO) == 0 ) { return b; }
    return gcd(b.remainder(a), a);
  }

  String solve(BigInteger val[], int n) {
    Arrays.sort(val);
    BigInteger g = BigInteger.ZERO;
    for(int i=1; i<n; ++i) {
      g = gcd(g, val[i].subtract(val[i-1]));
    }
    BigInteger ret = val[0].remainder(g);
    if( ret.compareTo(BigInteger.ZERO) == 0 ) { return ret.toString(); }
    return g.subtract(ret).toString();
  }

  void exec() {

    Scanner cin = new Scanner(System.in);
    int t = cin.nextInt();
    for(int i=1; i<=t; ++i) {
      int n = cin.nextInt();
      BigInteger val[] = new BigInteger[n];
      for(int j=0; j<n; ++j) { val[j] = new BigInteger(cin.next()); }
      System.out.println("Case #" + i + ": " + solve(val, n));
    }

  }

}
