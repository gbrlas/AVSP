package codejam.mc.y2014.r1c;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class A
{
  static void solve() throws Exception
  {
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++)
    {
      //
      String frac = sc.next();
      String[] fs = frac.split("/");
      BigInteger z = new BigInteger(fs[0]);
      BigInteger n = new BigInteger(fs[1]);
      // norm
      BigInteger b2 = BigInteger.valueOf(2L);
      BigInteger zfact = new BigInteger(z.toString());
      while (true)
      {
        BigInteger[] dr2 = zfact.divideAndRemainder(b2);
        if (dr2[1].compareTo(BigInteger.ZERO) == 0)
        {
          zfact = dr2[0];
        }
        else
        {
          BigInteger[] ndr = n.divideAndRemainder(zfact);
          if (ndr[1].compareTo(BigInteger.ZERO) == 0)
          {
            z = z.divide(zfact);
            n = n.divide(zfact);
          }
          break;
        }
      }

      // out(z + "/ " + n);

      BigInteger pot = BigInteger.valueOf(2L).pow(40);
      BigInteger[] dar = pot.divideAndRemainder(n);
      // out(dar[1]);
      if (dar[1].compareTo(BigInteger.ZERO) != 0)
        out("Case #" + i + ": impossible");
      else
      {
        int d = 0;
        BigInteger mult = z.multiply(dar[0]);
        while (true)
        {
          if (mult.compareTo(pot) >= 0)
            break;
          else
          {
            mult = mult.multiply(b2);
            d++;
          }
        }
        out("Case #" + i + ": " + d);
      }

      String result = "Case #" + i + ": ";

      //
      // out(result);
    }
  }

  // =====================
  // no changes
  // =====================

  public static void main(String[] args) throws Exception
  {
    long start = System.currentTimeMillis();
    Properties prop = new Properties();
    ClassLoader cl = A.class.getClassLoader();
    prop.load(cl.getResourceAsStream("build.properties"));
    String task = prop.getProperty("input");
    sc = new Scanner(new File(prop.getProperty("download.dir") + task + ".in"));
    sc.useLocale(Locale.US);
    pw = new PrintWriter(prop.getProperty("upload.dir") + task + ".out");
    solve();
    sc.close();
    pw.flush();
    pw.close();
    float dur = ((float) (System.currentTimeMillis() - start)) / 1000f;
    System.out.println("Finished in : " + dur + " sek.");
  }

  static void out(Object result) throws Exception
  {
    System.out.println(result.toString());
    pw.println(result.toString());
  }

  static PrintWriter pw;
  static Scanner sc;
}