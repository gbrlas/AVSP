
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Кирилл
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small-attempt1.in")));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        int numOfTestCases = Integer.parseInt(in.readLine());
        for (int testCase = 1; testCase <= numOfTestCases; testCase++) {
            StringTokenizer tokens = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(tokens.nextToken());
            int n = Integer.parseInt(tokens.nextToken());
            int[] motes = new int[n];
            tokens = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                motes[i] = Integer.parseInt(tokens.nextToken());
            }
            if (a == 1) {
                out.write("Case #" + testCase + ": " + motes.length + "");
                out.newLine();
            } else {
                System.out.println("Test #" + testCase);
                Arrays.sort(motes);
                System.out.println("a = " + a);
                System.out.println(Arrays.toString(motes));
                int[] p = new int[n];
                for (int i = 0; i < n; i++) {
                    while (a <= motes[i]) {
                        a = 2 * a - 1;
                        p[i]++;
                    }
                    a += motes[i];
                    if (i > 0) {
                        p[i] += p[i - 1];
                    }
                }
                System.out.println(Arrays.toString(p));
                int min = p[n - 1];
                for (int i = n - 1; i > 0; i--) {
                    min = Math.min(min, p[i - 1] + n - i);
                }
                System.out.println("s = " + min);
                System.out.println("Answer: " + Math.min(min, n));
                out.write("Case #" + testCase + ": " + Math.min(min, n) + "");
                out.newLine();
            }
        }
        in.close();
        out.close();
    }
}
