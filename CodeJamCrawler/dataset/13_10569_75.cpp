import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class TicTacTomek {

	private static final String O_WON = "O won";
	private static final String X_WON = "X won";

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("tictac.in"));
		int n = in.nextInt();

		for (int i = 1; i <= n; i++)
		{
			in.nextLine();
			char[][] board = new char[4][4];
			for (int j = 0; j < board.length; j++)
			{
				String line = in.nextLine();
				for (int k = 0; k < board[j].length; k++)
				{
					board[j][k] = line.charAt(k);
				}
			}

			String answer = analyzeBoard(board);
			System.out.println("Case #" + i + ": " + answer);
		}
	}

	private static String analyzeBoard(char[][] board) {
		boolean seenEmptySpace = false;
		// check rows
		for (int i = 0; i < board.length; i++)
		{
			int xCount = 0;
			int oCount = 0;

			for (int j = 0; j < board.length; j++)
			{
				switch (board[i][j])
				{
				case 'X':
					xCount++;
					break;
				case 'O':
					oCount++;
					break;
				case 'T':
					xCount++;
					oCount++;
					break;
				case '.':
					seenEmptySpace = true;
				}
			}
			if (xCount == 4)
				return X_WON;
			if (oCount == 4)
				return O_WON;
		}

		// check columns
		for (int i = 0; i < board.length; i++)
		{
			int xCount = 0;
			int oCount = 0;

			for (int j = 0; j < board.length; j++)
			{
				switch (board[j][i])
				{
				case 'X':
					xCount++;
					break;
				case 'O':
					oCount++;
					break;
				case 'T':
					xCount++;
					oCount++;
					break;
				case '.':
					seenEmptySpace = true;
				}
			}
			if (xCount == 4)
				return X_WON;
			if (oCount == 4)
				return O_WON;
		}

		// check first diagonal
		int xCount = 0;
		int oCount = 0;

		for (int j = 0; j < board.length; j++)
		{
			switch (board[j][j])
			{
			case 'X':
				xCount++;
				break;
			case 'O':
				oCount++;
				break;
			case 'T':
				xCount++;
				oCount++;
				break;
			case '.':
				seenEmptySpace = true;
			}
		}
		if (xCount == 4)
			return X_WON;
		if (oCount == 4)
			return O_WON;

		xCount = 0;
		oCount = 0;
		// check second diagonal
		for (int j = 0; j < board.length; j++)
		{
			switch (board[3-j][j])
			{
			case 'X':
				xCount++;
				break;
			case 'O':
				oCount++;
				break;
			case 'T':
				xCount++;
				oCount++;
				break;
			case '.':
				seenEmptySpace = true;
			}
		}
		if (xCount == 4)
			return X_WON;
		if (oCount == 4)
			return O_WON;


		
		if (seenEmptySpace)
			return "Game has not completed";
		else
			return "Draw";
	}
}
