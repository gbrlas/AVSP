package gcj.round1B_2013;

import java.io.*;
import java.util.Arrays;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 5/4/13
 * Time: 8:39 AM
 * To change this template use File | Settings | File Templates.
 */
public class Prob {


  public static void main(String[] args) {

    try {

      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\gcj\\round1B_2013\\A_small.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\gcj\\round1B_2013\\A.out")));

      int T = Integer.parseInt(reader.readLine());
      for (int iT = 0; iT < T; iT++) {

        Integer[] dataInfo = parseInt(reader.readLine());
        int A = dataInfo[0];
        int N = dataInfo[1];

        Integer[] motes = parseInt(reader.readLine());
        if (motes.length != N) {
          System.err.println("FATAL ERROR");
        }
        Arrays.sort(motes);

        int ans = 0;
        for (int iMote = 0; iMote < N; iMote++) {

          int sum = A;
          if (sum == 1) {
            ans++;
            continue;
          }

          int nTry = 0;
          while (sum <= motes[iMote]) {
            sum = 2*sum-1;
            nTry++;
          }

          if (nTry >= N-iMote) {
            ans += N-iMote;
            break;
          } else {
            A = sum + motes[iMote];
            ans += nTry;
          }
        }

        //System.out.println(ans);
        writer.print("Case #" + (iT + 1) + ": ");
        writer.println(ans);
      }

      reader.close();
      writer.close();

    } catch (Exception e) {
      e.printStackTrace();
    }

  }

  public static Integer[] parseInt(String line) {
    String[] parts = line.split(" ");
    Integer[] intParts = new Integer[parts.length];
    for (int i = 0; i < parts.length; i++) {
      intParts[i] = Integer.parseInt(parts[i]);
    }
    return intParts;
  }

}
