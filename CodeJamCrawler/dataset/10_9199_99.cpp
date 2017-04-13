import java.math.*;
import java.util.*;

public class b {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int C = s.nextInt();
        for (int i = 0; i < C; i++) {
            int N = s.nextInt();
            BigInteger[] ts = new BigInteger[N];
            for (int j = 0; j < N; j++) {
                String tstr = s.next();
                BigInteger t = new BigInteger(tstr);
                ts[j] = t;
            }
            Arrays.sort(ts);

            BigInteger d1 = ts[1].subtract(ts[0]);
            for (int j = 2; j < N; j++) {
                BigInteger d2 = ts[j].subtract(ts[j - 1]);
                d1 = d1.gcd(d2);
            }

            BigInteger[] dr = ts[0].divideAndRemainder(d1);
            if (dr[1].compareTo(BigInteger.ZERO) > 0) {
                dr[0] = dr[0].add(BigInteger.ONE);
            }
            BigInteger answer = (d1.multiply(dr[0])).subtract(ts[0]);
            System.out.println("Case #" + (i + 1) + ": " + answer);
        }
    }
}
