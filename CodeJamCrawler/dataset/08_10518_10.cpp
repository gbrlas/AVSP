
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;


/** @author Philip Rud */
public class TaskB {

    public static boolean isPrime(long n) {
        for (long i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }

        return true;
    }

    public static int solve(long A, long B, long P) {

        int[] sets = new int[(int) (B - A + 1)];

        for (int i = 0; i < sets.length; i++)
            sets[i] = i;

        for (long p = P; p <= B; p++) {

            if (!isPrime(p)) continue;

            int candidateSet = -1;

            for (int i = 0; i < sets.length; i++) {
                if ((A + i) % p == 0) {
                    if (candidateSet == -1)
                        candidateSet = sets[i];
                    else {
                        int group = sets[i];
                        for (int j = 0; j < sets.length; j++) {
                            if (sets[j] == group) sets[j] = candidateSet;
                        }
                    }
                }
            }
        }


        int setsCount = 0;

        ArrayList<Integer> setsList = new ArrayList();
        for (int i: sets) setsList.add(i);

        while (!setsList.isEmpty()) {
            setsCount++;
            Integer el = setsList.get(0);
            while(setsList.remove(el));
        }

        return setsCount;
    }

    public static void main(String[] args) {
        Scanner fin = null;
        FileWriter fout = null;

        try {
            fin = new Scanner(new File("B-small.in"));
            fout = new FileWriter("B-small.out");

            int testsCount = fin.nextInt();
            
            for (int testNumber = 1; testNumber <= testsCount; testNumber++) {

                long A = fin.nextLong();
                long B = fin.nextLong();
                long P = fin.nextLong();

                int solution = solve(A, B, P);

                fout.write(String.format(Locale.US, "Case #%d: %d\n", testNumber, solution));
            }
        } catch (IOException e) {
            System.out.println(e.getStackTrace());
        }

        try {fin.close();} catch (Exception e) {}
        try {fout.close();} catch (Exception e) {}
    }

}
