import javax.swing.plaf.basic.BasicInternalFrameTitlePane;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * TODO
 *
 * @author Leo Polovets
 */
public class FreeCellStatistics {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new FileReader(args[0]));
    try {
      int numExamples = Integer.parseInt(br.readLine());
      for (int i = 0; i<numExamples; i++) {
        String[] parts = br.readLine().split(" ");
        long numToday = Long.parseLong(parts[0]);
        int percentToday = Integer.parseInt(parts[1]);
        int percentAll = Integer.parseInt(parts[2]);
        if (percentAll ==100) {
          System.out.println("Case #" + (i+1) + ": " + (percentToday < 100 ? "Broken" : "Possible"));
        } else if (percentAll == 0) {
          System.out.println("Case #" + (i+1) + ": " + (percentToday > 0 ? "Broken" : "Possible"));
        } else {
          int gcd = gcd(100, percentToday);
          System.out.println("Case #" + (i+1) + ": " + (numToday < 100 / gcd ? "Broken" : "Possible"));
        }
      }
    } catch (Exception e) {
      e.printStackTrace();
    } finally {
      br.close();
    }
  }
  
  private static int gcd(int a, int b) {
     return b == 0 ? a : gcd(b, a % b);
  }
}
