package codejam.mc.y2014.quali;

import java.io.File;
import java.io.PrintWriter;
import java.util.*;
import java.math.*;

import static java.lang.Math.*;

public class D
{
  static void solve() throws Exception
  {
    int T = sc.nextInt();
    for (int i = 1; i <= T; i++)
    {
      //
      int N = sc.nextInt();
      List<Double> naoOrig = new ArrayList<Double>();
      List<Double> kenOrig = new ArrayList<Double>();
      for (int j = 0; j < N; j++)
        naoOrig.add(sc.nextDouble());
      for (int j = 0; j < N; j++)
        kenOrig.add(sc.nextDouble());

      Collections.sort(naoOrig);
      Collections.sort(kenOrig);

      List<Double> nao = new ArrayList<Double>(naoOrig);
      List<Double> ken = new ArrayList<Double>(kenOrig);

      int pnao = 0;
      int pken = 0;

      Iterator<Double> itnao = nao.iterator();
      while (itnao.hasNext())
      {
        boolean found = false;
        double dnao = itnao.next();

        Iterator<Double> itken = ken.iterator();
        while (itken.hasNext())
        {
          Double dken = (Double) itken.next();

          if (dken > dnao)
          {
            pken++;
            itken.remove();
            itnao.remove();
            found = true;
            break;
          }
        }
        if (!found)
        {
          pnao++;
          itnao.remove();
          ken.remove(0);
        }
      }

      nao = new ArrayList<Double>(naoOrig);
      ken = new ArrayList<Double>(kenOrig);

      int dpnao = 0;
      int dpken = 0;

      Iterator<Double> itken = ken.iterator();
      while (itken.hasNext())
      {
        boolean found = false;
        double dken = itken.next();

        itnao = nao.iterator();
        while (itnao.hasNext())
        {
          Double dnao = (Double) itnao.next();

          if (dnao > dken)
          {
            dpnao++;
            itken.remove();
            itnao.remove();
            found = true;
            break;
          }
        }
        if (!found)
        {
          dpken++;
          nao.remove(0);
          itken.remove();
        }
      }

      String result = "Case #" + i + ": " + dpnao + " " + pnao;

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
    ClassLoader cl = D.class.getClassLoader();
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