import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;

public class TicTacToeTomek {
    
    private static boolean CONSOLE = false;
    
    public static void main(String[] args) throws Exception {
	if (CONSOLE) {
	    process(new BufferedReader(new InputStreamReader(System.in)),
		    System.out);
	} else {
	    JFileChooser fc = new JFileChooser();
	    fc.setFileFilter(new FileFilter() {
		@Override
		public boolean accept(File f) {
		    return f.isDirectory() || f.getName().endsWith(".in");
		}
		
		@Override
		public String getDescription() {
		    return "Input File (*.in)";
		}
	    });
	    if (fc.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
		File in = fc.getSelectedFile();
		File out = new File(in.getParentFile(),
		        in.getName().replaceAll(".in$", ".out"));
		process(new BufferedReader(new FileReader(in)),
		        new PrintStream(new FileOutputStream(out)));
	    }
	}
    }
    
    private static void process(BufferedReader r, PrintStream w)
	    throws IOException {
	int numCases = Integer.parseInt(r.readLine());
	for (int i = 1; i <= numCases; i++) {
	    w.print("Case #" + i + ": ");
	    char[][] board = new char[4][];
	    for (int row = 0; row < 4; row++) {
		board[row] = r.readLine().toCharArray();
	    }
	    if (hasWon(board, 'X')) {
		w.println("X won");
	    } else if (hasWon(board, 'O')) {
		w.println("O won");
	    } else if (isFilled(board)) {
		w.println("Draw");
	    } else {
		w.println("Game has not completed");
	    }
	    r.readLine();
	}
	r.close();
	w.close();
    }
    
    private static boolean isFilled(char[][] board) {
	for (char[] row : board) {
	    for (char cell : row) {
		if (cell == '.') {
		    return false;
		}
	    }
	}
	return true;
    }
    
    private static boolean hasWon(char[][] board, char c) {
	boolean backwardDiagonal = true;
	boolean forwardDiagonal = true;
	for (int i = 0; i < 4; i++) {
	    boolean horizontal = true;
	    boolean vertical = true;
	    for (int n = 0; n < 4; n++) {
		if (horizontal && !checkCell(board[i][n], c)) {
		    horizontal = false;
		}
		if (vertical && !checkCell(board[n][i], c)) {
		    vertical = false;
		}
	    }
	    if (horizontal || vertical) {
		return true;
	    }
	    if (backwardDiagonal && !checkCell(board[i][i], c)) {
		backwardDiagonal = false;
	    }
	    if (forwardDiagonal && !checkCell(board[i][3 - i], c)) {
		forwardDiagonal = false;
	    }
	}
	return backwardDiagonal || forwardDiagonal;
    }
    
    private static boolean checkCell(char cell, char c) {
	return cell == c || cell == 'T';
    }
    
}
