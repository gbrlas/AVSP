import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Date: 13.04.14 at 1:24
 *
 * @author Nickolay Polyarniy aka PolarNick
 */
public class ProblemD {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("inputD.txt"));
        PrintWriter out = new PrintWriter("outputD.txt");
        int t = Integer.parseInt(in.readLine());
        for (int testNumber = 1; testNumber <= t; testNumber++) {
            int n = Integer.parseInt(in.readLine());
            double[] a = new double[n];
            double[] b = new double[n];
            StringTokenizer tok = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Double.parseDouble(tok.nextToken());
            }
            tok = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                b[i] = Double.parseDouble(tok.nextToken());
            }

            Arrays.sort(a);
            Arrays.sort(b);
            int badResult = 0;
            {
                int nextB = 0;
                int lastB = n - 1;
                for (int i = 0; i < n; i++) {
                    if (a[i] > b[nextB]) {
                        badResult++;
                        nextB++;
                    } else {
                        lastB--;
                    }
                }
            }
            int result = 0;
            boolean[] wasUsed = new boolean[n];
            for (int i = 0; i < n; i++) {
                int toUse = -1;
                for (int j = 0; j < n; j++) {
                    if (!wasUsed[j] && b[j] > a[i]) {
                        toUse = j;
                        break;
                    }
                }
                if (toUse == -1) {
                    for (int j = 0; j < n; j++) {
                        if (!wasUsed[j]) {
                            toUse = j;
                            break;
                        }
                    }
                }
                wasUsed[toUse] = true;
                if (a[i] > b[toUse]) {
                    result++;
                }
            }

            out.println("Case #" + testNumber + ": " + badResult + " " + result);
        }
        in.close();
        out.close();
    }

}
