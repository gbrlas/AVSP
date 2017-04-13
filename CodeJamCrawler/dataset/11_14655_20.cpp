
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Кирилл и Папа
 */
public class Task1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        double a = 2.0;
        double b = 4;
        a = (a - 1) / (b);
        System.out.println(a);
        try {
//            System.out.println(nod(100, ));
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt"))));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                int numOfPlayers = Integer.parseInt(br.readLine());
                String[] all = new String[numOfPlayers];
                double[] wins = new double[numOfPlayers];
                double[] looses = new double[numOfPlayers];
                double[] notPlayed = new double[numOfPlayers];
                double[] wp = new double[numOfPlayers];
                double[] owp = new double[numOfPlayers];
                double[] oowp = new double[numOfPlayers];
                double[] res = new double[numOfPlayers];
                int[][] map = new int[numOfPlayers][numOfPlayers];
                for (int j = 0; j < numOfPlayers; j++) {
                    all[j] = br.readLine();
//                    wins[j] = all[j].length() - all[j].replace(".", "").replace("0", "").length() - 1;
//                    looses[j] = all[j].length() - all[j].replace(".", "").replace("1", "").length() - 1;
//                    notPlayed[j] = all[j].length() - wins[j] - looses[j];
                    for (int k = 0; k < numOfPlayers; k++) {
                        if (all[j].charAt(k) == '1') {
                            wins[j] = wins[j] + 1;
                            map[j][k] = 1;
                        } else if (all[j].charAt(k) == '0') {
                            map[j][k] = 0;
                            looses[j] = looses[j] + 1;
                        } else if (all[j].charAt(k) == '.') {
                            map[j][k] = -1;
                            if (k != j) {
                                notPlayed[j] = notPlayed[j] + 1;
                            }
                        }
                    }
                }
                for (int j = 0; j < numOfPlayers; j++) {
                    wp[j] = wins[j] / (numOfPlayers - notPlayed[j] - 1);
//                    System.out.println(wp[j]);
                }
                System.out.println("");
                System.out.println("");
                for (int j = 0; j < numOfPlayers; j++) {
//                    System.out.println("Calc " + j);
                    double twp = 0;
                    for (int k = 0; k < numOfPlayers; k++) {
                        if (k == j) {
                            continue;
                        }
                        double temp = wins[k];
                        double denom = (numOfPlayers - notPlayed[k] - 2);
//                        System.out.println("win #" + k + ": " + temp);
//                        System.out.println("notplayed #" + k + ": " + denom);
//                        System.out.println(map[k][i]);
                        if (map[k][j] == -1) {
//                            System.out.println("temp=" + temp);
//                            System.out.println("denom+1 = " + (denom + 1));
                            temp = (temp / (denom + 1));
                        } else if (map[k][j] == 1) {
//                            System.out.println("temp-1=" + (temp-1));
//                            System.out.println("denom = " + (denom));
                            temp = ((temp - 1) / (denom));
                        } else {
//                            System.out.println("temp=" + temp);
//                            System.out.println("denom = " + (denom ));
                            temp = ((temp - 0) / (denom));
                        }
//                        twp = twp + (wp[k]) * (numOfPlayers - notPlayed[k] - 1)
//                                / ((map[k][j]>-1) ? 
//                                ;
                        if (map[k][j] > -1) {
                            System.out.println(temp);
                            twp = twp + temp;
                        }
                    }
                    owp[j] = twp / (numOfPlayers - notPlayed[j] - 1);
                    System.out.println("owp " + (j + 1) + "="
                            + owp[j]);
                }
                for (int j = 0; j < numOfPlayers; j++) {
                    double u = 0;
                        for (int k = 0; k < numOfPlayers; k++) {
                            if (map[k][j] == -1) {
                                continue;
                            }
                            u = u + owp[k];
                    }
                    oowp[j] = u / (numOfPlayers - notPlayed[j] - 1);
                }
                for (int j = 0; j < numOfPlayers; j++) {
                    res[j] = 0.25 * wp[j] + 0.5 * owp[j] + 0.25 * oowp[j];
                }
                bw.write("Case #" + (i + 1) + ":");
                bw.newLine();
                for (int j = 0; j < numOfPlayers; j++) {
                    bw.write(res[j] + "");
                    bw.newLine();
                }
                bw.newLine();
                System.out.println("");
            }
            bw.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
