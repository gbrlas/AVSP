import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        Scanner sc = new Scanner(/*System.in*/ new File(args[0]));
        PrintWriter pw = new PrintWriter(/*System.out*/ new File(args[1]));
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            List<Integer> one = readMatrix(sc);
            one.retainAll(readMatrix(sc));
            pw.print(String.format("Case #%d: ", t));
            if (one.size() > 1) {
                pw.println("Bad magician!");
            } else if (one.size() == 1) {
                pw.println(one.get(0));
            } else if (one.size() == 0) {
                pw.println("Volunteer cheated!");
            }
        }
        pw.flush();
        pw.close();
    }

    private static List<Integer> readMatrix(Scanner sc) {
        List<Integer> a = new ArrayList<Integer>(4);
        int r = sc.nextInt() - 1;
        for (int i = 0; i < r; i++) {
            sc.nextInt();
            sc.nextInt();
            sc.nextInt();
            sc.nextInt();
        }
        for (int i = 0; i < 4; i++) {
            a.add(sc.nextInt());
        }
        for (int i = r+1; i < 4; i++) {
            sc.nextInt();
            sc.nextInt();
            sc.nextInt();
            sc.nextInt();
        }
        return a;
    }
}
