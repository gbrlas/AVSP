import java.util.Scanner;

public class Snapper
{

    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int tsts = in.nextInt();
        for (int tst = 0; tst < tsts; ++tst)
        {
            int n = in.nextInt();
            int k = in.nextInt();
            System.out.printf("Case #%d: %s\n", tst + 1, solve(n, k));
        }
    }

    private static String solve(int n, int k)
    {
        int mask = 1 << n;
        boolean ans = k % mask == mask - 1;
        return ans ? "ON" : "OFF";
    }

}
