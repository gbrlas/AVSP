package global2013.qualification;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lawnmover {

    static final String INPUT_FILENAME = "B-large.in"; // B-small-attempt0.in";
    static final boolean OUTPUT_TO_FILE = true;

    private void solve(Scanner sc, PrintWriter pw) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        int lawn[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lawn[i][j] = sc.nextInt();
            }
        }
        int[] horiz = new int[n];
        int[] vert = new int[m];
        for (int i = 0; i < n; i++) {
            horiz[i] = 0;
            for (int j = 0; j < m; j++) {
                horiz[i] = Math.max(horiz[i], lawn[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            vert[i] = 0;
            for (int j = 0; j < n; j++) {
                vert[i] = Math.max(vert[i], lawn[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lawn[i][j] < horiz[i] && lawn[i][j] < vert[j]) {
                    pw.println("NO");
                    return;
                }
            }
        }
        pw.println("YES");
    }

    public static void main(String[] args) throws FileNotFoundException {
        String inputFilename = System.getProperty("user.home") + "/Downloads/" + INPUT_FILENAME;
        Scanner sc = new Scanner(new FileReader(inputFilename));
        PrintWriter pw;
        if (OUTPUT_TO_FILE) {
            pw = new PrintWriter(inputFilename.replaceFirst("\\.in$", ".out"));
        } else {
            pw = new PrintWriter(System.out);
        }
        int caseCnt = sc.nextInt();
        sc.nextLine();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.err.println("Solving test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new Lawnmover().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
