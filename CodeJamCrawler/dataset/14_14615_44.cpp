package codeJam.qualification;

import java.io.*;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/**
 * Created by aleksandr on 12.04.14.
 */
public class ProblemA {
    public static void main(String[] args) {
        String file;
        file = "/Volumes/data/codejam/resources/codeJam/qualification/ProblemATest.in";
        file = "/Volumes/data/codejam/resources/codeJam/qualification/A-small-attempt0.in";

        File dst = new File("/Volumes/data/codejam/resources/codeJam/qualification/ProblemATest.out");
        String result;

        try {
            if (!dst.exists()) {
                dst.createNewFile();
            }
            FileWriter fw = new FileWriter(dst.getAbsoluteFile());
            BufferedWriter bw = new BufferedWriter(fw);

            BufferedReader br = new BufferedReader(new FileReader(file));

            int t = Integer.parseInt(br.readLine());
            for (int e = 1; e<=t; e++){

                Set<String> row1 = getRowSet(br);
                Set<String> row2 = getRowSet(br);

                row1.retainAll(row2);
                switch (row1.size()) {
                    case 0:
                        result = "Volunteer cheated!";
                        break;
                    case 1:
                        result = row1.iterator().next();
                        break;
                    default:
                        result = "Bad magician!";
                }


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
