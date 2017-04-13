
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Locale;
import java.util.Scanner;


/** @author Philip Rud */
public class TaskB {

    public static long solve(String s) {
        long count = 0;

        byte[] signs = new byte[s.length()-1];
        for (byte i = 0; i < signs.length; i++) signs[i] = 0;

        while (true) {
            

            //evaluating
            long total = 0;

            byte currentOp = 1;
            long currentNum = Long.parseLong("" + s.charAt(0));

            for (byte i=0; i < signs.length; i++) {

                if (signs[i] == 0) {
                    currentNum = currentNum * 10 + Long.parseLong("" + s.charAt(i+1));
                } else {
                    if (currentOp == 1) total += currentNum;
                    if (currentOp == 2) total -= currentNum;
                    currentNum = 0;
                    currentOp = signs[i];
                    currentNum = currentNum * 10 + Long.parseLong("" + s.charAt(i+1));
                }

            }

            if (currentOp == 1) total += currentNum;
            if (currentOp == 2) total -= currentNum;

            //checking whether is ugly
            if ((total % 2 == 0) || (total % 3 == 0) || (total % 5 == 0) || (total % 7 == 0))
                count++;

            //next case
            if (signs.length > 0) {
                signs[0]++;
                for (byte i = 0; i < signs.length-1; i++)
                    if (signs[i] > 2) {
                        signs[i] = 0;
                        signs[i+1]++;
                    }
                if (signs[signs.length-1] > 2) break;
            } else break;
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner fin = null;
        FileWriter fout = null;

        try {
            fin = new Scanner(new File("B-small.in"));
            fout = new FileWriter("B-small.out");

            int testsCount = fin.nextInt();
            for (int testNumber = 1; testNumber <= testsCount; testNumber++) {

                String s = fin.next();

                long solution = solve(s);

                fout.write(String.format(Locale.US, "Case #%d: %d\n", testNumber, solution));
            }
        } catch (IOException e) {
            System.out.println(e.getStackTrace());
        }

        try {fin.close();} catch (Exception e) {}
        try {fout.close();} catch (Exception e) {}
    }

}
