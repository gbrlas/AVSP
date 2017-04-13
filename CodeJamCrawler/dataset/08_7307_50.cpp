import java.io.*;
import java.util.*;

public class B
{
  public static void main(String args[])
  {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 1; i <= n; i++)
    {
      int tat = sc.nextInt();
      int a = sc.nextInt();
      int b = sc.nextInt();
      List<Integer> froma = new ArrayList<Integer>();
      List<Integer> fromb = new ArrayList<Integer>();
      List<Integer> toa = new ArrayList<Integer>();
      List<Integer> tob = new ArrayList<Integer>();
      for (int j = 0; j < a; j++)
      {
        froma.add(getTime(sc.next()));
        toa.add(getTime(sc.next()) + tat);
      }
      for (int j = 0; j < b; j++)
      {
        fromb.add(getTime(sc.next()));
        tob.add(getTime(sc.next()) + tat);
      }
      Collections.sort(froma);
      Collections.sort(fromb);
      Collections.sort(toa);
      Collections.sort(tob);
      for (int ta : toa)
      {
	boolean end = false;
        while (true)
	{
	  if (fromb.isEmpty())
	  {
	    end = true;
	    break;
	  }
	  if (ta <= fromb.remove(0))
	  {
	    b--;
	    break;
	  }
	}
	if (end)
	  break;
      }
      for (int tb : tob)
      {
	boolean end = false;
        while (true)
	{
	  if (froma.isEmpty())
	  {
	    end = true;
	    break;
	  }
	  if (tb <= froma.remove(0))
	  {
	    a--;
	    break;
	  }
	}
	if (end)
	  break;
      }
      System.out.println("Case #" + i + ": " + a + " " + b);
    }
  }

  private static int getTime(String ts)
  {
    int hr = Integer.parseInt(ts.substring(0,2));
    int min = Integer.parseInt(ts.substring(3));
    return hr * 60 + min;
  }
}
