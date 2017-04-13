package gcj.qual2013;

import java.io.*;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * User: Administrator
 * Date: 4/13/13
 * Time: 12:27 PM
 * To change this template use File | Settings | File Templates.
 */
public class TicTacToe {

  private static final String X_WON = "X won";
  private static final String O_WON = "O won";
  private static final String DRAW = "Draw";
  private static final String UNCOMPLETE = "Game has not completed";


  String solve(String[][] board) {

    boolean isNotComplete = false;

    List<Integer[][]> winSequences = new LinkedList<Integer[][]>();
    Integer[][] diagWinSequence = new Integer[4][2];
    Integer[][] antiDiagWinSequence = new Integer[4][2];
    for (int i = 0; i < 4; i++) {
      diagWinSequence[i][0] = i;
      diagWinSequence[i][1] = i;
      antiDiagWinSequence[i][0] = i;
      antiDiagWinSequence[i][1] = 3-i;
      Integer[][] rowWinSequence = new Integer[4][2];
      Integer[][] colWinSequence = new Integer[4][2];
      for (int j = 0; j < 4; j++) {
        rowWinSequence[j][0] = i;
        rowWinSequence[j][1] = j;
        colWinSequence[j][0] = j;
        colWinSequence[j][1] = i;
      }
      winSequences.add(rowWinSequence);
      winSequences.add(colWinSequence);
    }
    winSequences.add(diagWinSequence);
    winSequences.add(antiDiagWinSequence);

    for (Integer[][] winSequence: winSequences) {
      Set<String> chs = new HashSet<String>();
      for (int i = 0; i < winSequence.length; i++) {
        int row = winSequence[i][0];
        int col = winSequence[i][1];
        chs.add(board[row][col]);
      }

      if (!chs.contains(".")) {
        if (chs.contains("X") && !chs.contains("O"))
          return X_WON;
        if (chs.contains("O") && !chs.contains("X"))
          return O_WON;
      } else {
        isNotComplete = true;
      }

    }

    if (!isNotComplete)
      return DRAW;
    return UNCOMPLETE;
  }

  public static void main(String[] args) {

    TicTacToe solver = new TicTacToe();

    try {
      BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(".\\data\\A-small-attempt0.in")));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(new FileOutputStream(".\\data\\A-small-attempt0.out")));

      int T = Integer.parseInt(reader.readLine());
      for (int iT = 0; iT < T; iT++) {

        String line;
        String[][] board = new String[4][4];
        for (int j = 0; j < 4; j++) {
          line = reader.readLine();
          for (int k = 0; k < 4; k++) {
            board[j][k] = line.substring(k, k+1);
          }
        }
        reader.readLine();

        writer.print("Case #" + (iT+1) + ": ");
        writer.println(solver.solve(board));
      }
      writer.close();
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    } catch (IOException e) {
      e.printStackTrace();
    }
  }


}
