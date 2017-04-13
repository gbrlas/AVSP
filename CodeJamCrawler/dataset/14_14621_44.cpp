package codeJam.qualification;

import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by aleksandr on 12.04.14.
 */
public class ProblemB {
    public static void main(String[] args) {
        String file;
        file = "/Volumes/data/codejam/resources/codeJam/qualification/B-small-attempt0.in";

        File dst = new File("/Volumes/data/codejam/resources/codeJam/qualification/B-small-attempt0.out");
        double result;

        try {
            if (!dst.exists()) {
                dst.createNewFile();
            }
            FileWriter fw = new FileWriter(dst.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);

            BufferedReader br = new BufferedReader(new FileReader(file));

            int t = Integer.parseInt(br.readLine());
            for (int e = 1; e<=t; e++){

                String[] line = br.readLine().split(" ");
                double c = Double.parseDouble(line[0]);
                double f = Double.parseDouble(line[1]);
                double x = Double.parseDouble(line[2]);

                Clicker clicker = new Clicker(c, f, x);
                result = clicker.resolve();

                System.out.print("Case #" + e + ": ");

                System.out.println(result);
                bw.write("Case #" + e +": " + result + "\n");
            }

            bw.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static Set<String> getRowSet(BufferedReader br) throws IOException {
        Set<String> rowSet = null;
        int r = Integer.parseInt(br.readLine());
        for (int i = 1; i <= 4; i++) {
            if (r == i) {
                rowSet = new HashSet<>(Arrays.asList(br.readLine().split(" ")));
            } else {
                br.readLine();
            }
        }
        return rowSet;
    }
}
