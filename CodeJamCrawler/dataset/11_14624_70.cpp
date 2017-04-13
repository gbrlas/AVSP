
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
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
 * @author Кирилл и Папа
 */
public class BotTrust {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt"))));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int n = Integer.parseInt(st.nextToken());
                int[] a = new int[n + 1];
                int[] b = new int[n + 1];
                int[] aTr = new int[n + 1];
                int[] bTr = new int[n + 1];
                int pointerA = 0;
                int pointerB = 0;
                aTr[pointerA] = 1;
                bTr[pointerB] = 1;
                for (int j = 0; j < n; j++) {
                    String robot = st.nextToken();
                    if (robot.equals("O")) {
                        a[j] = Integer.parseInt(st.nextToken());
                        aTr[++pointerA] = a[j];
                    } else {
                        b[j] = Integer.parseInt(st.nextToken());
                        bTr[++pointerB] = b[j];
                    }
                }
                pointerA = 0;
                pointerB = 0;
                int step = 0;
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    if (a[j] > 0) {
                        pointerA++;
                        step = Math.abs(aTr[pointerA] - aTr[pointerA - 1]) + 1;
                        sum = sum + step;
                        if (bTr[pointerB] > 0) {
                            if (bTr[pointerB + 1] > bTr[pointerB]) {
                                bTr[pointerB] =
                                        (step > bTr[pointerB + 1] - bTr[pointerB])
                                        ? bTr[pointerB + 1] : bTr[pointerB] + step;
                            } else {
                                bTr[pointerB] =
                                        (step > bTr[pointerB] - bTr[pointerB + 1])
                                        ? bTr[pointerB + 1] : bTr[pointerB] - step;
                            }
                        }
                    } else {
                        pointerB++;
                        step = Math.abs(bTr[pointerB] - bTr[pointerB - 1]) + 1;
                        sum = sum + step;
                        if (aTr[pointerA] > 0) {
                            if (aTr[pointerA + 1] > aTr[pointerA]) {
                                aTr[pointerA] =
                                        (step > aTr[pointerA + 1] - aTr[pointerA])
                                        ? aTr[pointerA + 1] : aTr[pointerA] + step;
                            } else {
                                aTr[pointerA] =
                                        (step > aTr[pointerA] - aTr[pointerA + 1])
                                        ? aTr[pointerA + 1] : aTr[pointerA] - step;
                            }
                        }
                    }
                }
                bw.write("Case #" + (i + 1) + ": " + sum);
                bw.newLine();
            }
            bw.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
