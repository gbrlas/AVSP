import java.util.*;
import java.math.BigInteger;
import java.io.*;

public class Main
{
    public static BigInteger gcd(BigInteger a, BigInteger b) {
        if (b.compareTo(BigInteger.ZERO) == 0)
            return a;
        return gcd(b, a.mod(b));
    }
    public static BigInteger Min(BigInteger a, BigInteger b) {
        if (a.compareTo(b) == -1) return a;
        return b;
    }
    public static void main(String args[])
    {
        try
        {
            BufferedReader br = new BufferedReader(new FileReader("B.in"));
            BufferedWriter bw = new BufferedWriter(new FileWriter("B.out"));
            int t = Integer.parseInt(br.readLine());
            String[] ss;
            BigInteger[] a;
            for(int gl=1; gl<=t; ++gl) {
                String s = br.readLine();
                ss = s.split(" ");
                int n = Integer.parseInt(ss[0]);
                a = new BigInteger[n];
                for(int i=0; i<n; ++i)
                    a[i] = new BigInteger(ss[i+1]);
                Arrays.sort(a);
                BigInteger r = a[n-1].subtract(a[n-2]);
                for(int i=n-3; i>=0; --i)
                    r = gcd(r, a[n-1].subtract(a[i]));

                BigInteger res = (r.subtract(a[n-1].mod(r))).mod(r);
                for(int i=n-2; i>=0; --i)
                    res = Min((r.subtract(a[i].mod(r))).mod(r), res);

                bw.write("Case #"+gl+": "+res.toString());
                bw.newLine();
            }
            bw.close();
        }
        catch (Exception ex)
        {
            System.out.println(ex.toString());
        }
    }
}