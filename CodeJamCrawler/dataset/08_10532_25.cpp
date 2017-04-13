
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;


/** @author Philip Rud */
public class TaskA {

    public static long solve(int P, int K, int L, ArrayList<Integer> frequency) {

        long count = 0;

        Collections.sort(frequency);
        Collections.reverse(frequency);

        int ttPress = 1;
        int keysUsed = 0;

        for (Integer freq: frequency) {

            keysUsed++;
            if (keysUsed > K) {
                ttPress++;
                keysUsed = 1;
            }

            count += freq * ttPress;

        }

        return count;
    }

    public static void main(String[] args) {
        Scanner fin = null;
        FileWriter fout = null;

        try {
            fin = new Scanner(new File("A-large.in"));
            fout = new FileWriter("A-large.out");

            int testsCount = fin.nextInt();
            for (int testNumber = 1; testNumber <= testsCount; testNumber++) {

                int P = fin.nextInt();
                int K = fin.nextInt();
                int L = fin.nextInt();

                if (K * P < L) {
                    fout.write(String.format(Locale.US, "Case #%d: Impossible\n", testNumber));
                    continue;
                }

                ArrayList<Integer> frequency = new ArrayList();

                for (int i = 0; i < L; i++) frequency.add(fin.nextInt());

                long solution = solve(P, K, L, frequency);

                fout.write(String.format(Locale.US, "Case #%d: %d\n", testNumber, solution));
            }
        } catch (IOException e) {
            System.out.println(e.getStackTrace());
        }

        try {fin.close();} catch (Exception e) {}
        try {fout.close();} catch (Exception e) {}
    }

}
