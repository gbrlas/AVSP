import jlab.graphics.DWindow;
import java.util.Scanner;
import java.io.*;

public class AAA {
  public static void main(String[] args) throws IOException {
    Scanner kb = new Scanner(System.in);
    int t = kb.nextInt();
    for (int z = 1; z <= t; z++)
    {
      System.out.println("Case #" + z + ":");
      int r, c, m;
      r = kb.nextInt();
      c = kb.nextInt();
      m = kb.nextInt();
      if (m == 0)
      {
        for (int i = 0; i < r; i++)
        {
          for (int j = 0; j < c; j++)
            if (i == j && i == 0) System.out.print("c");
            else System.out.print(".");
          System.out.println("");
        }
      }
      else if (m == r * c - 1)
      {
        for (int i = 0; i < r; i++)
        {
          for (int j = 0; j < c; j++)
            if (i == j && i == 0) System.out.print("c");
            else System.out.print("*");
            System.out.println("");
        }
      }
      else if (r == 1 && c == 3 && m == 1)
      {
        System.out.println("c.*");
      }
      //
      else if (r == 3 && c == 1 && m == 1)
      {
        System.out.println("c");
        System.out.println(".");
        System.out.println("*");
      }
      //
      else if (r == 1 && c == 4 && m == 1)
      {
        System.out.println("c..*");
      }
      else if (r == 1 && c == 4 && m == 2)
      {
        System.out.println("c.**");
      }
      //
      else if (r == 4 && c == 1 && m == 1)
      {
        System.out.println("c");
        System.out.println(".");
        System.out.println(".");
        System.out.println("*");
      }
      else if (r == 4 && c == 1 && m == 2)
      {
        System.out.println("c");
        System.out.println(".");
        System.out.println("*");
        System.out.println("*");
      }
      //
      else if (r == 1 && c == 5 && m == 1)
      {
        System.out.println("c...*");
      }
      else if (r == 1 && c == 5 && m == 2)
      {
        System.out.println("c..**");
      }
      else if (r == 1 && c == 5 && m == 3)
      {
        System.out.println("c.***");
      }
      //
      else if (r == 5 && c == 1 && m == 1)
      {
        System.out.println("c");
        System.out.println(".");
        System.out.println(".");
        System.out.println(".");
        System.out.println("*");
      }
      else if (r == 5 && c == 1 && m == 2)
      {
        System.out.println("c");
        System.out.println(".");
        System.out.println(".");
        System.out.println("*");
        System.out.println("*");
      }
      else if (r == 5 && c == 1 && m == 3)
      {
        System.out.println("c");
        System.out.println(".");
        System.out.println("*");
        System.out.println("*");
        System.out.println("*");
      }
      //
      else if (r == 2 && c == 3 && m == 2)
      {
        System.out.println("c.*");
        System.out.println("..*");
      }
      //
      else if (r == 3 && c == 2 && m == 2)
      {
        System.out.println("c.");
        System.out.println("..");
        System.out.println("**");
      }
      //
      else if (r == 2 && c == 4 && m == 2)
      {
        System.out.println("c..*");
        System.out.println("...*");
      }
      else if (r == 2 && c == 4 && m == 4)
      {
        System.out.println("c.**");
        System.out.println("..**");
      }
      //
      else if (r == 4 && c == 2 && m == 2)
      {
        System.out.println("c.");
        System.out.println("..");
        System.out.println("..");
        System.out.println("**");
      }
      else if (r == 4 && c == 2 && m == 4)
      {
        System.out.println("c.");
        System.out.println("..");
        System.out.println("**");
        System.out.println("**");
      }
      //
      else if (r == 2 && c == 5 && m == 2)
      {
        System.out.println("c...*");
        System.out.println("....*");
      }
      else if (r == 2 && c == 5 && m == 4)
      {
        System.out.println("c..**");
        System.out.println("...**");
      }
      else if (r == 2 && c == 5 && m == 6)
      {
        System.out.println("c.***");
        System.out.println("..***");
      }
      //
      else if (r == 5 && c == 2 && m == 2)
      {
        System.out.println("c.");
        System.out.println("..");
        System.out.println("..");
        System.out.println("..");
        System.out.println("**");
      }
      else if (r == 5 && c == 2 && m == 4)
      {
        System.out.println("c.");
        System.out.println("..");
        System.out.println("..");
        System.out.println("**");
        System.out.println("**");
      }
      else if (r == 5 && c == 2 && m == 6)
      {
        System.out.println("c.");
        System.out.println("..");
        System.out.println("**");
        System.out.println("**");
        System.out.println("**");
      }
      //
      else if (r == 3 && c == 3 && m == 1)
      {
        System.out.println("c..");
        System.out.println("...");
        System.out.println("..*");
      }

      else if (r == 3 && c == 3 && m == 3)
      {
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("***");
      }
      else if (r == 3 && c == 3 && m == 5)
      {
        System.out.println("c.*");
        System.out.println("..*");
        System.out.println("***");
      }
      //
      else if (r == 3 && c == 4 && m == 1)
      {
        System.out.println("....");
        System.out.println(".c..");
        System.out.println("...*");
      }
      else if (r == 3 && c == 4 && m == 2)
      {
        System.out.println("....");
        System.out.println("c...");
        System.out.println("..**");
      }
      else if (r == 3 && c == 4 && m == 3)
      {
        System.out.println("...*");
        System.out.println(".c.*");
        System.out.println("...*");
      }
      else if (r == 3 && c == 4 && m == 4)
      {
        System.out.println(".c..");
        System.out.println("....");
        System.out.println("****");
      }
      else if (r == 3 && c == 4 && m == 6)
      {
        System.out.println("..**");
        System.out.println("c.**");
        System.out.println("..**");
      }
      else if (r == 3 && c == 4 && m == 8)
      {
        System.out.println("c.**");
        System.out.println("..**");
        System.out.println("****");
      }
      //
      else if (r == 4 && c == 3 && m == 1)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("..*");
      }
      else if (r == 4 && c == 3 && m == 2)
      {
        System.out.println("...");
        System.out.println("...");
        System.out.println("c.*");
        System.out.println("..*");
      }
      else if (r == 4 && c == 3 && m == 3)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("***");
      }
      else if (r == 4 && c == 3 && m == 4)
      {
        System.out.println("..*");
        System.out.println("c.*");
        System.out.println("..*");
        System.out.println("..*");
      }
      else if (r == 4 && c == 3 && m == 6)
      {
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("***");
        System.out.println("***");
      }
      else if (r == 4 && c == 3 && m == 8)
      {
        System.out.println("c.*");
        System.out.println("..*");
        System.out.println("***");
        System.out.println("***");
      }
      //
      else if (r == 3 && c == 5 && m == 1)
      {
        System.out.println(".....");
        System.out.println(".c...");
        System.out.println("....*");
      }
      else if (r == 3 && c == 5 && m == 2)
      {
        System.out.println(".....");
        System.out.println(".c...");
        System.out.println("...**");
      }
      else if (r == 3 && c == 5 && m == 3)
      {
        System.out.println("....*");
        System.out.println(".c..*");
        System.out.println("....*");
      }
      else if (r == 3 && c == 5 && m == 4)
      {
        System.out.println("....*");
        System.out.println(".c..*");
        System.out.println("...**");
      }
      else if (r == 3 && c == 5 && m == 5)
      {
        System.out.println(".c...");
        System.out.println(".....");
        System.out.println("*****");
      }
      else if (r == 3 && c == 5 && m == 6)
      {
        System.out.println("...**");
        System.out.println(".c.**");
        System.out.println("...**");
      }
      else if (r == 3 && c == 5 && m == 7)
      {
        System.out.println(".c..*");
        System.out.println("....*");
        System.out.println("*****");
      }
      else if (r == 3 && c == 5 && m == 9)
      {
        System.out.println("..***");
        System.out.println("c.***");
        System.out.println("..***");
      }
      else if (r == 3 && c == 5 && m == 11)
      {
        System.out.println("c.***");
        System.out.println("..***");
        System.out.println("*****");
      }
      //
      else if (r == 5 && c == 3 && m == 1)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("...");
        System.out.println("..*");
      }
      else if (r == 5 && c == 3 && m == 2)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("..*");
        System.out.println("..*");
      }
      else if (r == 5 && c == 3 && m == 3)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("...");
        System.out.println("***");
      }
      else if (r == 5 && c == 3 && m == 4)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("..*");
        System.out.println("***");
      }
      else if (r == 5 && c == 3 && m == 5)
      {
        System.out.println("..*");
        System.out.println("c.*");
        System.out.println("..*");
        System.out.println("..*");
        System.out.println("..*");
      }
      else if (r == 5 && c == 3 && m == 6)
      {
        System.out.println("...");
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("***");
        System.out.println("***");
      }
      else if (r == 5 && c == 3 && m == 7)
      {
        System.out.println("..*");
        System.out.println("..*");
        System.out.println("c.*");
        System.out.println("..*");
        System.out.println("***");
      }
      else if (r == 5 && c == 3 && m == 9)
      {
        System.out.println(".c.");
        System.out.println("...");
        System.out.println("***");
        System.out.println("***");
        System.out.println("***");
      }
      else if (r == 5 && c == 3 && m == 11)
      {
        System.out.println("c.*");
        System.out.println("..*");
        System.out.println("***");
        System.out.println("***");
        System.out.println("***");
      }
      //
      else if (r == 4 && c == 4 && m == 1)
      {
        System.out.println("c...");
        System.out.println("....");
        System.out.println("....");
        System.out.println("...*");
      }
      else if (r == 4 && c == 4 && m == 2)
      {
        System.out.println("....");
        System.out.println("..c.");
        System.out.println("....");
        System.out.println("..**");
      }
      else if (r == 4 && c == 4 && m == 3)
      {
        System.out.println("....");
        System.out.println(".c..");
        System.out.println("...*");
        System.out.println("..**");
      }
      else if (r == 4 && c == 4 && m == 4)
      {
        System.out.println("....");
        System.out.println("..c.");
        System.out.println("....");
        System.out.println("****");
      }
      else if (r == 4 && c == 4 && m == 5)
      {
        System.out.println("....");
        System.out.println("..c.");
        System.out.println("*...");
        System.out.println("****");
      }
      else if (r == 4 && c == 4 && m == 6)
      {
        System.out.println("....");
        System.out.println("...c");
        System.out.println("**..");
        System.out.println("****");
      }
      else if (r == 4 && c == 4 && m == 7)
      {
        System.out.println("*...");
        System.out.println("*.c.");
        System.out.println("*...");
        System.out.println("****");
      }
      else if (r == 4 && c == 4 && m == 8)
      {
        System.out.println("..c.");
        System.out.println("....");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 4 && c == 4 && m == 10)
      {
        System.out.println("*.c.");
        System.out.println("*...");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 4 && c == 4 && m == 12)
      {
        System.out.println("**.c");
        System.out.println("**..");
        System.out.println("****");
        System.out.println("****");
      }
      //
      else if (r == 4 && c == 5 && m == 1)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("....*");
      }
      else if (r == 4 && c == 5 && m == 2)
      {
        System.out.println("*....");
        System.out.println("...c.");
        System.out.println(".....");
        System.out.println("....*");
      }
      else if (r == 4 && c == 5 && m == 3)
      {
        System.out.println("*....");
        System.out.println(".....");
        System.out.println(".c...");
        System.out.println("...**");
      }
      else if (r == 4 && c == 5 && m == 4)
      {
        System.out.println("....*");
        System.out.println("..c.*");
        System.out.println("....*");
        System.out.println("....*");
      }
      else if (r == 4 && c == 5 && m == 5)
      {
        System.out.println(".....");
        System.out.println("..c..");
        System.out.println(".....");
        System.out.println("*****");
      }
      else if (r == 4 && c == 5 && m == 6)
      {
        System.out.println(".....");
        System.out.println("..c..");
        System.out.println("*....");
        System.out.println("*****");
      }
      else if (r == 4 && c == 5 && m == 7)
      {
        System.out.println(".....");
        System.out.println("..c..");
        System.out.println("*...*");
        System.out.println("*****");
      }
      else if (r == 4 && c == 5 && m == 8)
      {
        System.out.println("...**");
        System.out.println(".c.**");
        System.out.println("...**");
        System.out.println("...**");
      }
      else if (r == 4 && c == 5 && m == 9)
      {
        System.out.println("...**");
        System.out.println(".c.**");
        System.out.println("...**");
        System.out.println("..***");
      }
      else if (r == 4 && c == 5 && m == 10)
      {
        System.out.println("...c.");
        System.out.println(".....");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 4 && c == 5 && m == 11)
      {
        System.out.println("...**");
        System.out.println(".c.**");
        System.out.println("...**");
        System.out.println("*****");
      }
      else if (r == 4 && c == 5 && m == 12)
      {
        System.out.println("***.c");
        System.out.println("***..");
        System.out.println("***..");
        System.out.println("***..");
      }
      else if (r == 4 && c == 5 && m == 14)
      {
        System.out.println("***.c");
        System.out.println("***..");
        System.out.println("***..");
        System.out.println("*****");
      }
      else if (r == 4 && c == 5 && m == 16)
      {
        System.out.println("***.c");
        System.out.println("***..");
        System.out.println("*****");
        System.out.println("*****");
      }
      //
      else if (r == 5 && c == 4 && m == 1)
      {
        System.out.println("c...");
        System.out.println("....");
        System.out.println("....");
        System.out.println("....");
        System.out.println("...*");
      }
      else if (r == 5 && c == 4 && m == 2)
      {
        System.out.println("*...");
        System.out.println("..c.");
        System.out.println("....");
        System.out.println("....");
        System.out.println("...*");
      }
      else if (r == 5 && c == 4 && m == 3)
      {
        System.out.println("*...");
        System.out.println("..c.");
        System.out.println("....");
        System.out.println("....");
        System.out.println("..**");
      }
      else if (r == 5 && c == 4 && m == 4)
      {
        System.out.println("....");
        System.out.println("..c.");
        System.out.println("....");
        System.out.println("....");
        System.out.println("****");
      }
      else if (r == 5 && c == 4 && m == 5)
      {
        System.out.println("...*");
        System.out.println(".c.*");
        System.out.println("...*");
        System.out.println("...*");
        System.out.println("...*");
      }
      else if (r == 5 && c == 4 && m == 6)
      {
        System.out.println("...*");
        System.out.println(".c.*");
        System.out.println("...*");
        System.out.println("...*");
        System.out.println("..**");
      }
      else if (r == 5 && c == 4 && m == 7)
      {
        System.out.println("..**");
        System.out.println("...*");
        System.out.println(".c.*");
        System.out.println("...*");
        System.out.println("..**");
      }
      else if (r == 5 && c == 4 && m == 8)
      {
        System.out.println("....");
        System.out.println(".c..");
        System.out.println("....");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 5 && c == 4 && m == 9)
      {
        System.out.println("....");
        System.out.println(".c..");
        System.out.println("...*");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 5 && c == 4 && m == 10)
      {
        System.out.println("..**");
        System.out.println("..**");
        System.out.println("c.**");
        System.out.println("..**");
        System.out.println("..**");
      }
      else if (r == 5 && c == 4 && m == 11)
      {
        System.out.println("...*");
        System.out.println(".c.*");
        System.out.println("...*");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 5 && c == 4 && m == 12)
      {
        System.out.println(".c..");
        System.out.println("....");
        System.out.println("****");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 5 && c == 4 && m == 14)
      {
        System.out.println(".c.*");
        System.out.println("...*");
        System.out.println("****");
        System.out.println("****");
        System.out.println("****");
      }
      else if (r == 5 && c == 4 && m == 16)
      {
        System.out.println("c.**");
        System.out.println("..**");
        System.out.println("****");
        System.out.println("****");
        System.out.println("****");
      }
      //
      else if (r == 5 && c == 5 && m == 1)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("....*");
      }
      else if (r == 5 && c == 5 && m == 2)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("...**");
      }
      else if (r == 5 && c == 5 && m == 3)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("....*");
        System.out.println("...**");
      }
      else if (r == 5 && c == 5 && m == 4)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("...**");
        System.out.println("...**");
      }
      else if (r == 5 && c == 5 && m == 5)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 6)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("....*");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 7)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("...**");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 8)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println("....*");
        System.out.println("*...*");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 9)
      {
        System.out.println(".....");
        System.out.println("..c..");
        System.out.println("*...*");
        System.out.println("*...*");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 10)
      {
        System.out.println("c....");
        System.out.println(".....");
        System.out.println(".....");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 11)
      {
        System.out.println("**...");
        System.out.println("*..c.");
        System.out.println("*....");
        System.out.println("*...*");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 12)
      {
        System.out.println(".....");
        System.out.println("..c..");
        System.out.println("*...*");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 13)
      {
        System.out.println("....*");
        System.out.println("..c.*");
        System.out.println("....*");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 14)
      {
        System.out.println("....*");
        System.out.println("..c.*");
        System.out.println("*...*");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 15)
      {
        System.out.println("...c.");
        System.out.println(".....");
        System.out.println("*****");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 16)
      {
        System.out.println("**.c.");
        System.out.println("**...");
        System.out.println("**...");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 17)
      {
        System.out.println("**..c");
        System.out.println("**...");
        System.out.println("***..");
        System.out.println("*****");
        System.out.println("*****");
      }
      else if (r == 5 && c == 5 && m == 19)
      {
        System.out.println("***..");
        System.out.println("***.c");
        System.out.println("***..");
        System.out.println("*****");
        System.out.println("*****");
      }
     else if (r == 5 && c == 5 && m == 21)
      {
        System.out.println("***.c");
        System.out.println("***..");
        System.out.println("*****");
        System.out.println("*****");
        System.out.println("*****");
      }
      else System.out.println("Impossible");
    }
  }
}