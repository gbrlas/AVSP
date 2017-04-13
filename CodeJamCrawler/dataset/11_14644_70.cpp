
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOError;
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
 * @author Кирилл и Папа
 */
public class CandySplitting {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt"))));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                int n = Integer.parseInt(br.readLine());
                StringTokenizer st = new StringTokenizer(br.readLine());
                int[] piles = new int[n];
                for (int j = 0; j < n; j++) {
                    piles[j] = Integer.parseInt(st.nextToken());
                }
                Arrays.sort(piles);
                char[][] c = new char[n][];
                for (int j = 0; j < n; j++) {
                    c[j] = Integer.toBinaryString(piles[j]).toCharArray();
                }
                if (!hasSolution(c)) {
                    bw.write("Case #" + (i + 1) + ": NO");
                    bw.newLine();
                } else {
                    int sum = 0;
                    for (int j = 1; j < piles.length; j++) {
                        sum = sum + piles[j];
                    }
                    bw.write("Case #" + (i + 1) + ": " + sum);
                    bw.newLine();
                }
            }
            bw.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static boolean hasSolution(char[][] c) {
        int maxSize = -1;
        for (int i = 0; i < c.length; i++) {
            if (c[i].length > maxSize) {
                maxSize = c[i].length;
            }
        }
        for (int i = 0; i < c.length; i++) {
            char[] v = c[i];
            c[i] = new char[maxSize];
            for (int j = 0; j < maxSize - v.length; j++) {
                c[i][j] = '0';
            }
            for (int j = maxSize - v.length; j < maxSize; j++) {
                c[i][j] = v[j - maxSize + v.length];
            }
        }
        char[] sum = new char[maxSize];
        for (int i = 0; i < maxSize; i++) {
            sum[i] = '0';
        }
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[i].length; j++) {
                if ((c[i][j] == '1') && (sum[j] == '0')) {
                    sum[j] = '1';
                } else if ((c[i][j] == '1') && (sum[j] == '1')) {
                    sum[j] = '0';
                } else if ((c[i][j] == '0') && (sum[j] == '0')) {
                    sum[j] = '0';
                } else if ((c[i][j] == '0') && (sum[j] == '1')) {
                    sum[j] = '1';
                }
            }
        }
        for (int i = 0; i < sum.length; i++) {
            if (sum[i] == '1') {
                return false;
            }
        }
        return true;
    }
}
