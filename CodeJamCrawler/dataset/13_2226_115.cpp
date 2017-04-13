package global2013.qualification;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class TicTacToeTomek {

    static final String INPUT_FILENAME = "A-small-attempt0.in";
    static final boolean OUTPUT_TO_FILE = true;

    private void solve(Scanner sc, PrintWriter pw) {
        char[][] board = new char[4][4];
        for (int i = 0; i < 4; i++) {
            char[] row = sc.next().toCharArray();
            board[i] = row;
        }
        boolean isCompleted = true;
        for (int i = 0; i < 4; i++) {
            boolean xWinsHoriz = true;
            boolean oWinsHoriz = true;
            boolean xWinsVert = true;
            boolean oWinsVert = true;
            boolean xWinsDiagTopLeft = true;
            boolean oWinsDiagTopLeft = true;
            boolean xWinsDiagTopRight = true;
            boolean oWinsDiagTopRight = true;
            for (int j = 0; j < 4; j++) {
                switch (board[i][j]) {
                    case '.':
                        isCompleted = false;
                        xWinsHoriz = false;
                        oWinsHoriz = false;
                        break;
                    case 'X':
                        oWinsHoriz = false;
                        break;
                    case 'O':
                        xWinsHoriz = false;
                        break;
                    case 'T':
                        // do nothing
                        break;
                }
                switch (board[j][i]) {
                    case '.':
                        isCompleted = false;
                        xWinsVert = false;
                        oWinsVert = false;
                        break;
                    case 'X':
                        oWinsVert = false;
                        break;
                    case 'O':
                        xWinsVert = false;
                        break;
                    case 'T':
                        // do nothing
                        break;
                }
                switch (board[j][j]) {
                    case '.':
                        isCompleted = false;
                        xWinsDiagTopLeft = false;
                        oWinsDiagTopLeft = false;
                        break;
                    case 'X':
                        oWinsDiagTopLeft = false;
                        break;
                    case 'O':
                        xWinsDiagTopLeft = false;
                        break;
                    case 'T':
                        // do nothing
                        break;
                }
                switch (board[j][3-j]) {
                    case '.':
                        isCompleted = false;
                        xWinsDiagTopRight = false;
                        oWinsDiagTopRight = false;
                        break;
                    case 'X':
                        oWinsDiagTopRight = false;
                        break;
                    case 'O':
                        xWinsDiagTopRight = false;
                        break;
                    case 'T':
                        // do nothing
                        break;
                }
            }
            if (xWinsHoriz || xWinsVert || xWinsDiagTopLeft || xWinsDiagTopRight) {
                pw.println("X won");
                return;
            }
            if (oWinsHoriz || oWinsVert || oWinsDiagTopLeft || oWinsDiagTopRight) {
                pw.println("O won");
                return;
            }
        }
        if (isCompleted) {
            pw.println("Draw");
        } else {
            pw.println("Game has not completed");
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        String inputFilename = System.getProperty("user.home") + "/Downloads/" + INPUT_FILENAME;
        Scanner sc = new Scanner(new FileReader(inputFilename));
        PrintWriter pw;
        if (OUTPUT_TO_FILE) {
            pw = new PrintWriter(inputFilename.replaceFirst("\\.in$", ".out"));
        } else {
            pw = new PrintWriter(System.out);
        }
        int caseCnt = sc.nextInt();
        sc.nextLine();
        for (int caseNum = 0; caseNum < caseCnt; caseNum++) {
            System.err.println("Solving test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum + 1) + ": ");
            new TicTacToeTomek().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
