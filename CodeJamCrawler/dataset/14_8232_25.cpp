import java.io.*;
import java.nio.charset.Charset;

public class CookieClickerAlpha {
    public static final double START_RATE = 2.0;
    public static final double STEP_SIZE  = 1.0;
    public static final boolean DEBUG = false;
    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Please put an input file");
            System.exit(-1);
        }
        try {
            InputStream fis = new FileInputStream(args[0]);
            BufferedReader br = new BufferedReader(new InputStreamReader(fis, Charset.forName("UTF-8")));
            String line;
            PrintWriter writer = new PrintWriter("answer.out", "UTF-8");

            int i = 0;
            while( (line = br.readLine()) != null) {
                if (i == 0) {}
                else {
                    if(!DEBUG)
                        writer.print("Case #" + String.valueOf(i) + ": ");
                    else     
                        System.out.print("Case #" + String.valueOf(i) + ": ");
                    String[] data1 = line.split("\\s");
                    double[] data = new double[3];
                    data[0] = Double.parseDouble(data1[0]);
                    data[1] = Double.parseDouble(data1[1]);
                    data[2] = Double.parseDouble(data1[2]);
                    double ans = solve(data);
                    if (!DEBUG) {
                        writer.println(String.valueOf(ans));
                    } else {
                        System.out.println(String.valueOf(ans));
                    }

                }
                i++;
            }

            writer.close();
            br.close();
        } catch(IOException e) {
            e.printStackTrace();
        }

    }
    
    /* Solves a single trial.
     * @param   data contains C,F,X
     */
    public static double solve(double[] data) {
        double C = data[0];
        double F = data[1];
        double X = data[2];
        double cur_rate = START_RATE;
        double total_time = 0.0;
        while(true) {
            // compare the time it would take
            // to reach X with the fixed rate versus
            // waiting for a farm and then keeping that fixed
            // rate, break when it is better to just reach X
            // and calculate the total time elapsed
            double dont_buy_time = X/(cur_rate * STEP_SIZE);
            double buy_time_a    = C/(cur_rate * STEP_SIZE);
            double buy_time_b    = X/((cur_rate + F) * STEP_SIZE);
            double buy_time = buy_time_a + buy_time_b;
            if (dont_buy_time <= buy_time) {
                total_time += dont_buy_time;
                break;
            } else {
                cur_rate = cur_rate + F;
                total_time += buy_time_a;
            }
        }

        return total_time;
    }
}

