/*
 * Language: Java
 * Compiler: OpenJDK (IcedTea6 1.8.13), java 1.6.0_18
 */
import java.util.Scanner;

public class B {
  public static void main(String[] args) throws Throwable {
    Scanner in = new Scanner(System.in);
    int[][] a = new int[100][100];
    int t = in.nextInt();
    for (int c = 1; c <= t; c++) {
      int n = in.nextInt();
      int m = in.nextInt();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          a[i][j] = in.nextInt();
        }
      }
      boolean all = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          boolean nr = true, mr = true;
          for (int k = 0; k < n; k++) {
            if (a[k][j] > a[i][j]) {
              nr = false;
            }
          }
          for (int k = 0; k < m; k++) {
            if (a[i][k] > a[i][j]) {
              mr = false;
            }
          }
          if (!nr && !mr) {
            all = false;
          }
        }
      }
      System.out.printf("Case #%d: %s\n", c, all ? "YES" : "NO");
    }
  }
}
