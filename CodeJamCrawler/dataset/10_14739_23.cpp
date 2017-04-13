import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;


public class Rotate {

    public static void main(final String[] args) throws Throwable {
        File file = new File("Rotate.in");
        BufferedReader in = new BufferedReader(new FileReader(file));

        String line = in.readLine();

        int cases = Integer.parseInt(line);

        for (int i = 0; i < cases; i++) {
            line = in.readLine();

            int n = Integer.parseInt(line.split(" ")[0]);
            int k = Integer.parseInt(line.split(" ")[1]);

            boolean R = false;
            boolean B = false;

            Character[][] finalBoard = new Character[n][n];

            ArrayList<ArrayList<Character>> rotatedBoard = new ArrayList<ArrayList<Character>>();

            for (int j = 0; j < n; j++) {
                line = in.readLine();
                ArrayList<Character> rotatedLine = new ArrayList<Character>();
                for (int l = 0; l < n; l++) {
                    if (line.charAt(l) != '.') {
                        rotatedLine.add(line.charAt(l));
                    }
                }

                if (rotatedLine.size() < n) {
                    int size = rotatedLine.size();
                    for (int m = 0; m < n - size; m++) {
                        rotatedLine.add(0, '.');
                    }
                }

                rotatedBoard.add(rotatedLine);
            }

            for (int j = 0; j < n; j++) {
                for (int m = 0; m < n; m++) {
                    char c = rotatedBoard.get(j).get(m);
                    if (c != '.') {
                        int count = 1;
                        for (int w = m + 1; w < n; w++) {
                            if (c != rotatedBoard.get(j).get(w)) {
                                break;
                            } else {
                                count++;
                            }
                        }
                        if (count == k) {
                            R = c == 'R' || R;
                            B = c == 'B' || B;
                        }

                        count = 1;
                        for (int w = j + 1; w < n; w++) {
                            if (c != rotatedBoard.get(w).get(m)) {
                                break;
                            } else {
                                count++;
                            }
                        }
                        if (count == k) {
                            R = c == 'R' || R;
                            B = c == 'B' || B;
                        }

                        count = 1;
                        for (int w = 1; w + m < n && w + j < n; w++) {
                            if (c != rotatedBoard.get(j + w).get(m + w)) {
                                break;
                            } else {
                                count++;
                            }
                        }
                        if (count == k) {
                            R = c == 'R' || R;
                            B = c == 'B' || B;
                        }

                        count = 1;
                        for (int w = 1; (m - w) >= 0 && (j + w) < n; w++) {
                            if (c != rotatedBoard.get(j + w).get(m - w)) {
                                break;
                            } else {
                                count++;
                            }
                        }
                        if (count == k) {
                            R = c == 'R' || R;
                            B = c == 'B' || B;
                        }

                        // check diagonal

                    }
                }
            }

            System.out.println("Case #" + (i + 1) + ": " + (R && B ? "Both" : R ? "Red" : B ? "Blue" : "Neither"));
//            System.out.println(rotatedBoard);
        }
    }


}
