import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class CandySplit {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        br.readLine();
        String[] values = br.readLine().split(" ");
        int[] v = new int[values.length];
        for (int j = 0; j < values.length; j++) {
          v[j] = Integer.parseInt(values[j]);
        }
        System.out.println("Case #" + (i + 1) + ": " + solve(v));
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }

  private static String solve(int[] v) {
    Integer best = -1;
    for (int i = 1; i< (1 << v.length) - 1; i++) {
      int s1 = 0;
      int s2 = 0;
      int realSum1 = 0;
      int realSum2 = 0;
      for (int j = 0; j<v.length; j++) {
        if (((i >> j)&1)==0) {
          s1 ^= v[j];
          realSum1 += v[j];
        } else {
          s2 ^= v[j];
          realSum2 += v[j];
        }
      }
      if (s1 == s2) {
        best = Math.max(best, Math.max(realSum1, realSum2));
      }
    }
    return best > -1 ? Integer.toString(best) : "NO";
  }
}
