import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class MainB {

    public static void main(String[] args) throws FileNotFoundException {
        new MainB().solve(args[0], args[1]);
    }

    private void solve(String inFile, String outFile) throws FileNotFoundException {
        Scanner sc = new Scanner(/*System.in*/ new File(inFile));
        PrintWriter pw = new PrintWriter(/*System.out */new File(outFile));
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            double farmPrice = sc.nextDouble();
            double farmsProd = sc.nextDouble();
            double neededMoney = sc.nextDouble();

            pw.println(String.format("Case #%d: %.7f", t,
                    search(new FarmParams(farmPrice, farmsProd, neededMoney)
            )));
        }
        pw.flush();
        pw.close();
    }

    private double search(FarmParams farmParams) {
        double left = 0, right = 10000;
        while (right - left > 0.5) {
            double a = (left * 2 + right) / 3.;
            double b = (left + right * 2) / 3.;
            if (calcTime(farmParams, a) < calcTime(farmParams, b))
                right = b;
            else
                left = a;
        }
        return calcTime(farmParams, (left + right) / 2);
    }

    private double calcTime(FarmParams farmParams, double farms) {
        int farmsNum = (int) (farms);
        ClickerState state = new ClickerState(farmParams, farmsNum);
        return state.calcTime();
    }

   private static class FarmParams {
       final double farmPrice;
       final double farmsProd;
       final double neededMoney;

       private FarmParams(double farmPrice,
                          double farmsProd,
                          double neededMoney) {
           this.farmPrice = farmPrice;
           this.farmsProd = farmsProd;
           this.neededMoney = neededMoney;
       }
   }

    private static class ClickerState {

        private final FarmParams farmParams;
        private final int farmsNumber;
        private int curFarms;

        private ClickerState(FarmParams farmParams,
                             int farmsNumber) {
            this.farmParams = farmParams;
            this.farmsNumber = farmsNumber;
        }

        private double prodSpeed() {
            return 2 + curFarms * farmParams.farmsProd;
        }

        private double timeToBuyFarm() {
            return farmParams.farmPrice / prodSpeed();
        }

        public double calcTime() {
            curFarms = 0;
            double time = 0;
            for (int i = 0; i < farmsNumber; i++) {
                time += timeToBuyFarm();
                curFarms++;
            }
            time += farmParams.neededMoney / prodSpeed();
            return time;
        }
    }

}

