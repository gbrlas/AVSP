import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

/**
 * Date: 12.04.14 at 20:04
 *
 * @author Nickolay Polyarniy aka PolarNick
 */
public class ProblemA {

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("inputA.txt"));
        PrintWriter out = new PrintWriter("outputA.txt");
        int t = Integer.parseInt(in.readLine());
        for (int i = 1; i <= t; i++) {
            int row1 = Integer.parseInt(in.readLine()) - 1;
            int[][] a1 = read(in, 4, 4);
            int row2 = Integer.parseInt(in.readLine()) - 1;
            int[][] a2 = read(in, 4, 4);

            HashSet<Integer> res1 = new HashSet<Integer>();
            for (int a : a1[row1]) {
                res1.add(a);
            }
            HashSet<Integer> res2 = new HashSet<Integer>();
            for (int a : a2[row2]) {
                if (res1.contains(a)) {
                    res2.add(a);
                }
            }
            String result = null;
            if (res2.size() == 1) {
                for (int a : res2) {
                    result = Integer.toString(a);
                }
            } else if (res2.size() == 0) {
                result = "Volunteer cheated!";
            } else {
                result = "Bad magician!";
            }
            out.println("Case #" + i + ": " + result);
        }
        in.close();
        out.close();
    }

    private static int[][] read(BufferedReader in, int n, int m) throws IOException {
        int[][] res = new int[n][m];
        for (int i = 0; i < n; i++) {
            StringTokenizer tok = new StringTokenizer(in.readLine());
            for (int j = 0; j < m; j++) {
                res[i][j] = Integer.parseInt(tok.nextToken());
            }
        }
        return res;
    }

}
