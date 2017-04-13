
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
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
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("B-small-attempt0.in")));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        int numOfTestCases = Integer.parseInt(in.readLine());
        for (int testCase = 1; testCase <= numOfTestCases; testCase++) {
            StringTokenizer tokens = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(tokens.nextToken());
            int m = Integer.parseInt(tokens.nextToken());
            int[][] a = new int[n][m];
            for (int i = 0; i < n; i++) {
                tokens = new StringTokenizer(in.readLine());
                for (int j = 0; j < m; j++) {
                    a[i][j] = Integer.parseInt(tokens.nextToken());
                }
            }
            boolean isOk = true;
            boolean[] cutRows = new boolean[n];
            boolean[] cutColumns = new boolean[m];
            while (true) {
                int inRowMin = -1;
                int inColMin = -1;
                int min = Integer.MAX_VALUE;
                for (int i = 0; i < n; i++) {
                    if (cutRows[i]) {
                        continue;
                    }
                    for (int j = 0; j < m; j++) {
                        if (cutColumns[j]) {
                            continue;
                        }
                        if (a[i][j] < min) {
                            min = a[i][j];
                            inRowMin = i;
                            inColMin = j;
                        }
                    }
                }
                if (min == Integer.MAX_VALUE) {
                    break;
                }
                boolean rowContainsSameValues = true;
                boolean columnContainsSameValues = true;
                for (int i = 0; i < m; i++) {
                    if (!rowContainsSameValues) {
                        break;
                    }
                    if (cutColumns[i]) {
                        continue;
                    }
                    if (a[inRowMin][i] != min) {
                        rowContainsSameValues = false;
                    }
                }
                for (int i = 0; i < n; i++) {
                    if (!columnContainsSameValues) {
                        break;
                    }
                    if (cutRows[i]) {
                        continue;
                    }
                    if (a[i][inColMin] != min) {
                        columnContainsSameValues = false;
                    }
                }
                if ((columnContainsSameValues) && (rowContainsSameValues)) {
                    cutRows[inRowMin] = true;
                    cutColumns[inColMin] = true;
                } else if (columnContainsSameValues) {
                    cutColumns[inColMin] = true;
                } else if (rowContainsSameValues) {
                    cutRows[inRowMin] = true;
                } else {
                    isOk = false;
                }
                if (!isOk) {
                    break;
                }
            }
            out.write("Case #" + testCase + ": " + (isOk ? "YES" : "NO"));
            out.newLine();
        }
        in.close();
        out.close();
    }
}
