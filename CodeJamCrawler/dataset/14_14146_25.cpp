import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MagicTrick {

    public static void main(String[] args) throws FileNotFoundException {
        File input = new File("A-small-attempt0.in");
        Scanner data = new Scanner(input);
        PrintStream output = new PrintStream(new File("A-small-attempt0.out"));
        int times = data.nextInt();

        for(int i = 1; i <= times; i++){
            int ans1 = data.nextInt() - 1;
            List<List<Integer>> cards1 = new ArrayList<List<Integer>>();
            for (int j = 0; j < 4; j++) {
                List<Integer> row = new ArrayList<Integer>();
                for (int k = 0; k < 4; k++) {
                    row.add(data.nextInt());
                }
                cards1.add(row);
            }
            int ans2 = data.nextInt() - 1;
            List<List<Integer>> cards2 = new ArrayList<List<Integer>>();
            for (int j = 0; j < 4; j++) {
                List<Integer> row = new ArrayList<Integer>();
                for (int k = 0; k < 4; k++) {
                    row.add(data.nextInt());
                }
                cards2.add(row);
            }

            List<Integer> ansRow1 = cards1.get(ans1);
            List<Integer> ansRow2 = cards2.get(ans2);

            List<Integer> diff = new ArrayList<Integer>();

            for (int j = 0; j < 4; j++) {
                if (ansRow1.contains(ansRow2.get(j))) {
                    diff.add(ansRow2.get(j));
                }
            }

            if (diff.isEmpty()) {
                output.println("Case #" + i + ": Volunteer cheated!");
            } else if (diff.size() > 1) {
                output.println("Case #" + i + ": Bad magician!");
            } else {
                output.println("Case #" + i + ": " + diff.get(0));
            }
        }
    }
}
