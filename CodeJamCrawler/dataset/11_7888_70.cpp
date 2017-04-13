import java.util.Scanner;

public class CandySplitting {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int numTests = Integer.valueOf(s.nextLine());
        for (int i = 0; i < numTests; ++i) {
            int size = Integer.valueOf(s.nextLine());
            int[] ints = new int[size];
            String[] candy = s.nextLine().split(" ");
            for (int j = 0; j < candy.length; ++j) {
                ints[j] = Integer.valueOf(candy[j]);
            }
            System.out.println(String.format("Case #%d: %s", i + 1, doIt(ints)));
        }
    }

    public static String doIt(int[] ints) {
        boolean good = false;
        int pLim = ints.length;
        int max = 0;
        for (int k = 0; k < ints.length; ++k) {
            for (int i = 1; i < pLim; ++i) {
                int a = 0;
                int aa = 0;
                int b = 0;
                int bb = 0;
                for (int j = 0; j < i; ++j) {
                    a ^= ints[j];
                    aa += ints[j];
                }
                for (int j = i; j < ints.length; ++j) {
                    b ^= ints[j];
                    bb += ints[j];
                }
                if (a == b) {
                    if (aa > max) {
                        max = aa;
                    }
                    if (bb > max) {
                        max = bb;
                    }
                    good = true;
                }
            }
            int l = ints[0];
            for (int m = 1; m < ints.length; ++m) {
                ints[m - 1] = ints[m];
            }
            ints[ints.length - 1] = l;
        }

        if (good) {
            return String.valueOf(max);
        } else {
            return "NO";
        }
    }
}
