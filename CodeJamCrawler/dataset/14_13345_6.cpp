import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.io.Reader;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.OpenOption;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.HashSet;
import java.util.Set;

import static java.nio.file.StandardOpenOption.*;;

public class main {
    public static final String BAD_MAGICIAN = "Bad magician!";
    public static final String BAD_VOL = "Volunteer cheated!";

    public static void main(String args[]) {
        Path file  = Paths.get("./A-small-attempt3.in");
        Charset charset = Charset.forName("US-ASCII");

        try (BufferedReader reader = Files.newBufferedReader(file, charset)) {
            String line = null;
            int counter = 1;
            reader.readLine(); // ignore the test cases 
            while ((line = reader.readLine()) != null) {
                int firstAnswer = Integer.parseInt(line);
                int[][] firstGrid = getGrid(reader);
                int secondAnswer = Integer.parseInt(reader.readLine());
                int[][] secondGrid = getGrid(reader);
                int[] firstRow = firstGrid[firstAnswer-1];
                int[] secondRow = secondGrid[secondAnswer -1];
                Set<Integer> set = difference(firstRow, secondRow);
                if (set.size() > 1) {
                    System.out.println("Case #"+ counter + ": " + BAD_MAGICIAN);
                    writeLine("Case #"+ counter + ": " + BAD_MAGICIAN + "\n");

                } else if (set.size() == 0) {
                    System.out.println("Case #"+ counter + ": " + BAD_VOL);
                    writeLine("Case #"+ counter + ": " + BAD_VOL + "\n");

                } else {
                    System.out.println("Case #"+ counter + ": " + Integer.toString((Integer)set.toArray()[0]));
                    writeLine("Case #"+ counter + ": " + Integer.toString((Integer)set.toArray()[0]) + "\n");
                }
                counter++;
            }
        } catch (IOException x) {
            System.err.format("IOException: %s%n", x);
        }
    }

    private static void writeLine(String line) {
        Charset charset = Charset.forName("US-ASCII");
        Path file  = Paths.get("./output");
         // Convert the string to a
         // byte array.
         byte data[] = line.getBytes();
    
         try (OutputStream out = new BufferedOutputStream(Files.newOutputStream(file, CREATE,  APPEND))) {
             out.write(data, 0, data.length);
         } catch (IOException x) {
             System.err.println(x);
         }

    }

    private static Set<Integer> difference(int[] firstRow, int[] secondRow) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        Set<Integer> setToReturn = new HashSet<>();
        
        for (int i = 0; i < 4; i++) set1.add(firstRow[i]);
        for (int i = 0; i < 4; i++) set1.add(firstRow[i]);
        for (int i = 0; i < 4; i++) {
            if (set1.contains(secondRow[i])) {
                setToReturn.add(secondRow[i]);
            }
        }
        for (int i = 0; i < 4; i++) {
            if (set2.contains(firstRow[i])) {
                setToReturn.add(firstRow[i]);
            }
        }
        return setToReturn;
    }



    static int [][] getGrid(BufferedReader reader) throws IOException {
        int[][] grid = new int[4][4];
        for (int i = 0; i < 4; i++) {
            String[] row = reader.readLine().split(" ");
            for (int j = 0; j < 4; j++) {
                grid[i][j] = Integer.parseInt(row[j]);
            }
        }
        return grid;
    }
}
