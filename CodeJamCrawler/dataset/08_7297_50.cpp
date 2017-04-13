import java.io.*;
import java.util.*;

public class A
{
  public static void main(String args[])
  {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    for (int i = 1; i <= n; i++)
    {
      int m = sc.nextInt();
      sc.nextLine();
      Map<String, Integer> ses = new HashMap<String, Integer>();
      for (int j = 0; j < m; j++)
        ses.put(sc.nextLine(),j);
      int r = sc.nextInt();
      sc.nextLine();
      int[][] x = new int[m][r];
      for (int j = 0; j < r; j++)
        x[ses.get(sc.nextLine())][j] = 1;
      int pos = 0;
      int s = -1;
      while (pos < r)
      {
        s++;
	int max = pos;
	for (int j = 0; j < m; j++)
	{
	  int k;
	  for (k = pos; k < r; k++)
	    if (x[j][k] == 1)
	      break;
	  if (k > max)
	    max = k;
	}
	pos = max;
      }
      if (s == -1)
        s = 0;
      System.out.println("Case #" + i + ": " + s);
    }
  }
}
