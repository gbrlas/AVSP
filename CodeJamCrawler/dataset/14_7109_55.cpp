import java.util.Scanner;

/**
 * Created by pratyush.verma on 12/04/14.
 */
public class CookieClickerAlpha {
    public static void main(String[] args) {
        int T;
        int index = 1;
        Scanner cin = new Scanner(System.in);
        T = cin.nextInt();
        while (T-- != 0) {
            double res = 0;
            double c, f, x;
            c = cin.nextDouble();
            f = cin.nextDouble();
            x = cin.nextDouble();
            int farm = 0;

            double prevTime = computeTimeTaken(c, f, x, farm);
            while (true) {
                farm++;
                double nextTime = computeTimeTaken(c, f, x, farm);
                if (prevTime < nextTime) {
                    res = prevTime;
                    break;
                }
                prevTime = nextTime;
            }

            System.out.print("Case #" + index++ + ": ");
            System.out.println(String.format("%.7f", res));

        }
    }

    private static double computeTimeTaken(double c, double f, double x, int farm) {
        double res = 0.0;
        for (int i = 0; i < farm; i++) {
            res += (c) / ((i * f) + 2.0);
        }
        res += x / ((farm * f) + 2.0);
        return res;
    }
}
