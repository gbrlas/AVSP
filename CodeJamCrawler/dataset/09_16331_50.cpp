import java.math.BigDecimal;
import java.util.Scanner;

public class Fire {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        final int t = sc.nextInt();

        for (int tt = 1; tt <= t; ++tt) {

            final int flies = sc.nextInt();

            long A = 0;
            long C = 0;
            long E = 0;

            long B = 0;
            long D = 0;
            long F = 0;

            for (int i = 0; i < flies; ++i) {
                A += sc.nextLong();
                C += sc.nextLong();
                E += sc.nextLong();

                B += sc.nextLong();
                D += sc.nextLong();
                F += sc.nextLong();
            }

            double p;

            long up = A * B + C * D + E * F;
            long co = B * B + D * D + F * F;
            if (co == 0) {
                
                if (up == 0)
                    p = 0;
                else
                {
                    p = 0;
                }
            } else {
                p = -up / (double) co;
                //p = Math.ceil(p);
                if (p < 0)
                    p = 0;
            }

            double result = 0;
            double x = (A + p * B) / flies;
            result += x * x;

            x = (C + p * D) / flies;
            result += x * x;

            x = (E + p * F) / flies;
            result += x * x;

            result = Math.sqrt(result);
            
            /*DecimalFormat df = new DecimalFormat();
            DecimalFormatSymbols ddd = df.getDecimalFormatSymbols();
            ddd.setDecimalSeparator('.');
            df.setDecimalFormatSymbols(ddd);
            df.setGroupingUsed(false);
            df.setNegativePrefix("");*/

            System.out.println("Case #" + tt + ": " + new BigDecimal(result) + " " + new BigDecimal(p));

        }

    }

}
