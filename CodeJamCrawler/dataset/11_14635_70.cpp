
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Кирилл и Папа
 */
public class Magicka {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt"))));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                String s = br.readLine();
                StringTokenizer st = new StringTokenizer(s);

                int combineCounter = Integer.parseInt(st.nextToken());
                char[][] combine = new char[combineCounter][];
                for (int j = 0; j < combineCounter; j++) {
                    combine[j] = st.nextToken().toCharArray();
                }

                int oppositeCounter = Integer.parseInt(st.nextToken());
                char[][] opposite = new char[oppositeCounter][];
                for (int j = 0; j < oppositeCounter; j++) {
                    opposite[j] = st.nextToken().toCharArray();
                }

                st.nextToken();
                char[] aString = st.nextToken().toCharArray();
                ArrayList<Character> res = new ArrayList<Character>();
                for (int j = 0; j < aString.length; j++) {
                    boolean replaced = false;
                    if (res.size() > 0) {
                        for (int k = 0; k < combine.length; k++) {
                            if (((aString[j] == combine[k][1]) && (res.get(res.size() - 1) == combine[k][0]))
                                    || ((aString[j] == combine[k][0]) && (res.get(res.size() - 1) == combine[k][1]))) {
                                res.set(res.size() - 1, combine[k][2]);
                                replaced = true;
                                break;
                            }
                        }
                        if (!replaced) {
                            for (int k = 0; ((k < res.size()) && !replaced); k++) {
                                for (int l = 0; ((l < opposite.length) && !replaced); l++) {
                                    if (((aString[j] == opposite[l][1]) && (res.get(k) == opposite[l][0]))
                                            || ((aString[j] == opposite[l][0]) && (res.get(k) == opposite[l][1]))) {
                                        res.clear();
                                        replaced = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    if (!replaced) {
                        res.add(aString[j]);
                    }
                }
                bw.write("Case #" + (i + 1) + ": ");
                bw.write("[");
                for (int j = 0; j < res.size() - 1; j++) {
                    bw.write(res.get(j) + ", ");
                }
                if (res.size() > 0) {
                    bw.write(res.get(res.size() - 1));
                }
                bw.write("]");
                bw.newLine();
            }
            bw.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}
