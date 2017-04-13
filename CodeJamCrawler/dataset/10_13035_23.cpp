import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Rotate
{
	public Rotate()
	throws Exception
	{
		BufferedReader reader = new BufferedReader(new FileReader("input"));
		PrintWriter writer = new PrintWriter("output");
		
		int testCases = Integer.parseInt(reader.readLine());
		
		for(int x=0;x<testCases;x++)
		{
			StringTokenizer tokens = new StringTokenizer(reader.readLine()," ");
			int N = Integer.parseInt(tokens.nextToken());
			int K = Integer.parseInt(tokens.nextToken());
			
			char[][] board = new char[N][N];
			
			for(int y=0;y<N;y++)
			{
				char[] line = reader.readLine().toCharArray();
				board[y]=line;
			}
			board = rotate(board);
			//printBoard(board);
			
			gravitate(board);
			//printBoard(board);
			
			boolean red = kInARow(board,'R', K);
			boolean blue = kInARow(board,'B', K);
			if(red && blue)
				writer.write("Case #"+(x+1)+": Both\n");
			else if (red)
				writer.write("Case #"+(x+1)+": Red\n");
			else if (blue)
				writer.write("Case #"+(x+1)+": Blue\n");
			else
				writer.write("Case #"+(x+1)+": Neither\n");
		}
		writer.close();
	}
	
	public char[][] rotate(char[][] board)
	{
		char[][] rotatedBoard= new char[board.length][board[0].length];
		
		for(int x=0;x<board.length;x++)
			for(int y=0;y<board[0].length;y++)
				rotatedBoard[x][y] = board[board.length - y - 1][x];
		
		return rotatedBoard;
	}
	
	public void gravitate(char[][] board)
	{
		boolean changeMade=true;
		while(changeMade)
		{
			changeMade=false;
			for(int x=1;x<board.length;x++)
			{
				for(int y=0;y<board[0].length;y++)
				{
					if(board[x][y]=='.' && board[x-1][y]!='.')
					{
						board[x][y]=board[x-1][y];
						board[x-1][y]='.';
						changeMade=true;
					}
				}
			}
		}
	}
	
	public boolean kInARow(char[][] board, char kind, int k)
	{
		for(int x=0;x<board.length;x++)
		{
			for(int y=0;y<board.length;y++)
			{
				if(recursiveWin(board,x,y,kind,k))
					return true;
			}
		}
		return false;
	}
	
	public boolean recursiveWin(char[][] board, int x, int y, char kind, int k)
	{
		boolean broke1=false;
		boolean broke2=false;
		boolean broke3=false;
		boolean broke4=false;
		for(int i=0;i<k;i++)
		{
			if(x+i>=board.length || board[x+i][y]!=kind)
				broke1=true;
			if(y+i>=board.length || board[x][y+i]!=kind)
				broke2=true;
			if(x+i>=board.length || y+i>=board.length || board[x+i][y+i]!=kind)
				broke3=true;
			if(y-i<0 || x+i>=board.length || board[x+i][y-i]!=kind)
				broke4=true;
		}
		return !broke1 || !broke2 || !broke3 || !broke4;
	}
	
	public void printBoard(char[][] board)
	{
		for(int x=0;x<board.length;x++)
		{
			for(int y=0;y<board[0].length;y++)
				System.out.print(board[x][y]);
			System.out.println();
		}
		System.out.println();
	}
	
	public static void main(String args[])
	{
		try {
			new Rotate();
		} catch (Exception e) {e.printStackTrace();}
	}
}