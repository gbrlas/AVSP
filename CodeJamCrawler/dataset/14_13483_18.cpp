package codejam.mc.y2014.r1c;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class B
{
  private static long res = 0;
  private static HashSet<Object> okTr;

  static void solve() throws Exception
  {
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++)
    {
      //
      notOkTr = new HashSet<>();
      okTr = new HashSet<>();
      res = 0;
      int N = sc.nextInt();
      trs = new String[N];
      for (int j = 0; j < N; j++)
        trs[j] = sc.next();

      Integer[] or = new Integer[N];
      nextTr(or, 0);

      res = res % 1000000007;
      String result = "Case #" + i + ": " + res;

      //
      out(result);
    }
  }

  // =====================
  // no changes
  // =====================

  private static void nextTr(Integer[] or, int pos)
  {
    if (pos == or.length)
    {
      String train = "";
      // check train
      for (Integer i : or)
        train += trs[i];

      if (checkTrain(train))
        res++;
    }
    for (int j = 0; j < or.length; j++)
    {
      if (or[j] == null)
      {
        Integer[] orNew = Arrays.copyOf(or, or.length);
        orNew[j] = pos;
        nextTr(orNew, pos + 1);
      }
    }
  }

  private static boolean checkTrain(String train)
  {
    // if (okTr.contains(train))
    // return true;
    // if (notOkTr.contains(train))
    // return false;

    char[] tc = train.toCharArray();
    Set<Character> forbid = new HashSet<>();
    Character prev = null;
    for (Character c : tc)
    {
      if (prev == null || c == prev)
      {
        prev = c;
        continue;
      }
      else
      {
        if (forbid.contains(c))
        {
          // notOkTr.add(train);
          return false;
        }
        else
        {
          forbid.add(prev);
          prev = c;
        }
      }
    }
    // okTr.add(train);
    return true;
  }

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
  private static String[] trs;
  private static Set<String> notOkTr;
}