package codejam.mc.y2014.quali;

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
      int A1 = sc.nextInt();
      int[][] f1 = new int[4][4];
      for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
          f1[r][c] = sc.nextInt();

      int A2 = sc.nextInt();
      int[][] f2 = new int[4][4];
      for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
          f2[r][c] = sc.nextInt();

      List<Integer> cards = new ArrayList<Integer>();
      for (int j1 : f1[A1 - 1])
      {
        for (int j2 : f2[A2 - 1])
        {
          if (j1 == j2)
            cards.add(j1);
        }
      }
      String res = "";
      if (cards.size() == 1)
        res += cards.get(0);
      else if (cards.size() > 1)
        res += "Bad magician!";
      else if (cards.size() == 0)
        res += "Volunteer cheated!";

      String result = "Case #" + i + ": " + res;

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
    ClassLoader cl = A.class.getClassLoader();
    prop.load(cl.getResourceAsStream("build.properties"));
    String task = prop.getProperty("input");
    sc = new Scanner(new File(prop.getProperty("download.dir") + task + ".in"));
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