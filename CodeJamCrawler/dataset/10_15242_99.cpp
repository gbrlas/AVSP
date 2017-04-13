import java.io.File;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;


public class Solution {

        public static void main(String args[]) throws Exception {
            Solution solution = new Solution();
            solution.run();
        }


        Scanner in;
        PrintStream out;

        private void run() throws Exception {
            in = new Scanner(new File("input.txt"));
            out = new PrintStream(new File("output.txt"));

            int tc = in.nextInt();

            for (int i = 0; i < tc; i++) {
                solve(i + 1);
            }
        }

        private void solve(int test) {
            out.print("Case #" + test + ": ");

            int n = in.nextInt();
            BigInteger a[] = new BigInteger[n];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextBigInteger();
            }

            BigInteger d = BigInteger.ZERO;

            for (int i = 1; i < n; i++) {
                d = d.gcd(a[i].subtract(a[0]).abs());
            }

            if (d.equals(BigInteger.ZERO)) {
                out.println(0);
                return;
            }

            BigInteger ans = BigInteger.ZERO;
            for (int i = 0; i < n; i++) {
                BigInteger cur = d.subtract(a[i].remainder(d)).remainder(d);
                ans = ans.max(cur);
            }

            out.println(ans);
        }
}
