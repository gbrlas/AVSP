import java.io.File;
import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class RPI {
    public static void main(String[] args) throws Exception {
        File in = new File(args[0]);
        Scanner s = new Scanner(new FileInputStream(in));
        int testCount = s.nextInt();

        for (int i = 0; i < testCount; ++i) {
            System.out.println("Case #" + (i+1) + ":");
            int teamCount = s.nextInt();
            char[][] schedule = new char[teamCount][];
            for (int j = 0; j < teamCount; ++j) {
                char[] teamSchedule = new char[teamCount];
                String sched = s.next();
                for (int k = 0; k < teamCount; ++k) {
                    teamSchedule[k] = sched.charAt(k);
                }
                schedule[j] = teamSchedule;
            }

            doStuff(schedule);
        }
    }

    public static void doStuff(char[][] schedule) {
        int[] gp = new int[schedule.length];
        int[] gw = new int[schedule.length];
        Double[] winPercent = new Double[schedule.length];
        for (int i = 0; i < schedule.length; ++i) {
            gp[i] = 0;
            gw[i]= 0;
            char[] teamSched = schedule[i];
            for (int j = 0; j < schedule.length; ++j) {
               char c = teamSched[j];
                if (c == '.') {
                    continue;
                }
                ++gp[i];
                if (c == '1') {
                    ++gw[i];
                }
                winPercent[i] = (double) gw[i]/gp[i];
            }
        }
        Double[] oppWinPercent = new Double[schedule.length];

        // for each team
        for (int i = 0; i < schedule.length; ++i) {
            double oppWinPer = 0.0d;
            // for my opponents
            for (int j = 0; j < schedule.length; ++j) {
                // skip me
                if (j == i) {
                    continue;
                }
                int ogp = gp[j];
                int ogw = gw[j];

                char[] os = schedule[j];
                // no change if they didn't play me
                if (os[i] != '.') {
                    // remove their game against me
                    ogp--;
                   if (os[i] == '1') {
                       // if they beat me, one less win in their calc
                       ogw--;
                   }
                } else {
                    continue;
                }
                oppWinPer += (double) ogw/ogp;
            }
            oppWinPercent[i] = (oppWinPer/(gp[i]));
        }

        Double[] oppoppWinPercent = new Double[schedule.length];
        // for each team
        for (int i = 0 ; i < schedule.length; ++i) {
            double oppoppWinPer = 0.0d;
            for (int j = 0; j < schedule.length; ++j) {
                if (schedule[i][j] != '.') {
                    // I played them, so count to total
                    oppoppWinPer += oppWinPercent[j];
                }
            }
            oppoppWinPercent[i] = (oppoppWinPer/(gp[i]));
        }
        for (int i = 0; i < schedule.length; ++i) {
            System.out.println((0.25 * winPercent[i]) + (0.5 * oppWinPercent[i]) + (0.25 * oppoppWinPercent[i]));
        }
    }
}
