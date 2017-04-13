package codejam.mc.y2014.quali;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class B
{
  static void solve() throws Exception
  {
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++)
    {
      //
      double c = sc.nextDouble();
      double f = sc.nextDouble();
      double x = sc.nextDouble();

      int farms = 0;
      double min = Double.MAX_VALUE;
      double farmtime = 0;
      while (farmtime < min)
      {
        double resttime = (x / (2 + (farms * f)));
        min = Math.min(min, resttime + farmtime);
        farms++;
        farmtime += (c / (2 + ((farms - 1) * f)));
      }

      String result = "Case #" + i + ": " + min;
      //
      out(result);
    }
  }

  // =====================
  // no changes
  // =====================

  public static void main(String[] args) throws Exception
  {
    long start = System.currentTimeMillis();
    Properties prop = new Properties();
    ClassLoader cl = B.class.getClassLoader();
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