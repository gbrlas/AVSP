
import java.io.BufferedReader;
import java.io.BufferedWriter;
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
 * @author Кирилл
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("input.in")));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("output.txt")));
        final int DASHBOARD_SIZE = 4;
        final int CANDIDATE_X = 0;
        final int CANDIDATE_O = 1;
        final char CANDIDATE_CHAR_X = 'X';
        final char CANDIDATE_CHAR_O = 'O';
        final char CHAR_T = 'T';
        int numOfTestCases = Integer.parseInt(in.readLine());
        for (int testCase = 1; testCase <= numOfTestCases; testCase++) {
            char[][] game = new char[DASHBOARD_SIZE][];
            for (int i = 0; i < DASHBOARD_SIZE; i++) {
                game[i] = in.readLine().trim().toCharArray();
            }
            in.readLine();
            int points = 0;
            int xSteps = 0;
            int oSteps = 0;
            int tSteps = 0;
            for (int i = 0; i < game.length; i++) {
                for (int j = 0; j < game[i].length; j++) {
                    if (game[i][j] == '.') {
                        points++;
                    } else if (game[i][j] == 'T') {
                        tSteps++;
                    } else if (game[i][j] == 'O') {
                        oSteps++;
                    } else if (game[i][j] == 'X') {
                        xSteps++;
                    }
                }
            }
            int candidate;
            char candChar;
            if (((xSteps + oSteps) & 1) == 1) {
                candidate = CANDIDATE_X;
                candChar = CANDIDATE_CHAR_X;
            } else {
                candidate = CANDIDATE_O;
                candChar = CANDIDATE_CHAR_O;
            }
            boolean winner = false;
            if (!winner) {
                for (int i = 0; i < game.length; i++) {
                    winner = true;
                    for (int j = 0; j < game[i].length; j++) {
                        if ((game[i][j] != candChar) && (game[i][j] != CHAR_T)) {
                            winner = false;
                            break;
                        }
                    }
                    if (winner) {
                        break;
                    }
                }
            }
            if (!winner) {
                for (int i = 0; i < game.length; i++) {
                    winner = true;
                    for (int j = 0; j < game.length; j++) {
                        if ((game[j][i] != candChar) && (game[j][i] != CHAR_T)) {
                            winner = false;
                            break;
                        }
                    }
                    if (winner) {
                        break;
                    }
                }
            }
            if (!winner) {
                winner = true;
                for (int i = 0; i < game.length; i++) {
                    if ((game[i][i] != candChar) && (game[i][i] != CHAR_T)) {
                        winner = false;
                        break;
                    }
                }
            }
            if (!winner) {
                winner = true;
                for (int i = 0; i < game.length; i++) {
                    if ((game[i][game.length - 1 - i] != candChar) && (game[i][game.length - 1 - i] != CHAR_T)) {
                        winner = false;
                        break;
                    }
                }
            }
            if (winner) {
                if (candidate == CANDIDATE_X) {
                    out.write("Case #" + testCase + ": X won");
                } else {
                    out.write("Case #" + testCase + ": O won");
                }
                out.newLine();
            } else {
                if (points == 0) {
                    out.write("Case #" + testCase + ": Draw");
                } else {
                    out.write("Case #" + testCase + ": Game has not completed");
                }
                out.newLine();
            }
        }
        in.close();
        out.close();
    }
}
