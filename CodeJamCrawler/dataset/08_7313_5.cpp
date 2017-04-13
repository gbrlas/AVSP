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
      ArrayList<Integer> l1 = new ArrayList<Integer>();
      ArrayList<Integer> l2 = new ArrayList<Integer>();

      for (int j = 0; j < m; j++)
        l1.add(sc.nextInt());
        
      for (int j = 0; j < m; j++)
        l2.add(sc.nextInt());

      Collections.sort(l1);
      Collections.sort(l2, Collections.reverseOrder());

      int sum = 0;
      for (int j = 0; j < m; j++)
      {
        sum += l1.get(j) * l2.get(j);
      }

      System.out.println("Case #" + i + ": " + sum);
    }
  }
}
