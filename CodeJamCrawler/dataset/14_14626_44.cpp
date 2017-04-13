package codeJam.qualification;

import java.io.*;
import java.util.*;

/**
 * Created by aleksandr on 12.04.14.
 */
public class ProblemD {
    public static void main(String[] args) {
        String file;
        file = "/Volumes/data/codejam/resources/codeJam/qualification/D-small-attempt0.in";

        File dst = new File("/Volumes/data/codejam/resources/codeJam/qualification/D-small-attempt0.out");
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
                int n = Integer.parseInt(br.readLine());

                DeceitfulWar war = new DeceitfulWar(getBlocks(n, br), getBlocks(n, br));

                System.out.print("Case #" + e + ": ");
                System.out.println(war.optimalResult() + " " + war.deceitfulResult());

                bw.write("Case #" + e +": " + war.optimalResult() + " " + war.deceitfulResult() + "\n");
            }

            bw.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static List<Double> getBlocks(int n, BufferedReader br) throws IOException {
        List<Double> blocks = new ArrayList<>();

        String[] s = br.readLine().split(" ");
        for (int i = 0; i<n; i++) {
            blocks.add(Double.parseDouble(s[i]));
        }

        Collections.sort(blocks);
        return blocks;
    }
}
