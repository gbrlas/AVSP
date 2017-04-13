import java.awt.Point;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Main {
	
	public static int period = 0;
	
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-large.in"));
		PrintWriter out = new PrintWriter(new File("A-large.out"));
		
		int t = in.nextInt();
		
		for(int c = 0; c < t; c++)
		{
			char[][] board = new char[4][4];
			for(int i = 0; i < board.length; i++)
			{
				char[] row= in.next().toCharArray();
				for(int j = 0;j < row.length; j++)
					board[i][j] = row[j];
			}
			
			out.printf("Case #%d: %s\n",c+1, checkBoard(board));
			
			
		}
		out.flush();
		out.close();
		in.close();
		
		
		
	}
	
	public static String checkBoard(char[][]  board)
	{
		period = 0;
		String verdict = null;
		if((verdict = checkRow(board, new Point(0, 0), new Point(1, 0))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(0, 1), new Point(1, 0))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(0, 2), new Point(1, 0))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(0, 3), new Point(1, 0))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(0, 0), new Point(0, 1))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(1, 0), new Point(0, 1))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(2, 0), new Point(0, 1))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(3, 0), new Point(0, 1))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(0, 0), new Point(1, 1))) != null)
			return verdict;
		if((verdict = checkRow(board, new Point(0, 3), new Point(1, -1))) != null)
			return verdict;
		
		
		
		
		
		if (period == 0) return "Draw";
		else return "Game has not completed";
		
	}
	
	public static int [] traverse(char [][] board, Point p, Point d, int [] data)
	{
		if(p.x < 0 || p.x >= board.length || p.y < 0 || p.y >= board[p.x].length)
			return data;
		
		if(board[p.x][p.y] == 'O')
			data[0]++;
		if(board[p.x][p.y] == 'X')
			data[1]++;
		if(board[p.x][p.y] == 'T')
			data[2]++;
		if(board[p.x][p.y] == '.')
			data[3]++;
		
		p.x += d.x;
		p.y += d.y;
		return traverse(board,p,d, data);
	}
	
	public static String checkRow(char [][] board, Point p, Point d)
	{
		int [] data = new int[4];
		traverse(board, p, d, data);
		period += data[3];
		if(data[0] == 4 || data[0] == 3 && data[2] == 1)
			return "O won";
		
		if(data[1] == 4 || data[1] == 3 && data[2] == 1)
			return "X won";
		return null;
	}
}
