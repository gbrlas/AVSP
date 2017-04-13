import java.io.BufferedReader;
import java.io.FileReader;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class SpinningBlade {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new FileReader("input.txt"));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i < numExamples; i++) {
        String[] parts = br.readLine().split(" ");
        int R = Integer.parseInt(parts[0]);
        int C = Integer.parseInt(parts[1]);
        int[][] d = new int[R][C];
        for (int r1 = 0; r1 < R; r1++) {
          String line = br.readLine();
          for (int c1 = 0; c1 < C; c1++) {
            d[r1][c1] = line.charAt(c1) - '0';
          }
        }

        int bestK = -1;
        for (int k = 3; k <= Math.min(R, C); k++) {
          boolean found = false;
          for (int r1 = 0; r1 <= R - k && !found; r1++) {
            for (int c1 = 0; c1 <= C - k && !found; c1++) {
              if (centered(d, r1, c1, k)) {
                bestK = k;
                found = true;
              }
            }
          }
        }
        System.out.println("Case #" + (i + 1) + ": " + (bestK >= 3 ? bestK : "IMPOSSIBLE"));
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }

  private static boolean centered(int[][] d, int r, int c, int k) {
    double horizontalWeight = 0;
    double verticalWeight = 0;
    for (int   i = r; i < r + k; i++) {
      for (int j = c; j < c + k; j++) {
        // ignore 4 corners
        if ((i == r || i == r + k - 1) && (j == c || j == c + k - 1)) {
          continue;
        }
        horizontalWeight += (i - (r+(k-1)/2.0)) * d[i][j];
        verticalWeight += (j - (c+(k-1)/2.0)) * d[i][j];
      }
    }
    return Math.abs(horizontalWeight)<.000001 && Math.abs(verticalWeight)<.000001;
  }
}
