package gcj.qual2013;

import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 4/13/13
 * Time: 9:36 AM
 * To change this template use File | Settings | File Templates.
 */
public class LawnMower {

  private static final int MAX_VAL = 1000;

  public boolean solve(int[][] heights) {
    while (true) {

      int m = heights.length;
      int n = heights[0].length;

      if (m == 1 || n == 1) {
        return true;
      }

      int minVal = MAX_VAL;
      int iMinVal = -1, jMinVal = -1;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (heights[i][j] < minVal) {
            minVal = heights[i][j];
            iMinVal = i;
            jMinVal = j;
          }
        }
      }

      boolean deleteCol = true;
      for (int i = 0; i < m; i++) {
        if (heights[i][jMinVal] != minVal) {
          deleteCol = false;
          break;
        }
      }

      boolean deleteRow = true;
      for (int i = 0; i < n; i++) {
        if (heights[iMinVal][i] != minVal) {
          deleteRow = false;
          break;
        }
      }

      if (!deleteRow && !deleteCol) {
        return false;
      }

      int mNew = m, nNew = n;
      if (deleteRow) {
        mNew = m - 1;
      }
      if (deleteCol) {
        nNew = n - 1;
      }

      int[][] newHeights = new int[mNew][nNew];
      int iNew = -1, jNew = -1;
      for (int i = 0; i < m; i++) {
        if (deleteRow && i == iMinVal) {
          continue;
        }
        iNew++;

        jNew = -1;
        for (int j = 0; j < n; j++) {
          if (deleteCol && j == jMinVal) {
            continue;
          }
          jNew++;
          newHeights[iNew][jNew] = heights[i][j];
        }
      }

      heights = newHeights;
    }
  }


  public static void main(String[] args) {

    LawnMower solver = new LawnMower();

    try {
      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\B-small-attempt0.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\lawnmower.out")));

      int T = Integer.parseInt(reader.readLine());
      for (int i = 0; i < T; i++) {
        String line = reader.readLine();
        String[] parts = line.split(" ");
        int m = Integer.parseInt(parts[0]);
        int n = Integer.parseInt(parts[1]);
        int[][] heights = new int[m][n];
        for (int im = 0; im < m; im++) {
          line = reader.readLine();
          parts = line.split(" ");
          for (int in = 0; in < n; in++) {
            heights[im][in] = Integer.parseInt(parts[in]);
          }
        }
        writer.print("Case #" + (i+1) + ": ");
        if (solver.solve(heights)) {
          writer.println("YES");
        } else {
          writer.println("NO");
        }
      }
      writer.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }


}
